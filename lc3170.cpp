class Solution {
public:
    string clearStars(string s) {
        unordered_set<int> deleted;
        vector<int> track[26];
        for(int i=0;i<s.size();i++) {
            if(s[i]=='*') {
                for(int j=0;j<26;j++) {
                    if(track[j].size()>0) {
                        deleted.insert(track[j].back());
                        deleted.insert(i);
                        track[j].pop_back();
                        break;
                    }
                }
            }
            else 
                track[s[i]-97].push_back(i);
        }
        string ans="";
        for(int i=0;i<s.size();i++) {
            if(deleted.find(i)==deleted.end())
                ans.push_back(s[i]);
        }
        return(ans);
    }
};