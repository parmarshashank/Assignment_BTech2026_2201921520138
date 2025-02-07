#define pi pair<int, int>

struct Node {
    Node* links[2] = {nullptr, nullptr};

    bool containsKey(int i) { return links[i] != nullptr; }
    Node* get(int i) { return links[i]; }
    void put(int i, Node* node) { links[i] = node; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { this->root = new Node(); }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit)) {
                maxNum |= (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int n = nums.size(), m = queries.size();
        vector<int> res(m, 0);
        vector<pair<pi, int>> offlineQueries;

        for (int i = 0; i < m; i++) {
            offlineQueries.push_back({{queries[i][1], queries[i][0]}, i});
        }

        sort(offlineQueries.begin(), offlineQueries.end());
        sort(nums.begin(), nums.end());

        int i = 0;
        for (auto& [p, ind] : offlineQueries) {
            int m_i = p.first, x = p.second;

            while (i < n && nums[i] <= m_i) {
                trie.insert(nums[i]);
                i++;
            }
            res[ind] = (i == 0) ? -1 : trie.getMax(x);
        }
        return res;
    }
};
