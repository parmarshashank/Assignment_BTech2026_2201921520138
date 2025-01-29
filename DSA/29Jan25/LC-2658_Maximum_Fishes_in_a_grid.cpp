#define pi pair<int, int>
class Solution {
private:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size())
            return true;
        return false;
    }

    int bfs(vector<vector<int>> &grid, pi start, vector<vector<int>> &visited){
        int fish=0;
        queue<pi> q;
        q.push(start);
        visited[start.first][start.second]=1;
        vector<pi> dirs= {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(!q.empty()){
            auto [x, y]= q.front();
            q.pop();
            fish+= grid[x][y];
            for(auto &[dx, dy]: dirs){
                int newX= x+dx;
                int newY= y+dy;
                if(isValid(newX, newY, grid) && !visited[newX][newY] && grid[newX][newY]>0){
                    q.push({newX, newY});
                    visited[newX][newY]=1;
                }
            }
        }
        return fish;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxFish=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]>0){
                    int fishes= bfs(grid, {i, j}, visited);
                    maxFish= max(fishes, maxFish);
                }
            }
        }
        return maxFish;
    }
};