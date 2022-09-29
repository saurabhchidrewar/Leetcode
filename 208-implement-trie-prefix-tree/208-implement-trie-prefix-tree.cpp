struct Node {
    Node* arr[26];
    bool flag = false;
    
    bool containsKey(char ch) {
        return (arr[ch - 'a'] != NULL);
    }
    
    void set(char ch, Node* node) {
        arr[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return arr[ch - 'a'];
    }
    
    void setEnd() {
        flag = true;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->set(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->flag == true;
    }
    
    bool startsWith(string word) {
        Node * node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
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