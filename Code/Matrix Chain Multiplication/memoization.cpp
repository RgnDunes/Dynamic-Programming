/*
PROBLEM STATEMENT 
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have: 

(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parenthesization requires less number of operations.


Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i]. We need to write a function that should return the minimum number of multiplications needed to multiply the chain.
*/

#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int mcm(int arr[], int i, int j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int min_cost = INT_MAX;
    for(int k=i ; k<=j-1 ; k++)
    {
        int tempAns = (mcm(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]));
        min_cost = min(min_cost,tempAns);
    }
    return dp[i][j] = min_cost;
}
int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    int minCost = mcm(arr, 1, n-1);
    cout<<"Min cost is : "<<minCost<<endl;
    return 0;
}