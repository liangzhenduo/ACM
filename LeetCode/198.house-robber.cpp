class Solution {
public:
	int rob(vector<int>& nums) {
		int l = nums.size();
		if (l == 0) {
			return 0;
		}
		if (l == 1) {
			return nums[0];
		}
		vector<int> dp;
		dp.push_back(nums[0]);
		dp.push_back(max(nums[0], nums[1]));
		for (int i = 2; i < l; i++) {
			dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
		}
		return dp[l - 1];
	}
};
