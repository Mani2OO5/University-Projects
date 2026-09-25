import random
import os
from tkinter.constants import Y
os.system('cls' or 'clear')
from  tkinter import messagebox
class color :
   GREEN = '\033[92m'
   RED = '\033[91m'
   WHITE = '\033[97m'
   YELLOW = '\033[93m'
   CYAN = '\033[96m'
   PURPLE = '\033[95m'
   BLUE = '\033[94m'
   GRAY = '\033[90m'
   BLACK = '\033[30m'
lower = "abcdefghijklmnopqrstuvwxyz"
upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
numbers = "123456789"
symbols = "\_-/"

all = lower + upper + numbers + symbols

length = 15
ID = "".join(random.sample(all,length))
print(color.BLACK + "====================")
print("")
print(color.WHITE + "Sign up")
print("")
first_name = input("enter your first name: ")
last_name = input("enter your last name: ")
nick_name = input("make a nickname: ")
Email = input("enter your E-mail: ")
password = input("enter your E-mail password: ")
print("")
print(color.GREEN + "Hi " + first_name + "!")
print(color.WHITE + "ID: " + color.GRAY + ID)
print("")
print(color.BLUE + "Now you can login!")
print("")
print("")
print("")
print(color.WHITE + "Login")
print("")
nick_name2 = input("please enter your name: ")
password2 = input("enter your password: ")
print("")
print(color.BLACK + "====================")

if nick_name2 == (nick_name) and  password2 == (password):
    print(color.GREEN + "Welcome!")  

if nick_name2 != (nick_name) or password2 != (password):
    print(color.RED + "invalid name or password")

print(color.BLACK + "====================")
