#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;

vector < int > graph[ MAX_NODE ];

int articulationPoint[ MAX_NODE ], visit[ MAX_NODE ], low[ MAX_NODE ];
int discover[ MAX_NODE ], discover_time, node, edge;

void costructGraph()
{
    cin >> node >> edge;

    for( int i = 0 ; i <= node ; i++ )
    {
        graph[i].clear();
        articulationPoint[i] = 0;
        visit[i] = 0;
    }

    for( int i = 0 ; i < edge ; i++ )
    {
        string x , y;
        cin >> x >> y;
        graph[ x[0] - 'A'].push_back( y[0] - 'A' );
        graph[ y[0] - 'A'].push_back( x[0] - 'A' );

    }
}

void dfs(int node, int parent)
{
    visit[node] = 1;
    discover[node] = low[node] = ++discover_time;
    int sz = graph[node].size();
    int child = 0;
    for( int i = 0 ; i < sz ; i++ )
    {
        int nxt_node = graph[node][i];
        if( parent == nxt_node ) continue;
        if( visit[nxt_node] == 0 )
        {
            child++;
            dfs(nxt_node, node);
            // not root
            if( parent != -1 && discover[node] <= low[nxt_node] )
            {
                articulationPoint[node] = 1;
            }

        }
        low[node] = min( low[node] , low[nxt_node]);
    }
    // root node
    if( parent == -1 && child >= 2 ) articulationPoint[node] = 1;
}


int main()
{
    costructGraph();
    dfs(0 , -1 );
    printf("Ariculation Points of that graph :: ");
    for( int i = 0 ; i < node ; i++ )
    {
        if( articulationPoint[i] == 1)
        {
             printf(" %c", i + 'A' );
        }

    }
}

/*
8 9
A B
B C
C D
B E
E F
F G
G H
A C
E G


*/
