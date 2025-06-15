class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if(pos != string::npos) {
            char a = s[pos];
            replace(s.begin(),s.end(),a,'9');
        }
        if(t[0]!='1') {
            char b = t[0];
            replace(t.begin(),t.end(),b,'1');
        }
        else {
            int i=1 , n = t.size();
            for(i ; i < n && (t[i]==t[0] || t[i]=='0' ) ; i++);

            if(i==n) {
                char b = t[0];
                replace(t.begin(),t.end(),b,'1');
            }
            else {
                char b = t[i];
                replace(t.begin(),t.end(),b,'0');
            }
        }
        return stoi(s) - stoi(t);
    }
};