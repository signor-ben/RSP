#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
        int key;
        int val;
        Node* next;

        Node(int k = -1, int v = -1, Node* n = nullptr) : key(k), val(v), next(n) {}
};


class MyHashMap {
    public:
        vector<Node*> map;

        MyHashMap() {
            map.resize(1000);
            for(int i = 0; i<1000;i++)
                map[i] = new Node();
        }

        int hashFunc(int key)
        {
            return key % 1000;
        }

        
        void put(int key, int value) {
            int hash = hashFunc(key);
            Node* temp = map[hash];

            while(temp->next)
            {
                if(temp->next->key == key)
                {
                    temp->next->val = value;
                    return;
                }
                temp = temp->next;
            }

            temp->next = new Node(key, value);
            return;
        }
        
        int get(int key) {
            int hash = hashFunc(key);

            Node* temp = map[hash];
            while(temp->next)
            {
                if(temp->next->key == key)
                    return temp->next->val;
                temp = temp->next;
            }

            return -1;
        }
        
        void remove(int key) {
            int hash = hashFunc(key);
            Node* temp = map[hash];
            while(temp->next)
            {
                if(temp->next->key == key)
                {
                    Node* del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                    return;
                }
                temp = temp->next;
            }
            return;
        }
    };
    

// must implement chaining, and using a shash function
// easily done by storing a linked list in a vector, every function cheks the linked list at the hashed vector location for the key
// must create node class for linked list with key and val variables
// hash func can be something basic like: key % (size of storage vector)
// here since the vector is 1000, the hash func is key%1000
// technically can just use an std list of pairs instead of a custom node. one may be easier/better than the other