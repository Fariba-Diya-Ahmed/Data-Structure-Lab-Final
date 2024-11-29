/*
Write a C/C++ program to implement a binary search on an unsorted array using the recursive method.
The program should first sort the array using the Insertion Sort algorithm before performing the binary search.

The program must handle the following edge cases gracefully:

Empty Array: If the user provides an array of size 0, the program should display an error message and exit.

Unsorted Input: The array must be sorted before performing the binary search.

Key Not Found: If the key is not found in the array, the program should correctly report that the element is absent.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define N 10
int a[N];

int BS(int a[],int left,int right,int value)
{
    while(left <= right)
    {
        int mid = (left + right )/2 ;

        if(a[mid]==value) return mid;
        else if (a[mid]<value)
            return BS(a,mid+1,right,value);
        else
        return BS(a,left,mid-1,value);

    }
    return -1;
}
int main()
{
    int i,j,n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    if(n<=0 || n>N)
    {
        cout<<"Error size\n";
        return 0;
    }

    // int a[n];
    cout<<"Enter "<<n<<" elements of the array: ";
    for(i=0; i<n; i++) cin>>a[i];

    // insertion sort

    for(i=1; i<n; i++)
    {
        int temp = a[i];
        j= i-1;

        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp ;
    }

    cout<<"Sorted array: ";
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;

    int value;
    cout<<"Enter the element to search: ";
    cin>>value;

    int index = BS(a,0,n-1,value);

    if(index == -1) cout<<"Element is absent!\n";
    else  cout<<"Element "<<value<<" found at index "<<index<<endl;
}

