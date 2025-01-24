struct Node {
    Node* links[26];    // Array for 26 lowercase English letters
    int cntEndWith = 0; // Tracks how many words end at this node
    int cntPrefix = 0;  // Tracks how many words have this node in their prefix

    bool containsKey(char ch) { 
        return (links[ch - 'a'] != NULL); 
        }

    Node* get(char ch) { 
        return links[ch - 'a']; 
        }

    void put(char ch, Node* node) { 
        links[ch - 'a'] = node; 
    }

    void increaseEnd() { 
        cntEndWith++; 
    }

    void increasePrefix() { 
        cntPrefix++; 
    }

    void deleteEnd() { 
        cntEndWith--; 
    }

    int getEnd() { 
        return cntEndWith; 
    }

    int getPrefix() { 
        return cntPrefix;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (node->containsKey(prefix[i])) {
                node = node->get(prefix[i]);
            } else {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->cntPrefix--;
            }
        }
        node->deleteEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return false;
            }
        }
        return node->getEnd() > 0;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (node->containsKey(prefix[i])) {
                node = node->get(prefix[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
