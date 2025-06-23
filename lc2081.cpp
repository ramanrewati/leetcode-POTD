class Solution {
public:
    bool isKMirror(long long num ,const int k) {
        string s="";
        while(num) {
            s += to_string((num%k));
            num/=k;
        }
        int i = 0 , j = s.size()-1;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++ , j--;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        int start = 1 , count = 0;
        long long res = 0;
        while(count<n) {
            //op==0 -> odd length & op==1 -> even length
            for(int op = 0 ; op<2 ; op++) {
                for(int i = start ; i < start*10 && count<n ; i++) {
                    long long x = i;
                    int to_add = op==0 ? i/10 : i;
                    while(to_add) {
                        x = x*10 + to_add%10;
                        to_add /= 10;
                    }
                    if(isKMirror(x,k)) {
                        count++;
                        res += x;
                    }
                }
            }
            start*=10;
        }
        return res;
    }
};