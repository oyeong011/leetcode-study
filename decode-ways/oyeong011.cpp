class Solution {
public:
    int dp[104];
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return go(s, 0);
    }

    int go(string s, int idx) {
        if (idx >= s.length()) return 1;
        if (s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int ret = 0;

        ret += go(s, idx + 1);

        if (idx + 1 < s.length() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))) {
            ret += go(s, idx + 2);
        }

        return dp[idx] = ret;
    }
};
