class Solution {
public:
    vector<vector<int>> method1(int numRows){
        if(numRows==0) return {{}};
        if(numRows==1) return {{1}};
        vector<vector<int>>ans = generate(numRows-1);
        vector<int>temp(numRows,1);
        for(int i=1;i<numRows-1;i++){
            temp[i] = ans.back()[i-1] + ans.back()[i];
        }
        ans.push_back(temp);
        return ans;
    }
    vector<vector<int>> sirMethod(int n){
        vector<vector<int>> ans;
        
        for(int i=0; i<n;i++){
            vector<int> row;
            for(int j=0; j<=i;j++){
                if(j==0 || j==i) row.push_back(1);
                else row.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        // return method1(numRows);
        return sirMethod(numRows);
    }
};