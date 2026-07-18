class Solution {
    class Node {
    public:
        char val;
        unordered_map<char, Node*> children;
        bool isTerminal;
        Node(char v) : val(v), isTerminal(false) {}
    };

    class Trie {
    public:
        Node* root;
        Trie() { root = new Node('\0'); }

        void insertutil(Node* root, string word) {
            if (word.empty()) {
                root->isTerminal = true;
                return;
            }
            Node* child;
            if (root->children.count(word[0])) { // if not null
                child = root->children[word[0]];
            } else {
                child = new Node(word[0]); // if null
                root->children[word[0]] = child;
            }
            insertutil(child, word.substr(1));
        }

        void insertword(string word) { insertutil(root, word); }

        bool check(string word) {
            Node* curr = root;
            for (auto i : word) {
                if (curr->children.count(i)) { //if present
                    curr = curr->children[i];
                } else if (isupper(i)) { //next camel case
                    return false;
                }
            }
            return curr->isTerminal; // placeholder
        }
    };

public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(), false);
        Trie t;
        t.insertword(pattern);
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = t.check(queries[i]);
        }
        return ans;
    }
};
