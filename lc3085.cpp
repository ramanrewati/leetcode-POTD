class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        int n=0;
        for(auto&ch:word)
            n = max((++freq[ch-'a']),n);
        int i = 0 , j = k , mini = INT_MAX;
        while(j<=n) {
            int cur = 0;
            for(int c = 0 ; c < 26 ; c++) {
                if(freq[c]>j)
                    cur += freq[c]-j;
                else if(freq[c]<i)
                    cur += freq[c]; 
            }
            mini = min(mini,cur);
            i++ , j++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};