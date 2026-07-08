class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        vector<int> pos, digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> prefSum(m + 1, 0);
        vector<long long> hash(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
            prefSum[i] = prefSum[i - 1] + digit[i - 1];
            hash[i] = (hash[i - 1] * 10 + digit[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            // Extract the number formed by digits[L...R] using rolling hash.
            long long x = (hash[R + 1] - (hash[L] * pow10[len]) % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};