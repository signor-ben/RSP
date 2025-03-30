#include <bits/stdc++.h>
using namespace std;

/*
could do more test driven development kind of idea
come up with multiple inputs, then can use another for coding guide
dont assume which function should be time/space priority


*/






/*
impleneting a browser

can visit a url
can move forwards and backwards from urls 

same url multiple

vector idea:
visit = push_back url into vector


history = ["abc","x"]
it                ^


BrowserHistory test("abc");

test.visit("def"); 


tets.forward(1);
return 
ghi



Test 2:

start at = "google"

visit = youtube <==

visit = atlassian

visit = youtube

back 2

forward 1

visit atlassian

BrowserHistory obj("google")

history = ["google", "youtube", "atlassian", "atlassian"]
it = 3                                              ^

return "youtube"

return "atlassian"

*/

class BrowserHistory {
    public:
        int iterator;
        vector<string> history;

        BrowserHistory(string homepage) {
            iterator = 0;
            history.push_back(homepage);
        }
    
        void visit(string url) { // add url to storage
            int size = history.size();

            if(size > iterator+1)
                history.erase(history.begin()+iterator+1,history.end());
            
            history.push_back(url);
            iterator++;
        }
    
        string back(int steps) { //moving an iterator back
            // ~100 steps
            //some exceptiong hanedling
            iterator -= steps;
            return history[iterator];
        }
    
        string forward(int steps) { //moving an iterator back
            // ~100 steps
            //some exceptiong hanedling
            iterator += steps;

            return history[iterator];
        }
    };

