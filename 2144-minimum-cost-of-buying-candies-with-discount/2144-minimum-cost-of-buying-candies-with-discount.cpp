class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        //length of arr
        int n = cost.size();

        //base cases
        if(n==1) return cost[0];
        if(n==2) return cost[0] + cost[1];

        //sorting in rev order
        sort(cost.rbegin(), cost.rend());
        
        // calculate sum
        int sum = 0;
        for(int i=0; i<n; i++){
            if((i+1) < n) sum += (cost[i] + cost[i+1]);
            else sum += cost[i];
            i+= 2;
        }

        return sum;
    }
};