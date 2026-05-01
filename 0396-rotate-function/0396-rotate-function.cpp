class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int f = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            f += nums[i]*i;
        }

        int ans = f;

        for(int i=0; i<n; i++){
            f = f + sum - n*(nums[n-i-1]);
            ans = max(ans, f);
        }
        return ans;
    }
};