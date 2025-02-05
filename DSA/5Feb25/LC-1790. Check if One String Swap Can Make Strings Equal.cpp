class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> uneqPos;
        int n= s1.size();
        if(n != s2.length())
            return false;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i])
                uneqPos.push_back(i);
        }
        if(uneqPos.size()==0) return true;
        if(uneqPos.size()!=2)
            return false;
        return s1[uneqPos[0]]==s2[uneqPos[1]] && s1[uneqPos[1]]==s2[uneqPos[0]];
    }
};