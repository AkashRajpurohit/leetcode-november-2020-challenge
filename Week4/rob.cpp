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
    
    int robHelper(TreeNode* node, unordered_map<TreeNode*, int>& robMap) {
        if(node == NULL) return 0;
        
        if(robMap.count(node) > 0) return robMap.at(node);
        
        
        int withoutNode = robHelper(node->left, robMap) + robHelper(node->right, robMap);
        
        int withNode = node->val;
        if(node->left) {
            withNode += robHelper(node->left->left, robMap);
            withNode += robHelper(node->left->right, robMap);
        }
        if(node->right) {
            withNode += robHelper(node->right->left, robMap);
            withNode += robHelper(node->right->right, robMap);
        }
        
        robMap[node] = max(withNode, withoutNode);
        return robMap[node];
            
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> robMap;
        return robHelper(root, robMap);
    }
};