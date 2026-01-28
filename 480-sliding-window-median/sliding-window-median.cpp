#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set st;
        vector<int>a(n);
        for(int i=0;i<k;i++){
            st.insert(nums[i]);
        }
        vector<double>ans;
        if((k&1) == 1){
            ans.push_back(*st.find_by_order((k-1)/2));
        }else{
            double val1 = *st.find_by_order((k-1)/2);
            double val2 = * st.find_by_order((k-1)/2  + 1);
            ans.push_back((val1+val2)/2.0);
        }
        int i = 0;
        int j = k-1;
        while(j < n - 1) {
            int rank = st.order_of_key(nums[i++]);//Number of elements that are less than v in t
            auto it = st.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
            st.erase(it);
            st.insert(nums[++j]);
            if(k & 1 == 1) {
                ans.push_back(*st.find_by_order((k - 1) / 2));
            }else {
                double val1 = *st.find_by_order((k - 1) / 2);
                double val2 = *st.find_by_order(((k - 1) / 2) + 1);
                ans.push_back((val1 + val2) / 2.0);
            }
        }
        return ans;
    }
};