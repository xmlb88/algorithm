int binarySearch(int[] nums, int target) {
    int left = 0, right = ...;

    while(...) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ...
        } else if (nums[mid] < target) {
            left = ...
        } else if (nums[mid] > target) {
            right = ...
        }
    }
    return ...;
}

int binarySearch(int[] nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // ע��

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // ע��
        else if (nums[mid] > target)
            right = mid - 1; // ע��
    }
    return -1;
}

int left_bound(int[] nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size(); // ע��

    while(left < right) { // ע��
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // ע��
        }
    }
    return left;
}

int left_bound(int[] nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}