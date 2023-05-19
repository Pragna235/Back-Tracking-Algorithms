//Enable the comments to understand the tracing

#include<iostream>
using namespace std;
#define N 5
//global variables
int n, x[100] = {0};
int g[N][N] = {{0,1,0,1,0},
               {1,0,1,1,1},
               {0,1,0,0,1},
               {1,1,0,0,1},
               {0,1,1,1,0}};
//Function to print array
printArray(int arr[])
{
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//Function to find the next k value
void NextValue(int k)
{
    while (true)
    {
        //cout<<"k in NextValue Function = "<<k<<endl;
        x[k] = (x[k] + 1)% N; //we are including the particular node as it is.

        //cout<<"x[k] after updation in NextValue = "<<x[k]<<endl;
        if(x[k]==0) //if node not included, hamiltonian cycle is not formed
            return;


        if((g[x[k-1]][x[k]]) != 0) //checking for edge between the k node and it's previous node i.e., k-1
        {
            //cout<<"In Second if in NextValue!"<<endl;
            for(int j=0;j<k;j++)
            {
                //cout<<"In For Loop in NextValue "<<endl;
                //cout<<"x[j] = "<<x[j]<<" x[k] = "<<x[k]<<endl;
                if(x[j] == x[k]) //there should not be same node twice
                    break;

                //cout<<"j+1 = "<<j+1<<" k = "<<k<<endl;
                if((j+1) == k) //to get the order of the hamiltonian cycle
                {
                    //cout<< " In Fourth if in NextValue = "<<endl;
                    if((k< (N-1)) || ((k==(N-1)) && (g[x[N-1]][x[0]] )!= 0)) //if all nodes are still not covered or checking if the last row first column of the graph is not a zero
                        return;
                }
            }
        }
    }
}

//Function to find the hamiltonian path
void Hamiltonian(int k)
{
    while (true)
    {
        //cout<<"k in Hamiltonian Function = "<<k<<endl;
        NextValue(k);

        //cout<<"x[k] in Hamiltonian = "<<x[k]<<endl;
        if(x[k]==0) //if the node at index k is not included (it does not form a hamiltonian cycle)
            return;

        //cout<<"k = "<<k<<"N-1 = "<<N-1<<endl;
        if(k==N-1) //if k is the last node included... print the hamiltonian path
        {
            cout<<"Hamiltonian Path : ";
            printArray(x);
            cout<<endl<<endl;
        }


        else //if every node is not included, then get the next node value of the hamiltonian path
            Hamiltonian(k+1);
    }
}


int main()
{

    cout<<"Initial Hamiltonian Path x : ";
    printArray(x);
    cout<<endl;

    cout<<endl<<"Entered Adjacency Matrix of the graph is = "<<endl;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    Hamiltonian(1); //We are backtracking so, we are checking if the given node and it's previous node has an edge or not. So we passed 1 to check the edge between 1 and 0 - that means it is not forming a cycle



    return 0;
}
