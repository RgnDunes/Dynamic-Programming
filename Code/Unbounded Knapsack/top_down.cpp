#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int knapsack(int wt[], int val[], int W, int n)
{
    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j=1 ; j<W+1 ; j++)
        {
            if(j>=wt[i-1])
            {
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cout<<"No of items : ";
    cin>>n;
    int wt[n], val[n], W;
    cout<<"Enter weight of Items : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter value of Items : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>val[i];
    }
    cout<<"Enter the capacity of knapsack : ";
    cin>>W;
    memset(dp,-1,sizeof(dp));
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<W+1 ; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    int maxProfit = knapsack(wt, val, W, n);
    cout<<"Max Profit is : "<<maxProfit<<endl;
    return 0;
}