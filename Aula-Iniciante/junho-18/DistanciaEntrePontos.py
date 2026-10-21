from math import sqrt

def colineares(a, b, c):
    x1, y1 = a
    x2, y2 = b
    x3, y3 = c
    
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)

def distancia_ponto_reta(ponto, reta):
    x0, y0 = ponto
    a, b, c = reta
    return abs(a * x0) #incompleto

def posicao_ponto_circulo(xa, ya, xm, ym, r):
    dist2 = (xa - xm) ** 2 + (ya - ym)**2
    raio2 = r**2
    if dist2 < raio2:
        return "dentro"
    elif dist2 == raio2:
        return "sobre"
    else:
        return "fora"
#Centro M = (0,0) e Raio r = 5
#print(posicao_ponto_circulo(3, 4, 0, 0, 5))
#print(posicao_ponto_circulo(2, 1, 0, 0, 5))

