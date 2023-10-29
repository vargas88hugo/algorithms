function isValidSubsequence(array, sequence) {
  let pointer = 0;
  for (const element of array) {
    const subsequentNumber = sequence[pointer];
    if (subsequentNumber === element) {
      pointer++;
    }

    if (pointer === sequence.length) {
      return true;
    }
    
  }
  return false;
}

// Do not edit the line below.
exports.isValidSubsequence = isValidSubsequence;
