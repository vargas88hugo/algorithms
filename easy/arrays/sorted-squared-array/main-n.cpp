#include <vector>
#include <cmath>

using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  vector<int> outputArray(array.size(), 0);
  int startIndex = 0;
  int endIndex = array.size() - 1;

  for (int i = array.size() - 1; i >= 0; i--) {
    int smallerValue = array[startIndex];
    int largerValue = array[endIndex];
  
    if (abs(smallerValue) > abs(largerValue)) {
      outputArray[i] = pow(smallerValue, 2);
      startIndex++;
    } else {
      outputArray[i] = pow(largerValue, 2);
      endIndex--;
    }
  }

  return outputArray;
}
