#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

#define GET_FASTER ios_base::sync_with_stdio(false); cin.tie(NULL)
#define watch(c) for(auto i: c){cout<< i <<" ";}cout<<endl;
#define watch2(c) for(auto i: c){for(auto j : i){cout<< j <<" ";}cout<<endl;}
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
void input(vector<int>&v, int n) {for(int i=0; i<n; i++){int x; cin>>x; v.push_back(x);}}


//One's complement of a Binary Number
string onescomplement(string bin){
	int bit ;
	if(bin.size()>=0 && bin.size()<=3)
		bit = 4;
	else if(bin.size()>=4 && bin.size()<=7)
		bit = 8;
	else if(bin.size()>=8 && bin.size()<=15)
		bit = 16;
	else if(bin.size()>=16 && bin.size()<=31)
		bit = 32;

	string temp(bit  - bin.size(),'0');
	bin = temp + bin;

	for(int i=0;i<bin.size();i++){
		if(bin[i]=='0')
			bin[i] = '1';
		else
			bin[i] = '0';
	}
	return bin;	 
}

//Two's complement of a Binary Number
string twoscomplement(string bin){
	bin = onescomplement(bin);
	char car = '1';
	for(int i=bin.size()-1;i>=0;i--){
		if(car=='1' && bin[i]=='1'){
			bin[i] = '0';
			car = '1';
		}
		else if(bin[i]!=car){
			bin[i] = '1';
			car='0';
		}
	}
	return bin;
}

// Print Binary Number
string pb(int n){
	if(n==0)
		return "0";
	bool positive = true;
	if(n<0){
		positive = false;
		n = ~n + 1;
	}
	string bin;
	while(n){
		bin.insert(bin.begin(),(n&1)+48);
		n = n >> 1;
	}
	if(positive){
		//cout<< bin<<endl;
		return bin;
	}
	cout<< twoscomplement(bin)<<endl;
	return "";
}

void pb_bit(int num, int bit){
	for(int i=bit-1;i>=0;i--)
		cout<<((num>>i)&1);
	cout<<endl;
}

//Swap two numbers
void swap2(int &a,int &b){
	a = a^b;
	b = a^b;
	a = a^b;
}

//Check i'th bit set or not
bool isBitSet(int num, int i){
	return num & (1 << i);
}

//Check Even or Odd
bool isEven(int n){
	return !(n&1);
}

//Set i'th bit from 0 to 1
int setBit(int n, int i){
	return n | (1<<i);
}

//Unset i'th bit from 1 to 0
int unsetBit(int n, int i){
	return n & ~(1<<i);

}
//Toogle i'th bit
int toogleBit(int n, int i){
	return n ^ (1<<i);
}

//Unset last set bit
int unsetLastsetBit(int &n){
	return n & (n-1);
}

//Clear all set bit up to i
int clearRSB(int n, int i){
	return (n & (~((1<<(i+1))-1)));
}

//Clear all left set bit from i
int clearLSB(int n, int i){
	return (n & ((1<<(i+1))-1));
}

//Return index of last set bit
int lastSetBit(int n){
	if(n==0)
		return -1;
	n = (n&(~(n-1)));
	return log2(n);
}


//Count number of set bits
int countSetBits(int n){
	int count = 0;
	while (n){
		n = n & (n - 1);
		count++;
	}
	return count;
}

//Check a number power of 2 or not
bool isPowerOfTwo(int n){
	return n && !(n & (n - 1));
}

//Check a number power of 4 or not
bool isPowerOfFour(int n){
	bool mask = !(n & 0xAAAAAAAA); // 0xAAAAAAAA = 10101010101010101010101010101010
	return isPowerOfTwo(n) && mask;
}





//All Subsets of a array
vvi subsets(vi &a){
	int n = a.size();
	vvi subset;
	int number_of_subset = (1<<n);

	for(int i=0;i<number_of_subset;i++){
		vi temp;
		for(int j=0;j<n;j++){
			if(i &(1<<j)){
				temp.push_back(a[j]);
			}
		}
		subset.push_back(temp);
	}
	return subset;
}


//Find unique element when all duplicate element appears even time
//Single number 1
int uniqueFromEvenDuplicate(vi &a){
	int xo = 0;
	for(int i=0;i<a.size();i++){
		xo = xo^a[i];
	}
	return xo;
}


//Find two unique element when all duplicate element appears even time
//Single number 3
vector<int> twouniqueFromEvenDuplicate(vi &a){
	int xo = 0;
	for(int i=0;i<a.size();i++){
		xo = xo^a[i];
	}
	int lastset=0;
	while(!isBitSet(xo,lastset)){
		lastset++;
	}

	vector<int> ans;
	int xo2=0;
	for(int i = 0;i<a.size();i++){
		if(isBitSet(a[i],lastset))
			xo2 = xo2 ^ a[i];
	}
	ans.push_back(xo2);
	ans.push_back(xo2 ^ xo);
	return ans;
}


//Find unique element when all duplicate element appears odd time
//Single number 2
int uniqueFromOddDuplicate(vi &a, int app){
	int ans = 0;
	for(int i=0;i<32;i++){
		int cnt = 0;
		for(int j=0;j<a.size();j++){
			if(isBitSet(a[j],i)){
				cnt++;
			}
		}
		if(cnt%app != 0){
			setBit(ans,i);
		}
	}
	return ans;
}



//XOR in 1 to N  (Just following output pattern)
int xorOneToN(int n){
	if(n%4==1)
		return 1;
	if(n%4==2)
		return n+1;
	if(n%4==3)
		return 0;
	if(n%4==0)
		return n;
	return 0;
}

int xorGivenRange(int a, int b){
	return xorOneToN(a-1) ^ xorOneToN(b);
}


int add(int n){
	int i=0;
	while(1){
		if(isBitSet(n,i)){
			n = toogleBit(n,i);
		}
		else{
			n = toogleBit(n,i);
			return n;
		}
		i++;
	}
}


//devide two integer without division operator
int divide(int dividend, int divisor) {
	if (divisor == dividend)
		return 1;
	bool sign = true;
	if (dividend < 0 && divisor > 0) {
		sign = false;
	} else if (divisor < 0 && dividend >= 0) {
		sign = false;
	}
	long n = abs(dividend), d = abs(divisor);
	long ans = 0;
	while (n >= d) {
		int cnt = 0;
		while (n >= (d << (cnt + 1))) {
			cnt++;
		}
		ans += (1LL << cnt);
		n = n - (d << cnt);
	}

	if (!sign)
		ans = ~ans + 1;

	if (ans < INT_MIN)
		return INT_MIN;
	if (ans > INT_MAX)
		return INT_MAX;
	return ans;
}

//Sum of two number without + or - operator
 int getSum(int a, int b) {
      int ans = 0;
      int car = 0;
      for(int i=0;i<32;i++){
      	int aa = isBitSet(a,i);
      	int bb = isBitSet(b,i);
          if(aa^bb == 1 ){
          	if(car==0){
          		ans = setBit(ans,i);
          	}
          }
          else if(aa==0 && bb==0){
          	if(car==1){
          		car = 0;
          		ans = setBit(ans,i);
          	}
          }
          else if(aa==1 && bb==1){
          	if(car==0){
          		car=1;
          	}
          	else{
          		ans = setBit(ans,i);
          	}
          }



      }
      return ans;

    }
int main(){
	GET_FASTER;

    vi a = {14,70,53,83,49,91,30,80,92,51,66,70};
    sort(all(a));
  int xo = 0;
    for(int i=0;i<a.size();i++){
    	xo = xo ^ a[i];
    	cout<< a[i]<<" ";
    	  pb_bit(a[i],8);
    }
  cout<<endl<<endl<< xo;

  
	
}






