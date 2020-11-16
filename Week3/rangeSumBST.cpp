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
    void calculateSum(TreeNode* root, int low, int high, int& sum) {
        if(root == NULL) return;
        
        calculateSum(root->left, low, high, sum);
        
        // No point going beyound this
        if(root->val > high) return;
        if(root->val >= low && root->val <= high)
            sum += root->val;
        
        calculateSum(root->right, low, high, sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        calculateSum(root, low, high, sum);
        return sum;
    }
};