class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //Checking for AllEven
        bool canMakeEven = true;
        for(auto &it: nums1){
            if(it%2!=0){
                canMakeEven = false;
                break;
            }
        }
        //Checking for AllOdd
        bool canMakeOdd = true;
        int minOdd = INT_MAX;
        for(auto it: nums1){
            if(it%2!=0){
                minOdd = min(minOdd, it);
            }
        }
        for(auto &it: nums1){
            if(it%2==0 && minOdd!=INT_MAX && minOdd>=it){
                canMakeOdd = false;
                break;
            }
        }
        return canMakeEven || canMakeOdd;
    }
};