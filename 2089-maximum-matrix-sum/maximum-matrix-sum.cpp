class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negativeCount = 0;
        long long sum = 0;
        int smallest = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0){
                    negativeCount++;
                    sum += (-1* matrix[i][j]);
                }
                else{
                    sum+= matrix[i][j];
                }
                if(abs(matrix[i][j])<smallest){
                    smallest = abs(matrix[i][j]);
                }
            }
        }
        // cout<<sum;
        cout<<smallest;
        if((negativeCount&1) == 0) return sum;
        return sum - 2*smallest;
    }
};