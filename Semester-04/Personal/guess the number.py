from random import randint

def Generator():
    '''
    this Function Generate a random number between 1 & 100
    '''
    return randint(1,100)

def Welcome():
    '''
    this Function show greeting message include start order
    '''
    print("Hello")
    print("Welcome to This game.")
    print("all you do is guess the coreect number.")
    Start = input("Press Enter to Start The game...")
    return Start == ''

def Finish():
    '''
    this function ask member to continue the game
    '''

    FinishGame = input("Do you want to finish the game: ")
    return FinishGame.upper() in ['Y','YES','ARE', 'AHA', 'BALE']


def Check(Guessed_number , Computer_number):
    '''
    This function check the statue of two Guessed_number & Computer_number values
    '''
    if Guessed_number > Computer_number:

        return "make a smaller guess"

    if Guessed_number < Computer_number:

        return "make a bigger guess"

    else:

        return "Good Guess.\n You WON!!!!!!!!"


#main Program:
KeyAnswer = Welcome()
if KeyAnswer:
    
    finishGame = False
    while not finishGame:
        Com_NUm = Generator()
        Guess = 0
        Count = 0
        while int(Guess) != Com_NUm:
            Count +=1
            Guess = input("guess a number: ")
            Statue = Check(int(Guess),Com_NUm)
            print(Statue)

        print (f"with just {Count} guesses")
        
        finishGame = Finish()