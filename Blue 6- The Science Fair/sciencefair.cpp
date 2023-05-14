#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, arr[100000];

bool ok(int x)
{
    priority_queue<int, vector<int>, greater<int>> q;
    int ind = 0;

    for (int i = 0; i < x; ++i)
    {
        q.push(arr[ind++]);
    }

    while (ind < N)
    {
        int f = q.top(); q.pop();
        q.push(arr[ind++] + f);
    }

    for (int i = 0; i < x - 1; ++i)
    {
        q.pop();
    }

    return q.top() <= K;
}

int main()
{
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int x = -1;
    for (int b = N + 1; b >= 1; b /= 2)
    {
        while (!ok(x + b))
        {
            x += b;
        }
    }

    cout << x + 1 << endl;
}