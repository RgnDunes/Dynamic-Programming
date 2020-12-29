/*
PROBLEM : 
    Given one array coin[] and a sum sum1. Calculate the total
    number of ways to produce a sum of sum1 using the coins 
    given in the coin array. Provided that we have infinite 
    number of coins of each type. 

EXAMPLE : 
    coin[] ={1, 2, 3}
    sum1 = 5
OUTPUT : 
    5
EXPLANATION :
    {2,3} {1,2,2} {1,1,3} {1,1,1,1,1} {1,1,1,2}
*/

#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int unbounded_knapsack(int coin[], int W, int N)
{
    for(int i=1 ; i<N+1 ; i++)
    {
        for(int j=1 ; j<W+1 ; j++)
        {
            if(j>=coin[i-1])
            {
                dp[i][j] = (dp[i][j-coin[i-1]]+ dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}
int main()
{
    int N;
    cout<<"Length of Coin array : ";
    cin>>N;
    int coin[N], W;
    cout<<"Enter elements of coin array : ";
    for(int i=0 ; i<N; i++)
    {
        cin>>coin[i];
    }
    cout<<"Enter the sum required : ";
    cin>>W;
    memset(dp,-1,sizeof(dp));
    for(int i=0 ; i<N+1 ; i++)
    {
        for(int j=0 ; j<W+1 ; j++)
        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }
    int maxWays = unbounded_knapsack(coin, W, N);
    cout<<"Max number of ways are : "<<maxWays<<endl;
    return 0;
}