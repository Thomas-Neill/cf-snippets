// thanks to: cp-algorithms.com
ll tree[4*200000];
void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        tree[v] = 0;
    } else {
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}
void add(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        tree[v] += new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            add(v*2, tl, tm, pos, new_val);
        else
            add(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}