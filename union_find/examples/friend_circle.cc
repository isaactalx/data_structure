/**
 *
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知
A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是
C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] =
1，表示已知第 i 个和 j
个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:

输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friend-circles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;
    vector<int> unions(M.size());
    for (int i = 0; i < unions.size(); ++i) {
      unions[i] = i;
    }
    for (int i = 0; i < M.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (M[i][j] == 1) {
          buildUnions(unions, i, j);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < unions.size(); ++i) {
      if (i == findParent(unions, i)) {
        ++res;
      }
    }
    return res;
  }
  int findParent(const vector<int>& unions, int p) {
    while (p != unions[p]) {
      p = unions[p];
    }
    return p;
  }
  void buildUnions(vector<int>& unions, int p, int q) {
    int root_p = findParent(unions, p);
    int root_q = findParent(unions, q);
    if (root_p != root_q) {  //这里N较小就没有用rank优化
      unions[root_q] = root_p;
    }
  }
};