class Solution {
public:
    bool bfs(int node, vector<vector<int>>&graph, vector<int> &col){
        queue<pair<int,int>> q;
        col[node]=1;
        q.push({node,1});
        while(!q.empty()){
            int par=q.front().first;
            int color=q.front().second;
            q.pop();
            for(auto child: graph[par]){
                if(col[child]==-1){
                    col[child]=!color;
                    q.push({child,!color});
                }
                if(col[child]==color)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(bfs(i,graph,col)==false)
                    return false;
            }
        }
        return true;
    }
};