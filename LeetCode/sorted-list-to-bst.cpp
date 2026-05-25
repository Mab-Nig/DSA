#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() {
    if (next) {
      delete next;
    }
  }
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
  ~TreeNode() {
    if (left) {
      delete left;
    }
    if (right) {
      delete right;
    }
  }
};

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
      return nullptr;
    }

    std::vector<int> nums;
    for (ListNode *p = head; p; p = p->next) {
      nums.push_back(p->val);
    }
    return build_tree(nums, 0, nums.size() - 1);
  }

private:
  TreeNode *build_tree(const std::vector<int> &nums, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    if (l == r) {
      return new TreeNode(nums[l]);
    }

    int mid = (l + r) >> 1;
    TreeNode *left = build_tree(nums, l, mid - 1);
    TreeNode *right = build_tree(nums, mid + 1, r);
    return new TreeNode(nums[mid], left, right);
  }
};
