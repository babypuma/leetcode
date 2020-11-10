/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date ` : 2020/11/10
 *
 * Source : https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 * Problem:	Copy List with Random Pointer
 *               
 */
#include <gtest/gtest.h>
#include "copy_list_with_random_pointer.h"

TEST(SolutionTest, copyRandomList) {
  vector<Node*> vec;
  vec.push_back(new Node(7));
  vec.push_back(new Node(13));
  vec.push_back(new Node(11));
  vec.push_back(new Node(10));
  vec.push_back(new Node(1));

  vec[0]->next = vec[1];
  vec[0]->random = NULL;
  vec[1]->next = vec[2];
  vec[1]->random = vec[0];
  vec[2]->next = vec[3];
  vec[2]->random = vec[4];
  vec[3]->next = vec[4];
  vec[3]->random = vec[2];
  vec[4]->next = NULL;
  vec[4]->random = vec[0];

  Solution solution;
  Node* node = solution.copyRandomList(vec[0]);
  vector<Node*> vec2;
  while (node != NULL) {
    vec2.push_back(node);
    node = node->next;
  }
  EXPECT_EQ(vec.size(), vec2.size());
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(vec[i]->val, vec2[i]->val);
    if (vec[i]->next != NULL) {
      EXPECT_EQ(vec[i]->next->val, vec2[i]->next->val);
    }
    if (vec[i]->random != NULL) {
      EXPECT_EQ(vec[i]->random->val, vec2[i]->random->val);
    }
  }
}

