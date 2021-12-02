#include <iostream>
#include <vector>


using std::vector;


//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* ret = nullptr;
        ListNode* start = nullptr;
        while (head != nullptr) {

            int n = 0;
            while ((head->next != nullptr) and (head->val == head->next->val)) {

                ++n;
                head = head->next;

            }

            std::cout << n << " ";
            if (not n) {
                if (start == nullptr) {

                    start = head;
                    ret = start;

                }
                else {

                    start->next = head;
                    start = start->next;

                }

            }
            head = head->next;

        }
        if (ret != nullptr) {

            start->next = nullptr;

        }
        return ret;

    }
};