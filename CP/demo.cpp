// TC=O(N)
// SC=O(N*3)

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    vector<int>dp(n+1,0);
    dp[1]=1;
    dp[2]=2;
    
    int i=3;
    while(i<=n){
        dp[i]=dp[i-1]+dp[i-2];
        i++;
    }
    return dp[n];
    
 }


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

    int n;
    cin>>n;

    int ans=solve(n);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
4

// output1:
5

Input2:

// output 2:



input3:


output:


input4:

output: 



*/