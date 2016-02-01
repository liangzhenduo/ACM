#include <bits/stdc++.h>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,j=0;i<nums.size();i++)
            if(nums[i])
                swap(nums[j++],nums[i]);
    }
};