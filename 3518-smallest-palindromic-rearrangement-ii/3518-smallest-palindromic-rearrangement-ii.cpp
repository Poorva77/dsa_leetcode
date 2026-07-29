class Solution {
public:
    string smallestPalindrome(string s, int k) {
        // Count total frequencies of all characters
        vector<int> f(26, 0);
        for (char c : s) f[c - 'a']++;

        // Separate frequencies into the left half and find the middle character (if odd)
        vector<int> half(26, 0);
        int len = 0;
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            half[i] = f[i] / 2;
            len += half[i];
            if (f[i] % 2) mid = 'a' + i;
        }

        // Lambda helper: Calculates distinct permutations (n! / (c1! * c2! * ...)) capped at k
        auto getWays = [&](const vector<int>& cnt) -> long long {
            int total = 0;
            for (int x : cnt) total += x;
            long long ways = 1;
            for (int x : cnt) {
                // nCr computation to avoid overflow
                long long ncr = 1;
                int r = min(x, total - x);
                for (int i = 1; i <= r; ++i) {
                    ncr = ncr * (total - i + 1) / i;
                    if (ncr > k) ncr = k + 1;
                }
                ways *= ncr;
                if (ways > k) return k + 1;
                total -= x;
            }
            return ways;
        };

        // If k exceeds total possible distinct half-string permutations, return empty string
        if (getWays(half) < k) return "";

        // Construct the half-string position by position
        string left = "";
        for (int pos = 0; pos < len; ++pos) {
            for (int ch = 0; ch < 26; ++ch) {
                if (!half[ch]) continue;

                // Try placing character 'ch' at current position
                half[ch]--;
                long long ways = getWays(half);

                if (ways >= k) {
                    left += (char)('a' + ch);
                    break; // Confirmed character for pos
                }

                k -= ways;
                half[ch]++; // Backtrack and try next character
            }
        }

        // Mirror the half-string to build the full palindrome
        string res = left;
        if (mid) res += mid; // Add odd center character
        for (int i = (int)left.size() - 1; i >= 0; --i) res += left[i];

        return res;
    }
};