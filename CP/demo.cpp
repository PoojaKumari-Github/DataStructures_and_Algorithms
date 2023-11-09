// TC=O(N)
// SC=O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n) {
    int maxSum=0;
    //  u need to compute nums[i]-i
    vector<int> prefix(n+1);
    for(int i=1;i<=n;i++){
        prefix[i]=nums[i]-i;
    }

    unordered_map<int,int> mp;

    for(int i=1;i<=n;i++){
        mp[prefix[i]]+=nums[i];
        maxSum=max(maxSum,mp[prefix[i]]);
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


    //*********
    // 1-- based indexing are used here

    int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

    cout<<solve(arr,n);
}






/*

input :
3
1 2 3
output :
6

input 2:
5
1 5 3 7 8



output :
20

*/



