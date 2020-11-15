#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 直接排序
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++) {
        res.push_back(arr[i]);
    }
    return res;
}

// 最大堆
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
    if (k == 0) return res;
    priority_queue<int> heap;
    for (int i = 0; i < arr.size(); i++) {
        if (i < k) {
            heap.push(arr[i]);
        }
        else {
            if (arr[i] > heap.top()) continue;
            else {
                heap.pop();
                heap.push(arr[i]);
            }
        }
    }

    while (!heap.empty()) {
        res.push_back(heap.top());
        heap.pop();
    }

    return res;
}

// 退化的快速排序 快速选择
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    srand((unsigned)time(NULL));
    randomized_selected(arr, 0, arr.size() - 1, k);
    vector<int> vec;
    for (int i = 0; i < k; i++) {
        vec.push_back(arr[i]);
    }
    return vec;
}

void randomized_selected(vector<int>& arr, int l, int r, int k) {
    if (l >= r) return;

    int pos = randomized_partition(arr, l, r);
    int num = pos - l + 1;
    if (k == num) return;
    else if (k < num) {
        randomized_selected(arr, l, pos - 1, k);
    } else {
        randomized_selected(arr, pos + 1, r, k - num);
    }
}

int randomized_partition(vector<int>& nums, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(nums[r], nums[i]);
    return partition(nums, l, r);
}

int partition(vector<int>& nums, int l, int r) {
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (nums[j] <= pivot) {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}

// 5 6 2 3 7 4 
// l         r
//           pivot


vector<int> getLeastNumbers(vector<int>& arr, int k) {
    srand((unsigned)time(NULL));
    random_selected(arr, k, l, r);
    vector<int> vec;
    for (int i = 0; i < k; i++) {
        vec.push_back(arr[i]);
    }
    return vec;
}

void random_selected(vector<int>& arr, int k, int l, int r) {
    if (l >= r) return;
    int index = random_partition(arr, l, r);
    if (index == k) return;
    else if (index < k) {
        random_selected(arr, k, index + 1, r);
    } else if (index > k) {
        random_selected(arr, k, l, index - 1);
    }

}

int random_partition(vector<int>& arr, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(arr[l], arr[i]);
    return partition(arr, l, r);
}

int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[l];
    while (l < r) {
        while (l < r && arr[r] >= pivot) {
            r--;
        }
        if (l < r) {
            arr[l] = arr[r];
        }
        if (l < r && arr[l] <= pivot) {
            l++;
        }
        if (l < r) {
            arr[r] = arr[l];
        }
    }
    arr[l] = pivot;
    return l;
}

