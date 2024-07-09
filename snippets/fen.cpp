// thanks to: cp-algorithms.com
ll bit[1000000];
ll N;

ll sum(ll r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

ll sum(ll l, ll r) {
    return sum(r) - sum(l - 1);
}

void add(ll idx, ll delta) {
    for (; idx < N; idx = idx | (idx + 1))
        bit[idx] += delta;
}

void update(ll idx, ll delta) {
    add(idx, delta-sum(idx,idx));
}