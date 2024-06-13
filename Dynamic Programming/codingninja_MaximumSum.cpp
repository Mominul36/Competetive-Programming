//https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&nps=true&leftPanelTabValue=SUBMISSION

#include<bits/stdc++.h>
using namespace std;
// Recursion (TLE)
int solve(vector<int> nums, int n){
   if(n<0)
   	return 0;
   if(n==0)
   	return nums[0];

    int pick = solve(nums,n-2) + nums[n];
    int not_pick = solve(nums,n-1); 

    return max(pick, not_pick);

}

//memoaisation (TLE)
int solveMem(vector<int> nums, int n, vector<int> dp){
   if(n<0)
   	return 0;
   if(n==0)
   	return nums[0];

   if(dp[n]!=-1)
   	return dp[n];

    int pick = solveMem(nums,n-2,dp) + nums[n];
    int not_pick = solveMem(nums,n-1,dp); 

    dp[n] = max(pick, not_pick);
    return dp[n];
}

//dp (pass)
int solvetab(vector<int> nums){
	int n = nums.size();
	vector<int> dp(n,-1);
	dp[0] = nums[0];

	for(int i=1;i<n;i++){
		int pick = dp[i-2] + nums[i];
		int not_pick = dp[i-1];
        dp[i] = max(pick, not_pick);
	}
    
    return dp[n-1];

}
int maximumNonAdjacentSum(vector<int> &nums){
     // int ans  = solve(nums, nums.size()-1);
     // return ans;


	// vector<int> dp(nums.size(),-1);
	// return solveMem(nums, nums.size()-1, dp);


	return solvetab(nums);

}
int main(){
    
   return 0; 
}
