class Solution {
private:
    int calc(long long a ,const int& n) {
        long long cur = a , next = a+1;
        int sz=0;
        while(cur<=n) {
            sz += min((long long)n+1 , next) - cur;
            next*=10;
            cur*=10;
        } 
        return sz;
    }
public:
    int findKthNumber(int n, int k) {
        int result = 1 , curK = 1;
        while(curK <= k) {
            if(curK==k) return result;
            int subSize = calc(1LL*result,n);
            if(subSize + curK > k) {
                result *= 10;
                curK++;
            }
            else {
                result += 1;
                curK += subSize;
            }
        }
        return result;
    }
};