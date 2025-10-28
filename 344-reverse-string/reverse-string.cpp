class Solution {
public:
    void helper(vector<char>& s, int index){
        int index2 = s.size()-1-index;
        if(index>=index2){
            return;
        }
        swap(s[index],s[index2]);
        helper(s,index+1);
    }
    void reverseString(vector<char>& s) {
        //Using recursion i will be reversing
        helper(s,0);
    }
};