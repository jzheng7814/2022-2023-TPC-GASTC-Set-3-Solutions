#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int N, adjMat[100][100], visited[100] = {}, dist[100] = {}, p[100], tot = 0;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> adjMat[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    p[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        int mn = INT_MAX, node;
        for (int j = 0; j < N; ++j)
        {
            if (visited[j])
            {
                continue;
            }

            if (dist[j] < mn)
            {
                mn = dist[j];
                node = j;
            }
        }

        tot += adjMat[p[node]][node];
        visited[node] = true;

        for (int j = 0; j < N; ++j)
        {
            if (visited[j])
            {
                continue;
            }

            if (adjMat[node][j] < dist[j])
            {
                dist[j] = adjMat[node][j];
                p[j] = node;
            }
        }
    }

    cout << tot << endl;
}