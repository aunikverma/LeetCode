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
        unordered_map<Node*, Node*> mp;
        Node* node = head;
        Node* clonehead = new Node(-1);
        Node* curr = clonehead;
        while (node != NULL) {
            Node* newnode = new Node(node->val);
            curr->next = newnode;
            mp[node] = newnode;
            node = node->next; //copying structure list and mapping them
            curr = curr->next;
        }
        node = head;
        curr = clonehead->next;
        while (node != NULL) {//now setting random with help of map
            if (node->random != NULL) {
                curr->random = mp[node->random];
            } else {
                curr->random = NULL;
            }
            node = node->next;
            curr = curr->next;
        }
        return clonehead->next;
    }
};