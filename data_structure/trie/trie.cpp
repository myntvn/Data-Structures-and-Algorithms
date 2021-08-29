#include <bits/stdc++.h>
using namespace std;

class Trie {
    Trie *children[26];
    bool isLastWord;
public:
    /** Initialize your data structure here. */
    // Trie() : children(26, NULL) {
    //     // children = vector(26, NULL);
    //     isLastWord = false;
    // }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!node->children[index]) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isLastWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) return false;
            node = node->children[i];
        }
        return node && node->isLastWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            int i = c - 'a';
            if (!node->children[i]) return false;
            node = node->children[i];
        }
        return node;
    }
};

/**
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */