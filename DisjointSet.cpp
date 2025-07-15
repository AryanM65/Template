#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent, rank, size;
    public:
    int components;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
        components = n;
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        //path compression and finding ultimate parent
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int pu = findUPar(u); //ultimate parent of u
        int pv = findUPar(v);  //ultimate parent of v
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u, int v){
        int pu = findUPar(u); //ultimate parent of u
        int pv = findUPar(v);  //ultimate parent of v
        if(pu == pv)return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        components--;
    }
};

int main(){

    return 0;
}