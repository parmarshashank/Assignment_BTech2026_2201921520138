class Solution {
public:
    string frequencySort(string s) {
        vector<int> hash(128,0);
        for(auto c: s){
            hash[c]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b){
            if(hash[a]==hash[b]) return a>b;
            return hash[a]>hash[b];
        });
        return s;
    }        
};