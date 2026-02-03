class Solution {
public:
    bool check1(vector<int>& nums, int &p, int &q){
        bool flag = false;
        int index = -1;
        for(int i=p;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                index = i+1;
                flag = true;
            }
            else break;
        }
        
        if(index!=-1) q = index;
        return flag;
    }
    bool check2(vector<int>& nums, int &p, int &q){
        bool flag = false;
        int index = -1;
        for(int j=p;j<nums.size()-1;j++){
            if(nums[j]>nums[j+1]){
                index = j+1;
                flag = true;
            }else break;
        }
        if(index!=-1) q = index;
        return flag;
    }
    bool check3(vector<int>& nums, int q, int n){
        bool found = false;
        for(int i=q;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                found = true;
            }
            else{
                return false;
            }
        }
        return found;

    }
    bool isTrionic(vector<int>& nums) {
        int p = 0; 
        int q = 0;
        if(!check1(nums, p, q)) return false;
        p = q;
        if(!check2(nums, p, q)) return false;
        p = q;
        int x = nums.size();
        if(!check3(nums, p, x)) return false;
        return true;

    }
};