class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        
        for(vector<int>& row: A) {
            int l = 0, r = n - 1;
            
            while(l <= r) {
                int temp = row[l];
                row[l++] = row[r] ^ 1;
                row[r--] = temp ^ 1;
            }
        }
        
        return A;
    }
};