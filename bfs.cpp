#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;




void bfs(map<char,vector<char>>&graph,char src){

    set<char>visited;
    queue<char>queue;

    visited.insert(src);
    queue.push(src);

    while(!queue.empty()){

        char currentnode=queue.front();
        queue.pop();
        cout<<currentnode<<"  ";

        for(char neigbhour:graph[currentnode]){
            if(visited.find(neigbhour)==visited.end()){
                visited.insert(neigbhour);
                queue.push(neigbhour);

            }
        }



    }




}


void dfs(map<char,vector<char>>&graph,set<char>&visited,char src1){

    visited.insert(src1);
    cout<<src1<<"  ";

    for(char neighbhour :graph[src1]){
        if(visited.find(neighbhour)==visited.end()){

            dfs(graph,visited,neighbhour);

        }
    }




}

int main(){



    map<char,vector<char>>graph={


        {'A',{'B','C','E'}},
        {'B',{'E','A'}},
        {'E',{'B','A'}},
        {'C',{'D','A'}},
        {'D',{'C'}},





    };


    char src;

    cout<<"Enter the node you want to start BFS "<<endl;
    cin>>src ;  

    bfs(graph,src);



cout<<"\n";


char src1;

cout<<"Enter the node you want to start DFS"<<endl;

cin>>src1;

set<char>visited;

dfs(graph,visited,src);




}
