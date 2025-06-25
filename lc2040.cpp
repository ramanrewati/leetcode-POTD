typedef long long ll;

class Solution {
public:
    bool isValid(const ll x,const vector<int>& nums1,const vector<int>& nums2,const ll k) {
        /* this fxn will return if there are atleast k pairs of products
            for a given x using binary search efficiently */
        ll count = 0 , n2 = nums2.size();
        for(ll a:nums1) {
            if(a==0) {
                if(x>=0) count += n2;
            }
            else if(a>0) {
                //a*b<=x -> b<=x/a
                ll val = x/a;
                if((x^a)<0 && x%a!=0) --val;
                count += upper_bound(nums2.begin(),nums2.end(),val) - nums2.begin(); 
            }
            else {
                //b>=ceil(x/a)
                ll val = x/a;
                if((x^a)>0 && x%a!=0) ++val;
                count += nums2.end() - lower_bound(nums2.begin(),nums2.end(), val);
            }

            if(count>=k) return true;
        }
        return count>=k;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        /* This is a classial binary search problem on answer space
            here the search space will be from min product to max product
            for each mid element we have to efficiently check if their exists
            atleast k product pairs greater than or equal to the element */
        
        //defining the search space
        ll Amin = nums1.front() , Amax = nums1.back() , Bmin = nums2.front() , Bmax = nums2.back();
        ll low = min({Amin*Bmin , Amin*Bmax , Amax*Bmin , Amax*Bmax});
        ll high = max({Amin*Bmin , Amin*Bmax , Amax*Bmin , Amax*Bmax});

        //performing binary search
        ll res = low;
        while(low<=high) {
            ll mid = low + (high-low)/2;
            if(isValid(mid,nums1,nums2,k)) res = mid , high = mid-1;
            else low = mid+1;
        }
        return res;
    }
};