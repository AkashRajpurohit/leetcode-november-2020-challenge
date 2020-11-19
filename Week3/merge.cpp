class Solution {
public:
    static bool compare(vector<int> I1, vector<int> I2) {
        return I1[0] == I2[0] ? I1[1] < I2[1] : I1[0] < I2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;
        
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare);
        
        int i = 0;
        res.push_back(intervals[i]);
        
        for(int j = 1; j < n; ++j) {
            vector<int>& interval = res.at(i);
            
            if(intervals[j][0] <= interval[1]) {
                interval[1] = max(intervals[j][1], interval[1]);
            } else {
                res.push_back(intervals[j]);
                i++;
            }
        }
        
        return res;
    }
};