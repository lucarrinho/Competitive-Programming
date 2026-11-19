class SegTreeLazy:
    def __init__(self, vetor):
        self.n = len(vetor)
        self.vetor = vetor
        self.tree = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)
        if self.n > 0:
            self.build(1, 0, self.n-1)
    
    def build(self, nodo, start, end):
        if start == end:
            self.tree[nodo] = self.vetor[start]
        
        mid = (start + end) // 2
        left = 2 * nodo
        right = 2 * nodo + 1
        
        self.build(left, start, mid)
        self.build(right, mid+1, end)
        
        self.tree[nodo] = self.tree[left] + self.tree[right]
    
    def update(self, l, r, valor):
        #marca todos no intervalo para atualizar o valor
        self._update(0, 0, self.n-1, l, r, valor)
    
    def _update(self, nodo, start, end, l, r, valor):
        #define o lazy de todos no intervalo
        if r < start or end < l:
            return
                
        if l <= start and end <= r:
            self.lazy[nodo] += valor
            self._push(nodo, l, r)
            return
                
        mid = (start + end) // 2
        left = 2 * nodo + 1
        right = 2 * nodo + 2
        
        self._update(left, start, mid, l, r, valor)
        self._update(left, mid+1, end, l, r, valor)
        return
    
    def _push(self, nodo, start, end):
        if self.lazy[nodo] != 0:
            self.tree[nodo] += (end - start + 1) * self.lazy[nodo]
        
        if start != end:
            self.lazy[2*nodo] += self.lazy[nodo]
            self.lazy[2*nodo+1] += self.lazy[nodo]
        
        self.lazy[nodo] = 0
    
    def query(self, l, r):
        return self._query(1, 0, self.n-1, l, r)
    
    def _query(self, nodo, start, end, l, r):
        self._push(nodo, start, end)
        if r < start or end < l:
            return 0
        
        if l <= start and end <= r:
            return self.tree[nodo]
        
        mid = (start + end) // 2
        left = 2 * nodo + 1
        right = 2 * nodo + 2
        
        sum_l = self._query(left, start, mid, l, r)
        sum_r = self._query(right, mid+1, end, l, r)
        return sum_l + sum_r