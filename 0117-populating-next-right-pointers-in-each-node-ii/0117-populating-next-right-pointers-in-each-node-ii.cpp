class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        Node* curr = root; // Tracks the current node on the current level
        
        while (curr != nullptr) {
            Node dummy(0);      // Dummy node to start the next level's linked list
            Node* tail = &dummy; // Tail to append nodes to the next level
            
            // Traverse the current level
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                // Move to the next node on the current level
                curr = curr->next;
            }
            
            // Move down to the start of the next level
            curr = dummy.next;
        }
        
        return root;
    }
};