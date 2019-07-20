class NumArray {
public:
	vector<int> sums;

    NumArray(vector<int> nums) {
        sums.push_back(0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
        	sums.push_back(sums[i] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
