class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]==target){
                return i;
            }else if(nums[i]>target){
                return i;
            }
        }
        return nums.size();
    }
};