#include<bits/stdc++.h>
using namespace std;
template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}
bool cmp(int a, int b){
   return a>b;
}
int main(){
   cout<< min(INT_MAX, 1+INT_MAX)<<endl;
 
  return 0; 
}