// Approach 1 - Set
class Solution {
private:
    void permute(set<vector<int>>& s, vector<int>& nums, int start) {
        if(start == nums.size()) {
            s.insert(nums);
        } else {
            for(int i = start; i < nums.size(); ++i) {
                swap(nums[i], nums[start]);
                permute(s, nums, start + 1);
                swap(nums[i], nums[start]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        permute(s, nums, 0);
        
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};

// Approach Two - Map to avoid unnecessary calls
class Solution {
private:
    void permute(map<int, int>& m, vector<vector<int>>& result, vector<int>& temp, int start) {
        if(start == temp.size()) {
            result.push_back(vector<int>(temp.begin(), temp.end()));
        } else {
            for(auto &x: m) {
                if(x.second > 0) {
                    m[x.first] = x.second - 1;
                    temp[start] = x.first;
                    permute(m, result, temp, start + 1);
                    m[x.first] = x.second + 1;
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> m;
        vector<int> temp(nums.size());
        
        for(int num: nums)
            m[num]++;
        
        permute(m, result, temp, 0);
        return result;
    }
};