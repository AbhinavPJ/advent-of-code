/**
 * author:VectorVirtuoso
 * created: 02:14:58 on 26-11-2025
 **/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <iterator>
#include <numeric>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <functional>
#include <type_traits>
#include <exception>
#include <cassert>
#include <climits>
#include <cfloat>
#include <cctype>
#include <chrono>
#include <complex>
#include <random>
#include <valarray>
#include <locale>
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
using namespace std;
#define int ll
#define endl '\n' // comment for interactive
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define pb push_back
#define re resize
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define print(x) cout << #x << ": " << x << endl \
                      << flush
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> ii;
typedef array<int, 3> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
typedef vector<vi> vvi;
typedef priority_queue<int> pq;
template <class T>
bool ckmin(T &a, T b)
{
    bool B = a > b;
    a = min(a, b);
    return B;
}
template <class T>
bool ckmax(T &a, T b)
{
    bool B = a < b;
    a = max(a, b);
    return B;
}
const int inf = 1e17;
const int mod = 1e9 + 7;
int expo(int a, int b)
{
    if (a == 0 && b == 0)
    {
        return 1;
    }
    if (a == 0)
    {
        return 0;
    }
    if (b == 1)
    {
        return a;
    }
    if (b == 0)
    {
        return 1;
    }
    int x = expo(a, b / 2);
    if (b % 2 == 0)
    {
        return (x) * (x) % mod;
    }
    else
    {
        return (a * (x) % mod) * (x) % mod;
    }
}
int fac(int a)
{
    if (a == 0 || a == 1)
    {
        // factorial[a] = 1;
        return 1;
    }
    return (fac(a - 1) * a) % mod;
}
int nCr(int n, int r)
{
    int mod1 = fac(n);
    int mod2 = expo(fac(r), mod - 2);
    int mod3 = expo(fac(n - r), mod - 2);
    return (((mod1 * mod2) % mod) * mod3) % mod;
}
class SegmentTree
{
private:
    vector<long long> tree, lazy;
    vector<bool> lazySet;
    int n;

    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void propagate(int node, int start, int end)
    {
        if (lazySet[node])
        {
            tree[node] = lazy[node];

            if (start != end)
            {
                lazySet[2 * node + 1] = true;
                lazySet[2 * node + 2] = true;
                lazy[2 * node + 1] = lazy[node];
                lazy[2 * node + 2] = lazy[node];
            }

            lazy[node] = 0;
            lazySet[node] = false;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int value)
    {
        propagate(node, start, end);

        if (start > r || end < l)
        {
            return;
        }

        if (start >= l && end <= r)
        {
            lazySet[node] = true;
            lazy[node] = value;
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, value);
        updateRange(2 * node + 2, mid + 1, end, l, r, value);

        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    long long queryRange(int node, int start, int end, int l, int r)
    {
        propagate(node, start, end);

        if (start > r || end < l)
        {
            return LLONG_MAX; // Neutral value for min query
        }

        if (start >= l && end <= r)
        {
            return tree[node];
        }

        int mid = (start + end) / 2;
        long long leftQuery = queryRange(2 * node + 1, start, mid, l, r);
        long long rightQuery = queryRange(2 * node + 2, mid + 1, end, l, r);

        return min(leftQuery, rightQuery);
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n, LLONG_MAX);
        lazy.resize(4 * n, 0);
        lazySet.resize(4 * n, false);
        build(arr, 0, 0, n - 1);
    }

    void updateRange(int l, int r, int value)
    {
        updateRange(0, 0, n - 1, l, r, value);
    }

    long long queryRange(int l, int r)
    {
        return queryRange(0, 0, n - 1, l, r);
    }
};
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
// Golden Rules
/*
   Solutions are simple.

   Proofs are simple.

   Implementations are simple.
*/

void solve()
{
    string s;
    string line;
    while (getline(cin, line))
    {
        s += line;
    }
    int ans = 0;
    for (int i = 3; i < s.size(); i++)
    {
        string temp = s.substr(i - 3, 4);
        int cur = i + 1;
        if (temp == "mul(")
        {
            int a = 0, b = 0;
            bool bad = false;
            while (s[cur] != ',')
            {
                if (s[cur] < '0' || s[cur] > '9')
                {
                    bad = true;
                    break;
                }
                a = 10 * a + (s[cur] - '0');
                cur++;
                if (cur >= s.size())
                    break;
            }
            cur++;
            if (bad)
            {
                // print(cur);
                i = cur;
                continue;
            }
            print(a);
            if (cur >= s.size())
                break;
            while (s[cur] != ')')
            {
                if (s[cur] < '0' || s[cur] > '9')
                {
                    bad = true;
                    break;
                }
                b = 10 * b + (s[cur] - '0');
                cur++;
                if (cur >= s.size())
                    break;
            }
            print(b);
            if (cur >= s.size())
                break;
            if (!bad)
                ans += a * b;
        }
        i = cur - 1;
    }
    cout << ans << endl;
}

signed main()
{

    fast_io;

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}