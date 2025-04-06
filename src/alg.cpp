// Copyright 2021 NNTU-CS
#include <iostream>
#include <ctime>
#include <iomanip>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j] == value)
                && arr[i] >= 0
                && arr[j] >= 0) {
                count++;
            }
        }
    }
    if (count == 0)
        return 0;
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int pos = len - 1;
    for (int i = len; i > 0; --i) {
        if (arr[i] > value) {
            pos = i;
        }
    }
    for (int i = 0; i < pos; ++i) {
        for (int j = pos; j > i; --j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    if (count != 0) {
        return count;
    }
    return 0;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (arr[i] > value)
            break;

        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int first = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (first != -1) {
            int last = first;
            while (last + 1 < len && arr[last + 1] == target)
                ++last;
            count += (last - first + 1);
        }
    }
    return count;
}
