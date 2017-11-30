# Python implementation of Kosaraju's algorithm to print all SCCs

from collections import defaultdict

#This class represents a directed graph using adjacency list representation
class Graph:

    def __init__(self,vertices):
        self.V= vertices #No. of vertices
        self.graph = defaultdict(list) # default dictionary to store graph

    # function to add an edge to graph
    def addEdge(self,u,v):
        self.graph[u].append(v)

    # A function used by DFS
    def DFSUtil(self,listA,count,v,visited):
        # Mark the current node as visited and print it
        visited[v]= True
        listA[count].append(v)
        print (str(v))
        #Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[i]==False:
                self.DFSUtil(listA,count,i,visited)


    def fillOrder(self,v,visited, stack):
        # Mark the current node as visited
        visited[v]= True
        #Recur for all the vertices adjacent to this vertex
        for i in self.graph[v]:
            if visited[i]==False:
                self.fillOrder(i, visited, stack)
        stack = stack.append(v)


    # Function that returns reverse (or transpose) of this graph
    def getTranspose(self):
        g = Graph(self.V)

        # Recur for all the vertices adjacent to this vertex
        for i in self.graph:
            for j in self.graph[i]:
                g.addEdge(j,i)
        return g



    # The main function that finds and prints all strongly
    # connected components
    def printSCCs(self):
        listA = []
        stack = []
        # Mark all the vertices as not visited (For first DFS)
        visited =[False]*(self.V)
        # Fill vertices in stack according to their finishing
        # times
        for i in range(self.V):
            if visited[i]==False:
                self.fillOrder(i, visited, stack)

        # Create a reversed graph
        gr = self.getTranspose()

        # Mark all the vertices as not visited (For second DFS)
        visited =[False]*(self.V)

        # Now process all vertices in order defined by Stack
        count = 0
        while stack:
            i = stack.pop()
            if visited[i]==False:
                print(i)
                listA.append([])
                gr.DFSUtil(listA,count,i, visited)
                print("")
                count+=1
        return listA

# Create a graph given in the above diagram
while True:
        case=input()
        n,m=case.strip().split(' ')
        if int(n)==0 & int(m)==0: break
        # matrix = [[0 for x in range(int(n))] for y in range(int(n))]
        # print(matrix)
        g = Graph(int(n))
        for p in range(int(m)):
                getting = input()
                a,b,c= getting.strip().split(' ')
                if(int(c)==2):

                    g.addEdge(int(b)-1,int(a)-1)
                    # matrix[int(b)-1][int(a)-1]=1
                g.addEdge(int(a)-1, int(b)-1)
        print(g.graph)
        listja = g.printSCCs()
        if len(listja)>1:
            print("realans 0")
        else :
            print("realans 1")

# g = Graph(5)
# g.addEdge(1, 0)
# g.addEdge(0, 2)
# g.addEdge(2, 1)
# g.addEdge(0, 3)
# g.addEdge(3, 4)
#
# print ("Following are strongly connected components " +
#                            "in given graph")
# g.printSCCs()
#This code is contributed by Neelam Yadav
