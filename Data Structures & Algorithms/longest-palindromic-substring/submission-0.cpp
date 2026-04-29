class Solution {
public:
    bool rec(string &s, int l,int r){
        if(l>=r) return true;
        if(s[l]==s[r]) return rec(s,l+1,r-1);
        return false;
    }

    string longestPalindrome(string s) {
        int maxL = 0;
        int startI=0;

        for(int i = 0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(rec(s,i,j)){
                    if(j-i+1 > maxL){
                        maxL = j-i+1;
                        startI = i;
                    }
                }
            }
        }
        return s.substr(startI, maxL);
    }
};