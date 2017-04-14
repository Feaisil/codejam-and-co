f = open('input','r')
o = open('output','w')
import sys, resource
sys.setrecursionlimit = 100000000000000000000000000000000
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))

import networkx as nx
import time
start = time.time()
T= int(f.readline()[:-1])

class Node:
        def __init__(self, val, cost):
                self.built = False
                self.array = val
                self.path_cost = cost
                self.cost = max(val)+cost
        def __repr__(self):
                return "node "+str(self.array) + " cost " + str(self.cost) + " path cost " + str(self.path_cost)
        def __eq__(self, o):
                return self.array == o.array
        def __hash__(self):
                k = 0
                for i in self.array :
                     k = hash(i+k)   
                return k
        def build(self, graph):
                if self.built:
                        return
                for i,v in enumerate(self.array):
                        if v < 4: continue
                        for k in range(2, int(v/2)+1):
                                a=self.array.copy()
                                a[i]=k
                                a+=[v-a[i]]
                                a.sort()
                                n=Node(a,self.cost + 1)
                                graph.add_edge(self,n)
                                
                                nodes = graph.nodes()
                                n=nodes[nodes.index(n)]
                                n.path_cost=min(n.path_cost,self.path_cost+1)
                                n.cost=max(n.array)+n.path_cost
                                global min_cost
                                min_cost = min(min_cost, n.cost)
                                n.build(graph)
                                

                self.built = True

for Ti in range(T):
		
		
        #parse args
        D = int(f.readline().strip('\n'))
        P = [int(i) for i in f.readline().strip('\n').split(' ')]
        
        #logic
        g=nx.DiGraph()
        P.sort()
        n=Node(P,0)
        min_cost = n.cost
        n.build(g)
        print(P,g.number_of_nodes(), g.number_of_edges())


        o.write("case #{0}: {1}\n".format(Ti+1, min_cost))
        print("case #{0}: {1}\n".format(Ti+1, min_cost))
#conclude
o.close()
print("duration {0}".format(time.time()-start))
