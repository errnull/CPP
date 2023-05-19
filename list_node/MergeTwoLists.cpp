#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 测试代码
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 虚拟头节点
        ListNode *dummy = new ListNode(-1), *p = dummy;
        ListNode *p1 = l1, *p2 = l2;

        while (p1 != NULL && p2 != NULL) {
            // 比较 p1 和 p2 
            // 将较小的节点连接到 p 指针
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            // p 指针不断前进
            p = p->next;

            if (p1 != NULL) {
                p->next = p1;
            }
            if(p2 != NULL) {
                p->next = p2;
            }
        }
        
        return dummy->next;
    }
};

int main() {
    Solution solution;

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    printList(mergedList);

    return 0;
}