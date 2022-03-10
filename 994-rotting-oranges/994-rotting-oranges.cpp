class Solution {
public:
    bool check(int x, int y,vector<vector<int>> &grid){
        int rows = grid.size();
        int cols = grid[0].size();
        if(x>=0 && y>=0 && x<rows && y<cols && grid[x][y]==1)
            return true;
        else
            return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int> (cols,0));
        int time=0;
        int totalCount = 0, rotCount=0;
        queue<pair<pair<int,int>,int>> q; // {{x,y},time}
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},time});
                    vis[i][j]=1;
                    rotCount++;
                }
                if(grid[i][j]!=0) totalCount++;
            }
        }
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            time = q.front().second;
            q.pop();
            for(int dir=0;dir<4;dir++){
                int newx = x+dx[dir];
                int newy = y+dy[dir];
                if(check(newx,newy,grid)){
                    grid[newx][newy]=2;
                    rotCount++;
                    q.push({{newx,newy},time+1});
                }
            }
        }
        if(rotCount==totalCount)
            return time;
        else
            return -1;
    }
};