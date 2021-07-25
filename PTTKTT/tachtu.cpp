#include <bits/stdc++.h>

using namespace std;

#define MAX 26

// Su dung Trie de luu thu vien
struct Node {
    struct Node *child[MAX];
    int countWords;
};

struct Node *newNode() 
{
    struct Node *node = new Node;
    node -> countWords = 0;
    for (int i = 0; i < MAX; ++i) node -> child[i] = NULL;
    return node;
}

void addWord (struct Node *root, string s) {
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); ++i) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            temp->child[ch] = newNode();
        temp = temp->child[ch];
    }
    temp->countWords++;
}

bool findWord(Node *root, string s) {
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); ++i) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            return false;
        temp = temp->child[ch];
    }
    return temp->countWords > 0;
}

struct Node *root = new Node();
struct Node *cur = new Node();
string A;
int n;
void AddToDictionary() {
    ifstream fin ("word.txt");
    string s;
    while (fin >> s) {
        if (s.length() > 1 || s == "a")
            addWord(root, s);
    }
}

string SubString (string A, int i, int j) {
    string temp = "";
    for (int k = i; k <= j; ++k)
        temp += A[k];
    return temp;
}

bool SplitTable(int i) {
    if (i == n) return true;
    for (int j = i; j < n; ++j) {
        string temp = SubString(A, i, j);
        if (findWord(root, temp))
            if (SplitTable(j + 1))
                return true;
    }
    return false;
}

int main() {
    AddToDictionary();
    cin >> A;
    n = A.size();
    cout << SplitTable(0) << endl;
    return 0;
}