import random


def radix_sort(data):
    radixArray = [[],[],[],[],[],[],[],[],[],[]]
    exponent = 1
    maxData = max(data)

    while maxData // exponent > 0:
        while len(data) > 0:
            value = data.pop()
            radixArrayIndex = (value // exponent) % 10
            radixArray[radixArrayIndex].append(value)
        
        for innerArray in radixArray:
            while len(innerArray) > 0:
                data.append(innerArray.pop())
        
        exponent *= 10

def display(data):
    for e in data:
        print(e, end=" ")

n = int(input("Enter the number of data: "))
data = [random.randint(0, 1000) for _ in range(n)]
display(data)
print("\n\n")
radix_sort(data)
display(data)


