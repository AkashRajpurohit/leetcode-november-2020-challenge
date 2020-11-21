class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        
        int low = 0, high = n - 1, mid, first = nums[0];
        
        while(low <= high) {
            
            while(low < high && nums[low] == nums[low + 1])
                low++;
            
            while(low < high && nums[high] == nums[high - 1])
                high--;
            
            
            mid = low + (high - low) / 2;
            int value = nums[mid];
            
            if(value == target) return true;
            
            bool am_big = value >= first;
            bool target_big = target >= first;
            
            if(am_big == target_big) {
                if(value < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if(am_big) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};