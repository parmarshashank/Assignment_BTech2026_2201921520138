class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=nums[0];
        int currSum=nums[0];
        int n= nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1])
                currSum+=nums[i];
            else 
                currSum= nums[i];
            maxSum= max(maxSum, currSum);
        }
        return maxSum;
    }
};