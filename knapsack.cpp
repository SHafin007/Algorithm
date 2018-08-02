#include <bits/stdc++.h>

using namespace std;

const int itemMX = 105;
const int weightMX = 1005;

int dp[ itemMX ][ weightMX ];
int weight[ itemMX ], value[ itemMX ];
int numberOfItem, bagWeight;

void input()
{
    cin >> numberOfItem;
    for( int i = 1 ; i <= numberOfItem; i++ )
    {
        cin >> weight[i] >> value[i];
    }

    cin >> bagWeight;
}

void knapsack()
{
    for( int i = 1 ; i <= numberOfItem ; i++ )
    {
        for( int j = 0 ; j <= bagWeight; j++ )
        {
            if( weight[i] <= j )
            {
                dp[i][j] = max( dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("Maximum value :: %d\n", dp[numberOfItem][bagWeight]);
}

int main()
{
    input();
    knapsack();
}


