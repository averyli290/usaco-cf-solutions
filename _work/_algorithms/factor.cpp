// please don't have to look at this ever again

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {        // only check up to sqrt(n)
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1) factorization.push_back(n);          // dont forget to add n as a prime factor itself
                                                    // if remaining number is greater than 1
    return factorization;
}