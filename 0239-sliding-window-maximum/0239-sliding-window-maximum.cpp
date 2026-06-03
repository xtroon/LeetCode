class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0; i<nums.size(); i++){
            //remove from front if exceed size
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            // remove smaller from back
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            // add cuurrent idx to deque 
            dq.push_back(i);

            // push front elemnt after 1st window done
            if( i >= k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};