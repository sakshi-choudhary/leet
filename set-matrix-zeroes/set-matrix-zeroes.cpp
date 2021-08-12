class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> u;
        vector<int> v;
        int rowsize=matrix.size();
        int colsize=matrix[0].size();
        for(int i=0;i<rowsize;i++){
            for(int j=0;j<colsize;j++){
                if(matrix[i][j]==0){
                    u.push_back(i);
                    v.push_back(j);
                }
            }
        }
        for(int m=0;m<u.size();m++){
            for(int p=0;p<colsize;p++){
            matrix[u[m]][p]=0;
        }
        }
        for(int n=0;n<v.size();n++){
          for(int q=0;q<rowsize;q++){
            matrix[q][v[n]]=0;
        }
        }
        
    }
};