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
private:
    int tilt(TreeNode* root, int& result) {
        if(root == NULL) return 0;
        
        int left = tilt(root->left, result);
        int right = tilt(root->right, result);
        
        result += abs(left - right);
        
        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int result = 0;
        tilt(root, result);
        return result;
    }
};