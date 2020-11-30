class Solution {
private:
    bool canReachHelper(vector<int>& arr, int start, unordered_map<int, bool>& dp, unordered_set<int>& inStack) {
        if(start < 0 || start >= arr.size())
            return false;
        
        if(arr[start] == 0)
            return true;
        
        if(inStack.count(start) > 0)
            return false;
        
        if(dp.count(start) > 0)
            return dp[start];
        
        
        inStack.insert(start);
        
        bool left = canReachHelper(arr, start - arr[start], dp, inStack);
        bool right = left || canReachHelper(arr, start + arr[start], dp, inStack);
        
        dp[start] = left || right;
        inStack.erase(start);
        
        return dp[start];
    }
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int, bool> dp;
        unordered_set<int> inStack;
        
        return canReachHelper(arr, start, dp, inStack);
    }
};