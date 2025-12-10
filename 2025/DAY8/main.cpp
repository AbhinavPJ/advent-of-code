/**
 * author:VectorVirtuoso
 * created: 15:29:46 on 10-12-2025
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
struct DSU
{
    vi parent, rank;
    DSU(int n)
    {
        parent.re(n);
        rank.re(n, 0);
        loop(i, n) parent[i] = i;
    }
    int find(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
void solve()
{
    vti v;
    string s;
    map<ti, int> mp;
    int i = 0;
    while (getline(cin, s))
    {
        int x, y, z;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ',')
            {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        ss >> x >> y >> z;
        v.pb({x, y, z});
        mp[{x, y, z}] = i + 1;
        i++;
    }
    int n = v.size();
    vector<pair<int, pair<ti, ti>>> res;
    loop(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            res.pb({(v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) + (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]) + (v[i][2] - v[j][2]) * (v[i][2] - v[j][2]), {v[i], v[j]}});
        }
    }
    sort(all(res));
    DSU dsu(n);
    DSU dsu2(n);
    int prod = 1;
    loop(i, res.size())
    {
        if (i < n)
            dsu.unite(mp[res[i].second.first] - 1, mp[res[i].second.second] - 1);
        if (dsu2.find(mp[res[i].second.first] - 1) != dsu2.find(mp[res[i].second.second] - 1))
        {
            dsu2.unite(mp[res[i].second.first] - 1, mp[res[i].second.second] - 1);
            prod = res[i].second.first[0] * res[i].second.second[0];
        }
    }
    map<int, int> components;
    loop(i, n)
    {
        components[dsu.find(i)]++;
    }
    vi comp_sizes;
    for (auto &it : components)
    {
        comp_sizes.push_back(it.second);
    }
    sort(all(comp_sizes));
    reverse(all(comp_sizes));
    int prod2 = 1;
    loop(i, 3)
    {
        prod2 *= comp_sizes[i];
    }
    cout << prod2 << " " << prod << endl;
}

signed main()
{

    fast_io;

    int t = 1;
    auto start = chrono::high_resolution_clock::now();
    solve();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Time elapsed: " << elapsed.count() << " seconds" << endl;
    return 0;
}