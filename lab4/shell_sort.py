import random


def shell_sort(data):
    n = len(data)
    #gap for comparing elements (n/2, n/4, ..... 1)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            j = i
            temp = data[i] #data we are holding

            while j >= gap and data[j - gap] > temp:
                data[j] = data[j-gap]
                j -= gap
            data[j] = temp
        gap //= 2

def display(data):
    for e in data:
        print(e, end=" ")

n = int(input("Enter the number of data: "))
data = [random.randint(0, 1000) for _ in range(n)]
display(data)
print("\n\n")
shell_sort(data)
display(data)