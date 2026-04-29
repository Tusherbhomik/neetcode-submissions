class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto a:strs){
            //alphabet count
            vector<int>alpcnt(26,0);
            for(auto b:a){
                alpcnt[b-'a']++;
            }
            //create_string
            string temp="";
            for(auto a:alpcnt){
                temp+=to_string(a)+'#';
            }
            mp[temp].push_back(a);
        }
        vector<vector<string>>ans;
        for(auto &[a,b]:mp){
            ans.push_back(b);
        }
        return ans;
    }
};
