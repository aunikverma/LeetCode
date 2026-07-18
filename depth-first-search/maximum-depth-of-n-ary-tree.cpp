/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        // int ans = 0;
        // queue<Node*> q;
        // q.push(root);
        // while (!q.empty()) {
        //     Node* curr = NULL;
        //     int n = q.size();
        //     ans++; //adding when moving to other level
        //     while (n) {
        //         curr = q.front();
        //         q.pop();
        //         for (auto i : curr->children) {
        //             q.push(i); //adding all children nodes
        //         }
        //         n--;
        //     }
        // }
        // return ans; 

        //recursicve soln
        int depth = 0;
        for(auto i : root->children) depth = max(depth,maxDepth(i));
        return 1+depth;
    }
};