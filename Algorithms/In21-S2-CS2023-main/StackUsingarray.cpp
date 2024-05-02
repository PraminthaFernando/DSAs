#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class stack {
    public:
        int tail = 0;
        int temp,top;

    void Stacktop(vector<int> arr){
        if(tail>0){
            top = arr[tail-1];
            cout << top;
        }
        else{
            cout << "no any top element.";
        }
    }
    bool isfull(vector<int> arr){
        if(tail == arr.size()){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(tail == 0){
            return true;
        }
        return false;
    }
    void push(vector<int> &arr, int element){
        if(isfull(arr)){
            cout << "Stack overflow." << "\n";
        }
        else{
            tail++;
            arr[tail-1] = element;
        }

    }
    int pop(vector<int> &arr){
        if(!isEmpty()){
            temp = arr[tail-1];
            arr[tail-1] = 0;
            tail--;
            return temp;
        }
        else{
            cout << "stack underflow" << "\n";
        }
        return temp;
    }
    void Display(vector<int> arr){
        for(int i: arr){
            cout << i << " ";
        }
        cout << "\n";
    }
};
int main(int argc, char const *argv[])
{
    vector<int> arr(12);
    stack a;
    auto start = high_resolution_clock::now();

{   a.push(arr,8);
    a.push(arr,10);
    a.push(arr,5);
    a.push(arr,11);
    a.push(arr,15);
    a.push(arr,23);
    a.push(arr,6);
    a.push(arr,18);
    a.push(arr,20);
    a.push(arr,17);
    a.Display(arr);
    int num1 = a.pop(arr);
    int num2 = a.pop(arr);
    int num3 = a.pop(arr);
    int num4 = a.pop(arr);
    int num5 = a.pop(arr);
    a.Display(arr);
    a.push(arr,4);
    a.push(arr,30);
    a.push(arr,3);
    a.push(arr,1);
    a.Display(arr);}
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Elapsed time: " << duration.count() / 1000000.0 << " seconds (" << duration.count() << " microseconds)" << endl;
    
    return 0;
}
