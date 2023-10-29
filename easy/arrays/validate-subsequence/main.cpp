#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int pointer = 0;
  for (const int &number : array) {
    const int sequentialNumber = sequence[pointer];
    if (sequentialNumber == number) {
      pointer++;
    }

    if (pointer == sequence.size()) {
      return true;
    }
  }
  return false;
}
