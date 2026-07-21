class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>arr;
        int n = s.length();
        int i=0;
        int cnt1 = 0;
        while(i<n){
            int count1 = 0;
            while(i<n && s[i]-'0'>0){
                count1++;
                i++;
            }
            if(count1>0)
                arr.push_back(count1);
            cnt1 += count1;
            int count2 = 0;
            while(i<n && s[i]-'0' == 0){
                count2++;
                i++;
            }
            if(count2>0)
                arr.push_back(-count2);
            
        }
        int m = arr.size();
        int ans = INT_MIN;
        i=0;
        // for(int i=0;i<m;i++){
        //     if(arr[i]>0){
        //         cnt1 += arr[i];
        //     }
        // }
        ans = cnt1;
        int j=2;
        while(j<m){
            if(arr[i]<0 || arr[j]<0){
                ans = max(ans, cnt1 + abs(arr[i]) + abs(arr[j]));
            }
            i++;
            j++;
        }
        return ans;
    }
};