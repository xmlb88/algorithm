int findNthDigit(int n) {
    // bit 记录所在区间的位数，p记录所在区间的长度
    long long bit = 1, p = 9;
    while (n - bit * p > 0) {
        n -= bit * p;
        bit++;
        p *= 10;
    }

    // num 是答案所在数字
    int num = pow(10, bit - 1) + (n - 1) / bit;

    // pos 是答案在num中的位数
    int pos = n % bit;
    pos = pos == 0 ? bit : pos;
    int t = pow(10, bit - pos);
    return num / t % 10;
}