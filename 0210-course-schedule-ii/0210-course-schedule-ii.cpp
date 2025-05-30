

class Solution {
  public: 
  vector<int>findOrder(int N, vector<vector<int>>&arr) {
     vector<vector<int>>list(N);
     vector<int>indegree(N,0);
      
      for(auto node : arr){
        list[node[1]].push_back(node[0]);
      }
    for(int i=0; i<N; i++){
        for(auto it : list[i]){
        indegree[it]++;
      }
    }
      
    vector<int>order;

    order = toposort(indegree,N,list);

    return order.size() == N ? order : vector<int>(); 
  }

vector<int>toposort(vector<int>&indegree,int N,vector<vector<int>>&list){
    vector<int>ans;
    queue<int>q;

    for(int i=0;i<N;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : list[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return ans;
}
};

