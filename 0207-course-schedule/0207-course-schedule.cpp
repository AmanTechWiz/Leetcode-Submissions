class Solution{
public:
    bool canFinish(int N, vector<vector<int>>&arr) {
      vector<vector<int>>list(N);
      
      for(auto node : arr){
        list[node[1]].push_back(node[0]);
      }

      vector<bool>visited(N,false);
      vector<bool>pathvisited(N,false);

      for(int i=0; i<N; i++){
        if(!visited[i]){
            if(dfs(i,list,visited,pathvisited)) return false;
        }
      }
    return true;
    }

    bool dfs(int node, vector<vector<int>>&list, vector<bool>&visited, vector<bool>&pathvisited){
        visited[node] = true;
        pathvisited[node] = true;
        
        for(auto it : list[node]){
            if(!visited[it]){
                if(dfs(it,list,visited,pathvisited)) return true;
            }else if(pathvisited[it] == true) return true;
        } 
        pathvisited[node] = false;
        return false;
    }
};

