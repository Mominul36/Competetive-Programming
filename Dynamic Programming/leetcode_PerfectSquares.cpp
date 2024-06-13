//https://leetcode.com/problems/perfect-squares/description/

  //dp
    int solvedp(vector<int> ps, int tar){
         vector<int> dp(tar+1,-1);
         dp[0] =0;

         for(int i=1;i<=tar;i++){
            int minnum = INT_MAX;
            for(int j=0;j<ps.size();j++){
                if(i - ps[j] < 0)
                continue;
              int ans = dp[i - ps[j]];
              if (ans != INT_MAX)
                minnum = min(minnum, ans + 1);      
            }
            dp[i] = minnum;
         }

        return dp[tar];
    }
    int numSquares(int n) {
         vector<int> ps;
        int a = 1;
        while(a*a <= n){
            ps.push_back(a*a);
            a++;
        }
        return solvedp(ps, n); 
    }