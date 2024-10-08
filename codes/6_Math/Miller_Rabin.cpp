// n < 4,759,123,141      3 : 2, 7, 61
// n < 1,122,004,669,633  4 : 2, 13, 23, 1662803
// n < 3,474,749,660,383  6 : primes <= 13
// 7 : 2,325,9375,28178,450775,9780504,1795265022
#define llu unsigned long long
llu add(llu a, llu b, llu c) { return (__int128{a} + b) % c; }
llu mul(llu a, llu b, llu c) { return __int128{a} * b % c; }
llu mpow(llu a, llu b, llu c) {
  llu res = 1;
  while (b) {
    if (b & 1) res = mul(res, a, c);
    a = mul(a, a, c) ; b>>=1;
  }
  return res;
}
inline bool isprime(llu x) {
  static auto witn = [](llu a, llu n, int t) {
    if (!a) return false;
    while (t--) {
      llu a2 = mul(a, a, n);
      if (a2 == 1 && a != 1 && a != n - 1) return true;
      a = a2;
    }
    return a != 1; };
  if (x < 2) return false; if (!(x & 1)) return x == 2;
  int t = __builtin_ctzll(x - 1); llu odd = (x - 1) >> t;
  for (llu m:{2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    if (witn(mpow(m % x, odd, x), x, t)) return false;
  return true;
}

