#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct Node {
    //create new nodes
    public:
        int value;
        Node *next;  
};

class list {
    private:
        Node *Head,*top;
        
    public:
        list(){
            Head = NULL;
        }
    bool isEmpty(){
        //ckeck stack is empty or not before the poping
        if(Head == NULL){
            return true;
        }
        return false;
    }

    void push(int element){
        //add new element to the stack
        Node *node = new Node;
        node->value = element;
        node->next = Head;
        Head = node;
    }
    
    void pop(){
        //remove the last element in satck
        if(isEmpty()){
            cout << "stack underflow" << endl;
        }
        else{
            int temp = Head->value;
            Head = Head->next;
        }    
    }

    void Display(){
        //Display stack element
        top = Head;
        vector<int> arr;

        while(top != NULL){
            arr.push_back(top->value);
            top = top->next;
        }
        
        for(int i=arr.size()-1; i>=0; i--){     //print array element input arrangement
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
};
int main(int argc, char const *argv[])
{

    list l;
    auto start = high_resolution_clock::now();

{   l.push(8);
    l.push(10);
    l.push(5);
    l.push(11);
    l.push(15);
    l.push(23);
    l.push(6);
    l.push(18);
    l.push(20);
    l.push(17);
    l.Display();
    l.pop();
    l.pop();
    l.pop();
    l.pop();
    l.pop();
    l.Display();
    l.push(4);
    l.push(30);
    l.push(3);
    l.push(1);
    l.Display();
}
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Elapsed time: " << duration.count() / 1000000.0 << " seconds (" << duration.count() << " microseconds)" << endl;
    return 0;
}
