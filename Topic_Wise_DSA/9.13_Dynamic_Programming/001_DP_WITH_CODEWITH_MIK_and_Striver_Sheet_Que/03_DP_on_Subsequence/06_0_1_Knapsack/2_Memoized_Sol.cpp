
// TC=O(n*w)
// SC=O(n*w)+O(n)

class Solution
{
    public:
    int solve(int ind, int Capacity,int wt[], int val[],vector<vector<int>>&dp)
    {
        // base case
        
        // if(Capacity==0) return 0; // this base case u not need to write,
        if(ind==0)  
        {
            if(wt[0]<=Capacity) return val[0]; // ✨✨ ThiThis base case write correctly, when ind==0 then only u will check this base case
            return 0;
        }
        
        if(dp[ind][Capacity]!=-1) return dp[ind][Capacity];
        
        int notTake=0+solve(ind-1,Capacity, wt,val,dp);
        int take=INT_MIN;
        if(wt[ind]<=Capacity)
        {
            take=val[ind]+solve(ind-1,Capacity-wt[ind],wt,val,dp);
        }
        
      
        return dp[ind][Capacity]=max(notTake,take);
        
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return solve(n-1,W,wt,val,dp);
    }
};