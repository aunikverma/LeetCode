/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr) {
                    ans += to_string(curr->val) + ",";
                    q.push(curr->left);
                    q.push(curr->right);
                } else {
                    ans += "null,";
                }
                n--;
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        // Splitting  string by ','
        vector<string> a;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            a.push_back(token);
        }

        if (a[0] == "null")
            return NULL; // root null

        TreeNode* root = new TreeNode(stoi(a[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < a.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (a[i] != "null") {
                curr->left = new TreeNode(stoi(a[i]));
                q.push(curr->left);
            }
            i++;

            if (i < a.size() && a[i] != "null") {
                curr->right = new TreeNode(stoi(a[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;