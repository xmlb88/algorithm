#include <iostream>
#include <list>
using namespace std;

List<List<Integer>> res = new LinkedList<>();

List<List<Integer>> permute(int[] nums) {
    LinkedList<Integer> track = new LinkedList<>();
    backtrace(nums, track);
    return res;
}

void backtrace(int[] nums, LinkedList<Integer> track) {
    if (track.size() == nums.length) {
        res.add(new LinkedList(track));
        return;
    }

    for (int i = 0; i < nums.length; i++) {
        if (track.contains(nums[i]))
            continue;
        track.add(nums[i]);
        backtrace(nums, track);
        track.removeLast();
    }
}

int main() {
    int nums[6] = [1, 2, 3, 4, 5, 6];
    cout << permute(nums) << endl;
}