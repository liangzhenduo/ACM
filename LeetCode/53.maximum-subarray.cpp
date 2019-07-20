class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int l = nums.size();
        int m = INT_MIN;
        int dp = 0;
        for (int i = 0; i < l; i++) {
        	dp = max(nums[i], dp + nums[i]);
        	m = max(m, dp);
        }
        return m;
    }
};
