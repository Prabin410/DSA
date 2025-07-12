def postfix(expression):
    stack = []
    operators = {'+', '-', '*', '/', '^'}

    for token in expression.split():
        if token not in operators:
            
            stack.append(float(token))
        else:
            b = stack.pop()
            a = stack.pop()

            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(a / b)
            elif token == '^':
                stack.append(a ** b)
            elif token == '+':
                stack.append()

    return stack[0]

expression = input("Enter a postfix expression : ")
result = postfix(expression)
print("Result:",result)