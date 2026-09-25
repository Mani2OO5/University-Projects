from InfoSet import InfoSet

counter = 0

while counter != 2:
    
    print("\n\n")
    print("..................................................")
    for i,j,k in InfoSet:
        print(f"{i} {j} is {k} years old")

    print("\n\n")

    print("add a person info: ")
    FirstName = input("insert firstname: ")
    LastName  = input("insert lastname: ")
    Age       = input("insert the age: ")

    print("\n\n")

    InfoSet.add((FirstName, LastName, int(Age)))



    for i,j,k in InfoSet:
        print(f"{i} {j} is {k} years old")
    
    counter += 1


with ("InfoSet.py", "w") as f:
    f.write(f"({FirstName},{LastName},{Age})")

