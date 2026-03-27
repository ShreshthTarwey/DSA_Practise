class Solution {
public:
    void leftShift(vector<int>& arr, int k){
        int n = arr.size();
        for(int i=0;i<k;i++){
            int temp = arr[0];
            for(int j=0;j<n-1;j++){
                arr[j] = arr[j+1];
            }
            arr[n-1] = temp;
        }
    }
    void rightShift(vector<int>& arr, int k){
        int n = arr.size();
        for(int i=0;i<k;i++){
            int temp = arr[n-1];
            for(int j=n-1;j>=1;j--){
                arr[j] = arr[j-1];
            }
            arr[0] = temp;
        }
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int noOfRotations = k%m;
        vector<vector<int>>temp = mat;
        for(int i=0;i<n;i++){
            if((i&1)){
                leftShift(mat[i], noOfRotations);
            }
            else{
                rightShift(mat[i], noOfRotations);
            }
            if(mat[i] != temp[i]) return false;
        }
        return true;
    }
};