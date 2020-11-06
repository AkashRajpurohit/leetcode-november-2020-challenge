class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> degree(n);
        vector<vector<int>> adjList(n, vector<int>());
        
        for(vector<int> e: edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; ++i) {
            if(degree[i] == 1) 
                q.push(i);
        }
        
        // Max 2 MHT are possible
        while(n > 2) {
            int size = q.size();
            n -= size;
            
            while(size-- > 0) {
                
                int v = q.front();
                q.pop();
                
                for(int i: adjList.at(v)) {
                    degree[i]--;
                    if(degree[i] == 1)
                        q.push(i);
                }
                
            }
        }
        
        vector<int> res;
        
        while(!q.empty()) {
            int val = q.front();
            q.pop();
            
            res.push_back(val);
        }
        
        return res;
    }
};