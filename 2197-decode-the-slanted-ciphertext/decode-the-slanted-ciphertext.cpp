class Solution {
public:
    string method1(string &encodedText, int rows){
        int n = rows;
        if(encodedText.empty()) return "";
        int m = encodedText.length()/rows;
        vector<vector<char>>mat(rows, vector<char>(m, ' '));
        int index = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j] = encodedText[index++];
            }
        }
        string temp = "";
        for(int i=0;i<m;i++){
            int index = i;
            int index2 = 0;
            while(index<m  && index2<n){
                temp+=mat[index2][index];
                index++;
                index2++;
            }
        }
        string res = "";
        index = 0;
        // while(temp[index] == ' '){
        //     index++;
        // }
        int index2 = temp.length()-1;
        while(temp[index2] == ' '){
            index2--;
        }
        for(int i=index;i<=index2;i++){
            res+=temp[i];
        }
        return res;
    }
    string method2(string &encodedText, int rows){
        string original = "";
        int col = encodedText.length()/rows;
        for(int j = 0;j<col;j++){
            for(int i=j;i<encodedText.length();i += (col+1)){
                original += encodedText[i];
            }
        }
        while(!original.empty() && original.back() == ' '){
            original.pop_back();
        }
        return original;
    }
    string decodeCiphertext(string encodedText, int rows) {
        // return method1(encodedText, rows);//T.C-> O(m*n), S.C->O(m*n)

        return method2(encodedText, rows);
    }
};