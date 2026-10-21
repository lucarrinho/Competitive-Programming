def main():
    entrada = input()
    pilha = []
    validade = True
    for c in entrada:
        if c in '([{':
            pilha.append(c)
        elif c == ")" and pilha[-1] == "(":
            pilha.pop()
        elif c == "]" and pilha[-1] == "[":
            pilha.pop()
        elif c == "}" and pilha[-1] == "{":
            pilha.pop()
        else:
            break

    if len(pilha) > 0:
        validade = False
    
    print(validade)

main()