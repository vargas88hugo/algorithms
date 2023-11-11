#include <vector>
using namespace std;

void quickSort(vector<int>& array);
void quickSortHandler(vector<int>& array, int startIndex, int endIndex);
void swap(vector<int>& array, int i, int j);
void squareArray(vector<int>& number);

vector<int> sortedSquaredArray(vector<int> array) {
  squareArray(array);
  quickSort(array);
  return array;
}

void squareArray(vector<int>& array) {
  for (int& element : array) {
    element *= element;
  }
}

void quickSort(vector<int>& array) {
  quickSortHandler(array, 0, array.size() - 1);
}

void quickSortHandler(vector<int>& array, int startIndex, int endIndex) {
  if (startIndex >= endIndex) {
    return;
  }

  int pivotIndex = startIndex;
  int leftIndex = startIndex + 1;
  int rightIndex = endIndex;

  while (leftIndex <= rightIndex) {
    if (array[rightIndex] < array[pivotIndex] && array[leftIndex] > array[pivotIndex]) {
      swap(array, rightIndex, leftIndex);
    } else if (array[rightIndex] >= array[pivotIndex]) {
      rightIndex--;
    } else if (array[leftIndex] <= array [pivotIndex]) {
      leftIndex++;
    }
  }
  swap(array, rightIndex, pivotIndex);

  int newPivotIndex = rightIndex;
  bool leftSubarrayIsShorter = (newPivotIndex - 1) - startIndex < endIndex - (newPivotIndex + 1);
  if (leftSubarrayIsShorter) {
    quickSortHandler(array, startIndex, newPivotIndex - 1);
    quickSortHandler(array, newPivotIndex + 1, endIndex);
  } else {
    quickSortHandler(array, newPivotIndex + 1, endIndex);
    quickSortHandler(array, startIndex, newPivotIndex - 1);
  }
}

void swap(vector<int>& array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
