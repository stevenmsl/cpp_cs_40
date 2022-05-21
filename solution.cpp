#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol40;
using namespace std;

/*takeaways
  - refer to question 39 for more information
  - sort the numbers in ascending order
    - so we can calculate the sum and avoid
      duplicates easily
  - {1,2,2,2,5}
    - pick 1
      - then 2 (index 1), and then 2 (index 2) to form {1,2,2}
      - skip 2 (index 2) or we will create another {1,2,2}
      - skip 2 (index 3) to avoid potential duplicates

 */

void Solution::_find(
    vector<int> &candidates,
    int start, int target,
    vector<int> &combination, vector<vector<int>> &result)
{
  if (target == 0)
  {
    result.push_back(combination);
    return;
  }
  int n = candidates.size();
  for (auto picked = start; picked < n; picked++)
  {
    if (candidates[picked] > target)
      break;

    /* we are at the same recursion level
       avoid picking the same number
       (albeit different index) so we
       won't have duplicate combinations
    */
    if (picked > start && candidates[start] == candidates[picked])
      continue;

    combination.push_back(candidates[picked]);
    /* start from picked + 1 as each number can only be used once
     */
    _find(candidates, picked + 1, target - candidates[picked], combination, result);
    combination.pop_back();
  }
}

vector<vector<int>> Solution::find(vector<int> &candidates, int target)
{
  auto result = vector<vector<int>>();
  auto c = vector<int>();
  /* start from the smaller numbers */
  sort(begin(candidates), end(candidates));

  _find(candidates, 0, target, c, result);

  return result;
}
