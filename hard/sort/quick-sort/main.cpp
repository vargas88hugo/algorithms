#include <vector>
using namespace std;

void swap(vector<int>& array, int i, int j);
void quickSortHelper(vector<int>& array, int startIndex, int endIndex);

vector<int> quickSort(vector<int> array) {
  quickSortHelper(array, 0, array.size() - 1);
  return array;
}

void quickSortHelper(vector<int>& array, int startIndex, int endIndex) {
  if (startIndex >= endIndex) {
    return;
  }

  int pivotIndex = startIndex;
  int leftIndex = startIndex + 1;
  int rightIndex = endIndex;

  while (leftIndex <= rightIndex) {
    if (array[leftIndex] > array[pivotIndex] && array[rightIndex] < array[pivotIndex]){
      swap(array, leftIndex, rightIndex);
    } else if (array[leftIndex] <= array[pivotIndex]) {
      leftIndex++;
    } else if (array[rightIndex] >= array[pivotIndex]) {
      rightIndex--;
    }
  }
  swap(array, pivotIndex, rightIndex);

  bool leftSubArrayIsSmaller = rightIndex - 1 - startIndex < endIndex - (rightIndex + 1);

  if (leftSubArrayIsSmaller) {
    quickSortHelper(array, startIndex, rightIndex - 1);
    quickSortHelper(array, rightIndex + 1, endIndex);
  } else {
    quickSortHelper(array, rightIndex + 1, endIndex);
    quickSortHelper(array, startIndex, rightIndex - 1);
  }
}

void swap(vector<int>& array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}