class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(is_sorted(s.begin(), s.end())){
            return 0;
        }      
        if(n == 2){
            return -1;
        }
        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());
        if(s[0] == min_char || max_char == s[n-1]){
            return 1;
        }
        int min_count = count(s.begin(), s.end(), min_char);
        int max_count = count(s.begin(), s.end(), max_char);
        if(s[0] == max_char && s[n-1] == min_char && min_count == 1 && max_count == 1){
            return 3;
        }
        else{
            return 2;
        }
    }
};