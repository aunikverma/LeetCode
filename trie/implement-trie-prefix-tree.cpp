class Node // trie node
{
public:
    char val;
    Node* children[26];
    bool isTerminal;

    Node(char v) // constructor
    {
        val = v;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie {
    Node* root;

public:
    Trie() { root = new Node('\0'); }

    // insertion in Trei
    void
    insertutil(Node* root,
               string word) // utility function to insert word using recursion
    {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a'; // assume all are uppercase
        Node* child;
        // if present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else // if not present
        {
            child = new Node(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertutil(child, word.substr(1));
    }

    void insert(string word) { insertutil(root, word); }

    // search util function using recursion
    bool searchutil(Node* root, string word) {
        if (word.length() == 0) {
            return (root->isTerminal);
        }

        int index = word[0] - 'a';
        Node* child;
        // if present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else // not present
        {
            return false;
        }
        // recursion
        return searchutil(child, word.substr(1));
    }

    bool search(string word) { return searchutil(root, word); }

    // startswith  util function using search funtion same
    bool startutil(Node* root, string word) {
        if (word.length() == 0) {
            return true;
        }

        int index = word[0] - 'a';
        Node* child;
        // if present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else // not present
        {
            return false;
        }
        // recursion
        return startutil(child, word.substr(1));
    }

    bool startsWith(string prefix) { return startutil(root, prefix); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */