class Solution {
public:
    string usingLoops(string& num1, string& num2) {
        int carry = 0;
        // int i = min(num1.length(),num2.length());
        string res = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        while (i >= 0 && j >= 0) {
            int sum = (num1[i]-'0') + (num2[j]-'0') + carry;
            carry = sum / 10;
            res = (char)((sum % 10)+'0') + res;
            // cout<<res<<endl;
            i--;
            j--;
        }
        // cout<<carry<<endl;
        cout<<res<<endl;
        cout<<"This is i"<<i<<endl;
        while(i>=0){
            int sum = carry + (num1[i]-'0');
            cout<<(num1[i]-'0')<<endl;
            // if(sum>=10)
            res = (char)((sum%10)+'0') + res;
            // else if(sum!=0)
            // res = (char)(sum+'0') + res;
            cout<<res<<endl;
            carry = sum/10;
            i--;
        }
        cout<<res<<endl;
        while(j>=0){
            cout<<"Enter in J?"<<endl;
            int sum = carry + (num2[j]-'0');
            // BUG 1 FIX: Swap logic
            carry = sum / 10;                     // This is the new carry
            res = (char)((sum % 10) + '0') + res; // This is the new digit
            j--;
        }
        cout<<"last carry"<<carry<<endl;
        if (carry > 0) {
            res = (char)(carry + '0') + res;
        }
        return res;
    }
    string recursiveMethod(string &num1, int i,string &num2, int j, int carry=0){
        //base case
        if(i<0 && j<0){
            if(carry!=0){
                return string(1,carry+'0');
            }
            return "";
        }

        string res = "";
        int n1 = (i>=0 ? num1[i] : '0') - '0';
        int n2 = (j>=0 ? num2[j] : '0') - '0';
        int sum = n1+n2+carry;
        int digit = sum%10;
        carry = sum/10;
        res.push_back(digit+'0');

        res += recursiveMethod(num1, i-1, num2, j-1, carry);
        return res;
    }
    string addStrings(string num1, string num2) {
        // Method 1 ---> using loops
        // return usingLoops(num1, num2); //T.C -> O(Max(N,M))
        string res = recursiveMethod(num1,num1.length()-1,num2,num2.length()-1);
        reverse(res.begin(),res.end());
        return res;
    }
};