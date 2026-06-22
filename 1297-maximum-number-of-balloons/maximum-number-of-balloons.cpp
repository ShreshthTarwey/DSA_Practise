class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Frequency array for all 26 lowercase English letters
        int counts[26] = {0};
        
        // Count frequencies of each character in the input string
        for (char c : text) {
            counts[c - 'a']++;
        }
        
        // Extract the counts for the letters in "balloon"
        int b_count = counts['b' - 'a'];
        int a_count = counts['a' - 'a'];
        int l_count = counts['l' - 'a'] / 2; // Needs 2 'l's per word
        int o_count = counts['o' - 'a'] / 2; // Needs 2 'o's per word
        int n_count = counts['n' - 'a'];
        
        // The bottleneck determines the maximum number of words we can form
        return min({b_count, a_count, l_count, o_count, n_count});
    }
};