class Solution {
    struct TrieNode {
        TrieNode* child[26];
        int cnt;

        TrieNode() {
            cnt = 0;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

public:
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();

        // Insert all words into Trie
        for (string &word : arr) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (node->child[idx] == nullptr)
                    node->child[idx] = new TrieNode();

                node = node->child[idx];
                node->cnt++;
            }
        }

        vector<string> ans;

        // Find shortest unique prefix
        for (string &word : arr) {
            TrieNode* node = root;
            string prefix = "";

            for (char ch : word) {
                int idx = ch - 'a';
                node = node->child[idx];
                prefix += ch;

                if (node->cnt == 1)
                    break;
            }

            ans.push_back(prefix);
        }

        return ans;
    }
};