class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n= c.size();
        int maxScore=0;
        for(int i=0; i<k; i++)
            maxScore+=c[i];
        int curr=maxScore;
        for(int i=k-1; i>=0; i--){
            curr-=c[i];
            curr+=c[n-k+i];
            maxScore= max(maxScore, curr);
        }
        return maxScore;
    }
};