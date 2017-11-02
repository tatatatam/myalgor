from collections import defaultdict


# This class represents a directed graph using adjacency list representation
class Graph:
    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)

    # Use BFS to check path between s and d
    def isReachable(self, s, d):
        # Mark all the vertices as not visited
        visited = [False] * (self.V)

        # Create a queue for BFS
        queue = []

        # Mark the source node as visited and enqueue it
        queue.append(s)
        visited[s] = True

        while queue:

            # Dequeue a vertex from queue
            n = queue.pop(0)

            # If this adjacent node is the destination node,
            # then return true
            if n == d:
                return True

            # Else, continue to do BFS
            for i in self.graph[n]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
        # If BFS is complete without visited d
        return False
# def walking(matrix):
#     cloner = matrix
#     for i in range(len(cloner)):
#         for j in range(len(cloner[i])):
#             starter = i
#             next = j
#             count = 0
#             while next!=starter:
#                 print("n "+str(next)+"and c "+str(count))
#                 if(cloner[next][count]==1):
#                     next=count
#                 elif count+1==len(cloner[i]):
#                     print("error")
#                     break
#                 else:
#                    count =count+1
#     print("yes")

####MAINCALL###
while True:

        case=input()
        n,m=case.split(' ')
        if int(n)==0 & int(m)==0: break
        matrix = [[0 for x in range(int(n))] for y in range(int(n))]
        print(matrix)
        g = Graph(int(n))
        for p in range(int(m)):
                getting = input()
                a,b,c= getting.split(' ');
                if(int(c)==2):
                    g.addEdge(int(b)-1,int(a)-1)
                    # matrix[int(b)-1][int(a)-1]=1
                g.addEdge(int(a)-1, int(b)-1)
                # matrix[int(a)-1][int(b)-1]=1
                # print(g.graph)
        answer=1
        for i in range(int(n)):
            for j in range(int(n)):
                if g.isReachable(i,j):
                    print('ok %d %d',i,j)
                    # answer=1
                else:
                    print('err %d %d',i,j)
                    answer = 0
        print(answer)
        # walking(matrix)
