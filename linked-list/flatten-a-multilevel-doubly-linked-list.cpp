/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    void getnodes(Node* temp, vector<int>& ans) {
        if (temp == NULL) { // if temp null return
            return;
        }
        if (!temp->child) {            // if child not exist
            ans.push_back(temp->val);  // add val to ans
            getnodes(temp->next, ans); // and call for next nodes
        } else {
            ans.push_back(temp->val);   // if child exist add parent
            getnodes(temp->child, ans); // call for child
            getnodes(temp->next, ans);  // call for next
        }
    }

public:
    Node* flatten(Node* head) {
        vector<int> ans;
        if (head == NULL) {
            return head; // base case
        }
        Node* temp = head;
        getnodes(temp, ans);           // getting nodes is ans
        Node* curr = new Node(ans[0]); // creating new doubly list
        head = curr;
        for (int i = 1; i < ans.size(); i++) {
            Node* newnode = new Node(ans[i]);
            newnode->prev = curr;
            curr->next = newnode;
            curr = curr->next;
        }
        return head;
    }
};