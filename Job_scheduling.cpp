#include <bits/stdc++.h>

using namespace std;

const int NX = 100;

struct job
{
    int startTime, endTime , profit;
}input[ NX ];

int n, dp[ NX ];

bool cmp( job A , job B )
{
    if( A.endTime == B.endTime ) return A.startTime < B.startTime ;
    return A.endTime < B.endTime ;
}


void Input()
{
    cin >> n;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> input[i].startTime >> input[i].endTime >> input[i].profit;
    }
    sort( input , input + n , cmp );
    for( int i = 0 ; i < n ; i++ )
    {
        dp[i] = input[i].profit;
    }
}

void Job_scheduling()
{
    int ans = 0;
    for( int j = 0 ; j < n ; j++ )
    {

        for( int i = 0 ; i < j ; i++ )
        {
            if( input[i].endTime <= input[j].startTime )
            {
                dp[j] = max( dp[j] , dp[i] + input[j].profit );
            }
        }
        ans = max( ans , dp[j] );
    }

    cout << "MAXIMUM_Profit " << ans << endl;
}


int main()
{
    Input();
    Job_scheduling();
    return 0;
}
