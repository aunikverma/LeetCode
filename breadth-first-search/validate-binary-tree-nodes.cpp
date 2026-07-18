class Solution {
private:
    bool dfs(vector<bool>& visited, int node, vector<int>& leftChild,
             vector<int>& rightChild) {
        if (visited[node])
            return false; // Cycle detected
        visited[node] = true;
        if (leftChild[node] != -1 &&
            !dfs(visited, leftChild[node], leftChild, rightChild))
            return false;
        if (rightChild[node] != -1 &&
            !dfs(visited, rightChild[node], leftChild, rightChild))
            return false;
        return true;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                                 vector<int>& rightChild) {
        vector<int> indeg(n, 0); // indeg
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1)
                indeg[leftChild[i]]++;
            if (rightChild[i] != -1)
                indeg[rightChild[i]]++;
        }

        // Find the root (node with indegree 0)
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                if (root != -1)
                    return false; // More than one root
                root = i;
            } else if (indeg[i] > 1) {
                return false; // Node has more than one parent
            }
        }
        if (root == -1)
            return false; // No root found

        vector<bool> visited(n, false);
        // DFS to check for cycles and connectivity
        if (!dfs(visited, root, leftChild, rightChild))
            return false;

        // Check if all nodes are visited (connected)
        for (bool v : visited) {
            if (!v)
                return false;
        }

        return true;
    }
};