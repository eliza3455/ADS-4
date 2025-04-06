// Copyright 2021 NNTU-CS
#include <iostream>
#include <ctime>
#include <iomanip>

int countPairs1(int *arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len-1; ++i) {
    for (int j = i+1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        result++;
      }
    }
  }
  return result;
}

int countPairs2(int *arr, int len, int value) {
  int result = 0;
  int left = 0, right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int lCount = 1, rCount = 1;
      while (left + 1 < right && arr[left] == arr[left + 1]) {
        lCount++;
        left++;
      }
      while (right - 1 > left && arr[right] == arr[right - 1]) {
        rCount++;
        right--;
      }
      result += lCount * rCount;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return result;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len-1; ++i) {
    int target = value - arr[i];
    int left = i+1;
    int right = len - 1;
    int firstMatch = -1;
    while (left <= right) {
      int mid = (left + right)/2;
      if (arr[mid] == target) {
        firstMatch = mid;
        right = mid - 1;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (firstMatch != -1) {
      int k = firstMatch;
      while (k < len && arr[k] == target) {
        count++;
        k++;
      }
    }
  }
  return count;
}
