struct Node{
    Node* links[2];

    bool containsKey(int i){
        return links[i]!=nullptr;
    }
    Node* get(int i){
        return links[i];
    }
    void put(int i, Node* node){
        links[i]=node;
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            this->root= new Node();
        }

        void insert(int num){
            Node* node= root;
            for(int i=31; i>=0; i--){
                int bit= (num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node=node->get(bit);
            }
        }

        int getMax(int num){
            Node* node= root;
            int maxNum=0;
            for(int i=31; i>=0; i--){
                int bit=(num>>i)&1;
                if(node->containsKey(!bit)){
                    maxNum|= (1<<i);
                    node=node->get(!bit);
                }
                else{
                    node=node->get(bit);
                }
            }
            return maxNum;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n= nums.size();
        Trie trie;
        for(auto i: nums){
            trie.insert(i);
        }
        int maxXor=0;
        for(auto i: nums){
            int t=trie.getMax(i);
            maxXor= max(maxXor, t);
        }
        return maxXor;
    }
};