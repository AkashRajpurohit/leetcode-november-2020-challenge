class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> s;
        
        for(int i = 0; i < k; ++i) {
            s.insert(nums[i]);
        }
        
        res.push_back(*(s.rbegin()));
        
        for(int i = k; i < nums.size(); ++i) {
            s.erase(s.find(nums[i - k]));
            s.insert(nums[i]);
            res.push_back(*(s.rbegin()));
        }
        
        return res;
    }
};