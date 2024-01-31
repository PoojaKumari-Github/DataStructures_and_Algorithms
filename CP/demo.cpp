// TC=O(N)
// SC=O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>arr)
{
   vector<int>freq_1(40,0);

    // this will store the freq of the same sequence which is present now at ith index occured previosuly.

   unordered_map<int,int>mp;

//   Empty subarray is also possible and it has no element so sequence -> digit conversion is 0.
    mp[0]++;

    int i=1;
    int ans=0;
    while(i<=n)
    {
        int num=arr[i];

        int decimal_conversion_of_sequence=0;

        // j--> row
        for(int j=30;j>=0;j--)
        {
            int g=(num>>j);
            if((g&1)==1)
            {
                freq_1[j]++;
            }

            // col sequence -> is stored in  decimal_conversion_of_sequence
            if(freq_1[j]%2!=0)
            {
                int ith_Bit_decimal=(1<<j);
                decimal_conversion_of_sequence+=ith_Bit_decimal;
            }
        }

        // decimal_conversion_of_sequence-> decimal conversion of current status.

        ans=ans+mp[decimal_conversion_of_sequence];
        mp[decimal_conversion_of_sequence]=mp[decimal_conversion_of_sequence]+1;


        i++;
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

    // Enter the decimal number.
    int n ;
    cin>>n;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    cout<<solve(n,arr);
    return 0;
}

/*
// input1 :
4
1 0 3 2


// output1:

2



// input 2 :


// output 2:







*/
