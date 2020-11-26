class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int remainder = 0;
        
        for(int len = 1; len <= K; ++len) {
            remainder = ((remainder * 10) + 1) % K;
            
            if(remainder == 0)
                return len;
        }
        
        return -1;
    }
};