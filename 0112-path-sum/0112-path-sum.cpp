#include <algorithm>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the tree is empty, no path can exist
        if (root == nullptr) {
            return false;
        }
        
        // If it's a leaf node, check if the remaining targetSum matches the node's value
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        // Recursively check the left and right subtrees with the updated targetSum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};