class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> list;
        for(int i=0;i<nums.size();i++){
            list[nums[i]]++;
            if(list[nums[i]]>nums.size()/2){
                return nums[i];
                break;
            }
        }
        return -1;
    }
};