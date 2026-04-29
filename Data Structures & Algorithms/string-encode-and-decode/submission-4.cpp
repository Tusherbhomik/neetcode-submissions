class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (const string &s : strs)// auto a -->  copies in new  location extra memory  cost
            res += to_string(s.size()) + "#" + s;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while (i < s.size()) {
            int len = 0;
            while (s[i] != '#') len = len * 10 + (s[i++] - '0');
            i++;
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};