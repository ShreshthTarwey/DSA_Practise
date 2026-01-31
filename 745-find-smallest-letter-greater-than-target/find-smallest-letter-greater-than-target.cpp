class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l= 0;
        int r = letters.size()-1;
        char ans = CHAR_MAX;
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(letters[mid]>target){
                ans = min(ans, letters[mid]);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans == CHAR_MAX ? letters[0] : ans;
    }
};