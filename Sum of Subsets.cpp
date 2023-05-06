#include<iostream>
#include<algorithm>
using namespace std;

int n,m,w[100],res[100]={0};

void printArray(int arr[],int n)
{
   for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

void SumofSubsets(int s, int k, int r)
{
    res[k]=1;

    if(s+w[k]==m)
    {
        //cout<<"Final Result = "<<endl;
        printArray(res,k+1);
    }
    else if(s+w[k]+w[k+1] <= m)
        SumofSubsets(s+w[k], k+1, r-w[k]);

    if(((s+r-w[k])>=m) && ((s+w[k+1])<=m) )
    {
        res[k]=0;
        SumofSubsets(s,k+1,r-w[k]);
    }
}

int main()
{
    int sum=0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>n;


    cout<<"Enter the weight required weight of subsets : "<<endl;
    cin>>m;

    cout<<"Enter the elements one by one : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"w["<<i<<"] = ";
        cin>>w[i];
        sum=sum+w[i];
    }
    cout<<endl;

    cout<<"Entered elements are : "<<endl;
    printArray(w,n);

    sort(w,w+n);
    cout<<"Elements after sorting are : "<<endl;
    printArray(w,n);

    cout<<"Total Weight of the array : "<<sum<<endl;

    SumofSubsets(0,0,sum);


    return 0;
}
