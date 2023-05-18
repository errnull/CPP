// 21.合并两个有序链表
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
   if (l1 == NULL) {
      return l2;
   }
   if (l2 == NULL) {
      return l1;
   }
   if (l1->val <= l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
   } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
   }
}

// 测试代码
void printList(struct ListNode *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->val = 2;
    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->val = 4;
    l1->next->next->next = NULL;

    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->val = 1;
    l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->val = 3;
    l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct ListNode *mergedList = mergeTwoLists(l1, l2);

    printList(mergedList);

    return 0;
}