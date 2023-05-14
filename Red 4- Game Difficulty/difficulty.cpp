#include <iostream>

using namespace std;

int N, M, adjMat[101][101], dist[101][101], seq[10000];

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> seq[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> adjMat[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            dist[i][j] = adjMat[i][j];
        }
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int tot = 0;
    for (int i = 0; i < M - 1; ++i)
    {
        tot += dist[seq[i]][seq[i + 1]];
    }

    cout << tot << endl;
}
