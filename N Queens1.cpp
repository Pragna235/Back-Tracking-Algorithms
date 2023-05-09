
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int* x;
int n;

bool Place(int row,int col){
    for(int j = 0;j < row;j++){
        if((x[j] == col) || (abs(x[j] - col) == abs(j -row)))
            return false;
    }
    return true;
}

void print(){
    static int i = 1;
    if(i == 1) cout <<"----------Printing Solutions---------"<<endl;
    cout<<"Solution "<<i++<<" : [";
    for(int i = 0;i < n;i++)
        cout<<x[i]<<" ";
    cout<<"\b]"<<endl;
}

void NQueens(int row){
    for(int i = 0;i < n;i++){
        if(Place(row,i)){
            x[row] = i;
            if(row == n-1)
                print();
            else NQueens(row+1);
        }
    }
}

int main()
{
    cout << "Enter size of board : ";
    cin >> n;
    x = (int*)calloc(n,sizeof(int));
    NQueens(0);

 return 0;
}
