/*
PROBLEM : 
    Given two strings X and Y. Print the length of shortest supersequence i.e., merge the two strings and return a shortest string which has string X and Y both as its subsequence.

EXAMPLE : 
    X : "geek"
    Y : "eke"
OUTPUT : 5
EXPLANATION : "geeke"

EXAMPLE : 
    X : "aggtab"
    Y : "gxtxayb"
OUTPUT : 9
EXPLANATION : "aggxtxayb"
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
    cout<<"Length of Shortest Common Supersequence is : "<<(X.length()+Y.length()-lcsLength)<<endl;
    return 0;
}