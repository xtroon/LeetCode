class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        int maxPro = nums[0];
        int minPro = nums[0];

        for(int i=1; i<n; i++){
            int curr = nums[i];

            if(curr < 0) swap(maxPro, minPro);

            maxPro = max(curr, maxPro*curr);
            minPro = min(curr, minPro*curr);

            ans = max(ans, maxPro);
        }

        return ans;
    }
};