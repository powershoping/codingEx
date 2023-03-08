#include<iostream>

#include "linkedList.h"

void push(ListNode **head, int val )
{
   ListNode *newNode = new ListNode(val);
   newNode->next = *head;
   *head = newNode;
}

ListNode *buildLinkedList(std::vector<int> &&vec)
{
   ListNode *head=nullptr;
   for(int ii=vec.size()-1; ii>=0; --ii){
      push(&head, vec[ii]);
   }
   return head;
}

void printLinkedList(ListNode *head)
{
   ListNode *cur = head;
   while(cur)
   {
      printf("%8d", cur->val);
      cur = cur->next;
   }
   printf("\n");
}