class Solution {
public:
    static bool compare(pair<int, int> ev1, pair<int, int> ev2) {
        if(ev1.first == ev2.first) 
            return ev1.second > ev2.second;
        
        return ev1.first < ev2.first;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {        
        typedef pair<int, int> Event;
        vector<Event> events;
        for(auto a: buildings){
            events.emplace_back(a[0], a[2]);
            events.emplace_back(a[1], -a[2]);
        }
        
        sort(events.begin(), events.end(), compare);
        
        vector<vector<int>> ans;
        for(const auto& ev: events){
            int x = ev.first;
            int h = ev.second;
            bool enter = h > 0;
            h = abs(h);
            
            if(enter){
                if(h > maxHeight())
                    ans.push_back({x, h});
                hs_.insert(h);
            }else{
                hs_.erase(hs_.equal_range(h).first);
                if(h > maxHeight())
                    ans.push_back({x, maxHeight()});
            }
        }
        return ans;
    }
    
private:
    multiset<int> hs_;
    int maxHeight(){
        return hs_.empty() ? 0 : *hs_.rbegin();
    } 
};