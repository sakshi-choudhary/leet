class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=nums[0],sum=nums[0];
        for(int i=0; i<nums.size(); i++) {
            sum=0;
            for(int j=i; j<nums.size();j++){
                    sum+=nums[j];
                    max_sum=max(max_sum,sum);
                }
            }
        return max_sum;
    }
};