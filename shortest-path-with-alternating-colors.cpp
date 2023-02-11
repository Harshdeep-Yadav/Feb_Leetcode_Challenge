class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // red->0
        // blue->1
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: redEdges){
            adj[it[0]].push_back({it[1],0});
        }
         for(auto it: blueEdges){
            adj[it[0]].push_back({it[1],1});
        }
        vector<int>ans(n,-1);
        vector<vector<bool>>vis(n,vector<bool>(2));
        queue<vector<int>>q;
        
        q.push({0,0,-1}); // node ,steps, color 
         vis[0][0]=true;
        vis[0][1]=true;
        ans[0]=0;
        // bfs
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int node =it[0];
            int steps=it[1];
            int prevC=it[2];
            
            for(auto &[neighbour,color]:adj[node]){
                if(!vis[neighbour][color]&&color!=prevC){
                    vis[neighbour][color]=true;
                    q.push({neighbour,steps+1,color});
                    if(ans[neighbour]==-1){
                        ans[neighbour]=1+steps;
                    }                }
            }
        }
        return ans ;
    }
    
};