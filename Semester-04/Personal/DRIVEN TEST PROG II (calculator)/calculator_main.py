'''
main
'''
def zerocheck(func):
    def wrapper(*args):
        if func(*args) == 0:
            print("SEFR shod ke")
        return func(*args)
    return wrapper

@zerocheck
def add(*args):
    result = 0
    for number in args:
        result += number
    return result

@zerocheck
def multi(num1 , num2):
    result = 0
    for time in range(num2):
        result = add(result,num1)
    return result

def power(num1, num2):
    result = 1
    for number in range(num2):
        result = multi(result,num1)
    return result
