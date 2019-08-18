#include<stdio.h>
void insertion(int a[],int n);
void bubble(int a[],int n);
void selection(int a[],int n);
void display(int a[],int n);
int parti(int a[],int low,int high);
void quicks(int a[],int low,int high);




int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble(a,n);
    printf("Bubble-sort\n");
    display(a,n);
    printf("\n");
    selection(a,n);
    printf("Selection-sort\n");
    display(a,n);
    printf("\n");
    insertion(a,n);
    printf("Insertion-sort\n");
    display(a,n);
    printf("\n");
    quicks(a,0,n);
    printf("Quick-sort\n");
    display(a,n);

    return 0;
}
void insertion(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0 && a[j]>t)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
}
void bubble(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selection(int a[],int n)
{
    int i,j,mindex,temp;
    for(i=0;i<n-1;i++)
    {
        mindex=i;
      for(j=i+1;j<n;j++)
      {
          if(a[j]<a[mindex])
          {
              mindex=j;
          }
      }
      if(i!=mindex)
      {
          temp=a[i];
          a[i]=a[mindex];
          a[mindex]=temp;

      }

    }
}
int parti(int a[],int low,int high)
{
    int i,t,pivot,index,t1;
    pivot=a[low];
    index=low;
    for(i=low+1;i<high;i++)
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

    if(low<high)
    {
       int q=parti(a,low,high);
       quicks(a,low,q-1);
       quicks(a,q+1,high);
    }
}




void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}
