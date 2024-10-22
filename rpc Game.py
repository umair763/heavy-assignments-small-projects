# -----------------headers--------------------
from asyncio import sleep
import random
import time
import numpy as np  # numpy: for scientific computing and working with arrays.
import math  # math: for mathematical functions and constants.
import datetime
import os  # os: for working with the operating system and file system.
import sys  # sys: for interacting with the Python interpreter and system.

# ---------functions and classes--------------
os.system("color 87")

pc = 5
user = 5

choice = ["rock", "paper", "sessor"]
rand = random.choice(choice)

def menu():
    os.system("cls")
    print("\n\t\t\t\t\t->>>   WELCOME TO THE GAME   <<<-")
    print("\n\t\t\t\t\t\t->  Rock   <-")
    print("\n\t\t\t\t\t\t->  Paper  <-")
    print("\n\t\t\t\t\t\t->  Sessor <-")
    print("\n\t\t\t\t\t\t->  exit   <-")
    print("\t\t\t\t------------------------------------------------")


while True:
    menu()
    cho = input("\n\t\t\t\t      Your choice : ")
    choice = ["rock", "paper", "sessor"]
    if cho == "exit":
        break
    boolSTATE = cho in choice
    if boolSTATE:
        rand = random.choice(choice)
        if rand == cho:
            print("\n\t\t\t\t\t\tIt was draw !\n")
            print("\n\t\t\t\t\t________________________________")
            print(
                f"\n\t\t\t\t\t| your choice     |   {cho}   |\n\t\t\t\t\t| computer choice |   {rand}   |"
            )
            print("\n\t\t\t\t\t________________________________")
        elif cho == "rock" and rand == "paper":
            print("\n\t\t\t\t\t\tYou Lost !\n")
            print("\n\t\t\t\t\t________________________________")
            print(
                f"\n\t\t\t\t\t| your choice     |   {cho}   |\n\t\t\t\t\t| computer choice |   {rand}   |"
            )
            print("\n\t\t\t\t\t________________________________")
            if user <= 0:
                print("Game over Your score is 0")
                menu()
            else:
                pc = pc + 1
                user = user - 1
        elif cho == "paper" and rand == "sessor":
            print("\n\t\t\t\t\t\tYou Lost !\n")
            print("\n\t\t\t\t\t________________________________")
            print(
                f"\n\t\t\t\t\t| your choice     |   {cho}   |\n\t\t\t\t\t| computer choice |   {rand}   |"
            )
            print("\n\t\t\t\t\t________________________________")
            if user <= 0:
                print("Game over Your score is 0")
                menu()
            else:
                pc = pc + 1
                user = user - 1
        elif cho == "sessor" and rand == "rock":
            print("\n\t\t\t\t\t\tYou Lost !\n")
            print("\n\t\t\t\t\t________________________________")
            print(
                f"\n\t\t\t\t\t| your choice     |   {cho}   |\n\t\t\t\t\t| computer choice |   {rand}   |"
            )
            print("\n\t\t\t\t\t________________________________")
            if user <= 0:
                print("Game over Your score is 0")
                menu()
            else:
                pc = pc + 1
                user = user - 1
        else:
            print("\n\t\t\t\t\t\tYou Win !\n")
            print("\n\t\t\t\t\t________________________________")
            print(
                f"\n\t\t\t\t\t| your choice     |   {cho}   |\n\t\t\t\t\t| computer choice |   {rand}   |"
            )
            print("\n\t\t\t\t\t________________________________")
            user = user + 1
            if pc <= 0:
                print("Game over Pc score is 0")
                menu()
            else:
                pc = pc - 1

        res = input("\nContinue (y/n) : ")
        if res == "n":
            print("\n\t\t\t\t\t\tLoading results ...")
            time.sleep(1)
            print("Your Score: ", user)
            print("Pc Score: ", pc)
            break
    else:
        print("Enter correct choice")
        menu()
