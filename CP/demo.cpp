// TC=O(N)
// SC=O(N)
#include <bits/stdc++.h>
using namespace std;


int solve(int n, vector<int>arr)
{
    int maxlen=0;

    vector<int>hashmap(32,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=30;j>=0;j--)
        {
            int num=arr[i];
            int g=(num>>j);
            if((g&1)==1)
            {
                hashmap[j]=hashmap[j]+1;

            }
        }
    }

    for(int i=0;i<=32;i++)
    {
        maxlen=max(maxlen,hashmap[i]);
    }

    return maxlen;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********

    // Enter the decimal number.

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(n,arr);
    return 0;
}

/*
// input1 :
5
7 4 11 8 3



// output1:
3



// input 2 :


// output 2:







*/
