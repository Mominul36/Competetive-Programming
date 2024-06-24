vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> bfs;
    queue<int> q;
    vector<bool> visited(n);
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
         int current = q.front();
         q.pop();
         bfs.push_back(current);
         for(int i=0;i<adj[current].size();i++){
             if(!visited[adj[current][i]]){
                 q.push(adj[current][i]);
                 visited[adj[current][i]] = true;
             }  
         }
    }
    return bfs;  
}