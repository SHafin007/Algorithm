#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;

vector <int> graph[ MAX_NODE ];
int edge, node, cost[ MAX_NODE ], visit[ MAX_NODE ], parent[ MAX_NODE ];
int costBetweenNodes[ MAX_NODE ][ MAX_NODE ];

void ini()
{
     for( int i = 1 ; i <= node ; i++ )
    {
        visit[i] = cost[i] = 0;
        graph[i].clear();
    }
}

void constructGraph()
{

    cin >> node >> edge;
    ini();
    int x , y;
    for( int i = 0 ; i < edge ; i++ )
    {
       cin >> x >> y;
       graph[x].push_back(y);
       graph[y].push_back(x);
    }


}


void bfs(int source)
{
    queue < int > q;
    q.push(source);
    cost[source] = 0;
    visit[source] = 1;
    while( !q.empty() )
    {
        int current = q.front();
        q.pop();
        int sz = graph[current].size();
        for( int i = 0 ; i < sz ; i++ )
        {
            int nxt = graph[current][i];
            if( visit[nxt] == 0 )
            {
                visit[nxt] = 1;
                parent[ nxt ] = current;
                cost[nxt] = cost[current] + 1;
                q.push(nxt);
            }
        }
    }

    for( int i = 1 ; i <= node ; i++ )
    {
        printf("from %d to %d:: minimum cost:: %d\n", source , i , cost[i] );
    }


}
/*
void bfsZerroOne(int source)
{
    deque < int > q;
    q.push_front(source);
    cost[source] = 0;
    visit[source] = 1;
    while( !q.empty() )
    {
        int current = q.front();
        q.pop();
        int sz = graph[current].size();
        for( int i = 0 ; i < sz ; i++ )
        {
            int nxt = graph[current][i];
            if( visit[nxt] == 0 )
            {
                visit[nxt] = 1;
                parent[ nxt ] = current;
                cost[nxt] = cost[current] + costBetweenNodes[current][nxt];
                if( costBetweenNodes[current][nxt] == 0 )
                {
                    q.push_front(nxt);
                }
                else
                {
                    q.push_back(nxt);
                }
            }
        }
    }

    for( int i = 1 ; i <= node ; i++ )
    {
        printf("from %d to %d:: minimum cost:: %d\n", source , i , cost[i] );
    }


}
*/
void print_road( int current_node, int source_node )
{
    if( current_node == source_node )
    {
        printf("%d", current_node );
        return;
    }
    print_road( parent[current_node] , source_node );
    printf(" - %d",current_node);
}

int main()
{
    constructGraph();
    bfs(1);
    print_road(9 , 1);

    return 0;
}

/*
9 9
1 2
2 3
2 4
4 5
4 6
4 8
8 7
6 7
7 9


*/


