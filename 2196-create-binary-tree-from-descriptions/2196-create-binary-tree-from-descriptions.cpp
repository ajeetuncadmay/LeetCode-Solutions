#include <vector>
#include <unordered_map>
#include <unordered_set>

// Definition for a binary tree node.
// (Omitted if pasting directly into LeetCode)
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/

class Solution {
public:
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
        // Maps node value to the actual TreeNode pointer
        std::unordered_map<int, TreeNode*> nodeMap;
        // Tracks all values that are children
        std::unordered_set<int> children;
        
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];
            
            // If parent node doesn't exist, create it
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            
            // If child node doesn't exist, create it
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }
            
            // Link parent and child
            if (isLeft == 1) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }
            
            // Mark this value as a child
            children.insert(childVal);
        }
        
        // Find the root (the node value that is never in the children set)
        TreeNode* root = nullptr;
        for (const auto& pair : nodeMap) {
            int currentVal = pair.first;
            if (children.find(currentVal) == children.end()) {
                root = pair.second;
                break;
            }
        }
        
        return root;
    }
};