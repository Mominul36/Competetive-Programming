class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
           return n;

        return fibb(0,1,2,n);
        
    }
    int fibb(int a, int b, int src, int n){
        int sum = a+b;
        if(src==n)
        return sum;
        return fibb(b,sum,src+1,n);
    }
};



