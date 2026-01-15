class Solution {
public:
    int findLongestConsicutive(vector<int>& arr){
        int ele = arr[0];
        int length = 1;
        int maxLength = 1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]+1==arr[i+1]){
                length++;
            }
            else{
                length = 1;
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //We have to find maximum consecutive subarray
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int consi1 = findLongestConsicutive(hBars);
        int consi2 = findLongestConsicutive(vBars);
        int length = min(consi1+1, consi2+1);
        return length*length;
    }
};