#include <iostream>
#include <vector>
using namespace std;

  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int left_child = 2*root + 1;
    int right_child = 2*root +2;

    int Max = arr[left_child];

    if( right_child>n-1 && left_child>n-1 ){return;}

    //get max if root has a right child 
    if(right_child<n){
        Max = max(arr[left_child], arr[right_child]);
    }

    //swap the child value with root
    if(Max > arr[root]){
        if(arr[left_child] == Max){
            arr[left_child] = arr[root];
            arr[root] = Max;
            heapify(arr, n, left_child); //heapify left child of the root
        }
        else{
            arr[right_child] = arr[root];
            arr[root] = Max;
            heapify(arr, n, right_child); //heapify right child of the root
        }
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    if(n == 1){return;}
    // build heap
    int i=(n-2)/2;
    while(i>=0){
        heapify(arr, n, i);
        i--;
    }
  
    // extracting elements from heap one by one
    int temp = arr[0];
    for(int j=0; j<n-1; j++){
        arr[j] = arr[j+1];
    }
    arr[n-1] = temp;
    heapSort(arr, n-1);
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int n;
    cout << "Enter Array size: ";
    cin >> n;

    int heap_arr[n];
    srand(time(0));
    int num;

    for(int i=0; i<n; i++){
        heap_arr[i] = rand() % 200 + 1;
    }
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
    
    heapSort(heap_arr, n);
    
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}