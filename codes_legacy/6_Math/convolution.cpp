VT convolution(VT &a, VT &b) { // NTT
    int len = 1<<(__lg(SZ(a) + SZ(b)) + 1); 
    a.resize(len); b.resize(len);
    vector<int> d1(len), d2(len), c(len), res(len);
    ntt(false, a, d1, len);
    ntt(false, b, d2, len);
    for (int i = 0; i < len; i++) c[i] = d1[i] * d2[i] % P;
    ntt(true, c, res, len); 
    return res;
}
