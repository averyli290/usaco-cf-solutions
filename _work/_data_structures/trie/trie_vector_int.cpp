
const int K = 2;

struct TrieNode {
    int next[K];
    bool has = false;
    
    TrieNode() {
        fill(begin(next), end(next), -1);
    }
};

void insert(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) {
            trie[curnode].next[c] = sz(trie);
            trie.emplace_back();
        }
        curnode = trie[curnode].next[c];
    }
    trie[curnode].has = true;
}

void erase(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
    }
    trie[curnode].has = false;
}

bool find(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
    }
    return trie[curnode].has;
}

/*

struct TrieNode {
    int next[K];
    int ct = 0;
    
    TrieNode() {
        fill(begin(next), end(next), -1);
    }
};

void insert(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) {
            trie[curnode].next[c] = sz(trie);
            trie.emplace_back();
        }
        curnode = trie[curnode].next[c];
        curnode.ct++;
    }
    trie[curnode].has = true;
}

void erase(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
        curnode.ct--;
    }
    trie[curnode].has = false;
}

bool find(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
    }
    return trie[curnode].ct > 0;
}
*/