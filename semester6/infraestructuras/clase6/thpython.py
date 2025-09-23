"""

Autor: Jaime Andres Noreña
Fecha: 2025-09-23
Ejemplo de uso de threading en python
"""
import threading

def generador(ini, fin):
    l = []
    for i in range(ini, fin):
        l.append(i)
    return l


if __name__ == "__main__":
    l = generador(0, 100000);
    print(l[:20])
    #generamos 4 hilos
