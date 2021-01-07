/*
PROBLEM : 
    Given a strings X. Perform minimum number of deletions to make string pallindrome.

EXAMPLE : 
    X : "agbcba"
OUTPUT : 5
EXPLANATION : Longest Pallindromic Subsequence is "abcba" and it's length is 5.
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
            if(X[i-1]==Y[j-1])
                dp[i][j] = (1+dp[i-1][j-1]);
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    cout<<"Enter string (X) : ";
    string X , Y;
    cin>>X;
    Y = X;
    reverse(Y.begin(), Y.end());
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
    cout<<"Minimum number of deletions : "<<(X.length()-lcsLength)<<endl;
    return 0;
}