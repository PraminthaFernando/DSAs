#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    srand(time(0));
    int a;
    cout << "Enter a number: ";
    cin >> a;
    vector<int> arr;
    float median;

    for(int i=0; i<a; i++){
        int num;
        cout << "Enter a element: ";
        cin >> num;
        arr.push_back(num);
        int index = (i+1)/2;
        for(int j=i-1; j>=0; j--){
            if(arr[j] > num && j>=0){
                arr[j+1] = arr[j];
                arr[j] = num;
            }
        }
        if ((i+1) % 2 == 1){
            median = arr[index];
            cout << median << "\n";
        }
        else{
            median = (arr[index] + arr[index-1])/2.0;
            cout << median << "\n";
        }
    }

    return 0;
}
