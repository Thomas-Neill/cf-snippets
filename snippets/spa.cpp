// thanks to: cp-algorithms.com
const ll K = 25;
const ll MAXN = 400000;
ll st[K+1][MAXN];

void fill(vector<ll>& A) {
    std::copy(A.begin(), A.end(), st[0]);
    for (ll i = 1; i <= K; i++)
        for (ll j = 0; j + (1 << i) <= A.size(); j++)
            st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
}

ll sum(ll L, ll R) {
    ll r = 0;
    FORR(i,K,-1) {
        if ((1 << i) <= R - L + 1) {
            r += st[i][L];
            L += 1 << i;
        }
    }
    return r;
}