class Solution {
public:
    string robotWithString(string s) {
        //map all characters
        vector<int> freq(26,0);
        for(auto& ch:s)
            freq[ch-'a']++;
        int currMin = 0;
        while(currMin < 26 && freq[currMin]==0) currMin++;
        //monotonic stack
        stack<char> st;
        string res = "";
        for(auto& ch : s) {
            freq[ch-'a']--;
            st.push(ch);
            while(currMin < 26 && freq[currMin]==0) 
                currMin++;
            while(!st.empty() && st.top() <= currMin+'a') {
                res += st.top();
                st.pop();
            }
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};