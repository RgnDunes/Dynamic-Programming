/*
PROBLEM STATEMENT : 
    Given an array arr and sum1 . Count total subsets of array arr with sum equals given sum (sum1).

    Example : 
    arr[] = {2, 3, 5, 6, 8 ,10}
    sum1 = 10
    Output : 3
    Explanation : {2,8} {5, 2, 3} {10}
*/

#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int subset_sum(int wt[], int W, int n)
{
    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j=1 ; j<W+1 ; j++)
        {
            if(j>=wt[i-1])
            {
                dp[i][j] = (dp[i-1][j-wt[i-1]] + dp[i-1][j]);
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
    int wt[n], val[n], W, tot_sum=0;
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
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }
    int tot_subsets = subset_sum(wt, W, n);
    
    cout<<"Total subsets with sum = "<<W<<" are : "<<tot_subsets<<endl;
    return 0;
}