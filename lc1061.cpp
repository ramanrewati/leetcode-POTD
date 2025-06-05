class DisjointSet {
private:
    vector<int> par;
public:
    DisjointSet(int n) {
        par.resize(n);
        for(int i = 0 ; i < n ; i++) par[i] = i;
    }
    
    int find(int node) {
        if(par[node]==node) return node;
        else return par[node] = find(par[node]);
    }

    void unionBySize(int u , int v) {
        int ulp_u = find(u) , ulp_v = find(v);
        if(ulp_u==ulp_v) return;
        if(ulp_u < ulp_v)
            par[ulp_v] = ulp_u;
        else
            par[ulp_u] = ulp_v;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet dsu(26);
        for(int i = 0 ; i < s1.size() ; i++)
            dsu.unionBySize(s1[i]-'a',s2[i]-'a');
        string resStr = "";
        for(auto&ch:baseStr)
            resStr += (char)(dsu.find(ch-'a')+'a');
        return resStr;
    }
};