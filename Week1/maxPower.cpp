// O(N) Time, O(1) Space

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        if(n <= 1) return n;
        
        int i = 0;
        int maxLen = 1;
        
        while(i < n) {
            char curr = s[i];
            int len = 1;
            
            while(i + 1 < n && s[i + 1] == curr) {
                i++;
                len++;
            }
            
            maxLen = max(maxLen, len);
            i++;
        }
        
        return maxLen;
    }
};