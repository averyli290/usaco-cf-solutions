
const int K = 2;
const char zero_char = '0';      // char representing index 0 out of [0, K)

struct TrieNode {
    int next[K];
    bool has = false;
    
    TrieNode() {
        fill(begin(next), end(next), -1);
    }
};

void insert(vector<TrieNode>& trie, string& s) {
    int curnode = 0;
    for(char ch : s) {
        int c = ch - zero_char;
        if (trie[curnode].next[c] == -1) {
            trie[curnode].next[c] = sz(trie);
            trie.emplace_back();
        }
        curnode = trie[curnode].next[c];
    }
    trie[curnode].has = true;
}

void erase(vector<TrieNode>& trie, string& s) {
    int curnode = 0;
    for(char ch : s) {
        int c = ch - zero_char;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
    }
    trie[curnode].has = false;
}

bool find(vector<TrieNode>& trie, string& s) {
    int curnode = 0;
    for(char ch : s) {
        int c = ch - zero_char;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
    }
    return trie[curnode].has;
}

/*
const int K = 2;
const char zero_char = '0';      // char representing index 0 out of [0, K)
struct TrieNode {
    int next[K];
    int ct = 0;
    
    TrieNode() {
        fill(begin(next), end(next), -1);
    }
};

void insert(vector<TrieNode>& trie, string& s) {
    int curnode = 0;
    for(char ch : s) {
        int c = ch - zero_char;
        if (trie[curnode].next[c] == -1) {
            trie[curnode].next[c] = sz(trie);
            trie.emplace_back();
        }
        curnode = trie[curnode].next[c];
        trie[curnode].ct++;
    }
}

void erase(vector<TrieNode>& trie, string& s) {
    int curnode = 0;
    vector<int> to_dec;     // only dec on successful erase
    for(char ch : s) {
        int c = ch - zero_char;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
        to_dec.push_back(curnode);
    }
    for(int i : to_dec) trie[i].ct--;
}

bool find(vector<TrieNode>& trie, string& s) {
    int curnode = 0;
    for(char ch : s) {
        int c = ch - zero_char;
        if (trie[curnode].next[c] == -1) return false;
        curnode = trie[curnode].next[c];
    }
    return trie[curnode].ct > 0;
}
*/