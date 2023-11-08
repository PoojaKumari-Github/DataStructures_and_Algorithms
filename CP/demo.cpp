// TC=O(2N)==O(N)
// SC=O(N)


#include <bits/stdc++.h>
using namespace std;

  int solve(vector<int>& nums,int n, int k) {
        unordered_map<int,int> mp;
        unordered_map<int,bool> vis;

        for(auto it : nums){
            mp[it]++;
            vis[it]=false;
        }

        int ans=0;
        
        for(int i=1;i<=n;i++){
            int el=nums[i];
            int partner=k-el;
            if(vis[partner]==false && vis[el]==false){
                if(el==partner){
                    ans=ans+(mp[el])/2;

                }
                else {
                ans=ans+min(mp[el] ,mp[partner]);

                }
                vis[el]=true;
                vis[partner]=true;
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

    //*********
    // 1-- based indexing are used here

    int n;
        cin>>n;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        int ans=0;
        int j=0;
        while(j<=2000000000){
            int  s=solve(arr,n,j);
            ans=max(s,ans);
            j=j+1;
        }

        cout<<ans<<endl;

        return 0;
}






/*

input :
5
1 2 6 6 5



output :
2

input 2:


output :


*/



