#include <iostream>
using namespace std;

int **a, n, cost = 0,start;
bool *visited;

void TSP(int s){

    //cout<<"s = "<<s<<endl;

    int k, adj = 999, min = 999;
    //cout<<"k = "<<k<<" adj = "<<adj<<" min = "<<min<<endl<<endl;

    visited[s] = true;
    cout << s+1 <<" ";

    for(k = 0;k < n;k++){
        //cout<<"k in for loop = "<<k<<endl<<endl;

        if((a[s][k] != 0) && (!visited[k])){
            if(a[s][k] < min){
                min = a[s][k];
                //cout<<"min in if of for loop = "<<min<<endl<<endl;

                adj = k;
                //cout<<"adj in if of for loop = "<<adj<<endl<<endl;
            }
        }
    }
    cout<<endl;

    if(min != 999)
        {
            cost += min;
            //cout<<"cost if min!=999 is : "<<cost<<endl;
        }
    //cout<<endl;

    if(adj == 999){
        //cout<<"if adj == 999"<<endl;

        adj = 0;
        cout << start + 1 << " ";
        cost += a[s][start];
        cout << endl << "Cost : " << cost;
        return;
    }

    //cout<<"Next adj to be going into TSP is : "<<endl;
    TSP(adj);
}

int main(){
    int num_nodes;
    cout << "Enter no. of nodes: ";
    cin >> num_nodes;

    n = num_nodes;
    a = new int*[n];
    visited = new bool[n];
    cout << "Enter cost matrix:" << endl;

    for(int i = 0;i < n;i++){
        a[i] = new int[n];
        visited[i] = false;
        for(int j = 0;j < n;j++)
            cin >> a[i][j];
    }
    cout<<endl;

    cout<<"Path should start with index : ";
    cin>>start;
    cout<<endl;

    TSP(start);
    return 0;
}
