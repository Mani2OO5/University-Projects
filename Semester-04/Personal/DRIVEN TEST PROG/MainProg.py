def is_word(expression):
    return len(expression.split())


def Sort(expression):
    WordsList = expression.split()
    WordsList.sort()
    return WordsList
