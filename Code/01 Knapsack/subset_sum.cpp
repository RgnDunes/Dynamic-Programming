/*
PROBLEM STATEMENT : 
    Given an array arr and a sum1 . Tell whether there is a subset of array 
    arr whose sum equals the given sum (sum1).

    Example : 
    arr[] = {2, 3, 7, 8, 10}
    sum1 = 11
    Output : Yes
    Explanation : sum({3, 8})=11
*/

#include<bits/stdc++.h>
using namespace std;
bool dp[102][1002];
int subset_sum(int wt[], int W, int n)
{
    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j=1 ; j<W+1 ; j++)
        {
            if(j>=wt[i-1])
            {
                dp[i][j] = (dp[i-1][j-wt[i-1]] || dp[i-1][j]);
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
    cout<<"Enter array elements : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter the sum : ";
    cin>>W;
    memset(dp,-1,sizeof(dp));
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<W+1 ; j++)
        {
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
        }
    }
    int possible = subset_sum(wt, W, n);
    if(possible)
        cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}