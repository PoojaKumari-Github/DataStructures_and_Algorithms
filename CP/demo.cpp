/*

*/

// TC=O(nlogn)
// SC=O(1)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>arr, int n)
{
    
    int maxSum=0; // not pikcing any element, as it is allowed in the question
    vector<int>odd;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]%2==0)
        {
            if(arr[i]>0)
            {
                maxSum+=arr[i];
            }
        }
        else 
        {
            odd.push_back(arr[i]);
        }
    }

    sort(odd.begin(),odd.end());

    int i=odd.size()-1;
    while(i>=0)
    {
        if((i-1)>=0)
        {
            int temp=odd[i]+odd[i-1];
            maxSum=max(maxSum,maxSum+temp);
        }
        i-=2;
    }
    return maxSum;
}   

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    //

    //*********

    int n;
    cin >> n;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i]; 
    }

  
    int ans = solve(arr, n);

    cout << "ans:"<<ans<< endl;

    return 0;
}

/*
input1 :
8
1 2 3 4 5 6 7 8 

Output 1:
ans:36


input2 :
6
6 3 4 -1 9 17

Output2:
ans:38






*/
