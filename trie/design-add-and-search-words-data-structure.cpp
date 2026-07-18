class Node //trie node
{
public:
    char val;
    Node* children[26];
    bool isTerminal;

    Node(char v) //constructor
    {
        val = v;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; 
        }
        isTerminal = false;
    }
};

class WordDictionary {
    Node* root;   // root of the trie
public:
    WordDictionary() {
        root = new Node('\0');
    }
    
    // insert word into trie
    void insertutil(Node* root, const string &word, int idx)
    {
        if (idx == word.size()) {
            root->isTerminal = true;
            return;
        }
        int index = word[idx] - 'a'; // assume lowercase
        if (root->children[index] == NULL)
        {
            root->children[index] = new Node(word[idx]);
        }
        insertutil(root->children[index], word, idx + 1);
    }

    void addWord(string word) {
        insertutil(root, word, 0);
    }
    
    // search with wildcard support
    bool searchutil(Node* root, const string &word, int idx)
    {
        if (idx == word.size())
            return root->isTerminal;

        char c = word[idx];

        if (c == '.') {
            // try all children
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    if (searchutil(root->children[i], word, idx + 1))
                        return true;
                }
            }
            return false; // none matched
        } else {
            int index = c - 'a';
            if (root->children[index] == NULL)
                return false;
            return searchutil(root->children[index], word, idx + 1);
        }
    }

    bool search(string word) {
        return searchutil(root, word, 0);
    }
};
