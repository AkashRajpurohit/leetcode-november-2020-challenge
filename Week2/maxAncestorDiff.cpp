/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result = 0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return result;
    }
    
    void dfs(TreeNode* root, int currMin, int currMax) {
        if(root == NULL) return;
        
        result = max(result, max(abs(root->val - currMin), abs(root->val - currMax)));
        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);
        
        dfs(root->left, currMin, currMax);
        dfs(root->right, currMin, currMax);
    }
};