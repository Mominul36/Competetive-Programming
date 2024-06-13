//https://www.youtube.com/watch?v=S31W3kohFDk&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=2
#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	int n= cost.size();
	if(n==2)
		return min(cost[0],cost[1]);
	vector<int> mincost(cost.size(),-1);

	mincost[n-1] = cost[n-1];
	mincost[n-2] = cost[n-2];

	for(int i=n-3;i>=0;i--){
		mincost[i] = min(cost[i]+mincost[i+1],  cost[i]+mincost[i+2]);
	}
	return min(mincost[0], mincost[1]);

}


//another approach
int minCostClimbingStairs(vector<int>& cost) {
	int n= cost.size();
	vector<int> mincost(cost.size(),-1);

	mincost[0] = cost[0];
	mincost[1] = cost[1];

	for(int i=2;i<n;i++){
		mincost[i] = min(cost[i]+mincost[i-1],  cost[i]+mincost[i-2]);
	}
	return min(mincost[n-1], mincost[n-2]);
}


//memory minimization
int minCostClimbingStairs2(vector<int>& cost) {
int n= cost.size();
	if(n==2)
		return min(cost[0],cost[1]);
	
	int last = cost[n-1];
	int slast = cost[n-2];

	for(int i=n-3;i>=0;i--){
        int temp = slast;
		slast = min(cost[i]+slast,  cost[i]+last);
        last = temp;	
	}
	return min(slast,last);
}
int main(){

	return 0; 
}
