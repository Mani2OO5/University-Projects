import os
from openai import OpenAI

#openai.api_key = os.getenv("API_KEY")

client = OpenAI()

user = input("Enter your question: ")

response = client.chat.completions.create(
    model="gpt-4o-mini",
    messages=[
        {"role": "system", "content": "You are a helpful assistant."},
        {"role": "user", "content": user}
    ]
)

print(response.choices[0].message['content'])