import heapq
def char_frequency():
    Data = open("data.txt", "rt")
    text = Data.read()
    counter = {}
    for char in text:
        if char in counter:
            counter[char] += 1
        else:
            counter[char] = 1

    counter = dict(sorted(counter.items(), key=lambda item: item[1]))

    return counter


def tree():
    counter = char_frequency()
    frequency = counter.copy()
    new_dict = counter.copy()

    while len(frequency) > 1:

        frequency = dict(sorted(frequency.items(), key=lambda item: item[1]))

        key1, value1 = list(frequency.items())[0]
        key2, value2 = list(frequency.items())[1]

        new_value = value1 + value2
        new_key = key1 + key2

        del frequency[key1]
        del frequency[key2]

        frequency[new_key] = new_value
        new_dict[new_key] = new_value

    #new_dict = dict(sorted(new_dict.items(), key=lambda item: item[1], reverse=True))
    heap_list = [(count , char) for char , count in new_dict.items()]
    heapq.heapify(heap_list)
    return heap_list

def tree2():
    frequency = list(char_frequency().copy().items())
    print(frequency)
    heapq.heapify(frequency)
    print(frequency)



print(tree())
# print(tree())
