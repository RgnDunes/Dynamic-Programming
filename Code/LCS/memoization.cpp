/*
PROBLEM : 
    Given two strings X and Y. Print the length of the longest 
    common subsequence formed from these two strings.

EXAMPLE : 
    X : "abcdgh"
    Y : "abedfhr"
OUTPUT : 4
EXPLANATION : Longest Common Subsequence is "abdh" and it's length is 4.
*/

#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int lcs(string X, string Y, int m, int n)
{
    if(m==0 || n==0) 
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];
    if(X[m-1]==Y[n-1])
        return dp[m][n] =  (1+lcs(X, Y, m-1, n-1));
    else
        return dp[m][n] =  max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
int main()
{
    cout<<"Enter first string (X) : ";
    string X;
    cin>>X;
    cout<<"Enter second string (Y) : ";
    string Y;
    cin>>Y;
    memset(dp,-1,sizeof(dp));
    int lcsLength=0;
    lcsLength=lcs(X, Y, X.length(), Y.length());
    cout<<"Length of Longest Common Subsequence is : "<<lcsLength<<endl;
    return 0;
}