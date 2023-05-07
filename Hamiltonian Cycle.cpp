#include<iostream>
using namespace std;
#define N 5
int n, x[100] = {0};
int g[N][N] = {{0,1,0,1,0},
               {1,0,1,1,1},
               {0,1,0,0,1},
               {1,1,0,0,1},
               {0,1,1,1,0}};

printArray(int arr[])
{
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void NextValue(int k)
{
    while (true)
    {
        //cout<<"k in NextValue Function = "<<k<<endl;
        x[k] = (x[k] + 1)% N;

        //cout<<"x[k] after updation in NextValue = "<<x[k]<<endl;
        if(x[k]==0)
            return;


        if((g[x[k-1]][x[k]]) != 0)
        {
            //cout<<"In Second if in NextValue!"<<endl;
            for(int j=0;j<k;j++)
            {
                //cout<<"In For Loop in NextValue "<<endl;
                //cout<<"x[j] = "<<x[j]<<" x[k] = "<<x[k]<<endl;
                if(x[j] == x[k])
                    break;

                //cout<<"j+1 = "<<j+1<<" k = "<<k<<endl;
                if((j+1) == k)
                {
                    //cout<< " In Fourth if in NextValue = "<<endl;
                    if((k< (N-1)) || ((k==(N-1)) && (g[x[N-1]][x[0]] )!= 0))
                        return;
                }
            }
        }
    }
}

void Hamiltonian(int k)
{
    while (true)
    {
        //cout<<"k in Hamiltonian Function = "<<k<<endl;
        NextValue(k);

        //cout<<"x[k] in Hamiltonian = "<<x[k]<<endl;
        if(x[k]==0)
            return;

        //cout<<"k = "<<k<<"N-1 = "<<N-1<<endl;
        if(k==N-1)
        {
            cout<<"Hamiltonian Path : ";
            printArray(x);
            cout<<endl<<endl;
        }


        else
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

    Hamiltonian(1);



    return 0;
}
