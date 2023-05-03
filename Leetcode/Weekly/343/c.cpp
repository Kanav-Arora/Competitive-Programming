#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define pp pair<int, pair<int, int>>

/*
1   Contraints are so big that we cannot make complete matrix and we don't need it
*/

class Solution
{
public:
    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
    {
        map<pair<int, int>, vector<pp>> graph;
        int si = start[0], sj = start[1], ti = target[0], tj = target[1];
        graph[{si, sj}].push_back({abs(ti - si) + abs(tj - sj), {ti, tj}});
        graph[{ti, tj}].push_back({abs(ti - si) + abs(tj - sj), {si, sj}});

        int size = specialRoads.size();
        for (int i = 0; i < size; i++)
        {
            int u1i = specialRoads[i][0], u1j = specialRoads[i][1], v1i = specialRoads[i][2], v1j = specialRoads[i][3], c1 = specialRoads[i][4];

            // edge u to start
            graph[{u1i, u1j}].push_back({abs(u1i - si) + abs(u1j - sj), {si, sj}});
            // start to edge u
            graph[{si, sj}].push_back({abs(u1i - si) + abs(u1j - sj), {u1i, u1j}});

            // edge v to start
            graph[{v1i, v1j}].push_back({abs(v1i - si) + abs(v1j - sj), {si, sj}});
            // start to edge v
            graph[{si, sj}].push_back({abs(v1i - si) + abs(v1j - sj), {v1i, v1j}});

            // edge u to target
            graph[{u1i, u1j}].push_back({abs(u1i - ti) + abs(u1j - tj), {ti, tj}});
            // target to edge u
            graph[{ti, tj}].push_back({abs(u1i - ti) + abs(u1j - tj), {u1i, u1j}});

            // edge v to target
            graph[{v1i, v1j}].push_back({abs(v1i - ti) + abs(v1j - tj), {ti, tj}});
            // target to edge v
            graph[{ti, tj}].push_back({abs(v1i - ti) + abs(v1j - tj), {v1i, v1j}});

            // adding edge from u to v and choosing the minimum cost. Note special roads might not give the better cost.
            graph[{u1i, u1j}].push_back({min(abs(v1i - u1i) + abs(v1j - u1j), c1), {v1i, v1j}});

            // linking this node with other special road nodes

            for (int j = i + 1; j < size; j++)
            {
                int u2i = specialRoads[j][0], u2j = specialRoads[j][1], v2i = specialRoads[j][2], v2j = specialRoads[j][3], c2 = specialRoads[j][4];

                // edge 1 node 1 -> edge 2 node 1
                graph[{u1i, u1j}].push_back({abs(u1i - u2i) + abs(u1j - u2j), {u2i, u2j}});
                // edge 1 node 1 -> edge 2 node 2
                graph[{u1i, u1j}].push_back({abs(u1i - v2i) + abs(u1j - v2j), {v2i, v2j}});

                // edge 1 node 2 -> edge 2 node 1
                graph[{v1i, v1j}].push_back({abs(v1i - u2i) + abs(v1j - u2j), {u2i, u2j}});
                // edge 1 node 2 -> edge 2 node 2
                graph[{v1i, v1j}].push_back({abs(v1i - v2i) + abs(v1j - v2j), {v2i, v2j}});

                // edge 2 node 1 -> edge 1 node 1
                graph[{u2i, u2j}].push_back({abs(u1i - u2i) + abs(u1j - u2j), {u1i, u1j}});
                // edge 2 node 1 -> edge 1 node 2
                graph[{u2i, u2j}].push_back({abs(u2i - v1i) + abs(u2j - v1j), {v1i, v1j}});

                // edge 2 node 2 -> edge 1 node 1
                graph[{v2i, v2j}].push_back({abs(v2i - u1i) + abs(v2j - u1j), {u1i, u1j}});
                // edge 2 node 2 -> edge 1 node 2
                graph[{v2i, v2j}].push_back({abs(v1i - v2i) + abs(v1j - v2j), {v1i, v1j}});
            }
        }

        map<pair<int, int>, int> vis;
        map<pair<int, int>, int> dis;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {si, sj}});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int cost = top.first;
            auto coord = top.second;

            if (vis[coord] == 1)
                continue;

            dis[coord] = cost;
            vis[coord] = 1;

            for (auto ch : graph[coord])
            {
                if (vis[ch.second] == 0)
                {
                    pq.push({cost + ch.first, ch.second});
                }
            }
        }

        return dis[{ti, tj}];
    }
};

int main()
{

    return 0;
}