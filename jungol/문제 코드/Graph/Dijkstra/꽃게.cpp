#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

struct node{
    LL dist;
    int idx;
    int cnt;

    node (LL d = 1e9, int i = -1, int c = 0) : dist(d), idx(i), cnt(c) {}
    bool operator<(const node& a) const {
        return dist > a.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, N, K;
    cin >> M >> N >> K;

    unordered_map<int,vector<int>> sameX, sameY;
    vector<iipair> edges(K);

    for (auto& [x, y] : edges) cin >> x >> y;
    edges.emplace_back(M, N);
    K++;

    for (int i = 0; i < K; i++) {
        const auto& [x, y] = edges[i];
        sameX[x].push_back(i);
        sameY[y].push_back(i);
    }

    vector<int> xIdx(K), yIdx(K);
    for (auto& [k, v] : sameX) {
        sort(v.begin(), v.end(), [&](const int& a, const int& b) {return edges[a].second < edges[b].second;});
        for (int i = 0; i < v.size(); i++) {
            yIdx[v[i]] = i;
        }
    }
    for (auto& [k, v] : sameY) {
        sort(v.begin(), v.end(), [&](const int& a, const int& b) {return edges[a].first < edges[b].first;});
        for (int i = 0; i < v.size(); i++) {
            xIdx[v[i]] = i;
        }
    }

    TwoVector<LL> dist(K, vector<LL>(2, 1e18)); // x방향으로 움직이면 0
    priority_queue<node> pq;

    for (auto& i : sameX[1]) {
        pq.push({abs(edges[i].second - 1), i, 1});
        dist[i][1] = abs(edges[i].second - 1);
    }

    while (!pq.empty()) {
        auto [d, cur, cnt] = pq.top();
        pq.pop();

        if (dist[cur][cnt % 2] < d) continue;

        if (cnt % 2) {
            for (const auto& delta : {-1, 1}) {
                auto& v = sameX[edges[cur].first];
                int idx = yIdx[cur];

                if (idx + delta < 0 || idx + delta >= v.size()) continue;
                int next = v[idx + delta];
                LL nxtDist = d + abs(edges[next].second - edges[cur].second);

                if (nxtDist < dist[next][1]) {
                    dist[next][1] = nxtDist;
                    pq.emplace(nxtDist, next, cnt);
                }
            }
        }
        else {
            for (const auto& delta : {-1, 1}) {
                auto& v = sameY[edges[cur].second];
                int idx = xIdx[cur];

                
                if (idx + delta < 0 || idx + delta>= v.size()) continue;
                int next = v[idx + delta];
                LL nxtDist = d + abs(edges[next].first - edges[cur].first);

                if (nxtDist < dist[next][0]) {
                    dist[next][0] = nxtDist;
                    pq.emplace(nxtDist, next, cnt);
                }
            }
        }

        if (d + 1 < dist[cur][(cnt+1)%2]) {
            dist[cur][(cnt + 1) % 2] = d + 1;
            pq.emplace(d + 1, cur, cnt+1);
        }
    }

    LL ans = min(dist.back()[0], dist.back()[1]);
    if (ans == 1e18) cout << -1;
    else cout << ans;

    return 0;
}