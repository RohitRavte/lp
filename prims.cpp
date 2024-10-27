#include<iostream>
#include<limits.h>
using namespace std;

int minkey(int key[100],bool mstset[100],int n){

    int min=INT_MAX;
    int index;
    for(int i=0;i<n;i++){
        if (mstset[i]==false&& key[i]<min){
            min=key[i];
            index=i;
        }
    }
    return index;
}





void print(int parent[100],int graph[100][100],int n){

    cout<<"edges --- wieght\n";
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-----"<<i<<"-----"<<graph[i][parent[i]]<<endl;
    }


}
void prims(int graph[100][100],int n){
    int parent[100];
    int key[100];
    bool mstset[100];

    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mstset[i]=false;
    }

    parent[0]=-1;
    key[0]=1;

    for(int i=0;i<n;i++){
        int u=minkey(key,mstset,n);

        mstset[u]=true;

        for(int i=0;i<n;i++){
            if(graph[u][i]&&mstset[i]==false&&graph[u][i]<key[i]){
                key[i]=graph[u][i];
                parent[i]=u;

            }
        }


    }

    print(parent,graph,n);



}

int main(){


   int  graph[100][100];

   cout<<"Enter number of nodes"<<endl;
   int  n;
   cin>>n;
   cout<<endl;
   cout<<"enter the adjancency matrix"<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

        cin>>graph[i][j];
    }
   }

   prims(graph,n);
   

}