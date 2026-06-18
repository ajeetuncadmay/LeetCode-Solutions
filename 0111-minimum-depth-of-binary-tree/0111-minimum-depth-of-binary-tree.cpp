#include <queue>
#include <algorithm>

class Solution {
public:
    int minDepth(TreeNode* root) {
        // Base case: If the tree is empty, depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Queue for BFS: stores pairs of {node, current_depth}
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            
            // If we reach a leaf node, return its depth immediately
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            
            // If left child exists, push it to the queue with depth + 1
            if (node->left != nullptr) {
                q.push({node->left, depth + 1});
            }
            
            // If right child exists, push it to the queue with depth + 1
            if (node->right != nullptr) {
                q.push({node->right, depth + 1});
            }
        }
        
        return 0;
    }
};