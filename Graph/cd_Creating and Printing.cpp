class graph {
public:
  vector<vector<int>> adj_list;
  graph(int v){
     for(int i=0;i<v;i++){
         vector<int> temp;
         temp.push_back(i);
         adj_list.push_back(temp);
     }
  }

  void addEdge(int source, int dest) {
     adj_list[source].push_back(dest);
     adj_list[dest].push_back(source);
  }


};


vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    
     graph g(n);
     for(int i=0;i<edges.size();i++){
         g.addEdge(edges[i][0],edges[i][1]);
     }
    return g.adj_list;
    
}