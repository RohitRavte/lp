#include<iostream>
#include<limits.h>
using namespace std;
#define v 5


int minkey(int dist[v],bool set[v]){
    int min=INT_MAX;
    int index;

    for(int i=0;i<v;i++){
       if( set[i]==false && dist[i]<min){
        min=dist[i];
        index=i;
       }


    }
    return index;
}

void print(int dist[v]){
    cout<<"vertex \t distance from src"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"----"<<dist[i]<<endl;
    }
}



void dijistra(int graph[v][v],int src){

    int dist[v];
    bool set[v];

    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
        set[i]=false;
    }

    dist[src]=0;

    for(int i=0;i<v;i++){
        int u=minkey(dist,set);
        set[u]=true;

        for(int i=0;i<v;i++){
            if(!set[i]&& graph[u][i]&&dist[u]!=INT_MAX&&dist[u]+graph[u][i]<dist[i]){
                dist[i]=dist[u]+graph[u][i];
            }
        }
    }

print(dist);

}

int main(){

    int graph[v][v];

    cout<<"Enter the  adjancencey matrix"<<endl;

    for(int i =0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>graph[i][j];
        }
    }


cout<<"enter the src node"<<endl;

int src;
cin>>src;

dijistra(graph,src);


}