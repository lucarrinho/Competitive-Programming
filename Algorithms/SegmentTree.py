from sys import stdin
input = stdin.readline

class segtree:
    def __init__(self, dados):
        self.n = len(dados)
        self.dados = dados
        #alocar memória para a árvore
        self.tree = [0] * (4 * self.n)
        if self.n > 0:
            self._build(0, 0, self.n-1)
    
    def _build(self, nodo, start, end):
        #Se na folha, atribui o valor
        if start == end:
            self.tree[nodo] = self.dados[start]
            return
        
        mid = (start + end) // 2
        left = 2*(nodo + 1)
        right = 2*(nodo + 1) + 1
        
        #Construir os filhos
        self._build(left, start, mid)
        self._build(right, mid+1, end)
        
        #Guarda a soma dos filhos
        self.tree[nodo] = self.tree[left] + self.tree[right]
        
    def update(self, index, valor):
        self._update(0, 0, self.n-1, index, valor)
        #self.dados[index] = valor #Para caso se queira alterar a lista original
    
    def _update(self, nodo, start, end, index, valor):
        if start == end:
            self.tree[nodo] = valor
            return
        
        mid = (start + end) // 2
        left = 2*(nodo + 1)
        right = 2*(nodo + 1) + 1
        
        if start <= index <= mid:
            self._update(left, start, mid, index, valor)
        else:
            self._update(right, mid+1, end, index, valor)
        
        self.tree[nodo] = self.tree[left] + self.tree[right]
    
    def query(self, l, r):
       return self._query(0, 0, self.n-1, l, r)
    
    def _query(self, nodo, start, end, l, r):
        #Se fora do intervalo inteiramente
        if r < start or end < l:
            return 0
        
        #Intervalo inteiramente dentro do que se quer
        if l <= start and end <= r:
            return self.tree[nodo]
        
        #Interseção parcial
        mid = (start + end) // 2
        left = 2*(nodo + 1)
        right = 2*(nodo + 1) + 1
        
        sum_l = self._query(left, start, mid, l, r)
        sum_r = self._query(right, mid+1, end, l, r)
        
        return sum_l + sum_r