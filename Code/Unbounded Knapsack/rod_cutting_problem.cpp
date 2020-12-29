/*
PROBLEM : 
    Given two arrays length[] and price[] and the total length of 
    the rod N. You are free to cut the rod in any number of pieces 
    such that length of each piece exists in the length[] array. 
    Rod of length length[i] has a price of price[i]. You have to 
    maximize the overall price of the rod after it is been cut.

EXAMPLE : 
    length[] = {1, 2, 3, 4, 5, 6, 7, 8}
    price[] = {1, 5, 8, 9, 10, 17, 17, 20}
    N = 8
OUTPUT : 
    22
*/

#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];
int unbounded_knapsack(int length[], int price[], int W, int N)
{
    for(int i=1 ; i<N+1 ; i++)
    {
        for(int j=1 ; j<W+1 ; j++)
        {
            if(j>=length[i-1])
            {
                dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}
int main()
{
    int N;
    cout<<"Total length of rod : ";
    cin>>N;
    int length[N], price[N], W;
    cout<<"Total length of price array : ";
    cin>>W;
    cout<<"Enter lengths of rod pieces : ";
    for(int i=0 ; i<W ; i++)
    {
        cin>>length[i];
    }
    cout<<"Enter price of rod pieces : ";
    for(int i=0 ; i<W ; i++)
    {
        cin>>price[i];
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0 ; i<N+1 ; i++)
    {
        for(int j=0 ; j<W+1 ; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    int maxProfit = unbounded_knapsack(length, price, W, N);
    cout<<"Max Profit is : "<<maxProfit<<endl;
    return 0;
}