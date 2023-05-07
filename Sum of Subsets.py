#Try all the comments to understand the working of the program
#Bakctracking!


global n,m,x,w
def SumofSub(s,k,r):
    x[k]=1
    #print("First x in function = ",x)
    #print()
    if(s+w[k]==m):
        print(x[:k+1])
        #print("s = ",s," w[k] = ",w[k]," m = ",m)
        #print()
    elif ((s+w[k]+w[k+1])<=m):
        #print("In Elif condition")
        #print("s = ",s," w[k] = ",w[k],"w[k+1] = ",w[k+1], "m = ",m)
        #print("s+w[k]+w[k+1] = ",s+w[k]+w[k+1], "m = ",m)
        #print()
        SumofSub(s+w[k],k+1,r-w[k])

    if ( ((s+r-w[k])>=m) and ((s+w[k+1])<=m)):
        
        x[k]=0
        #print("x in Second if is ",x)
        #print("s = ",s," r = ",r," w[k] = ",w[k], "w[k+1] = ",w[k+1])
        #print("s+r-w[k] = ",s+r-w[k],"s+w[k+1] = ",s+w[k+1]," m = ",m)
        #print()
        SumofSub(s,k+1,r-w[k])

# n is number of elements
n=int(input("Enter the nunber of elements : "))
# m is required sum of subset
m=int(input("Enter the weight required by the subsets : "))
# w is weights of n elements
print("Enter the elements in a single line separated by a space : ")
w=list(map(int,input().split()))
w.sort()
# solution vector
x=[]
#Initialize solution vector x[0:n-1]=[0..0]
for i in range(n):
    x.append(0)
#print("x = ",x)
#print()
SumofSub(0,0,sum(w))
