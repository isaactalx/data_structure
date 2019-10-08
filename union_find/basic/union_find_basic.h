#ifndef __UNION_FIND_BASIC__
#define __UNION_FIND_BASIC__
namespace DS {
class UnionFind {
 public:
  virtual ~UnionFind(){}
  virtual int Find(int p) = 0;           //查找结点p对应的id
  virtual void Union(int p, int q) = 0;  //两个节点之间建立连接关系
  virtual bool IsConnected(int p, int q) = 0;  //判断两个结点是否连接
};
}  // namespace DS
#endif