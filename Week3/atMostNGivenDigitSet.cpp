// Ref: https://www.youtube.com/watch?v=nqCM8opotjU

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int num) {
        sort(digits.begin(), digits.end());
        string numStr = to_string(num);
        
        int n = numStr.size(), dN = digits.size();
        int count = 0;
        
        for(int i = 1; i < n; ++i) {
            count += pow(dN, i);
        }
        
        int i = 0;
        while(i < n) {
            int j = 0;
            
            while(j < dN && digits[j][0] < numStr[i]) {
                count += pow(dN, n - 1 - i);
                j++;
            }
            
            if(j == dN || digits[j][0] > numStr[i]) {
                return count;
            }
            
            i++;
        }
        
        count++;
        return count;
    }
};