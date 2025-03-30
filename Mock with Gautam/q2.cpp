#include <bits/stdc++.h>
using namespace std;

/*
General weird implenation stuff, here just using iterator wouldve been so much better
took so long to actually get impleneation idea

*/


/*
least recently used cache

get = returns a given key if it exists otherwise -1
put = add value to cache. if key exists, reset the value in cache, otherwise adding key and sorting any over size


size 2

cache = [[3,2],[1,3],[4,2]]

1 to store key, pointer pairs
doubly linked list to store key values





cache = [[1,3],[3,2],[4,2]]
get(1);



return 3
*/

class LRUCache {
    public:
        list<pair<int,int>> lst;
        unordered_map<int,Node*> mp;
        int capacity;
        int curr_size;

        LRUCache(int capacity) {
            this->capacity = capacity;
            curr_size = 0;
        }
    
        int get(int key) {
            if(!mp[key].count)
                return -1;

            int value = mp[key]->val;
            Node* temp = mp[key];
            lst.erase(mp[key]);
            lst.push_front(temp);
            mp[key] = temp;

            return value;
        }
    
        void put(int key, int value) {
            if(curr_size < capacity)
            {
                lst.push_front({key,value});
                mp[key] = *lst.front().first;
                curr_size++;
            } else
            {
                if(mp.count(key))
                {
                    lst.erase(mp[key]);
                    lst.push_front({key,value});
                    mp[key] = *lst.front().first;
                } else
                {
                    mp.erase(key);
                    lst.pop_back();
                    lst.push_front({key,value});
                    mp[key] = *lst.front().first;
                }
            }
        }
    };