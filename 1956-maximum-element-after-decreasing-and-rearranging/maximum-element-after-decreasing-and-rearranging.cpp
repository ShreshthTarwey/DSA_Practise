class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int num = 1;
        int ans = num;
        for(int i=1;i<arr.size();i++){
            if(abs(num - arr[i])<=1){
                num = max(num, arr[i]);
            }
            else{
                num = num+1;
            }
            ans = max(ans, num);
        }
        return ans;
    }
};