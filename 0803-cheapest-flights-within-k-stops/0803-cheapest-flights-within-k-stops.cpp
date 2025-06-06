class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights,
                       int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q; // queue -> stops , node reached , price
        vector<int>minPrice(n,1e9);

        minPrice[src] = 0;
        q.push({0,{src,0}}); 

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if(stops > K) continue;

            for(auto it : adj[node]){
                int adjele = it.first;
                int new_price = it.second;

                if(price + new_price < minPrice[adjele] && stops <= K){
                    minPrice[adjele] = price + new_price;
                    q.push({stops+1,{adjele,price + new_price}});
                }
            }
        }

        if(minPrice[dst] == 1e9){
            return -1;
        }

        return minPrice[dst];
    }
};
