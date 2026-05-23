class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j=i;
            bool flag = false;
            bool isIt = true;
            while(true){
                if(j==((i-1 + n)%n) && flag){
                    break;
                }
                int next = (j+1)%n;
                if(nums[j]>nums[next]){
                    isIt = false;
                    break;
                }
                j = next;
                flag = true;
            }
            if(isIt){
                cout<<i<<endl;
                return true;
            }
        }
        return false;
    }
};