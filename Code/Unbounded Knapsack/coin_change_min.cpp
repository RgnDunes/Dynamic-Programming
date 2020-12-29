/*
PROBLEM : 
    Given one array coin[] and a sum sum1. Calculate the 
    minimum number of coins required to produce a sum of 
    sum1 using the coins given in the coin array. 
    Provided that we have infinite number of coins of each type. 

EXAMPLE : 
    coin[] ={1, 2, 3}
    sum1 = 5
OUTPUT : 
    2
EXPLANATION :
    {2,3} {1,2,2} {1,1,3} {1,1,1,1,1} {1,1,1,2}
    Minimum no of coins are used in 1st way i.e., {2,3} i.e., 2
*/

#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int unbounded_knapsack(int coin[], int W, int N)
{
    for(int i=2 ; i<N+1 ; i++)
    {
        for(int j=1 ; j<W+1 ; j++)
        {
            if(j>=coin[i-1])
            {
                dp[i][j] = min(dp[i][j-coin[i-1]]+1, dp[i-1][j]);
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
            if(j==0)
                dp[i][j]=0;
            if(i==0)
                dp[i][j]=INT_MAX-1;
            if(i==1 && j>0)
            {
                if(j%coin[0]==0)
                    dp[i][j]=j/coin[0];
                else
                    dp[i][j]=INT_MAX-1;
            }
        }
    }
    int minCoins = unbounded_knapsack(coin, W, N);
    cout<<"Min number of coins required are : "<<minCoins<<endl;
    return 0;
}