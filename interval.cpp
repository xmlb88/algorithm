#include <iostream>
using namespace std;

public int intervalSchedule(int[][] intvs) {
    if (intvs.length == 0) return 0;
    // 按照end升序排序
    Arrays.sort(intvs, new Comparator<int[]>() {
        public int compare(int[], a, int[], b) {
            return a[1] - b[1];
        }
    });
    // 至少一个区间不相交
    int count = 1;
    int x_end = intvs[0][1];
    for (int[] interval : intvs) {
        int start = interval[0];
        if (start >= x_end) {
            // 找到下一个选择的区间了
            count++;
            x_end = interval[1];
        }
    }
    return count;
}