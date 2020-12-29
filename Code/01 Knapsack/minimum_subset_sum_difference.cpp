/*
PROBLEM STATEMENT : 
    Given an array arr . Print the minimum difference between
    the two partition subset of the given array.

    Example : 
    arr[] = {1, 6, 11, 5}
    Output : 1
    Explanation : sum({5,6})-sum({1,11})=1
*/

#include<bits/stdc++.h>
using namespace std;
bool dp[102][1002];
bool subset_sum(int wt[], int W, int n)
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
    int wt[n], val[n], tot_sum=0;
    cout<<"Enter array elements : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>wt[i];
        tot_sum+=wt[i];
    }
    vector <int> subset1;
    for(int W=0 ; W<=tot_sum/2 ; W++)
    {
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
            subset1.push_back(W);
    }
    int final_subset1_sum=*max_element(subset1.begin(),subset1.end());
    cout<<"Minimum Difference : "<<(tot_sum-(2*final_subset1_sum))<<endl;
    return 0;
}