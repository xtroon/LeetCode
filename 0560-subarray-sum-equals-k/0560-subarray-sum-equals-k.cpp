class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;

        int sum = 0, count = 0;

        for(int it : nums){
            sum += it;

            int removed = sum - k;
            if(hash.find(removed) != hash.end()){
                count += hash[removed];
            } 

            hash[sum]++;
        }
        return count;
    }
};