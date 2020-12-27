#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int knapsack(int wt[], int val[], int W, int n)
{
    if(n==0 || W==0) 
        return 0;
    if(dp[n][W]!=-1)
        return dp[n][W];
    if(W>=wt[n-1])
    {
        dp[n][W] = max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
        return dp[n][W];
    }
    else
    {
        dp[n][W] = knapsack(wt, val, W, n-1);
        return dp[n][W];
    }
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
    int maxProfit = knapsack(wt, val, W, n);
    cout<<"Max Profit is : "<<maxProfit<<endl;
    return 0;
}