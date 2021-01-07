/*
PROBLEM : 
    Given two strings X. Print the length of the longest 
    repeating subsequence in string X.

EXAMPLE : 
    X : "aabebcdd"
OUTPUT : 3
EXPLANATION : "abd"
*/

#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int lcs(string X, string Y, int m, int n)
{
    for(int i=1 ; i<m+1 ; i++)
    {
        for(int j=1 ; j<n+1 ; j++)
        {
            if(X[i-1]==Y[j-1] && i!=j )
                dp[i][j] = (1+dp[i-1][j-1]);
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    cout<<"Enter first string (X) : ";
    string X, Y;
    cin>>X;
    Y = X;
    memset(dp,0,sizeof(dp));
    for(int i=0 ; i<X.length()+1 ; i++)
    {
        for(int j=0 ; j<Y.length()+1 ; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    int lcsLength=0;
    lcsLength=lcs(X, Y, X.length(), Y.length());
    cout<<"Length of Longest Repeating Subsequence is : "<<lcsLength<<endl;
    return 0;
}