class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int mid=0,start=0 , end=n-1;
        int first=0, last=0;
        while(start<=end){
            mid = start +(end-start)/2;
            if(nums[mid]== target){
                first = mid;
                last = mid;
                while(first>=0 && nums[first]==target) first--;
                while(last<n && nums[last]==target) last++;
                return {first+1 ,last-1};
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }      
        
        return {-1, -1};
    }
};