
import math
G=[
   [0,10,math.inf,5,0],
   [0,0,1,2,0],
   [0,0,math.inf,0,4],
   [0,3,9,0,2],
   [7,math.inf,6,0,0]
]
def FloydWarshall(w):
    n=len(w)
    D=dict()
    D[-1]=w
    for k in range(n):
        D[k]=D[k-1]
        for i in range(n):
            for j in range(n):
             D[k][i][j]=min(
                  D[k-1][i][j],
                  D[k-1][i][j]+D[k-1]) 
  