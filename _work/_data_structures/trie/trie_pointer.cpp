
const int K = 2;
const char zero_char = '0';      // char representing index 0 out of [0, K)
struct TrieNode {
    int ct = 0;
    vector<TrieNode*> next = vector<TrieNode*>(K, nullptr);
};

void insert(TrieNode* root, string &s) {
    TrieNode* cur_node = root;
    for (char c : s) {
        int cur = c - zero_char;
        if (cur_node->next[cur] == nullptr) cur_node->next[cur] = new TrieNode{};
        cur_node = cur_node->next[cur];
        cur_node->ct++;
    }
}

int query(TrieNode* root, string &s) {
    TrieNode* cur_node = root;
    for (char c : s) {
        int cur = c - zero_char;
        if (cur_node->next[cur] == nullptr) return 0;
        cur_node = cur_node->next[cur];
    }
    return cur_node->ct;
}

int erase(TrieNode* root, string &s) {
    TrieNode* cur_node = root;
    vector<TrieNode*> to_dec;
    for (char c : s) {
        int cur = c - zero_char;
        if (cur_node->next[cur] == nullptr) return -1;
        cur_node = cur_node->next[cur];
        to_dec.push_back(cur_node);
    }
    for(auto node : to_dec) node->ct--;     // only dec on successful erase
    return cur_node->ct;
}