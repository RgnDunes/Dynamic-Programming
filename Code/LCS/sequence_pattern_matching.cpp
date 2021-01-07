/*
PROBLEM : 
    Given two strings X and Y. Print true/false whether string X is subsequence of string Y.

EXAMPLE : 
    X : "axy"
    Y : "adxcpy"
OUTPUT : True

EXAMPLE : 
    X : "axyz"
    Y : "adxcpy"
OUTPUT : False
*/

//METHOD - 1
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
    if(lcsLength==X.length())
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}

//METHOD - 2
#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
string lcs(string X, string Y, int m, int n)
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
    int i=m, j=n;
    string rev_ans="";
    while(i>0 || j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            rev_ans += X[i-1];
            i-=1;
            j-=1;
        }
        else
        {
            if(dp[i-1][j] >= dp[i][j-1])
            {
                i-=1;
            }
            else if(dp[i-1][j] < dp[i][j-1])
            {
                j-=1;
            }   
        }   
    }
    return rev_ans;
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
    string lcs_string="";
    lcs_string=lcs(X, Y, X.length(), Y.length());
    reverse(lcs_string.begin(),lcs_string.end());
    if(lcs_string==X)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}