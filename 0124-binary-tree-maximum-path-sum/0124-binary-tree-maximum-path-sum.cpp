#include <algorithm>
#include <climits>

class Solution {
private:
    int globalMaxSum;

    int maxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        // Step 1: Recursively calculate the maximum gain from left and right subtrees.
        // If the path sum from a subtree is negative, we ignore it by capping at 0.
        int leftGain = std::max(maxGain(node->left), 0);
        int rightGain = std::max(maxGain(node->right), 0);

        // Step 2: Calculate the total path sum if this node acts as the "turning point" (root) of the path
        int currentPathSum = node->val + leftGain + rightGain;

        // Update our global maximum if the current path is the largest seen so far
        globalMaxSum = std::max(globalMaxSum, currentPathSum);

        // Step 3: For the parent's recursive call, this node can only choose ONE child path to continue up
        return node->val + std::max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        globalMaxSum = INT_MIN; // Initialize with the smallest possible integer
        maxGain(root);
        return globalMaxSum;
    }
};