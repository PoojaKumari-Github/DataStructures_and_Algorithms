/*

*/

// TC=O(n2)
// SC=O(1)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int n)
{
    sort(nums.begin(),nums.end());
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(nums[i]<0)
        {
            int sum=0;
            int pk=1;
            for(int j=i;j<n;j++)
            {
                sum=sum+(pk*nums[j]);
                // cout<<"sum:"<<sum<<endl;
                pk++;
               

            }
             ans=max(ans,sum);
        }

        else 
        {
            int sum=0;
            int pk=1;
            for(int j=i;j<n;j++)
            {
                sum=sum+(pk*nums[j]);
                pk++;
                // cout<<"sum:"<<sum<<endl;

            } 
            ans=max(ans,sum);
            break;
        }
    }
    return ans;
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

    vector<int> arr(n, 0);
    for (int i = 0; i <n; i++)
    {
        cin >> arr[i];
    }

  
    int ans = solve(arr, n);
    cout << ans << endl;

    return 0;
}

/*
input1 :
5
-2 5 8 0 1


Output 1:
61


input2 :


Output2:



*/
