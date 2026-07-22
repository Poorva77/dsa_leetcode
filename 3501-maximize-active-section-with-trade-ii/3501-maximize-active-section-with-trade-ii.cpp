class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        // Extract all contiguous zero-blocks
        vector<int> z_start, z_end, z_len;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                z_start.push_back(i);
                z_end.push_back(j - 1);
                z_len.push_back(j - i);
                i = j;
            } else {
                i++;
            }
        }

        int m = z_len.size();

        // Sparse Table for adjacent zero-block sums: A[i] = z_len[i] + z_len[i+1]
        int K = m > 1 ? log2(m - 1) + 1 : 1;
        vector<vector<int>> st(K, vector<int>(max(0, m - 1), 0));

        for (int i = 0; i < m - 1; ++i) {
            st[0][i] = z_len[i] + z_len[i + 1];
        }

        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= m - 1; ++i) {
                // Corrected Sparse Table transition
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto query_rmq = [&](int L, int R) {
            if (L > R) return 0;
            int j = log2(R - L + 1);
            return max(st[j][L], st[j][R - (1 << j) + 1]);
        };

        // Calculates effective length of a zero-block trimmed to query bounds [l, r]
        auto get_eff_len = [&](int idx, int l, int r) {
            int start_pos = max(z_start[idx], l);
            int end_pos = min(z_end[idx], r);
            return max(0, end_pos - start_pos + 1);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            // Find first zero-block that intersects [l, r]
            auto it_first = lower_bound(z_end.begin(), z_end.end(), l);
            if (it_first == z_end.end()) {
                ans.push_back(total_ones);
                continue;
            }
            int first_z = distance(z_end.begin(), it_first);

            // Find last zero-block that intersects [l, r]
            auto it_last = upper_bound(z_start.begin(), z_start.end(), r);
            if (it_last == z_start.begin()) {
                ans.push_back(total_ones);
                continue;
            }
            int last_z = distance(z_start.begin(), it_last) - 1;

            if (first_z >= last_z) {
                // Need at least 2 zero-blocks within range [l, r] to perform a valid trade
                ans.push_back(total_ones);
                continue;
            }

            int max_gain = 0;

            if (last_z - first_z == 1) {
                // Exactly 2 zero-blocks touch [l, r]
                max_gain = get_eff_len(first_z, l, r) + get_eff_len(last_z, l, r);
            } else {
                // 1. First adjacent pair (involves potentially clipped first_z)
                max_gain = max(max_gain, get_eff_len(first_z, l, r) + z_len[first_z + 1]);

                // 2. Last adjacent pair (involves potentially clipped last_z)
                max_gain = max(max_gain, z_len[last_z - 1] + get_eff_len(last_z, l, r));

                // 3. Fully contained interior adjacent pairs
                if (first_z + 1 <= last_z - 2) {
                    max_gain = max(max_gain, query_rmq(first_z + 1, last_z - 2));
                }
            }

            ans.push_back(total_ones + max_gain);
        }

        return ans;
    }
};