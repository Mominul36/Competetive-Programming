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


//Using adjacency list
class graph{
public:
    map<int,list<int>> adj_list;
    bool direction;

    graph(bool direction){
        this->direction = direction;
    }
    void addEdge(int source, int dest){
       adj_list[source].push_back(dest);
        if(!direction){
           adj_list[dest].push_back(source);
        }
    }

    void print_graph(){
     for(auto it = adj_list.begin();it!=adj_list.end();it++){
      cout<< it->first<< " -> ";
      for(auto lst : it->second){
          cout<<lst<<"  ";
      }
      cout<<endl;
  }
}


void bfs(int source){
  queue<int> q;
  map<int,bool> visited;
  q.push(source);
  visited[0] = true;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    cout<< current << " ";
    for(auto lst: adj_list[current]){
        if(!visited[lst]){
            q.push(lst);
            visited[lst] = true;
        }
    } 
  }
  cout<<endl;
}

};


int main(){
    GET_FASTER;
    
    graph g(false);
    
    
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);

    g.print_graph();

    cout<<endl<<endl;
    g.bfs(0);





    
    return 0; 
}
