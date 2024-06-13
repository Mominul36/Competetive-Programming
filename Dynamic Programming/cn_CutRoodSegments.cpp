//https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

    //dp (pass)
    int solvetab(vector<int>& lengths, int n){
         vector<int> dp(n+1,0);
         dp[0] =0;

         for(int i=1;i<=n;i++){
            int maxsegemnt = -1;
            for(int j=0;j<lengths.size();j++){
                if(i - lengths[j] < 0)
                continue;
              int ans = dp[i - lengths[j]];
              if (ans != -1)
                maxsegemnt = max(maxsegemnt, ans + 1);      
            }
            dp[i] = maxsegemnt;
         }

        return dp[n];
    }

int cutSegments(int n, int x, int y, int z) {
	vector<int> lengths;
	lengths.push_back(x);
	lengths.push_back(y);
	lengths.push_back(z);

	int ans =  solvetab(lengths, n);
	if(ans==-1)
	return 0;
	return ans;
}