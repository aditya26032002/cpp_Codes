#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            cout << root->data << " ";
            return root->isTerminal;
        }
        cout << root->data << " ";
        int index = word[0] - 'A';
        if (root->children[index] == NULL)
            return false;
        else
        {
            return searchUtil(root->children[index], word.substr(1));
        }
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            bool furtherNodes = false;
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    furtherNodes = true;
                    break;
                }
            }
            if (!furtherNodes)
                delete root;
            return furtherNodes;
        }

        int index = word[0] - 'A';
        bool furtherNodes = true;
        if (root->children[index] != NULL)
        {
            furtherNodes = deleteUtil(root->children[index], word.substr(1));

            if (!furtherNodes)
            {
                root->children[index] = NULL;
                if (root->isTerminal)
                    return true;
                for (int i = 0; i < 26; i++)
                {
                    if (root->children[i] != NULL)
                    {
                        furtherNodes = true;
                        break;
                    }
                }
                if (!furtherNodes)
                    delete root;
            }
            return furtherNodes;
        }
    }

    void deleteEntry(string word)
    {
        deleteUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("MUG");
    t->insert("JUG");
    t->insert("DABBA");
    t->insert("DABBAS");
    t->insert("ADITYA");

    cout << t->search("DABBA") << endl;
    t->deleteEntry("DABBA");
    cout << t->search("DABBA") << endl;

    return 0;
}