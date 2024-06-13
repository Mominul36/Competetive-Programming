
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define watch(c) for(auto i: c){cout<< i <<" ";}

#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define endl '\n'
#define nl(x) (int)log10(x)+1
#define ig cin.ignore()
#define PI 3.1415926535897932384626
#define pi acos(-1.0)
#define mp make_pair
#define fi first
#define se second

#define GET_FASTER ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
const ll mx= LLONG_MAX;
const ll mn= LLONG_MIN;
const ll MOD= 1e9+7;

void input(vector<int>&v, int n) {for(int i=0; i<n; i++){int x; cin>>x; v.push_back(x);}}
void printBinary(int num){for(int i=10; i>=0; --i){cout<< ((num>>i)&1);}cout<< endl;}

int mid(int l, int r){return ((l>>1) + (r>>1) + ((r&1 + l&1)>>1));}
bool descending_order(int x, int y){return x>y;}

int sum_mod(ll a, ll b){return (((a % MOD) + (b % MOD)) % MOD);}
int mul_mod(ll a, ll b){return (((a % MOD) * (b % MOD)) % MOD);}
int sub_mod(ll a, ll b){return (((a % MOD) - (b % MOD) + MOD) % MOD);}
//int div_mod(ll a, ll b){return (((a % MOD) * (1/b) % MOD) % MOD);}


 
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
int main()
{
    GET_FASTER;

    vector<int> a= {1,2,3};
    cout<< combinationSum4(a,4)<<endl;




    return 0;
}


















