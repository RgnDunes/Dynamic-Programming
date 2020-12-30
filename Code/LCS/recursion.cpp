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
int lcs(string X, string Y, int n, int m)
{
    if(n==0 || m==0) 
        return 0;
    if(X[n-1]==Y[m-1])
        return (1+lcs(X, Y, n-1, m-1));
    else
        return max(lcs(X, Y, n, m-1), lcs(X, Y, n-1, m));
}
int main()
{
    cout<<"Enter first string (X) : ";
    string X;
    cin>>X;
    cout<<"Enter second string (Y) : ";
    string Y;
    cin>>Y;
    int lcsLength=0;
    lcsLength=lcs(X, Y, X.length(), Y.length());
    cout<<"Length of Longest Common Subsequence is : "<<lcsLength<<endl;
    return 0;
}