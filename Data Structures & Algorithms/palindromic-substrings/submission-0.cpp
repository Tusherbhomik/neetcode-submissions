class Solution {
    int count = 0;
    int n =0;
public:
    void expand(string &s,int l, int r){
        while(l>=0 && r<n && s[l]==s[r]){
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        n = s.length();
        cout<<n<<endl;
        for(int i = 0;i<n;i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return count;
    }
};
