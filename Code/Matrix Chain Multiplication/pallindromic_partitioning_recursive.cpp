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

    int minm = INT_MAX;
    for(int k=i ; k<=j-1 ; k++)
    {
        int tempAns = (mcm(X, i, k) + mcm(X, k+1, j) + 1);
        minm = min(minm,tempAns);
    }
    return minm;
}
int main()
{
    string X;
    cout<<"Enter the string : ";
    cin>>X;
    int minSplits;
    if(isPallindrome(X, 0, X.length()-1))
        minSplits = 0;
    else
        minSplits = mcm(X, 0, X.length()-1);
    cout<<"Min cost is : "<<minSplits<<endl;
    return 0;
}