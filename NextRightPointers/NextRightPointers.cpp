/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <vector>

using namespace std;


class Solution {
public:
    Node* connect(Node* root) {
        
        if (not root) {
            
            return root;
            
        }
        std::vector<Node*> cur = {root};
        while (cur.size()) {

            sew(cur);
            cur = sublevel(cur);

        }

    }

    void sew(vector<Node*>& cur) {

        for (int i = 0; i < cur.size() - 1; ++i) {

            cur[i]->next = cur[i + 1];

        }

    }


    vector<Node*> sublevel(vector<Node*>& cur) {

        vector<Node*> res;
        for (auto& n: cur) {

            if (n->left) {

                res.push_back(n->left);

            }
            if (n->right) {

                res.push_back(n->right);

            }

        }
        return res;


    }

};