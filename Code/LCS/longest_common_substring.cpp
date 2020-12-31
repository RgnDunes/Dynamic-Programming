/*
PROBLEM : 
    Given two strings X and Y. Print the length of the longest 
    common substring formed from these two strings.

EXAMPLE : 
    X : "abcde"
    Y : "abfce"
OUTPUT : 4
EXPLANATION : Longest Common Substring is "ab" and it's length is 2.
*/

#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int lcs(string X, string Y, int m, int n)
{
    int result=0;
    for(int i=1 ; i<m+1 ; i++)
    {
        for(int j=1 ; j<n+1 ; j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j] = (1+dp[i-1][j-1]);
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return result;
}
int main()
{
    cout<<"Enter first string (X) : ";
    string X;
    cin>>X;
    cout<<"Enter second string (Y) : ";
    string Y;
    cin>>Y;
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
    cout<<"Length of Longest Common Subsequence is : "<<lcsLength<<endl;
    return 0;
}