class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size() , numCandies = 0;
        queue<int> currBoxes;
        for(auto& ini : initialBoxes)
            currBoxes.push(ini);
        int nb = currBoxes.size();
        while(!currBoxes.empty()) {
            bool isHalt = true;
            for(int i = 0 ; i < nb ; i++) {
                int currBox = currBoxes.front();
                currBoxes.pop();
                if(status[currBox]==1) {
                    isHalt = false;
                    //acquire candies
                    numCandies += candies[currBox];
                    //acquire keys
                    for(auto&key : keys[currBox])
                        status[key] = 1;
                    //get contained boxes
                    for(auto&contained : containedBoxes[currBox])
                        currBoxes.push(contained);
                }
                else
                    currBoxes.push(currBox);
            }
            if(isHalt) break;
            nb = currBoxes.size();
        }
        return numCandies;
    }
};