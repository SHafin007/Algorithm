#include <bits/stdc++.h>
using namespace std;
const int NX = 1005;

vector < int > graph[ NX ], answer;
int inDegree[ NX ], present[ NX ];

void input()
{
    int node , edge ;
    cin >> node >> edge;
    char x[30] , y[30];
    for( int i = 0 ; i < edge ; i++ )
    {
       cin >> x >> y ;
       graph[x[0] - 'A'].push_back( y[0] - 'A');
       inDegree[ y[0] - 'A']++;
       present[ x[0] - 'A'] = present[ y[0] - 'A'] = 1;

    }
}

void topologicalSort()
{
    queue < int > Q;
    for( int i = 0 ; i < 26 ; i++ )
    {
        if( present[ i ] == 1 && inDegree[i] == 0 )
        {
            Q.push(i);
        }
    }
    while( !Q.empty())
    {
        int prevNode = Q.front();
        Q.pop();
        answer.push_back(prevNode);
        int sz = graph[prevNode].size();
        for( int i = 0 ; i < sz ; i++ )
        {
            int nextNode = graph[prevNode][i];
            inDegree[nextNode]--;
            if( inDegree[nextNode] == 0 )
            {
                Q.push(nextNode);
            }
        }
    }

    printf("Topological Order::");
    int sz = answer.size();
    for( int i = 0 ; i < sz ; i++ )
    {
        printf(" %c",answer[i] + 'A');
    }
    printf("\n");
}

int main()
{
    input();
    topologicalSort();
}

/*
8
9
A B
A C
B D
B E
C E
C G
D F
D R
E F



*/
