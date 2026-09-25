def new_func():
    num1 = int(input("Enter first number"))
    num2 = int(input("Enter second number"))
    op   = input("enter an operator: ")
    if(op == '+'):
        print(num1 + num2)
    elif(op == '-'):
        print(num1 - num2)
    elif(op == '*'):
        print(num1 * num2)
    elif(op == '/'):
        print(num1 / num2)

new_func()
