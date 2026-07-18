/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        unordered_map<Node*, Node*> adj; // node ->clone node
        adj[node] = new Node(node->val); // creating first new node
        queue<Node*> q;
        q.push(node); // first node
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (auto& i : curr->neighbors) {   // check neigh of first
                if (adj.find(i) == adj.end()) { // if neigh not in map
                    adj[i] = new Node(i->val);  // clone node
                    q.push(i);                  // passing old node
                }
                adj[curr]->neighbors.push_back(
                    adj[i]); // clone node->neigh me add krdo
            }
        }
        return adj[node]; // returning first node
    }
};