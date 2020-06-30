class LRUCache{
public:
    LRUCache(int capacity) : capacity_(capacity) {
    }
    
    int get(int key) {
      auto it = map_.find(key);
      if (it != map_.end()) {
        list_.splice(list_.begin(), list_, it->second);
        map_.erase(it);
        map_[key] = list_.begin();
        return list_.begin()->second;
      }
      return -1;
    }
    
    void put(int key, int value) {
      auto it = map_.find(key);
      if (it != map_.end()) {
        list_.erase(it->second);
      }
      list_.push_front(pair<int, int>(key, value));
      map_[key] = list_.begin();
      if (map_.size() > capacity_) {
        int k = list_.rbegin()->first;
        list_.pop_back();
        map_.erase(k);
      }
    }
    
private:
    int capacity_;
    list<pair<int, int> > list_;
    unordered_map<int, list<pair<int, int> >::iterator> map_;
};
