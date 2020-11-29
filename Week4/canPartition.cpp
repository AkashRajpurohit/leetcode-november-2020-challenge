class Solution {
private:
    bool helper(vector<int>& nums, int n, int target) {
        bool dp[n + 1][target + 1];
        
        for(int i = 0; i <= n; ++i)
            dp[i][0] = true;
        
        for(int i = 1; i <= target; ++i)
            dp[0][i] = false;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                
                if(j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]]) {
                    dp[i][j] = true;
                }
            }
        }
        
        return dp[n][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int num: nums)
            sum += num;
        
        if(sum & 1 == 1)
            return false;
        
        return helper(nums, n, sum / 2);
    }
};