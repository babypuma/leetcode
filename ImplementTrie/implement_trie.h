/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/11
 *
 * Source : https://leetcode.com/problems/implement-trie-prefix-tree/
 * Problem:	Implement Trie
 * Description: 
 *	Implement a trie with insert, search, and startsWith methods.
 * Note:
 *	You may assume that all inputs are consist of lowercase letters a-z.
 *
 */
#include <string>
using std::string;

class TrieNode {
	public:
		// Initialize your data structure here.
		TrieNode(): 
			ch_(0), endsWith_(false), leftChild_(NULL), rightSibling_(NULL) {
		}

		TrieNode(char ch, TrieNode *rSibling = NULL): 
			ch_(ch), endsWith_(false), leftChild_(NULL), rightSibling_(rSibling) {
		}

		char ch_;
		bool endsWith_;
		TrieNode *leftChild_;
		TrieNode *rightSibling_;
};

class Trie {
	public:
		Trie(): root(new TrieNode()) {
		}

		~Trie() {
			destroy(root);
		}

		// Inserts a word into the trie.
		void insert(string word) {
			size_t length = word.size();
			TrieNode *node = root;
			for (size_t i = 0; i < length; i++) {
				if (node->leftChild_ == NULL) {
					node->leftChild_ = new TrieNode(word[i]);
					node = node->leftChild_;
				}
				else {
					TrieNode *child = node->leftChild_;
					if (word[i] < child->ch_) {
						node->leftChild_ = new TrieNode(word[i], child);
						node = node->leftChild_;
					}
					else if (word[i] == child->ch_) {
							node = child;
					}
					else {
						while (child->rightSibling_ != NULL && word[i] > child->rightSibling_->ch_) {
							child = child->rightSibling_;
						}
						if (child->rightSibling_ == NULL || word[i] < child->rightSibling_->ch_) {
							child->rightSibling_ = new TrieNode(word[i], child->rightSibling_);
						} 
						node = child->rightSibling_;
					}
				}
			}
			node->endsWith_ = true;
		}

		// Returns if the word is in the trie.
		bool search(string word) {
			if (word.empty()) {
				return true;
			}
			TrieNode *node = endsWith(word);
			return node != NULL && node->endsWith_;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			return prefix.empty() || endsWith(prefix) != NULL;
		}

	private:
		TrieNode* endsWith(string word) {
			size_t length = word.size();
			TrieNode *node = root;
			for (size_t i = 0; i < length; i++) {
				if (node->leftChild_ == NULL) {
					return NULL;
				} 
				
				TrieNode *child = node->leftChild_;
				if (word[i] == child->ch_) {
					node = child;
				}
				else {
					while (child->rightSibling_ != NULL && word[i] > child->rightSibling_->ch_) {
						child = child->rightSibling_;
					} 
					if (child->rightSibling_ == NULL || word[i] < child->rightSibling_->ch_) {
						return NULL;
					} 
					node = child->rightSibling_;
				}
			}
			
			return node;
		}

		void destroy(TrieNode *node) {
			if (node != NULL) {
				delete node->rightSibling_;
				delete node->leftChild_;
				delete node;
			}
		}

		TrieNode* root;
};

