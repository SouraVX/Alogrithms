#include <iostream>
#include <optional>
#include <tuple>
#include <type_traits>

using namespace std;

optional<int> binarySearchRecursive(int *SortedArray, int LeftIndex,
                                    int RightIndex, int Key) {

  int MiddleIndex = (RightIndex + LeftIndex) / 2;

  if (Key == SortedArray[MiddleIndex])
    return Key;
  MiddleIndex = (RightIndex + LeftIndex) / 2;
  if (Key < SortedArray[MiddleIndex] && LeftIndex < RightIndex)
    return binarySearchRecursive(SortedArray, LeftIndex, MiddleIndex, Key);
  else if (Key > SortedArray[MiddleIndex] && LeftIndex < RightIndex)
    return binarySearchRecursive(SortedArray, MiddleIndex + 1, RightIndex, Key);
  return nullopt;
}

optional<int> binarySearchIterative(tuple<int *, int, int> SearchEntity) {

  int LeftIndex = 0;
  int RightIndex = get<1>(SearchEntity);
  int MiddleIndex = 0;
  int Key = get<2>(SearchEntity);

  while (LeftIndex < RightIndex) {
    MiddleIndex = (RightIndex + LeftIndex) / 2;
    if (Key == get<0>(SearchEntity)[MiddleIndex])
      return Key;
    else if (Key < get<0>(SearchEntity)[MiddleIndex])
      RightIndex = MiddleIndex;
    else
      LeftIndex = MiddleIndex + 1;
  }
  return nullopt;
}
