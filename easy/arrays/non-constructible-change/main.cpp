#include <vector>
using namespace std;

void quickSort(vector<int>& array, int startIndex, int endIndex);
void swap(vector<int>& array, int i, int j);

int nonConstructibleChange(vector<int> coins) {
  quickSort(coins, 0, coins.size() - 1);
  int change = 0;

  for (const int& coin : coins) {
    if (change + 1 < coin) {
      return change + 1;
    } else {
      change += coin;
    }
  }
  return change + 1;
}

void quickSort(vector<int>& array, int startIndex, int endIndex) {
  if (startIndex >= endIndex) {
    return;
  }

  int pivotIndex = startIndex;
  int leftIndex = startIndex + 1;
  int rightIndex = endIndex;

  while (leftIndex <= rightIndex) {
    if (array[leftIndex] > array[pivotIndex] && array[rightIndex] < array[pivotIndex]) {
      swap(array, leftIndex, rightIndex);
    } else if (array[leftIndex] <= array[pivotIndex]) {
      leftIndex++;
    } else if (array[rightIndex] >= array[pivotIndex]) {
      rightIndex--;
    }
  }
  swap(array, pivotIndex, rightIndex);

  bool leftSubarrayIsSmaller = rightIndex - 1 - startIndex < endIndex - (rightIndex + 1);

  if (leftSubarrayIsSmaller) {
    quickSort(array, startIndex, rightIndex - 1);
    quickSort(array, rightIndex + 1, endIndex);
  } else {
    quickSort(array, rightIndex + 1, endIndex);
    quickSort(array, startIndex, rightIndex - 1);
  }
}

void swap(vector<int>& array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
