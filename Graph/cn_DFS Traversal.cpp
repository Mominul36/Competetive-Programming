 void DFS_Implementation(int source, vector<int> &dfs, map<int,bool> &visited, vector<vector<int>> graph){
    visited[source] = true;
    dfs.push_back(source);
    for(int i=0;i<graph[source].size();i++){
        if(!visited[graph[source][i]])
            DFS_Implementation(graph[source][i],dfs,visited,graph);
    }
}

vector<int> DFS(int source,vector<vector<int>> graph, map<int,bool> &visited){
    vector<int> dfs;
    DFS_Implementation(source,dfs,visited,graph);
    return dfs;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   vector<vector<int>> graph(V);
   for(int i=0;i<E;i++){
       graph[edges[i][0]].push_back(edges[i][1]);
       graph[edges[i][1]].push_back(edges[i][0]);
   } 

   vector<vector<int>> result;
   map<int,bool> visited;
   for(int i=0;i<V;i++){
       if(!visited[i]){
          result.push_back(DFS(i,graph,visited));
       }
   }
   return result;
}