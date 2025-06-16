class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = INT_MAX , res = INT_MIN;
        for(auto&num:nums){
            res= max(num-mini,res);
            mini = min(num,mini);
        }
        return res<=0 ? -1 : res;
    }
};