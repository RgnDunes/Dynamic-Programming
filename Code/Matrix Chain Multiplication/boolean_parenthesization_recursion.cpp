/*
PROBLEM : 
Given a string X consisting of only T (signifies True), F (signifies False), | (signifies Or), & (signifies And), ^ (signifies XOR). Enclose this string in parenthesis such that this string evaluates to True. Print no of ways in which this can be done.

EXAMPLE : 
    X : "T^F&T"
OUTPUT : 2
EXPLANATION : "((T^F)&T)" , "(T^(F&T))"
*/

#include<bits/stdc++.h>
using namespace std;
int mcm(string X, int i, int j, bool isTrue)
{
    if(i>j)
        return false;

    if(i==j)
    {
        if(isTrue==true)
            return X[i]=='T';
        else
            return X[i]=='F';
    }
    int ways = 0;
    for(int k=i+1 ; k<=j-1 ; k+=2)
    {
        int leftTrue = mcm(X, i, k-1, true);
        int leftFalse = mcm(X, i, k-1, false);
        int rightTrue = mcm(X, k+1, j, true);
        int rightFalse = mcm(X, k+1, j, false);
        if(X[k]=='&')
        {
            if(isTrue)
                ways+=(leftTrue*rightTrue);
            else
            {
                ways+=(leftFalse*rightFalse); 
                ways+=(leftTrue*rightFalse);
                ways+=(leftFalse*rightTrue);
            }           
        }
        if(X[k]=='|')
        {
            if(isTrue)
            {
                ways+=(leftTrue*rightTrue);
                ways+=(leftTrue*rightFalse);
                ways+=(leftFalse*rightTrue);
            }
            else
                ways+=(leftFalse*rightFalse);
        }
        if(X[k]=='^')
        {
            if(isTrue)
                ways+=((leftTrue*rightFalse)+(leftFalse*rightTrue));
            else
                ways+=((leftFalse*rightFalse)+(leftTrue*rightTrue));            
        }
    }
    return ways;
}
int main()
{
    string X;
    cout<<"Enter the string : ";
    cin>>X;
    int totWays = mcm(X, 0, X.length()-1, true);
    cout<<"Total Ways are : "<<totWays<<endl;
    return 0;
}