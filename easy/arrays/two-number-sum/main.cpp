#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
  unordered_map<int, bool> algebraicMap;

  for (const int &number : array)
  {
    int algebraicSimplification = targetSum - number;
    if (algebraicMap.count(algebraicSimplification))
    {
      return {number, algebraicSimplification};
    }
    algebraicMap[number] = true;
  }

  return {};
}
