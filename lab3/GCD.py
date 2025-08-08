def GCD(a, b):
    if b == 0:
        return a
    else:
        return GCD(b, a % b) 


a = int(input("Enter the value of a: "))
b = int(input("Enter the value of b: "))


result = GCD(a, b)


print(f'The GCD value is: {result}')
