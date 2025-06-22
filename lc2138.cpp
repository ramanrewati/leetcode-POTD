class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i = 0; i < s.size(); i+=k)
            res.push_back(s.substr(i,k));
        while(res[res.size()-1].size()<k)
            res[res.size()-1] += fill;
        return res;
    }
};