class Solution {
public:
    bool isSame(string &word, string &str, int i, int m){
        for(int j=0;j<m;j++){
            if(word[i] != str[j]){
                return false;
            }
            i++;
        }
        return true;
    }
    string generateString(string str1, string str2) {
        //create string 
        int n = str1.length();
        int m = str2.length();
        // vector<char>arr(n+m-1, '$');
        string word(n+m-1, '$');
        vector<bool>canChange(n+m-1, false);
        //Filling string with T
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                int _i = i;
                for(int j=0;j<m;j++){
                    if(word[_i]!='$' && word[_i] != str2[j]){
                        return "";
                    }
                    word[_i++] = str2[j];
                }
            }
        }
        //Fill empty spaces
        for(int i=0;i<n+m-1;i++){
            if(word[i] == '$'){
                word[i] = 'a';
                canChange[i] = true;
            }
        }
        //Checking for F
        for(int i=0;i<n;i++){
            if(str1[i] == 'F'){
                if(isSame(word, str2, i, m)){
                    bool changed = false;
                    for(int k=i+m-1;k>=i;k--){
                        if(canChange[k]){
                            canChange[k] = false;
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if(!changed){
                        return "";
                    }
                }
            }
        }
        return word;

    }
};