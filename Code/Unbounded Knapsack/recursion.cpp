#include<bits/stdc++.h>
using namespace std;
int unbounded_knapsack(int wt[], int val[], int W, int n)
{
    if(n==0 || W==0) 
        return 0;
    if(W>=wt[n-1])
        return max(val[n-1]+unbounded_knapsack(wt, val, W-wt[n-1], n), unbounded_knapsack(wt, val, W, n-1));
    else
        return unbounded_knapsack(wt, val, W, n-1);
}
int main()
{ 
    int n;
    cout<<"No of items : ";
    cin>>n;
    int wt[n], val[n], W;
    cout<<"Enter weight of Items : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter value of Items : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>val[i];
    }
    cout<<"Enter the capacity of unbounded knapsack : ";
    cin>>W;
    int maxProfit = unbounded_knapsack(wt, val, W, n);
    cout<<"Max Profit is : "<<maxProfit<<endl;
    return 0;
}