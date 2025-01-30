class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        int currPSum=0;
        int currNSum=0;
        int maxAbsSum= 0;
        for(int i=0; i<n; i++){
            currPSum+=nums[i];
            currNSum+=nums[i];
            if(currPSum<0)
                currPSum=0;
            if(currNSum>0)
                currNSum=0;
            maxAbsSum= max({maxAbsSum, abs(currNSum), currPSum});
        }
        return maxAbsSum;
    }
};