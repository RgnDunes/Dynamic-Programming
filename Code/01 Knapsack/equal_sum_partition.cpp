/*
PROBLEM STATEMENT : 
    Given an array arr . Tell whether the given array can be 
    split into two subsets such that their respective sum is equal.

    Example : 
    arr[] = {1, 5, 11, 5}
    Output : Yes
    Explanation : sum({1, 5, 5}) == sum({11})
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
    int wt[n], val[n], W, tot_sum=0;
    cout<<"Enter array elements : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>wt[i];
        tot_sum+=wt[i];
    }
    if(tot_sum%2==0)
    {
        W=int(tot_sum/2);
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
        bool possible = subset_sum(wt, W, n);
        if(possible)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }  
    return 0;
}