
// TC=O(n) 
// SC=O(2*n)=O(n)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr1,vector<int> arr2, int n){

    vector<int> DPa(n+1,0);
    vector<int> DPb(n+1,0);

    DPa[1]=arr1[1];
    DPb[1]=arr2[1];

    // If taking the current element from arr1 at i ind , then adding the previous best ans from DPa at i-1 index....or taking the curr ele but the previous step is travelling and considering the best ans from DPb[i-2]
    if(n>=2){
    DPa[2]=max(arr1[2]+DPa[2-1] , arr1[2]+DPb[2-2]);
    DPb[2]=max(arr2[2]+DPb[2-1], arr2[2]+DPa[2-2]);

    for(int i=3;i<=n;i++){
    DPa[i]=max(arr1[i]+DPa[i-1] , arr1[i]+DPb[i-2]);
    DPb[i]=max(arr2[i]+DPb[i-1], arr2[i]+DPa[i-2]);       
    }
  }

  cout<<"DPa[n]:"<<DPa[n]<<" DPb[n]:"<<DPb[n]<<endl;
  return max(DPa[n],DPb[n]);
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
	int n;
    cin>>n;


    vector<int> arr1(n+1);
    vector<int> arr2(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }
    cout<<solve(arr1,arr2,n)<<endl;
	return 0;
}
	


/*
// input1 :



// output1:





*/