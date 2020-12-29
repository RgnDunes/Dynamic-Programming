/*
PROBLEM STATEMENT : 
    Given an array arr and a number sum1. Print the total number of subsets possible when elements of array arr are assigned either a positive sign or a negative sign and sum of this subset equals given sum (sum1).

    Example : 
    arr[] = {1, 1, 2, 3}
    sum1 = 1 
    Output : 3
    Explanation : sum({+1, -1, -2, +3}), sum({-1, +1, -2, +3}), sum({+1, +1, +2, -3}) == 1
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
    int wt[n], val[n], W, tot_sum=0, sum1;
    cout<<"Enter array elements : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>wt[i];
        tot_sum+=wt[i];
    }
    cout<<"Enter the sum : ";
    cin>>sum1;
    W=(tot_sum+sum1)/2;
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
    int total_subset = subset_sum(wt, W, n);
    cout<<"Total subsets with sum "<<sum1<<" is : "<<total_subset<<endl;
    return 0;
}