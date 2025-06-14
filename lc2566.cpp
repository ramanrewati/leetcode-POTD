class Solution {
public:
    int minMaxDifference(int num) {
        string number = to_string(num);
        int maxi = 0 , mini = 0 , n = number.size();
        int minChange = number[0]-'0' , j = 0;
        while(j < n && number[j] == 9 + '0') j++;
        int maxChange = number[j]-'0';
        for(int i = 0 ; i < n ; i++) {
            int currDigit = number[i] - '0';
            maxi = (currDigit==maxChange) ? maxi*10 + 9 : maxi*10 + currDigit ;
            mini = (currDigit==minChange) ? mini*10 + 0 : mini*10 + currDigit ;
        }
        return maxi - mini ;
    }
};