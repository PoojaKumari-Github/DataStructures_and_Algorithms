/*
dpa[i]= Best answer till index 'i' , if the last element is 'a'
dpa[i]=1+max(dpb[i-1],dpb2[i-1])

dpa2[i]=It store the best answer till index 'i' , if the last 2 elements are 'a'
dpa2[i]=2+max(dpb[i-2],dpb2[i-2])

dpb[i]= Best answer till index 'i' , if the last element is 'b'
dpb[i]=1+max(dpa[i-1],dpa2[i-1])

dpb2[i]=It store the best answer till index 'i' , if the last 2 elements are 'b'
dpb2[i]=2+max(dpa[i-2],dpa2[i-2])

*/

// TC= 
// SC= 
#include<bits/stdc++.h>
using namespace std;

int  solve(string s) 
{
    // check for all the substring 
    int n=s.size();
    int ans=0;
    int len=0;
   
    vector<int>dpa(n+1,0);
    vector<int>dpa2(n+1,0);
    vector<int>dpb(n+1,0);
    vector<int>dpb2(n+1,0);

    if(s[0]=='a') dpa[1]=1;
    if(s[0]=='b') dpb[1]=1;
    dpa2[1]=0; // At index 0, 2 length is not possible.
    dpb2[1]=0; // At index 0, 2 lenght is not possible , so ans is 0.

    int i=2;
    while(i<=n){


        if(s[i-1]=='a'){
            dpa[i]=1+max(dpb[i-1],dpb2[i-1]);

            if(i>=2 && s[i-1]=='a'){
                dpa2[i]=2+max(dpb[i-2],dpb2[i-2]);
            }
            else if (s[i-1]=='a'){
                dpa2[i]=2;
            }
            dpb[i]=0;
            dpb2[i]=0;
        }
        if(s[i-1]=='b'){
            dpb[i]=1+max(dpa[i-1],dpa2[i-1]);

            if(i>=2 && s[i-1]=='b'){
                dpb2[i]=2+max(dpa[i-2],dpa2[i-2]);
            }
            else if (s[i-1]=='b'){
                dpb2[i]=2;
            }
            dpa[i]=0;
            dpa2[i]=0;
        }

        len=max(dpa[i-1],max(dpa2[i-1],max(dpb[i],dpb2[i])));
        ans=max(ans,len);
        i++;
    }
    
    return ans;
  
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

   string s1;
   cin>>s1;

    cout<<solve(s1);

	return 0;
}
	


/*
// input1 :
aabbaaaaabb


// output1:
6

// input 2 :
aabbaabbaabbaaa

// output 2:
14

input3:
aabbaaaaaaabb

output:
6


*/