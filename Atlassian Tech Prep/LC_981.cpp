#include <bits/stdc++.h>
using namespace std;


class TimeMap {
    public:
        unordered_map<string,map<int,string>> mp;

        TimeMap() {
            
        }
        
        void set(string key, string value, int timestamp) {
            mp[key][timestamp] = value;
        }   
        
        string get(string key, int timestamp) {
            if(!mp.count(key)) return "";
            if(mp[key].count(timestamp)) return mp[key][timestamp];

            auto it = mp[key].upper_bound(timestamp);

            if(it == mp[key].begin()) return "";
            
            return prev(it)->second;
        }

    };
    
    /**
     * Your TimeMap object will be instantiated and called as such:
     * TimeMap* obj = new TimeMap();
     * obj->set(key,value,timestamp);
     * string param_2 = obj->get(key,timestamp);
     */


int main()
{
    TimeMap mp;
    
    mp.set("foo","bar",3);
    cout << mp.get("foo", 5) << endl;

    return 0;
}


/* 
used all the correct datastructures and everything, the final thing was slightly inoptimal but i considered and wouldve mentioned the optimal approach.
map<> time complexity is only O(logn) time. Bin search is O(logn).

so:
set is O(logn) because of the map
get is O(n) with the while loop or O(logn) with the binary search

space is O(n) as we're just storing the values as they come in, nothing really special there
*/