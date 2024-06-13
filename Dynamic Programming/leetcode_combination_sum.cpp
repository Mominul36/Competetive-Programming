//https://leetcode.com/problems/combination-sum-iv/description/
#include<bits/stdc++.h>
using namespace std;

//Recurssive method
 int solve(vector<int>& a, int tar, vector<int> dp){
 	 if(tar<0)
 	 	return 0;
 	 if(tar==0)
 	 	return 1;

 	 if(dp[tar]!=-1)
 	 	return dp[tar];

     int ans = 0;
     for(int i=0;i<a.size();i++){
     	ans+= solve(a,tar-a[i],dp);
     }
     dp[tar] = ans;
     return ans;
 }
 int combinationSum4(vector<int>& a, int tar) {
       vector<int> dp(tar+1,-1);
       return solve(a,tar,dp);   
  }






  //dp
 int combinationSum2(vector<int>& a, int tar) {
       vector<unsigned int> dp(tar+1,0);
       dp[0] = 1;

       for(int i=0;i<=tar;i++){
          for(int j=0;j<a.size();j++){
          	if(i-a[j]>=0)
          	dp[i]+= dp[i-a[j]];
          }
       }   
       return dp[tar];
  }

int main()
{
   vector<int> a= {1,2,3};
    cout<< combinationSum2(a,4)<<endl;

    return 0;
}


















