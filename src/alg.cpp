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
    int count = 0, mid = 0, start = 0, end = len,
        i = 0, find = 0, mid2 = 0;
    for (int i = 0; i < len; i++) {
        find = value - arr[i];
        start = i + 1;
        end = len - 1;
        bool flag = false;
        if (arr[i] > value) {
            break;
        }
        while ((start <= end) && (!flag)) {
            mid = (start + end) / 2;
            if (arr[mid] == find) {
                flag = true;
                mid2 = mid;
                count++;
            }
            if (arr[mid] > find) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        while (arr[mid] == find) {
            mid++;
            if (arr[mid] == find) {
                count++;
            }
        }
        mid = mid2;
        while ((arr[mid] == find) && (--mid > i)) {
            if (arr[mid] == find) {
                count++;
            }
        }
    }
    if (count != 0) {
        return count;
    }
    return 0;
}
