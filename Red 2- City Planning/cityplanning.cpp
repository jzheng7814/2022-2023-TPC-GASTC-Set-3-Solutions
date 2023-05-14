#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

template <class T, int SIZE>
class BIT
{
    public:
        T arr[SIZE + 1] = {};

        BIT()
        {

        }

        T qry(int idx)
        {
            T ret = 0;

            for (  ; idx > 0; idx -= (idx & -idx))
            {
                ret += arr[idx];
            }

            return ret;
        }

        void add(int idx, int val)
        {
            for (  ; idx <= SIZE; idx += (idx & -idx))
            {
                arr[idx] += val;
            }
        }
};

const int MAXN = 100000;

int N, c = 1;
ll ans = 0;
pair<int, int> buildings[MAXN + 1];
BIT<int, MAXN> b;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> buildings[i].first;
        buildings[i].second = i;

        b.add(i, 1);
    }

    sort(buildings + 1, buildings + N + 1);

    for (int i = 0; i < N; ++i)
    {
        cout << ans << endl;

        for (  ; c <= N && buildings[c].first <= i; ++c)
        {
            int idx = buildings[c].second;

            ans += b.qry(idx - 1);
            b.add(idx, -1);
        }
    }
}