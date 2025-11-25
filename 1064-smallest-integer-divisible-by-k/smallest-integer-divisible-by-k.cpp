class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        int num = 1;
        int rem = 1%k;
        if(rem==0) return 1;
        unordered_map<int,int>mp;
        mp[rem]++;
        for(int i=1;i<k;i++){
            
            // int newRem = rem*10 + 1;
            rem = (rem*10+1)%k;
            if(rem==0) return i+1;
            if(mp.find(rem)!=mp.end()){
                return -1;
            }
            mp[rem]++; 
        }
        return -1;
    }
};