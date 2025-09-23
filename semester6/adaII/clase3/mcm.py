import numpy as np

def mcm(p):
    n = p.shape[0]-1
    costos = np.zeros((n,n)).tolist()
    decision = np.zeros((n,n)).tolist()

    for i in range(n):
        costos[i][i] = 0
        decision[i][i] = i

    for k in range(0,n):
        for i in range(k,n):
            j = i+k+1
            if j >= n:
                break
            costos[i][j] = f"{i},{j}"
    return costos


if __name__ == "__main__":
    print(mcm(np.array([2,20,30,5,2])))
