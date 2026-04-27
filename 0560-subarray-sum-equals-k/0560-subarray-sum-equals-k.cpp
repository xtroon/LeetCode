class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);

        // store prefix sum of them in vecotr
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        int count = 0; // no. of subarrays
        unordered_map<int, int> hash; // prefixSum, frequency
        for(int j=0; j<n; j++){
            if(prefixSum[j] == k) count++;

            int val = prefixSum[j] - k;
            if(hash.find(val) != hash.end()){
                count += hash[val];
            }

            if(hash.find(prefixSum[j]) == hash.end()){
                hash[prefixSum[j]] = 0;
            }
            hash[prefixSum[j]]++;
        }
        return count;
    }
};