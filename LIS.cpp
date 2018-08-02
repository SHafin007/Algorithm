#include <bits/stdc++.h>

using namespace std;

const int NX = 1e5 + 10;

int input[ NX ] , dp[ NX ], n;


void Input()
{
    cin >> n ;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> input[i];
        dp[i] = 1;
    }
}


void LIS()
{
    int ans = 0;
    for( int i = 0 ; i < n ; i++ )
    {
        ans = max( ans , dp[i] );
        for( int j = i + 1 ; j < n ; j++ )
        {
            if( input[j] >= input[i] )
            {
                dp[j] = max( dp[j], dp[i] + 1 );
            }
        }
    }

    cout << " LIS length " << ans << endl;
}


int main()
{
    Input();
    LIS();
}
