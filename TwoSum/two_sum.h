#include <vector>
using std::vector;

struct TableElem {
	int value_;
	int index_;	
	TableElem *next_; 
};

class HashTable {
	public:
		HashTable(int size) : hash_table_(NULL), hash_table_length_(0) {
			init(size);
		}

		~HashTable() {
			destroy();
		}

		int insert(TableElem *elem) {
			if (!elem) {
				return 0;
			}
			elem->next_ = NULL;

			int pos = hash(elem->value_);
			TableElem *pelem = hash_table_[pos]; 

			if (!pelem) {
				hash_table_[pos] = elem;
			}
			else {
				while (pelem->next_ != NULL && pelem->next_->index_ < elem->index_) {
					pelem = pelem->next_;
				}
				elem->next_ = pelem->next_;
				pelem->next_ = elem;
			}

			return 0;
		}

		int find(int value, int cursor) {
			int pos = hash(value);
			TableElem *pelem = hash_table_[pos];
			if (!pelem) {
				return -1;
			}
			else {
				while (pelem != NULL && pelem->index_ <= cursor) {
					pelem = pelem->next_;
				}

				while (pelem != NULL && pelem->value_ != value) {
					pelem = pelem->next_;
				}

				return pelem != NULL ? pelem->index_ : -1;
			}
		}

	private:
		void init(int size) {
			hash_table_length_ = 1;
			while (hash_table_length_ < size) {
				hash_table_length_ <<= 1;
			}
			hash_table_length_++;

			hash_table_ = (TableElem **)calloc(hash_table_length_, sizeof(TableElem *));
			assert(hash_table_ != NULL);
		}

		void destroy() {
			TableElem *pelem;
			TableElem *pnext;
			for (int i = 0; i < hash_table_length_; i++) {
				pelem = hash_table_[i];	
				while (pelem != NULL) {
					pnext = pelem->next_;
					free(pelem);
					pelem = pnext;
				}
			}

			free(hash_table_);
		}

		int hash(int value) {
			return value >= 0 ? value % hash_table_length_ : -value % hash_table_length_;
		}

	private:
		TableElem **hash_table_;
		int hash_table_length_;
};

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) { 
			size_t length = numbers.size();
			HashTable hash_table(length << 1);
			for (size_t i = 0; i < length; i++) {
				TableElem *elem = (TableElem *)calloc(sizeof(TableElem), 1);
				elem->value_ = numbers[i];
				elem->index_ = i + 1;
				elem->next_ = NULL;
				hash_table.insert(elem);
			}

			vector<int> result;
			int index;
			for (size_t i = 0; i < length - 1; i++) {
				index = hash_table.find(target - numbers[i], i + 1); 
				if (index != -1) {
					result.push_back(i + 1);
					result.push_back(index);
					break;
				}
			}

            return result;
        }

};
