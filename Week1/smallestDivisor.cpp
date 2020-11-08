class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {        
        int left = 1, right = 1e6;
        int sum = 0;
        int mid, ans;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            sum = 0;
            
            for(int num: nums)
                sum += ceil((float)(num) / (float)(mid));
            
            if(sum <= threshold) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};