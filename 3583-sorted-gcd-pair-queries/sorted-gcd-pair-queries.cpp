class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int>freq(maxVal+1, 0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=1;j*j<=num;j++){
                if(num % j==0){
                    freq[j]++;
                    if(num/j != j){
                        freq[num/j]++;
                    }
                }
            }
        }
        vector<long long>pairWithGCD(maxVal+1, 0);
        for(int i=maxVal;i>=1;i--){
            long long pairs = freq[i];
            pairWithGCD[i] = (pairs)*(pairs-1)/2;
            //Galti Sudharo
            for(int j=2*i;j<=maxVal;j+=i){
                pairWithGCD[i] -= pairWithGCD[j];
            }
        }

        vector<long long>prefix(maxVal+1);
        for(int i=1;i<pairWithGCD.size();i++){
            prefix[i] = pairWithGCD[i];
            prefix[i] += prefix[i-1];
        }
        //Creating result array
        vector<int>result;
        for(long long x: queries){
            int l = 1;
            int r = maxVal;
            int temp = 1;
            while(l<=r){
                int mid_gcd = l + (r-l)/2;
                if(prefix[mid_gcd]>=x+1){
                    temp = mid_gcd;
                    r = mid_gcd-1;
                }
                else{
                    l = mid_gcd+1;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};