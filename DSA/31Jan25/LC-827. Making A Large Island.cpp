class DisjointSet{
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n){
            rank.resize(n, 0);
            parent.resize(n, 0);
            size.resize(n, 1);
            for(int i=0; i<n; i++)
                parent[i]=i;
        }
        int findUParent(int node){
            if(node== parent[node])
                return node;
            return parent[node]= findUParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int parU= findUParent(u);
            int parV= findUParent(v);
            if(parU==parV)  return;
            if(size[parU]< size[parV]){
                parent[parU]=parV;
                size[parV]+=size[parU];
            }
            else{
                parent[parV]=parU;
                size[parU]+=size[parV];
            }
        }
};
class Solution {
private:
    bool isValid(int x, int y, int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        DisjointSet ds(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                int dx[]= {0, 0, -1, 1};
                int dy[]= {1, -1, 0, 0};
                for(int k=0; k<4; k++){
                    int x= i+dx[k];
                    int y= j+ dy[k];
                    if(isValid(x, y, n) && grid[x][y]==1){
                        int node= i*n+j;
                        int newNode= x*n+ y;
                        ds.unionBySize(node, newNode);
                    }
                }
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                int dx[]= {0, 0, -1, 1};
                int dy[]= {1, -1, 0, 0};
                unordered_set<int> st;
                for(int k=0; k<4; k++){
                    int x= i+dx[k];
                    int y= j+ dy[k];
                    if(isValid(x, y, n) && grid[x][y]==1){
                        int node= x*n+y;
                        st.insert(ds.findUParent(node));
                    }
                }
            
            int total=0;
            for(auto it: st){
                total+= ds.size[it];
            }
            res= max(res, total+1);
        }}
        for(int i=0; i<n*n; i++){
            res= max(res, ds.size[ds.findUParent(i)]);
        }
        return res;
    }
};