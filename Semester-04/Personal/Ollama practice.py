import ollama
import random
import time

SHINY_GREEN = "\033[1;92m"
RESET_COLOR = "\033[0m"

def type(text , delay_ms = 50):
    for char in text:
        print(SHINY_GREEN + char + RESET_COLOR, end='' , flush = True)
        time.sleep(delay_ms / random.randint(100, 500))
    print()



def Llama(prompt):
    
    response = ollama.chat( model = "llama3.2", messages = [
                                         {"role": "system" , "content": "speak Secretively dont use ** words"},
                                         {"role": "user" , "content": prompt},
                                         {"role": "assistant" , "content": "guitar"}                
                                       ]
                          )
    return response['message']['content']

type(Llama("whats the weather today"))