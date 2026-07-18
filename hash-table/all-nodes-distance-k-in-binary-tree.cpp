class Solution {
private:
    void
    createparentmapping(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& nodetoparent) {
        queue<TreeNode*> q;
        q.push(root); // using bfs level order
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) {                    // left
                nodetoparent[temp->left] = temp; // node to parent mapping
                q.push(temp->left);
            }
            if (temp->right) { // right
                nodetoparent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> solve(TreeNode* root, int k,unordered_map<TreeNode*, TreeNode*>& nodetoparent) {
        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*, int>> q;
        vector<int> ans; // node at distance k
        q.push({root, k});
        visited[root] = true; // target node
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [curr, d] = q.front(); // node : distance
                q.pop();
                if (d == 0)
                    ans.push_back(curr->val); // ans
                if (curr->left && !visited[curr->left]) {
                    q.push({curr->left, d - 1});
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push({curr->right, d - 1});
                    visited[curr->right] = true;
                }
                if (nodetoparent[curr] && !visited[nodetoparent[curr]]) {
                    q.push({nodetoparent[curr], d - 1});
                    visited[nodetoparent[curr]] = true;
                }
            }
        }
        return ans;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> nodetoparent;
        createparentmapping(root, nodetoparent);
        return solve(target, k, nodetoparent);
    }
};