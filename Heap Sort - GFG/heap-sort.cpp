//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    //Function to build a Heap from array.
    public:
    void buildHeap(int arr[], int n)
    {
        //code
        for(int i = n/2 -1; i>=0; i--)
            heapify(arr, n, i);
    }
 
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        //code
        int largest = i;
        int l = 2*i +1; int r = 2*i+ 2;
        
        if( l < n && arr[l] > arr[largest] ){
            largest = l;
        }
        if( r < n && arr[r] > arr[largest] ){
            largest = r;
        }
        if( largest != i){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            
            heapify(arr, n, largest );
        }
    }
    
    //Function to sort an array using Heap Sort.
    public:
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr, n);
        for( int i = n-1; i>0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
            heapify(arr, i, 0);
        }
    }
 };



//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends