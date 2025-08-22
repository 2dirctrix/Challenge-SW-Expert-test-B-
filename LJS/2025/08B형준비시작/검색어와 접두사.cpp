#include <iostream>
using namespace std;

int n, m;
string words[100000];
string S;

struct trie {
    trie* children[26];
    bool is_end;
    int cnt;
    trie() {
        is_end = false;
        cnt = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
trie *root=new trie();

void insert(string word) {
    trie* t = root;
    int cnt = 0;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i]-'a';
        if (t->children[index] == nullptr) {
            t->children[index] = new trie();
            
        }
        t = t->children[index];
        t->cnt++;
    }
    t->is_end = true;
}

void SearchWord(string s) {
    trie* t = root;
    for (int i = 0; i < s.size(); i++) {
        if (t != nullptr) {
            int index = s[i] - 'a';
            t = t->children[index];
        }
        if (t != nullptr) {
            cout << t->cnt << ' ';
        }
        else
            cout << "0 ";
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cin >> S;

    // Please write your code here.

    for (string word : words) {
        insert(word);
    }
    SearchWord(S);
    return 0;
}