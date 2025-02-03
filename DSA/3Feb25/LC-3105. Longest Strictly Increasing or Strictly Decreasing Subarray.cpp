class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1, dec=1, maxi=1;
        int n= nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }
            else if(nums[i]<nums[i-1]){
                dec++;
                inc=1;
            }
            else{
                inc=1;
                dec=1;
            }
            maxi= max({maxi, inc, dec});
        }
        return maxi;
    }
};