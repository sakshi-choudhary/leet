class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
        int curr=matrix[i][j];
        if(target==curr){
            return true;
            break;
        }else if(target<curr){
            j--;
        }else{
            i++;
        }
        }
        return false;
    }
};
