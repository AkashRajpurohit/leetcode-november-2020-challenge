class Solution {
private:
    int distance(vector<int> a, vector<int> b) {
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        
        return x*x + y*y;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s;
        
        s.insert(distance(p1, p2));
        s.insert(distance(p2, p3));
        s.insert(distance(p3, p4));
        s.insert(distance(p1, p4));
        
        s.insert(distance(p1, p3));
        s.insert(distance(p2, p4));
        
        return s.find(0) == s.end() && s.size() == 2;
    }
};