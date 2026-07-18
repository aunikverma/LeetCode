class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int max_width = 1; //min width
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int level_size = q.size();
            int start_index = q.front().second; //level start index
            int end_index = q.back().second;
            max_width = max(max_width, end_index - start_index + 1); //max width
            
            for (int i = 0; i < level_size; ++i) {
                auto node_index_pair = q.front();
                TreeNode* node = node_index_pair.first;
                int node_index = node_index_pair.second - start_index;
                q.pop();
                if (node->left != nullptr) { //left child 2*i + 1
                    q.push({node->left, 2LL * node_index + 1});
                }
                if (node->right != nullptr) { // right child 2*i + 2
                    q.push({node->right, 2LL * node_index + 2});
                }
            }
        }
        return max_width;
    }
};