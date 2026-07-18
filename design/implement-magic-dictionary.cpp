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
class MagicDictionary {
    Node* root;

public:
    MagicDictionary() { root = new Node('\0'); }
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

    /** Inserts a word into the trie. */
    void insert(string word) { insertutil(root, word); }

    void buildDict(vector<string> dictionary) {
        for (auto i : dictionary) {
            insert(i);
        }
    }

    bool searchutil(Node* root, string& word, int index, int mismatched) {
        // if we already used more than one mismatch, stop
        if (mismatched > 1)
            return false;

        // end of word
        if (index == (int)word.size()) {
            // valid only if exactly 1 mismatch AND node isTerminal
            return (mismatched == 1 && root->isTerminal);
        }

        int charIndex = word[index] - 'a';

        // Try matching child first (no mismatch increment)
        if (root->children[charIndex] != NULL) {
            if (searchutil(root->children[charIndex], word, index + 1,
                           mismatched))
                return true;
        }

        // Try non-matching children (increment mismatch count)
        for (int i = 0; i < 26; i++) {
            if (i == charIndex || root->children[i] == NULL)
                continue;
            if (searchutil(root->children[i], word, index + 1, mismatched + 1))
                return true;
        }

        return false;
    }

    bool search(string searchWord) {
        return searchutil(root, searchWord, 0, 0);
    }
};
