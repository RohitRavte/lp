#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



class DSU{

    vector<int>parent,rank;

    public:
    DSU(int n){

        parent.resize(n,-1);
        rank.resize(n,1);

    }
        int find(int x){
            if(parent[x]==-1)
            return x;
            return parent[x]=find(parent[x]);

        }
  

        void unite(int x , int y){
            int root1=find(x);
            int root2=find(y);
            if(root1!=root2){
                if(rank[root1]!=rank[root2]){
                    parent[root1]=root2;
                }
                else if(rank[root1]>rank[root2]){
                    parent[root2]=root1;
                }
                else{
                    parent[root2]=root1;
                    rank[root1]++;
                }
            }
        }


    





};



class Graph{
    vector<vector<int>>edges;

    public:

    void addedge(int u , int v, int w){
        edges.push_back({w,u,v});
    }

    void kruskal(int v){
        sort(edges.begin(),edges.end());
        DSU dsu(v);
        int total=0;


        for(auto&e:edges){
            int w=e[0];
            int u=e[1];
            int v=e[2];
            if(dsu.find(u)!=dsu.find(v)){
                dsu.unite(u,v);
                total+=w;
                cout<<u<<"-----"<<v<<"-----"<<w<<endl;;
            }

        }

cout<<"total weight :"<<total<<endl;
    }




};


int main(){


    int v ,e;

    cout<<"enter the number of nodes and edges"<<endl;
    cin>>v;
    cin>>e;


    Graph g;


    for(int i=0;i<e;i++){
        int u ,v ,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w);

    }

    g.kruskal(v);



}