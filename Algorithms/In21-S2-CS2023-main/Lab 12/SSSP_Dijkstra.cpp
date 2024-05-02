#include <iostream>
#include <list>
#include <vector>

 
using namespace std;

//find the city that has minimum distance among unvisited cities
int Minvertex(vector<int> arr1, vector<bool> arr2){

    int Min = INT_MAX,index;
    for(int i=0; i<arr1.size(); i++){
        if(!arr2[i]){
            Min = min(Min,arr1[i]);
            if(Min == arr1[i]){
                index = i;
            }
        }
    }
    return index;
}

int main()
{
    //create a adjecency matrix for graph
    int adj[6][6] = {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };

    //take input for source node
    int Src;
    cout << "Enter source city: ";
    cin >> Src;

    vector<int> distance(6,INT_MAX);
    distance[Src] = 0;
    vector<bool> visited(6);

    //SSSP-Dijkstra algorithm
    while(!visited[Src]){
        int dis = distance[Src];
        for(int i=0; i<6; i++){
            if(!visited[i]){
                if(adj[Src][i] !=0 && distance[i]>adj[Src][i] + dis){
                    distance[i] = adj[Src][i] + dis;
                }
            }
        }
        visited[Src] = true;
        Src = Minvertex(distance,visited);
    }

    //print the average time taken for each city from the source
    cout << "Average time taken from source city, \n";
    int i=0;
    for(int num : distance){
        cout <<"to city " << i << ": " << num << "\n";
        i++;
    }

}
