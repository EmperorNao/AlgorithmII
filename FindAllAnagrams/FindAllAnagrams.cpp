#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;


class Solution {
public:

	void add(vector<int>& a, char c) {

		++a[c - 'a'];

	}

	void del(vector<int>& a, char c) {

		--a[c - 'a'];

	}

	const int n_letters = 26;
    vector<int> findAnagrams(string s, string p) {

    	int n = s.size();
    	int m = p.size();

    	vector<int> origin(n_letters, 0);
    	for (auto& ch: p) {

    		add(origin, ch);

    	}

    	vector<int> res;
    	vector<int> cur(n_letters, 0);
    	for (int i = 0; i < n; ++i) {

    		if (i < m) {

    			add(cur, s[i]);

    		}
    		else {

    			add(cur, s[i]);
    			del(cur, s[i - m]);

    		}
    		if (origin == cur) {

    			res.push_back(i - m + 1);

    		}


    	}
    	return res;

        
    }
};

int main() {



}