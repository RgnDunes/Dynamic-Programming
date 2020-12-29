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
    return 0;
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
    vector <int> subset1;
    W=tot_sum;
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
    subset_sum(wt, W, n);
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<(W/2)+1 ; j++)
        {
            if(dp[i][j])
                subset1.push_back(j);
        }
    }        
    int final_subset1_sum=*max_element(subset1.begin(),subset1.end());
    cout<<"Minimum Difference : "<<(tot_sum-(2*final_subset1_sum))<<endl;
    return 0;
}