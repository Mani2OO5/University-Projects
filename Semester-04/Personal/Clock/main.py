"""this program shows the current time and you can set an Alarm"""

import keyboard
import time
from emoji import emojize
from playsound import playsound

def time_input():
    """
    -this fuction get the Alerm time by user
    -check the input if its correct

    Hour:
    Minute:
    Second:
    """

    check = False
    while not check:
        hour = int(input("Hour: "))
        if hour < 0 or hour >= 24:
            print("out of range")
            continue
        check = True

    check = False
    while not check:
        minute = int(input("Minute: "))
        if minute < 0 or minute >= 60:
            print("out of range")
            continue
        check = True

    check = False
    while not check:
        second = int(input("Second: "))
        if second < 0 or second >= 60:
            print("out of range")
            continue
        check = True

    return (hour, minute, second)

def time_check(hour, minute, second):
    """
    this function calculates the Diffrence of two times in second
    and it checks if the input time is lower than current time.
    """
    currenttime = time.localtime()
    second1 = currenttime.tm_hour * 3600 + currenttime.tm_min * 60 + currenttime.tm_sec
    second2 = hour * 3600 + minute * 60 + second

    return not second2 - second1 < 0


def main():
    print("set Alarm: ")

    alarm_tuple = time_input()
    Hour, Minute, Second = alarm_tuple
    if not time_check(Hour, Minute, Second):
        print(
            f"""
    the input time is lower than current time
    the alarm will be set for tomorrow({time.localtime().tm_mday}/{time.localtime().tm_mon})
                """
            )

    alarm = f"{Hour:02}:{Minute:02}:{Second:02}"
    TIME = ""

    while TIME != alarm:
        current = time.localtime()
        TIME = f"{current.tm_hour:02}:{current.tm_min:02}:{current.tm_sec:02}"
        print(TIME, end="\r")
        time.sleep(1)

    while not keyboard.is_pressed("enter"):
        print(emojize(":bell:"))
        print("press Enter to stop the alarm")
        playsound("Retro-digital-alarm-clock-beep-sound-effect.mp3")


if __name__ == "__main__":
    main()