/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create copied nodes and insert them
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied list
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        curr = head;

        while (curr) {
            Node* copy = curr->next;

            curr->next = copy->next;
            copyCurr->next = copy;
            copyCurr = copy;

            curr = curr->next;
        }

        return dummy->next;
    }
};