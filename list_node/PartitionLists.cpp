#include <iostream>

// 链表节点的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

// 打印链表的函数
void printList(ListNode *head) {
    while(head != NULL) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 分隔链表的函数
ListNode* partition(ListNode *head, int x) {
  // 存放小于 x 的链表的虚拟头结点
  ListNode *dummy1 = new ListNode(-1);
  // 存放大于等于 x 的链表的虚拟头节点
  ListNode *dummy2 = new ListNode(-1);
  // p1，p2 指针负责生成结果链表
  ListNode *p1 = dummy1, *p2 = dummy2;
  // p 负责遍历原链表，类似合并两个有序链表的逻辑
  // 这里是将一个链表分解成两个链表
  ListNode *p = head;
  while(p != NULL) {
    if(p->val >= x) {
      p2->next = p;
      p2 = p2->next;
    } else {
      p1->next = p;
      p1 = p1->next;
    }
    // 断开原链表中的每个节点的 next 指针
    ListNode *temp = p->next;
    p->next = NULL;
    p = temp;
  }

  // 连接两个链表
  p1->next = dummy2->next;
  return dummy1->next;
}

// 测试代码
int main() {
    // 创建一个链表 1->4->3->2->5->2
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    std::cout << "原始链表：";
    printList(head);

    ListNode *result = partition(head, x);

    std::cout << "分隔后的链表：";
    printList(result);

    return 0;
}