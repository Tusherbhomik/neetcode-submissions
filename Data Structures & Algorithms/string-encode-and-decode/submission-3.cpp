class Solution {
public:

    string encode(vector<string>& strs) {
        string f="";
        for(auto a:strs){
            f+=to_string(a.size())+"#"+a;
        }
        return f;
    }

    vector<string> decode(string s) {
        vector<string>strs;
        int i=0;
        while(i<s.size()){
            string len ="";
            while(s[i]!='#') len+=s[i++];
            int length= stoi(len);
            strs.push_back(s.substr(i+1,length));
            i+=1+length;
        }
        return strs;
    }
};
