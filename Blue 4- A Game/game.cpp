#include <algorithm>
#include <iostream>

using namespace std;

int N, S, nums[10];

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> N >> S;

    for (int i = 1; i <= N; ++i)
    {
        nums[i - 1] = i;
    }

    do
    {
        int nxt[10], prv[10];
        copy(nums, nums + N, prv);

        for (int i = N; i >= 0; --i)
        {
            for (int j = 0; j < i - 1; ++j)
            {
                nxt[j] = prv[j] + prv[j + 1];
            }

            copy(nxt, nxt + i, prv);
        }

        if (nxt[0] == S)
        {
            for (int i = 0; i < N - 1; ++i)
            {
                cout << nums[i] << ' ';
            }

            cout << nums[N - 1] << endl;
            return 0;
        }

    } while (next_permutation(nums, nums + N));

    cout << 1 << endl;
}