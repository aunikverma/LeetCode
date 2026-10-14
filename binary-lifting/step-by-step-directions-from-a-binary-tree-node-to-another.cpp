class Solution {
private:
    TreeNode* createmapping(TreeNode* root,
                            unordered_map<TreeNode*, TreeNode*>& nodetoparent,
                            int start) {
        TreeNode* targetnode = NULL;
        queue<TreeNode*> q;
        q.push(root); // using bfs
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->val == start) {
                targetnode = curr; // starting node
            }
            if (curr->left) { // left
                nodetoparent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) { // right
                nodetoparent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetnode; // return starting node
    }

    void solve(TreeNode* root,
               unordered_map<TreeNode*, TreeNode*>& nodetoparent,
               unordered_map<TreeNode*, bool>& visited, int dest, string& path,
               string& ans) {
        if (root->val == dest) { // when equal
            if (ans.empty()) {   // if empty
                ans = path;
            } else { // else min
                ans = min(path, ans);
            }
            return;
        }
        visited[root] = true;
        if (root->left && !visited[root->left]) {
            path += "L"; // left
            solve(root->left, nodetoparent, visited, dest, path, ans);
            path.pop_back();
        }
        if (root->right && !visited[root->right]) {
            path += "R"; // right
            solve(root->right, nodetoparent, visited, dest, path, ans);
            path.pop_back();
        }
        if (nodetoparent[root] && !visited[nodetoparent[root]]) {
            path += "U"; // parent
            solve(nodetoparent[root], nodetoparent, visited, dest, path, ans);
            path.pop_back();
        }
    }

public:
    string getDirections(TreeNode* root, int start, int dest) {
        unordered_map<TreeNode*, TreeNode*> nodetoparent;
        TreeNode* target =
            createmapping(root, nodetoparent, start); // node to parent
        unordered_map<TreeNode*, bool> visited;       // visited
        string path = "";
        string ans = "";
        solve(target, nodetoparent, visited, dest, path, ans);
        return ans;
    }
};