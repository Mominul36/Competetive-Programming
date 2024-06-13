//https://leetcode.com/problems/coin-change/description/ 




 //Recursion with memoaization
    int solve(vector<int>& coin, int amount, vector<int> dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;
        if(dp[amount]!=-1)
          return dp[amount];

        int mincoin = INT_MAX;
        for (int i = 0; i < coin.size(); i++) {
             int ans = solve(coin, amount - coin[i],dp);
            if (ans != INT_MAX)
                mincoin = min(mincoin, ans + 1);
        }

        dp[amount] = mincoin;
        return mincoin;
    }
     //dp
    int solvetab(vector<int>& coin, int amount){
         
         vector<int> dp(amount+1,-1);
         dp[0] =0;

         for(int i=1;i<=amount;i++){
            int mincoin = INT_MAX;
            for(int j=0;j<coin.size();j++){
                if(i - coin[j] < 0)
                continue;
              int ans = dp[i - coin[j]];
              if (ans != INT_MAX)
                mincoin = min(mincoin, ans + 1);      
            }
            dp[i] = mincoin;
         }

        return dp[amount];

    }
    int coinChange(vector<int>& coin, int amount) {
        //Recursion with memoaization
        vector<int> dp(amount + 1, -1);
        int ans = solve(coin, amount, dp);
        if (ans == INT_MAX)
            return -1;
        return ans;


        //dp
        int ans = solvetab(coin, amount);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }