

#include <bits/stdc++.h>

using namespace std;

const int NX = 100;

int total_ball, ball[ NX ], dp[ NX ], n;



void Input()
{

    cin >> total_ball >> n ;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> ball[i];
    }
    for( int i = 0 ; i <= total_ball ; i++ )
    {
        dp[i] = -1;
    }
}


int MIN_MAX( int now )
{
    if( now == 0 ) return 0;
    if( dp[ now] != -1 ) return dp[now];

    for( int i = 0 ; i < n ; i++ )
    {
        if( now >= ball[i] && MIN_MAX(now - ball[i]) == 0 )
        {
            return dp[now] = 1;
        }
    }
    return dp[now] = 0;
}





int main()
{
    Input();
    if( MIN_MAX(total_ball) == 1 ) printf("Alice will win\n");
    else printf("Alice will lose\n");
}
