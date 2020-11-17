class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        
        int i = 0, ans = 0;
        
        while(i < n) {
            int base = i;
            
            while(i + 1 < n && A[i] < A[i + 1])
                i++;
            
            if(i == base) {
                i++;
                continue;
            }
            
            int peak = i;
            
            while(i + 1 < n && A[i] > A[i + 1])
                i++;
            
            if(i == peak)
                continue;
            
            ans = max(ans, i - base + 1);
        }
        
        return ans;
    }
};