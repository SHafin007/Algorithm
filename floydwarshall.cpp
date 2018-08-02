


#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 100;
const int INF = 1e9;

int node , edge , cost[ MAX_NODE ][ MAX_NODE ];



void ini()
{
     for( int i = 1 ; i <= node ; i++ )
    {
        for( int j = 1 ; j <= node ; j++ )
        {
            cost[i][j] = INF;
        }
        cost[i][i] = 0;
    }
}

void constructGraph()
{

    cin >> node >> edge;
    ini();
    int x , y, c;
    for( int i = 0 ; i < edge ; i++ )
    {
       cin >> x >> y >> c;
       cost[x][y] = cost[y][x] = min(cost[x][y], c );
    }


}

void floydwarshall(int source)
{

     for( int k = 1 ; k <= node ; k++ )
     {
         for( int i = 1 ; i <= node ; i++ )
         {
             for( int j = 1 ; j <= node ; j++ )
             {
                 cost[i][j] = min( cost[i][j], cost[i][k] + cost[k][j] );
             }
         }
     }

     for( int i = 1 ; i <= node ; i++ )
     {
         printf("source :: %d to :: %d dis :: %d\n",source, i , cost[source][i] );
     }



}





int main()
{
    constructGraph();
    floydwarshall(1);

    return 0;
}

/*
9 9
1 2 5
2 3 10
2 4 8
4 5 7
4 6 10
4 8 11
8 7 20
6 7 1
7 9 5


*/


