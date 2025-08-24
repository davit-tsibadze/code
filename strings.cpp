void zFunction(string s){
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        if (i <= r) {
            int k = i - l;
            z[i] = min(r - i + 1, z[k]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
}