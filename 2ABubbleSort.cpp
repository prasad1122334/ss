#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void bubbleSort(int *,int );
void swap(int &,int &);

void bubbleSort(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        int first=i%2;
        #pragma parallel for
        for(int j=first;j<n-1;j+=2)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
};

void swap(int &a,int &b)
{
    int test;
    test=a;
    a=b;
    b=test;
};

int main()
{
    int *a,n;
    cout<<"Enter No of Elements: ";
    cin>>n;
    a=new int[n];
    cout<<"Enter elements in array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubbleSort(a,n);

    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;

}

