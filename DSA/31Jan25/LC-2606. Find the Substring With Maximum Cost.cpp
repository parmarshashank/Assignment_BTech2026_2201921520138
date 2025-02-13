class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> mp;
        int l= chars.length();
        for(int i=0; i<l; i++){
            mp.insert({chars[i], i});
        }
        int maxCost=0;
        int currCost=0;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i])!=mp.end()){
                currCost+= vals[mp[s[i]]];
            }
            else
                currCost+= (s[i]-'a')+1;
            if(currCost<0)
                currCost=0;
            maxCost= max(currCost, maxCost);
        }
        return maxCost;
    }
};S