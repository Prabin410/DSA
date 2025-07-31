 
import math 
from queue import PriorityQueue
G={
    's':{'t':10,'y':5},
    't':{'x':1,'y':2},
    'x':{'z':4},
    'y':{'t':3,'x':9,'z':2},
    'z':{'s':7,'x':6}
}
def DJ(G,s):
    cost={}
    prev={}
    for vertex in G.keys():
        cost={}
        prev={}
        for vertex in G.keys():
            cost[vertex]=math.inf
            prev[vertex]=" "
        cost[s]=0
        visited=list()
        PQ=PriorityQueue()
        for vertex in G.keys():
            PQ.put((cost[vertex],vertex))
        while(len(visited)!=len(G.keys())):
            _, currentVertex=PQ.get()
            visited.append(currentVertex)
            for chimeki in G[currentVertex].keys():
                 if chimeki not in visited:
                     if cost[chimeki]>cost[currentVertex]+G[currentVertex][chimeki]:
                         cost[chimeki]=cost[currentVertex]+G[currentVertex][chimeki]
                         prev[chimeki]=currentVertex 
                         PQ.put((cost[chimeki],chimeki))
    return cost,prev 
def reconstruct_path(prev,vertex):
    path=vertex    
    while prev[vertex]!=" ":
        path=prev[vertex]+'->'+path 
        vertex=prev[vertex]
    return path 
source='s'
cost,prev=DJ(G,source)
for vertex in G.keys():
    print(f"From {source} to {vertex}, path is {reconstruct_path(prev,vertex)}")
    
print(cost)
print(prev)