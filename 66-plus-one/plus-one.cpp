class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i=digits.size()-1;i>=0;i--){
            if(i==digits.size()-1){
                int num = digits[i] + 1;
                carry = num/10;
                digits[i] = num%10;
            }
            else{
                int num = digits[i] + carry;
                carry = num/10;
                digits[i] = num%10;
            }
        }
        if(carry!=0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};