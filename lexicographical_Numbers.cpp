class Solution {
private:
    void pushme(int a , const int& n , vector<int>& result) {
        if(a>n) return; //base case

        int runs = a==1 ? 8 : 9 ;
        for(int i = 0 ; i <=runs && (a+i)<=n ; i++) {
            result.push_back(a+i);
            pushme((a+i)*10,n,result);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        pushme(1,n,result);
        return result;
    }
};