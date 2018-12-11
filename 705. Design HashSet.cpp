/*
Problem Description:


Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.
*/

class MyHashSet {
private:
    list<int> buckets[1000];
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool flag=false;
        int hash=(key*1031)%1000;
        list<int> &li=buckets[hash];
        for(auto it=li.begin();it!=li.end();it++)
             if(*it==key)
                 flag=true;
        if(!flag) li.emplace_back(key);
    }
    
    void remove(int key) {
        int hash=(key*1031)%1000;
        list<int> &li=buckets[hash];
        for(auto it=li.begin();it!=li.end();it++)
             if(*it==key)
             {
                 li.erase(it);
                 return;
             }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash=(key*1031)%1000;
        list<int> &li=buckets[hash];
        for(auto it=li.begin();it!=li.end();it++)
             if(*it==key)
                 return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */