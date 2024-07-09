//thanks to: cp-algorithms.com
ll tree[4*300000], lazy[4*300000];
void build(ll v, ll tl, ll tr) {
    lazy[v]=0;
    if (tl == tr) {
        tree[v] = 0;
    } else {
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2 + 1]);
    }
}

void push(ll v) {
    tree[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return -INF;
    if (l == tl && tr == r)
        return tree[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}