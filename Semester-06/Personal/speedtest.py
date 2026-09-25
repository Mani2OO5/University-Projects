from os import popen
from sys import argv


def main():

    quantity = 100
    host = argv[1]
    speed = 0.00
    tot_speed = 0.00
    successed_times = 0

    print(f"speed: {speed:.2f} Mbps", end="\r")

    for i in range(quantity):

        output = popen(f"ping -n 1 {host}").read()
        output = output.splitlines()

        if output[0][:32] == "Ping request could not find host":
            print(
                """

**********

wrong input

**********

correct_input : python speedtest.py example.domain

**********
                """
            )
            return

        if output[2] == "Request timed out.":
            speed = 0.00
            print(f"speed: {speed:.2f} Mbps", end="\r")
            continue

        else:
            successed_times += 1
            output = output[2]
            output = output.split()[4]
            time = int(output[5:-2])
            speed = 8 / (time / 10)
            tot_speed += speed
            if speed >= 1.50:
                print(f"speed: {speed:.2f} Mbps", end="\r")
            else:
                print(f"speed: {int(speed * 1000)} Kbps ", end="\r")

    # average speed

    print("\n")
    average_speed = 0.00

    if successed_times != 0:
        average_speed = tot_speed / successed_times
        if average_speed >= 1.00:
            print(f"average speed: {average_speed:.2f} Mbps")
            print(f"package recieved: {successed_times} / 100")
        else:
            print(f"average speed: {int(average_speed * 1000)} Kbps")
            print(f"[package recieved: {successed_times}")

    else:
        print(f"average speed: {average_speed:2f} Mbps")


if len(argv) == 2:
    main()


else:

    print(
        """
**********

wrong input

**********

exp ==> python speedtest.py <dns/url>

**********

                """
    )
