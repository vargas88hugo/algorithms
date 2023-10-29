function twoNumberSum(array, targetSum) {
  // Write your code here.
  const algebraicMap = new Map();

  for (const number of array) {
    const algebraicSimplification = targetSum - number;
    if (algebraicMap.has(algebraicSimplification)) {
      return [number, algebraicSimplification];
    }
    algebraicMap.set(number, true);
  }

  return [];
}

// Do not edit the line below.
exports.twoNumberSum = twoNumberSum;