class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);

        int left = INT_MAX;
        int right = INT_MIN;
        int ans = -1;

        for (vector<int>& e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (online[u] && online[v]) {
                graph[u].emplace_back(v, w);
                right = max(right, w);
                left = min(left, w);
            }
        }

        auto canReach = [&](int threshold) -> bool {

            const long long LIMIT = 1e18;

            vector<long long> dist(n, LIMIT);
            dist[0] = 0;

            priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > pq;

            pq.emplace(0, 0);

            while (!pq.empty()) {

                auto [cost, u] = pq.top();
                pq.pop();

                if (cost > dist[u]) continue;

                if (u == n - 1)
                    return cost <= k;

                for (auto &[v, w] : graph[u]) {

                    if (w < threshold)
                        continue;

                    long long newCost = cost + w;

                    if (newCost < dist[v] && newCost <= k) {
                        dist[v] = newCost;
                        pq.emplace(newCost, v);
                    }
                }
            }

            return false;
        };

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canReach(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};