class Solution {
    int n;
public:

    int rec(vector<int>& stones,int i, int grp1, int  grp2){
        if(i==n) return abs(grp1-grp2);

        int a = rec(stones,i+1,grp1+stones[i],grp2);
        int b = rec(stones,i+1,grp1,grp2+stones[i]);
        return min(a,b);
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        return rec(stones,0,0,0);
    }
};