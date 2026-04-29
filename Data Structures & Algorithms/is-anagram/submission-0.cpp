class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>s_seen(26,0);
        vector<int>t_seen(26,0);
        for(int i=0;i<s.size();i++){
            s_seen[s[i]-'a']++;
            t_seen[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(s_seen[i]!=t_seen[i]) return false;
        }
        return true;
    }
};
