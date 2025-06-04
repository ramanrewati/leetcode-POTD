class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int window = word.size() - (numFriends-1); //max length of the window
        int n = word.size();
        char maxChar = 'a';
        //get maxChar
        for(auto& c : word)
            maxChar = max(c,maxChar);
        //formulate result
        string result="";
        for(int i = 0 ; i < n ; i++) {
            if(word[i]==maxChar) {
                string cur="";
                int j = i;
                while(j<n && (j-i)<window)
                    cur += word[j] , j++ ;
                if(cur > result)
                    result = cur;
            }
        }
        return result;
    }
};