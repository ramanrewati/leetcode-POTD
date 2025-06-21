class Solution {
public:
    void count(int f1 , int f2 , int e1 , int e2 , vector<int>& k_cnt , vector<int>& mx) {
        mx[f1]++;
        mx[f2]++;

        mx[e1] += (k_cnt[e1]>0) ? 1 : -1;
        mx[e2] += (k_cnt[e2]>0) ? 1 : -1;
        k_cnt[e1]-- , k_cnt[e2]--;
    }
    int maxDistance(string s, int k) {
        if(s.size()==k) return k;
        int res=0;
        //0->NE , 1->NW , 2->SE , 3->SW
        vector<int> k_cnt(4,k) , mx(4);
        for(auto&c:s) {
            if(c=='N') count(0,1,2,3,k_cnt,mx);
            else if(c=='S') count(2,3,0,1,k_cnt,mx);
            else if(c=='E') count(0,2,1,3,k_cnt,mx);
            else count(1,3,0,2,k_cnt,mx);
            res = max({mx[0],mx[1],mx[2],mx[3],res});
        }
        return res;
    }
};