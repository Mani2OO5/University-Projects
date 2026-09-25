"""
This module implements the Rock, Paper, Scissors game.
"""
import random
from emoji import emojize

print("WELCOME!")
print(f"{emojize(":raised_fist:")} {emojize(":raised_hand:")} {emojize(":victory_hand:")}")
print(f"{emojize(":rock:")}  {emojize(":page_with_curl:")} {emojize(":scissors:")}")

while True:
    style = input("""
choose game style:
'h' for 'hand style'
'e' for 'emoji style'
::: """)
    if style == 'e':
        Dict = {
            "r" : emojize(":rock:"),
            "p" : emojize(":page_with_curl:"),
            "s" : emojize(":scissors:")}
        break
    if style == 'h':
        Dict = {
            "r" : emojize(":raised_fist:"),
            "p" : emojize(":raised_hand:"),
            "s" : emojize(":victory_hand:")}
        break

    print("\nWRONG INPUT")

user_input = ""
elements_list = ["r", "p", "s"]
while True:
    while user_input not in elements_list:
        user_input = input(f"""
insert a value:
'r' for 'Rock' {emojize(":raised_fist:")} {emojize(":rock:")}
'p' for 'Paper' {emojize(":raised_hand:")} {emojize(":page_with_curl:")}
's' for 'Scissors' {emojize(":victory_hand:")} {emojize(":scissors:")}
::: """)
        if user_input not in elements_list:
            print("\nWRONG INPUT")


    user_choice = user_input.lower()

    computer_choice = random.choice(elements_list)
    print(f"\nYou: {Dict[user_choice]}\nComputer: {Dict[computer_choice]}")

    if user_choice == 'r' and computer_choice == 'p':
        print("you lose")
    elif user_choice == 'r' and computer_choice == 's':
        print("you won")
    elif user_choice == 'p' and computer_choice == 'r':
        print("you won")
    elif user_choice == 'p' and computer_choice == 's':
        print("you lose")
    elif user_choice == 's' and computer_choice == 'r':
        print("you lose")
    elif user_choice == 's' and computer_choice == 'p':
        print("you won")
    else:
        print("DRAW")
    user_input = ""
