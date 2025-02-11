#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
#define endl '\n'
#define ture true
#define flase false
#define pow power
#define all(x) begin(x), end(x)
#define mem(a, x) memset(a, x, sizeof(a))
#define gcd(a, b) gcdint(a, b)
#define lcm(a, b) (a / gcd(a, b) * b)
#define sz(x) (int)x.size()
#define lowbit(x) (x & -x)
#define pb push_back
#define EPS 1e-7
#define int ll
#define ll long long
#define i64 long long
#define i128 __int128
#define fr first
#define sc second
#define tcT template <class T
#define tcTU tcT, class U

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setPrec() { cout << fixed << setprecision(15); }
void setIO() { unsyncIO(), setPrec(); }

inline int gcdint(int a, int b) { return b ? gcdint(b, a % b) : a; }
inline i128 gcd128(i128 a, i128 b) { return b ? gcd128(b, a % b) : a; }
inline int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
inline int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

tcT > using V = vector<T>;
tcTU > using PR = pair<T, U>;
tcTU > using MP = map<T, U>;
tcTU > using VP = vector<pair<T, U>>;
tcT > using pqg = priority_queue<T, vector<T>, greater<T>>;
tcT > using pql = priority_queue<T, vector<T>, less<T>>;

tcTU > istream &operator>>(istream &in, pair<T, U> &a) {
  return in >> a.first >> a.second;
}

tcT > istream &operator>>(istream &in, vector<T> &a) {
  for (auto &x : a) {
    in >> x;
  }
  return in;
}

tcTU > ostream &operator<<(ostream &out, const pair<T, U> &a) {
  return out << a.first << ' ' << a.second;
}

tcTU > ostream &operator<<(ostream &out, const vector<pair<T, U>> &a) {
  for (auto &x : a) {
    out << x << endl;
  }
  return out;
}

tcT > ostream &operator<<(ostream &out, const vector<T> &a) {
  int n = a.size();
  if (!n) {
    return out;
  }
  out << a[0];
  for (int i = 1; i < n; i++) {
    out << ' ' << a[i];
  }
  return out;
}

std::ostream &operator<<(std::ostream &os, i128 n) {
  std::string s;
  while (n) {
    s += '0' + n % 10;
    n /= 10;
  }
  std::reverse(s.begin(), s.end());
  return os << s;
}

inline int power(int a, i64 b, int p = 1e9 + 7) {
  int res = 1;
  for (; b; b /= 2, a = 1LL * a * a % p) {
    if (b % 2) {
      res = 1LL * res * a % p;
    }
  }
  return res;
}

tcT > bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
tcT > bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

tcT > void remDup(vector<T> &v) {
  sort(all(v));
  v.erase(unique(all(v)), end(v));
}

tcTU > void erase(T &t, const U &u) {
  auto it = t.find(u);
  assert(it != end(t));
  t.erase(it);
}

tcTU > T fstTrue(T lo, T hi, U f) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}

tcTU > T lstTrue(T lo, T hi, U f) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}

constexpr int mod = 1e9 + 7;
constexpr int inf = 0x7fffffff;
constexpr int N = 1.01e6;
constexpr int M = 2.01e3;

#ifdef LOCAL
#include <C:/Users/70510/Desktop/Others/algo/debug.h>
#else
#define debug(...) 42
#endif

vector<int> buildPrefix(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  int half = arr.size() / 2;
  vector<int> diff(half);
  for (int i = 0; i < half; i++) {
    diff[i] = arr[arr.size() - 1 - i] - arr[i];
  }
  sort(diff.begin(), diff.end(), greater<int>());
  vector<int> prefix(half + 1, 0LL);
  for (int i = 1; i <= half; i++) {
    prefix[i] = prefix[i - 1] + diff[i - 1];
  }
  return prefix;
}

int ternaryMax(const vector<int> &A, const vector<int> &B, int k, int low,
               int high) {
  if (low > high) return 0;
  auto G = [&](int x) { return A[x] + B[k - x]; };
  while (high - low >= 3) {
    int m1 = low + (high - low) / 3;
    int m2 = high - (high - low) / 3;
    if (G(m1) < G(m2))
      low = m1 + 1;
    else
      high = m2 - 1;
  }
  int ret = 0;
  for (int i = low; i <= high; i++) {
    ret = max(ret, G(i));
  }
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }

  vector<long long> preA = buildPrefix(a);
  vector<long long> preB = buildPrefix(b);
  int maxPickA = (int)preA.size() - 1;
  int maxPickB = (int)preB.size() - 1;
  int kmax = min((n + m) / 3LL, (long long)maxPickA + maxPickB);
  vector<long long> f(kmax + 1, 0LL);

  for (int k = 1; k <= kmax; k++) {
    // i的可行区间
    // 要满足 i + (k−i) = k，2*i + (k−i) <= n => i <= n-k
    //           i + 2*(k−i) <= m => i >= 2*k - m
    // 同时 i >= 0, i <= k, i <= maxPickA, k−i <= maxPickB
    int low = max(0LL, (int)max((long long)k - maxPickB, 2LL * k - m));
    int high = min(k, min(maxPickA, n - k));
    if (low <= high) {
      auto bestVal = ternaryMax(preA, preB, k, low, high);
      f[k] = bestVal;
    }
  }

  while (kmax > 0 && f[kmax] == 0) kmax--;

  cout << kmax << endl;
  if (kmax > 0) {
    for (int i = 1; i <= kmax; i++) {
      cout << f[i] << (i < kmax ? ' ' : '\n');
    }
  }
}

signed main() {
  setIO();
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}