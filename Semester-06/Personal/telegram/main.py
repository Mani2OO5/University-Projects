import asyncio
import dotenv
import os
import json
from ollama import chat
from telegram import Update
from telegram.constants import ChatAction
from telegram.ext import (
    Application,
    CommandHandler,
    MessageHandler,
    ContextTypes,
    filters
)

#open prompt files
with open("prompt/chat_prompt.txt", "r", encoding="utf-8") as f:
    SYSTEM_PROMPT = f.read()
with open("prompt/info_prompt.txt", "r", encoding="utf-8") as f:
    INFO_PROMPT = f.read()

#json saving part
FILE_PATH = "Memory.json"

def load_json():
    if not os.path.exists(FILE_PATH):
        return []
    try:
        with open(FILE_PATH, "r", encoding="utf-8") as f:
            return json.load(f)
    except json.JSONDecodeError:
        return []
    
def save_json(data):
    current_data = load_json()
    current_data.append(data)
    with open(FILE_PATH, "w", encoding="utf-8") as f:
        json.dump(current_data, f, ensure_ascii=False, indent=4)    

#extract info from text using the info prompt
def extract_info(txt):
    response = chat(model="llama3.2", 
                    messages=[{"role": "system", "content": INFO_PROMPT}, 
                              {"role": "user", "content": txt}])
    try:
        return json.loads(response.message.content)
    except json.JSONDecodeError:
        pass

#main part
def main(Token):
    temp_history = []
    temp_history.append({"role": "system", "content": SYSTEM_PROMPT})
    temp_history.extend(load_json())
    async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):

        await update.message.reply_text("Hello! I am a helpful assistant.")

    async def keep_typing(bot, chat_id):
        while True:
            await bot.send_chat_action(chat_id=chat_id, action=ChatAction.TYPING)
            await asyncio.sleep(5)

    async def generate(update: Update, context: ContextTypes.DEFAULT_TYPE):

        text = update.message.text

        if not text:
            await update.message.reply_text("Please send a text message.")
            return
        
        info = extract_info(text)
        if info:
            save_json(info)

        temp_history.append({"role": "user", "content": text})

        typing_task = asyncio.create_task(
            keep_typing(context.bot, update.effective_chat.id)
        )
        try:
            response = await asyncio.to_thread(
                chat, model="llama3.2", messages=temp_history
            )

            answer = response.message.content
            
            temp_history.append({"role": "assistant", "content": answer})
            await update.message.reply_text(answer)
        finally:
            typing_task.cancel()

    app = Application.builder().token(Token).build()

    app.add_handler(CommandHandler("start", start))
    app.add_handler(MessageHandler(filters.ALL, generate))

    app.run_polling()


if __name__ == "__main__":
    dotenv.load_dotenv()
    Token = os.getenv("Token")
    main(Token)