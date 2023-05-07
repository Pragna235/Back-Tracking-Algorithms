#Enable all the print statements to understand the working (Tracing)


global g,x,n

def Hamiltonian(k):
  #print("k in Hamiltonian Function = ",k)
  #print()
  while True:
    NextValue(k)
    #print("k after NextValue = ",k)
    #print("x[k] = ",x[k])
    #print()
    if (x[k]==0):
      return
    #print("k = ",k,"n-1 = ",n-1)
    #print()
    if (k==n-1):
      print("Final Hamiltonian Path = ",x)
    else:
      #print("Hamiltonian(k+1) : ")
      Hamiltonian(k+1)

def NextValue(k):
  while True:
    #print("k in NextValue Function = ",k)
    #print()
    #print("x[k] = ",x[k],"x[k]+1 = ",x[k]+1)
    #print()
    x[k]=(x[k]+1)%(n)
    #print("x[k] after computation = ",x[k])
    if(x[k]==0):
      return
    #print("g[x[k-1]][x[k]] = ",g[x[k-1]][x[k]])
    #print()
    if g[x[k-1]][x[k]]!=0:
      for j in range(k):
        #print("j in NextValue for loop is = ",j)
        #print("x[j] = ",x[j], "x[k] = ",x[k])
        #print()
        if (x[j]==x[k]):
          break
        #print("j+1 = ",j+1, "k = ",k)
        #print()
        if ((j+1)==k):
          #print("k = ",k,"n-1 = ",n-1, "g[x[n-1]][x[0]] = ",g[x[n-1]][x[0]])
          #print()
          if((k<n-1) or ((k==n-1) and g[x[n-1]][x[0]]!=0)):
            return
            
n=int(input("Enter the number of nodes in the graph : "))
#x is the Result list
x=[]
#g is the adjaceny matrix of the graph
g=[]
#vertex index starts from 0 to n-1
for i in range(n):
  x.append(0)
print("x = ",x)
print()
#Enter the adjacency matrix of the graph in 0s and 1s indicating that an edge is present or not
for i in range(n):
  g.append(list(map(int,input().split())))
print()
print("g = ",g)
print()

Hamiltonian(1)
