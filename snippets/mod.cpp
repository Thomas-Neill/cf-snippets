ll MOD = 998244353;
vll FACT(1e5);

ll fastexp(ll a, ll p) {
    ll r = 1;
    while(p) {
        if(p&1) r = r*a % MOD;
        a = a*a % MOD;
        p >>= 1;
    }
    return r;
}

ll modinv(ll x) {
    return fastexp(x,MOD-2);
}

void DOFACTS() {
    FACT[0] = 1;
    FOR(i,1,FACT.size()) {
        FACT[i] = i*FACT[i-1] % MOD;
    }
}

ll gcd(ll a, ll b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

ll nCk(ll n, ll k) {
    ll r0 = FACT[n];
    r0 *= modinv(FACT[k]);
    r0 %= MOD;
    r0 *= modinv(FACT[n-k]);
    r0 %= MOD;
    return r0;
}