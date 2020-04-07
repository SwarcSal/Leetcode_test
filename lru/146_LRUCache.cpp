/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-04-07 23:19:48
 * @LastEditors: youngchany
 * @LastEditTime: 2020-04-07 23:27:14
 */

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

 

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？
*/

// O(1)查找 hashtable
// O(1)插入 vector list
// O(1)删除 list
// so hash + list

// 执行用时 :184 ms, 在所有 C++ 提交中击败了36.70%的用户
// 内存消耗 :37.2 MB, 在所有 C++ 提交中击败了95.17%的用户

class LRUCache {
public:
    LRUCache(int capacity)
    : m_capacity(capacity) {

    }
    
    int get(int key) {
        const auto it = m.find(key);
        if(it  == m.end()) return -1;
		// list.splice() 从l中把it->second节点插入到l.begin()之前
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it = m.find(key);
        if (it != m.end()) {
            it->second->second = value;
            l.splice(l.begin(), l, it->second);
            return;
        }

        if (l.size() == m_capacity) {
			// map.erase(key) hash删除key 
            m.erase(l.back().first);
            l.pop_back();
        }

		// 构造元素并放到l头部
        l.emplace_front(key, value);
        m[key] = l.begin();

    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */