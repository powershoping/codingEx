#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<vector>

struct ListNode
{
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildLinkedList(std::vector<int> &&vec);
void printLinkedList(ListNode *head);

#endif
