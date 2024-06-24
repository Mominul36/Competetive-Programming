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
    map<int,vector<int>> adj_list;
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

 void DFS_Implementation(int source, vector<int> &dfs, map<int,bool> &visited){
    visited[source] = true;
    dfs.push_back(source);

    for(int i=0;i<adj_list[source].size();i++){
        if(!visited[adj_list[source][i]])
            DFS_Implementation(adj_list[source][i],dfs,visited);
    }
}

vector<int> DFS(int source){
    vector<int> dfs;
    map<int,bool> visited;

    DFS_Implementation(source,dfs,visited);

    return dfs;
}

void print_graph(){
   for(auto it = adj_list.begin();it!=adj_list.end();it++){
      cout<< it->first<< " -> ";
      for(auto vec : it->second){
          cout<<vec<<"  ";
      }
      cout<<endl;
  }
}

};


int main(){
    GET_FASTER;
    
    graph g(true);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.print_graph();


    vector<int> dfs = g.DFS(2);
    for(auto s : dfs)
        cout<< s<< " ";
    cout<<endl;



    
    return 0; 
}
