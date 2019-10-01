#include<bits/stdc++.h>
#define ll long long
using namespace std;
int parti(int a[],int low,int high)
{
    int i,t,pivot,index,t1;
    pivot=a[low];
    index=low;
    for(i=low+1;i<=high;i++)
    {
        if(a[i]<=pivot)
        {
            index=index+1;
            t=a[index];
            a[index]=a[i];
            a[i]=t;

        }
    }
    t1=a[index];
    a[index]=a[low];
    a[low]=t1;
    return index;


}
void quicks(int a[],int low,int high)
{
    int q;
    if(low<=high)
    {
       q=parti(a,low,high);
       quicks(a,low,q-1);
       quicks(a,q+1,high);
    }
}
int main()
{
    int a[100];
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicks(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }




    return 0;
}
