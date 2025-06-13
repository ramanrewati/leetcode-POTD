class Solution {
private:
    bool isValid(int thresh, const vector<int>& nums, const int p) {
        int cnt = 0;
        for(int i = 0 ; i < nums.size()-1 ; ) {
            if(abs(nums[i] - nums[i+1]) <= thresh)
                cnt++ , i += 2;
            else i++;
            if(cnt==p) return true;
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        if(p==0) return 0;
        int l = 0 , h = 1e9 , res = 0;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(isValid(mid,nums,p)) 
                res = mid , h = mid - 1;
            else l = mid + 1;
        }
        return res;
    }
};