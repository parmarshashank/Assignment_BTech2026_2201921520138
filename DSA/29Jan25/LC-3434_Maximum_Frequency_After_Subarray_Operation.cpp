class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int cnt= count(nums.begin(), nums.end(), k);
        int maxFreq=0;
        maxFreq+=cnt;
        for(int i=1; i<=50; i++){
            if(i==k) continue;
            int maxFreqofI=0;
            int currFreq=0;
            for(auto el: nums){
                if(el==i) currFreq++;
                else if(el==k) currFreq--;
                if(currFreq<0)
                    currFreq=0;
                maxFreqofI=max(maxFreqofI, currFreq);
            }
            maxFreq= max(maxFreq, maxFreqofI+cnt);
        }
        return maxFreq;
    }
};