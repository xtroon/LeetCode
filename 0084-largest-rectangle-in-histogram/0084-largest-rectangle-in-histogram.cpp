class Solution {
public:
    vector<int> PSE(vector<int>&  heights, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> NSE(vector<int>& heights, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        vector<int> left = PSE(heights, n);
        vector<int> right = NSE(heights, n);

        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;

            ans = max(ans, width*heights[i]);
        }
        return ans;
    }
};