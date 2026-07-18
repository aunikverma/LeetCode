class Solution {
public:
    class Node {
    public:
        int ind;
        Node* children[26];

        // constructor
        Node(int i) {
            ind = i;
            memset(children, NULL, sizeof(children));
        }

        // insert function
        void insert(Node* root, int i, vector<string>& wordsContainer) {
            Node* curr = root;
            string s = wordsContainer[i];
            int n = s.length();

            // root ind update
            if (wordsContainer[root->ind].length() > n ||
                (wordsContainer[root->ind].length() == n && i < root->ind)) {
                root->ind = i;
            }

            for (int j = n - 1; j >= 0; j--) {
                int c_i = s[j] - 'a';
                if (curr->children[c_i] == NULL) {
                    curr->children[c_i] = new Node(i);
                }
                curr = curr->children[c_i];
                if (wordsContainer[curr->ind].length() > n ||
                    (wordsContainer[curr->ind].length() == n &&
                     i < curr->ind)) {
                    curr->ind = i;
                }
            }
        }

        // search function
        int search(Node* root, string& s) {
            Node* curr = root;
            int n = s.length();
            int ans = root->ind;
            for (int j = n - 1; j >= 0; j--) {
                int c_i = s[j] - 'a';
                if (curr->children[c_i] == NULL) {
                    return ans;
                }
                curr = curr->children[c_i];
                ans = curr->ind;
            }
            return ans;
        }

        // destructor
        ~Node() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        Node* root = new Node(0);

        // insert all words
        for (int i = 0; i < m; i++) {
            root->insert(root, i, wordsContainer);
        }

        vector<int> ans(n, 0);

        // searching querys
        for (int i = 0; i < n; i++) {
            ans[i] = root->search(root, wordsQuery[i]);
        }

        // deleting trie
        delete root;

        // result
        return ans;
    }
};