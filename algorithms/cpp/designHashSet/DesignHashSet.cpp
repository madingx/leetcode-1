// Source : https://leetcode.com/problems/design-hashset/
// Author : Mading
// Date   : 2019-09-08

/********************************************************************************** 
* 705. Design HashSet [Easy]
* Design a HashSet without using any built-in hash table libraries.

* To be specific, your design should include these functions:

* add(value): Insert a value into the HashSet. 
* contains(value) : Return whether the value exists in the HashSet or not.
* remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

* Example:
* 
* MyHashSet hashSet = new MyHashSet();
* hashSet.add(1);         
* hashSet.add(2);         
* hashSet.contains(1);    // returns true
* hashSet.contains(3);    // returns false (not found)
* hashSet.add(2);          
* hashSet.contains(2);    // returns true
* hashSet.remove(2);          
* hashSet.contains(2);    // returns false (already removed)

* Note:

* All values will be in the range of [0, 1000000].
* The number of operations will be in the range of [1, 10000].
* Please do not use the built-in HashSet library.   
**********************************************************************************/



// 108 ms, faster than 47.60% of C++, 38.5 MB , less than 66.67% C++.
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<list<int>> vec;
    vector<int> num_arr_positive, num_arr_negative;
    unsigned int size_of_num_arr = 1 << 12;
    MyHashSet() {
        vec = vector<list<int>>(128);
        num_arr_positive = vector<int>(size_of_num_arr, 0);
        num_arr_negative = vector<int>(size_of_num_arr, 0);
    }
    
    
    inline int GetHash(int key) {
        int h = hash<int>{}(key);
        int hash_mod = h % vec.size();
        return hash_mod;
    }
    
    void addToTable(int key, int hash) {
        if (contains(key, hash))
            return ;
        auto &l = vec[hash];
        l.push_back(key);
        return ;
    }
    void addToTable(int key) {
        addToTable(key, GetHash(key));
        return ;
    }
    void add(int key) {
        if (key >= 0 && key < size_of_num_arr) {
            num_arr_positive[key] = 1;
            return ;
        } else if (key < 0 && -key <= size_of_num_arr) {
            num_arr_negative[-key - 1] = 1;
            return ;
        }
        int hash = GetHash(key);
        if (containsInTable(key, hash))
            return ;
        auto &l = vec[hash];
        l.push_back(key);
        return ;
    }
    
    inline void removeFromTable(int key, int hash) {
        auto &l = vec[hash];
        auto it = l.begin();
        while (it != l.end()) {
            if (*it != key) {
                ++it;
                continue;
            }
            l.erase(it);
            return ;
        }
        return ;
    }
    void remove(int key) {
        if (key >= 0 && key < size_of_num_arr) {
            num_arr_positive[key] = 0;
            return ;
        } else if (key < 0 && -key <= size_of_num_arr) {
            num_arr_negative[-key - 1] = 0;
            return ;
        }
        removeFromTable(key, GetHash(key));
        return ;
    }
    
    /** Returns true if this set contains the specified element */
    inline bool containsInTable(int key, int hash) {
        const auto &l = vec[hash];
        for (int n : l) {
            if (n == key)
                return true;
        }
        return false;
    }
    inline bool contains(int key, int hash) {
        if (key >= 0 && key < size_of_num_arr) {
            return num_arr_positive[key] > 0;
        } else if (key < 0 && -key <= size_of_num_arr) {
            return num_arr_negative[-key - 1] > 0;
        }
        return containsInTable(key, GetHash(key));
    }
    bool contains(int key) {
        return contains(key, GetHash(key));
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */