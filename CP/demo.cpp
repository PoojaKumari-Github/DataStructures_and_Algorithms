
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n  ){
    int dp[n+1];
    dp[1]=0;
    dp[2]=abs(arr[2]-arr[1])+dp[1];
    dp[3]=abs(arr[3]-arr[2])+dp[2];

    int i=4;
    while(i<=n){
        dp[i]=min((abs(arr[i]-arr[i-3])+dp[i-3]) , 
                 (dp[i-1]+ abs(arr[i-arr[i-1]])));
        i++;
    }
    return dp[n];

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
    cin >> n ;
    
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
   
        cin>>arr[i];
    }

  
    cout<<solve(arr,n)<<endl;
}






/*
input :
4
1 5 3 21234
-4509 200 3 40

output :
21434
*/




