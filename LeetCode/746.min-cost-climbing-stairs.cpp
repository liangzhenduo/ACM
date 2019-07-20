class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int d[1001];
        d[0] = cost[0];
        d[1] = cost[1];
        int l = cost.size();
        for (int i = 2; i < l; i ++) {
        	d[i] = min(d[i - 1] + cost[i], d[i - 2] + cost[i]);
        }
        return min(d[l - 1], d[l - 2]);
    }
};
