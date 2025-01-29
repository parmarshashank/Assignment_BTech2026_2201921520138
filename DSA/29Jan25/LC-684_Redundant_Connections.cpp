#include<bits/stdc++.h>

class DisjointSet{
    private:
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);
            size.resize(n+1, 1);
            for(int i=0; i<n+1; i++)
                parent[i]=i;
        }
        int findUParent(int node){
            if(node== parent[node])
                return node;
            return parent[node]= findUParent(parent[node]);
        }
        void unionByRank(int u, int v){
            int parU= findUParent(u);
            int parV= findUParent(v);
            if(parU==parV)  return;
            if(rank[parU]< rank[parV])
                parent[parU]= parV;
            else if(rank[parV]< rank[parU])
                parent[parV]= parU;
            else{
                parent[parU]= parV;
                rank[parV]++;
            }
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        DisjointSet ds(n);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            if(ds.findUParent(u)==ds.findUParent(v))
                return it;
            else
                ds.unionByRank(u, v);
        }
        return {};
    }
};