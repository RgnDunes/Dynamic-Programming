/*
PROBLEM STATEMENT 
Given a string X. Split string X into different substrings such that all the substrings formed are pallindromic keeping the number of splits (partition) minimum.

EXAMPLE : 
    X = "geek"
OUTPUT: 2
EXPLANATION : Minimum 2 splits are reqd to form 3 pallindromic substrings i.e., "g", "ee", "k"
*/

#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
bool isPallindrome(string st, int i, int j)
{
    string X="";
    for(int m = i ; m<=j ; m++)
        X+=st[m];
    string Y = X;
    reverse(Y.begin(), Y.end());
    if(X==Y) 
        return true;
    else 
        return false;
}
int mcm(string X, int i, int j)
{
    if(i>=j)
        return 0;

    if(isPallindrome(X, i, j))
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int minm = INT_MAX, left=0, right=0;
    for(int k=i ; k<=j-1 ; k++)
    {
        if(dp[i][k]!=-1)
            left = dp[i][k];
        else
        {
            left = mcm(X, i, k);
            dp[i][k] = left;
        }
        if(dp[k+1][j]!=-1)
            right = dp[k+1][j];
        else
        {
            right = mcm(X, k+1, j);
            dp[k+1][j] = right;
        }
        int tempAns = (left + right + 1);
        minm = min(minm,tempAns);
    }
    return dp[i][j] = minm;
}
int main()
{
    string X;
    cout<<"Enter the string : ";
    cin>>X;
    int minSplits;
    memset(dp,-1,sizeof(dp));
    if(isPallindrome(X, 0, X.length()-1))
        minSplits = 0;
    else
        minSplits = mcm(X, 0, X.length()-1);
    cout<<"Min cost is : "<<minSplits<<endl;
    return 0;
}