/*
PROBLEM:
Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1. Print true/false accordingly.

Scrambled string: 
Given string str, we can represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Note: Srambled string is not same as an Anagram.

Below is one possible representation of str = “coder”:
 

    coder
   /    \
  co    der
 / \    /  \
c   o  d   er
           / \
          e   r

To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node “co” and swap its two children, it produces a scrambled string “ocder”.
 

    ocder
   /    \
  oc    der
 / \    /  \
o   c  d   er
           / \
          e   r
Thus, “ocder” is a scrambled string of “coder”.
Similarly, if we continue to swap the children of nodes “der” and “er”, it produces a scrambled string “ocred”.
 

    ocred
   /    \
  oc    red
 / \    /  \
o   c  re  d
       / \
      r   e
Thus, “ocred” is a scrambled string of “coder”.


EXAMPLE : 
    X : "great"
    Y : "rgeat"
OUTPUT : True
*/

#include<bits/stdc++.h>
using namespace std;
bool mcm(string X, string Y)
{
    if(X.length()!=Y.length())
        return false;
    if(X.length()==0 && Y.length()==0)
        return true;
    if(X.compare(Y)==0)
        return true;
    if(X.length()<=1 || Y.length()<=1)
        return false;

    int n = X.length();
    bool flag = false;

    for(int k=1 ; k<=n-1 ; k++)
    {
        bool cond1 = (mcm(X.substr(0, k), Y.substr(n-k, k))==true) && (mcm(X.substr(k, n-k), Y.substr(0, n-k))==true);
        bool cond2 = (mcm(X.substr(0, k), Y.substr(0, k))==true) && (mcm(X.substr(k, n-k), Y.substr(k, n-k))==true);
        if(cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
int main()
{
    string X,Y;
    cout<<"Enter the first string : ";
    cin>>X;
    cout<<"Enter the second string : ";
    cin>>Y;
    bool isScrambled = mcm(X, Y);
    cout<<"Is Scrambled : "<<(isScrambled==1?"True":"False")<<endl;
    return 0;
}