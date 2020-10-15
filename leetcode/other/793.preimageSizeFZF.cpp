#include <iostream>
using namespace std;

int preimageSizeFZF(int k) {
    int i = 1;
    int count = 0;
    while (trailingZeroes(i) < k) {
        i++;
    }

    while (trailingZeroes(i) == k) {
        count++;
        i++;
    }
    return count;
}

int trailingZeroes(int n) {
    int res = 0;
    long divisor = 5;
    while (divisor <= n) {
        res += n / divisor;
        divisor *= 5;
    }
    return res;
}


// ¶þ·Ö
long trailingZeroes(long n) {
    long res;
    for (long d = n; d / 5 > 0; d /= 5) {
        res += d / 5;
    }
    return res;
}

int preimageSizeFZF(int k) {
    long left_bound, right_bound;

    long lo = 0, hi = LONG_MAX;
    while (lo <= hi) {
        long mid = lo + (hi - lo) / 2;
        if (trailingZeroes(mid) < k) {
            lo = mid + 1;
        } else if (trailingZeroes(mid) > k) {
            hi = mid - 1;
        } else if (trailingZeroes(mid) == k) {
            hi = mid - 1;
        }
    }

    left_bound = lo;

    lo = 0, hi = LONG_MAX;
    while (lo <= hi) {
        long mid = lo + (hi - lo) / 2;
        if (trailingZeroes(mid) < k) {
            lo = mid + 1;
        } else if (trailingZeroes(mid) > k) {
            hi = mid - 1;
        } else if (trailingZeroes(mid) == k) {
            lo = mid + 1;
        }
    }

    right_bound = lo;

    return right_bound - left_bound + 1;
}


// another way
long preimageSizeFZF(int k) {
    long lo = 0, hi = LONG_MAX;
    while (lo <= hi) {
        long mid = lo + (hi - lo) / 2;
        if (trailingZeroes(mid) == k) {
            return 5;
        } else if (trailingZeroes(mid) < k) {
            lo = mid + 1;
        } else if (trailingZeroes(mid) > k) {
            hi = mid - 1;
        }
    }
    return 0;
}

long trailingZeroes(long n) {
    long res = 0;
    for (long d = n; d / 5 > 0; d /= 5) {
        res += d / 5;
    }
    return res;
}