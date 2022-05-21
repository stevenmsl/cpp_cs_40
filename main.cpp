#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol40;

/*
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

tuple<vector<int>, int, vector<vector<int>>>
testFixture1()
{
  auto candidates = vector<int>{10, 1, 2, 7, 6, 1, 5};
  auto output = vector<vector<int>>{
      {1, 7},
      {1, 2, 5},
      {2, 6},
      {1, 1, 6}};
  return make_tuple(candidates, 8, output);
}

/*
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

tuple<vector<int>, int, vector<vector<int>>>
testFixture2()
{
  auto candidates = vector<int>{2, 5, 2, 1, 2};
  auto output = vector<vector<int>>{
      {1, 2, 2},
      {5}};
  return make_tuple(candidates, 5, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}