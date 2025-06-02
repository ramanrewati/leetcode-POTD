class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n) , right(n);
        left[0] = 1;
        right[n-1] = 1;
        //populate the left neighbour
        for(int i = 1 ; i < n ; i++) 
            left[i] = (ratings[i] > ratings[i-1]) ? left[i-1]+1 : 1;
        //populate the right neighbour
        for(int i = n-2 ; i >= 0 ; i--) {
            right[i] = (ratings[i] > ratings[i+1]) ? right[i+1]+1 : 1;
        }
        //calculate and return candies
        int numCandies = 0;
        for(int i = 0 ; i < n ; i++) 
            numCandies += max(left[i],right[i]);

        return numCandies;
    }
};