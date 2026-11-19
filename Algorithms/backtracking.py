def backtrack(estado):
    # 1. caso base
    if condicao_de_parada:
        salvar_ou_retornar
        return
    
    # 2. percorrer opções
    for escolha in opcoes_possiveis:
        
        # 3. verificar se a escolha é valida
        if escolha_valida(escolha, estado):
            # 4. fazer a escolha
            fazer_escolha(escolha, estado)
            # 5. explorar
            backtrack(estado_ou_novo_estado)
            # 6. desfazer a escolha
            desfazer_escolha(escolha, estado)