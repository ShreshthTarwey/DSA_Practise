class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        for(int i=0;i<bloomDay.size();i++){
            
            if(day>=bloomDay[i]){
                count++;
            }
            else{
                count = 0;
            }
            if(count==k){
                m--;
                count=0;
            }
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // long long x = m*k;
        // if(x>bloomDay.size()) return -1;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isPossible(bloomDay,mid,m,k)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};