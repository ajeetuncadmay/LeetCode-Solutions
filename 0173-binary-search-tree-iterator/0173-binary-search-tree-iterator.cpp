#include <stack>

class BSTIterator {
private:
    std::stack<TreeNode*> myStack;

    // Helper function to push all left children of a given node
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        // Initialize the stack by loading the leftmost path
        pushAllLeft(root);
    }
    
    int next() {
        // The top of the stack is the next smallest element
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        
        // If the popped node has a right child, process its left children
        if (tmpNode->right != nullptr) {
            pushAllLeft(tmpNode->right);
        }
        
        return tmpNode->val;
    }
    
    bool hasNext() {
        // If the stack is not empty, we still have elements to visit
        return !myStack.empty();
    }
};