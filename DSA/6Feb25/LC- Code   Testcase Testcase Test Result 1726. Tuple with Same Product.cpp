class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int, int> mp;
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                cnt+=8*mp[nums[i]*nums[j]];
                mp[nums[i]*nums[j]]++;
            }
        }
        return cnt;
    }
};