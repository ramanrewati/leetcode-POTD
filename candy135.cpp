class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //{rating,index}
        vector<int> candies(n+2,-1); //holds number of candies given to a  (i-1)'th child
        int numCandies=0;
        //insert all ratings along with it's index
        for(int i = 0 ; i < n ; i++)
            pq.push({ratings[i],i});
        
        //fill the candies in non-decreasing order
        while(!pq.empty()) {
            auto [currRating,i] = pq.top();
            pq.pop();

            if(i==0) 
                candies[i+1] = (ratings[i+1] < ratings[i]) ? candies[i+2]+1 : 1;
            else if(i==n-1)
                candies[i+1] = (ratings[i-1] < ratings[i]) ? candies[i]+1 : 1;
            else {
                if((ratings[i-1] < ratings[i]) && (ratings[i+1] < ratings[i]))
                    candies[i+1] = max(candies[i],candies[i+2])+1;
                else if(ratings[i-1] < ratings[i])
                    candies[i+1] = candies[i]+1;
                else if(ratings[i+1] < ratings[i])
                    candies[i+1] = candies[i+2]+1;
                else candies[i+1] = 1;
            }
            numCandies += candies[i+1];
        }
        return numCandies;
    }
};