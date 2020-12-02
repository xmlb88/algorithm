int findNthDigit(int n) {
    // bit ��¼���������λ����p��¼��������ĳ���
    long long bit = 1, p = 9;
    while (n - bit * p > 0) {
        n -= bit * p;
        bit++;
        p *= 10;
    }

    // num �Ǵ���������
    int num = pow(10, bit - 1) + (n - 1) / bit;

    // pos �Ǵ���num�е�λ��
    int pos = n % bit;
    pos = pos == 0 ? bit : pos;
    int t = pow(10, bit - pos);
    return num / t % 10;
}