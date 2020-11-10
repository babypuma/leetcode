/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/10
 *
 * Source : https://leetcode-cn.com/problems/lru-cache/
 * Problem:	LRU Cache
 *               
 */
#include <unordered_map>
using std::unordered_map;

struct DLinkedNode {
  int key;
  int value;
  DLinkedNode* next;
  DLinkedNode* prev;
  DLinkedNode(int k, int v) : key(k), value(v), next(NULL), prev(NULL) {
  }
};

struct DLinkedList {
  DLinkedNode* head;
  DLinkedNode* tail;
  int size;
  int capacity;

  DLinkedList(int cap) : size(0), capacity(cap) {
    head = new DLinkedNode(0, 0);
    tail = new DLinkedNode(0, 0);
    head->next = tail;
    tail->prev = head;
  }

  void erase(DLinkedNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    --size;
  }

  void insertAfter(DLinkedNode* node, DLinkedNode* new_node) {
    if (node == NULL || new_node == NULL) {
      return;
    }
    new_node->next = node->next;
    new_node->prev = node;
    new_node->next->prev = new_node;
    new_node->prev->next = new_node;
    ++size;
  }
};

class LRUCache {
 public:
   LRUCache(int capacity) : capacity_(capacity), doubly_list_(capacity_) {
   }

   int get(int key) {
     if (key_map_.find(key) == key_map_.end()) {
       return -1;
     }
     DLinkedNode* node = key_map_[key];
     if (node->prev != doubly_list_.head) {
       doubly_list_.erase(node);
       doubly_list_.insertAfter(doubly_list_.head, node);
     }
     return node->value;
   }

   void put(int key, int value) {
     if (key_map_.find(key) != key_map_.end()) {
       DLinkedNode* node = key_map_[key];
       node->value = value;
       doubly_list_.erase(node);
       doubly_list_.insertAfter(doubly_list_.head, node);
       return;
     }

     if (doubly_list_.size == capacity_) {
       DLinkedNode* node = doubly_list_.tail->prev;
       doubly_list_.erase(node);
       key_map_.erase(node->key);
       delete node;
     }

     DLinkedNode* node = new DLinkedNode(key, value);
     doubly_list_.insertAfter(doubly_list_.head, node);
     key_map_[key] = node;
   }

 private:
   int capacity_;
   DLinkedList doubly_list_;
   unordered_map<int, DLinkedNode*> key_map_;
};
