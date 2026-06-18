class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        // Start with the root node
        Node* leftMost = root;
        
        // Loop down the levels (stop when there are no children left)
        while (leftMost->left != nullptr) {
            Node* curr = leftMost;
            
            // Traverse the current level like a linked list
            while (curr != nullptr) {
                // Connection 1: Connect left child to right child
                curr->left->next = curr->right;
                
                // Connection 2: Connect right child to the next node's left child
                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }
                
                // Move to the next node on the current level
                curr = curr->next;
            }
            
            // Move down to the next level's leftmost node
            leftMost = leftMost->left;
        }
        
        return root;
    }
};