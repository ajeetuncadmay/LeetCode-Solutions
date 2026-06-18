class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            // If the current node has a left child
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                
                // Connect this rightmost node to the current node's right subtree
                prev->right = curr->right;
                
                // Move the left subtree to the right side
                curr->right = curr->left;
                curr->left = nullptr; // Clear the left pointer
            }
            
            // Move to the next node on the right
            curr = curr->right;
        }
    }
};