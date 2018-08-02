#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

const int max_node=1000;

vector<int>graph[max_node];
int articulationPoint[max_node],vis[max_node],low[max_node];

int node,edges,discover[max_node],discover_time,child;

string x,y;


void ini(int node){
for(int i=0;i<=node;i++){
    graph[i].clear();
    articulationPoint[i]=0;
    vis[i]=0;
}

}


void dfs(int node,int parent){
vis[node]=1;
discover[node]=low[node]=++discover_time;
int sz=graph[node].size();
child=0;
for(int i=0;i<sz;i++){
    int next_node=graph[node][i];
    if(parent == next_node)
        continue;
    if(vis[next_node]==0){
        child++;
        dfs(next_node,node);
        //not root
        if(parent!=-1&&discover[node]<=low[next_node]){
            articulationPoint [node]=1;
        }
    }
    low[node]=min(low[node],low[next_node]);
}
// root node
if(parent ==-1 && child>=2){
    articulationPoint[node]=-1;
}

}

main(){

cin>>node>>edges;
ini(node);

for(int i=0;i<edges;i++){

    cin>>x>>y;
    graph[x[0]-'A'].push_back(y[0]-'A');
    graph[y[0]-'A'].push_back(x[0]-'A');
}
//ini(node);

dfs(0,-1);
 printf("Ariculation Points of that graph :: ");
for(int i=0;i<node;i++){
    if(articulationPoint[i]==1){
         printf(" %c", i + 'A' );
    }
}

}





/*
8 9
A B
A C
B C
C D
D E
E F
F G
G E
F H
*/
