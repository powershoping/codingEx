
#include "linkedList.h"


ListNode* merge(ListNode *list1, ListNode* list2 ){
   
   if(!list1 && !list2 )return nullptr;
   if(!list1) return list2;
   if(!list2) return list1;

   ListNode dummy;
   ListNode *tail = &(dummy);
   
   int count = 0;
   while(list1 || list2)
   {
      if(list1==nullptr) {
         tail->next = list2;
         break;
      }
      if(list2==nullptr){
         tail->next = list1;
         break;
      }
      int v1 = list1->val;
      int v2 = list2->val;

      if(v1 <= v2){
         tail->next = list1;
         list1 = list1->next;
      }
      else{
         tail->next = list2;
         list2 = list2->next;
      }
      tail = tail->next;
   }

   return (dummy.next);
}

ListNode* merge2Lists(ListNode *list1, ListNode *list2)
{
   if (list1 == nullptr)
   {
      return list2;
   }
   if (list2 == nullptr)
      return list1;

   ListNode aa;
   ListNode *dummy = &aa;
   while (list1 && list2)
   {
      if (list1->val < list2->val)
      {
         dummy->next = list1;
         list1 = list1->next;
      }
      else
      {
         dummy->next = list2;
         list2 = list2->next;
      }
      dummy = dummy->next;
   }
   if (list1)
   {
      dummy->next = list1;
   }
   if (list2)
   {
      dummy->next = list2;
   }

    return aa.next;
}
//[leetcode 23] (https://leetcode.com/problems/merge-k-sorted-lists/description/) : Merge k Sorted Lists (binary-tree 2-leaves merges)
ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
   size_t interval = 1;
   size_t sz = lists.size();
   const size_t csz = lists.size();
   if (sz == 0)
      return nullptr;
   while (sz != 0)
   {
      for (size_t ii = 0; ii < csz; ii += 2 * interval)
      {
         if (ii + interval < csz)
         {
            lists[ii]=merge2Lists(lists[ii], lists[ii + interval]);
         }
      }
      interval <<= 1;
      sz >>= 1;
   }
   return lists[0];
}
//[leetcode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) :Reverse Nodes in k-Group in a linked list (O(n+2))
ListNode *reverseKGroup(ListNode *head, int k)
{
   {
      if (!head || !head->next)
         return head;
      ListNode dummyNode;
      ListNode *dummy = &dummyNode;
      dummy->next = head;
      int count = 2;
      ListNode *LastTail = dummy;
      ListNode *first = head;
      ListNode *prev = first;
      ListNode *cur = first->next;
      first->next = nullptr;

      ListNode *last = nullptr;
      while (cur)
      {
         if (count % k == 0)
         {

            ListNode *tmp = cur->next;
            cur->next = prev;
            LastTail->next = cur;
            LastTail = first;
            if (!tmp)
            {
               last = nullptr;
               count = 0;
               break;
            }
            else
            {
               if (tmp->next)
               {
                  // for next loop
                  cur = tmp->next;
                  first = tmp;
                  prev = first;
                  first->next = nullptr;
                  count = 2;
               }
               else
               {
                  last=tmp;
                  last->next=nullptr;
                  count = 1;
                  break;
               }
            }
         }
         else
         {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            last = cur;
            cur = tmp;
            count++;
         }
      }
      if(count <=1){
         LastTail->next = last;
      }
      else{
         count =count - 3;
         LastTail->next = first;
         prev=last;
         cur = last->next;
         last->next = nullptr;
         for(int ii =count; ii>=0; --ii){
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev=cur;
            cur=tmp;
         }
      }

      return dummy->next;
   }
}
//[leetcode 61](https://leetcode.com/problems/rotate-list/description/) : rotate a linked list
ListNode *rotateRight(ListNode *head, int k)
{
   if (!head || !head->next || k == 0)
      return head;
   int sz = 0;
   ListNode dummyNode;
   ListNode *dummy = &dummyNode;
   ListNode *tail = nullptr;
   dummy->next = head;
   ListNode *cur = dummy->next;
   while (cur)
   {
      sz++;
      tail = cur;
      cur = cur->next;
   }
   if (k % sz == 0)
      return head;
   int nrot = sz - k % sz - 1;
   cur = dummy->next;
   while (nrot > 0)
   {
      nrot--;
      cur = cur->next;
   }
   ListNode *newhead = cur->next;
   cur->next = nullptr;
   tail->next = dummy->next;
   dummy->next = newhead;

   return dummy->next;
}
//[leetcode 147](https://leetcode.com/problems/insertion-sort-list/description/) : Insertion Sort List
ListNode *insertionSortList(ListNode *head)
{
   if (head == nullptr || head->next == nullptr)
      return head;
   ListNode dummy_node;
   ListNode *dummy = &dummy_node;
   dummy->next = head;
   ListNode *prev = dummy->next;
   ListNode *cur = prev->next;
   while (cur)
   {
      if (cur->val < prev->val)
      {
         prev->next = cur->next;
         cur->next = nullptr;
         ListNode *cur2 = dummy->next;
         ListNode *prev2 = dummy;
         while (true)
         {
            if (cur->val <= cur2->val)
            {
               prev2->next = cur;
               cur->next = cur2;
               break;
            }
            prev2 = cur2;
            cur2 = cur2->next;
         }
         cur = prev->next;
      }
      else
      {
         prev = cur;
         cur = cur->next;
      }
   }

   return dummy->next;
}
int main()
{
  auto list1 = buildLinkedList({1,3,6});
  auto list2 = buildLinkedList({2,4,5});
  printLinkedList(list1);
  printLinkedList(list2);
  printLinkedList(merge(list1, list2));

// list1 and list2 are interconnected; needs to create news ones.
  list1 = buildLinkedList({1,3,6});
  list2 = buildLinkedList({2,4,5});
  auto list3 = buildLinkedList({1,6,9});
  auto list4 = buildLinkedList({8,8,15,20});
  auto list5 = buildLinkedList({4,4,15,20});

  printLinkedList(list1);
  printLinkedList(list2);
  printLinkedList(list3);
  printLinkedList(list4);
  printLinkedList(list5);

  std::vector<ListNode*> kLists{list1, list2, list3, list4, list5};
  printLinkedList(mergeKLists(kLists));

  auto lkrvs = buildLinkedList({1,2,3,4,5,6,7});
  printLinkedList(reverseKGroup(lkrvs,4));

  printLinkedList(rotateRight(buildLinkedList({1,2,3, 4,5,6,7}),3));

  printLinkedList(insertionSortList(buildLinkedList({4,2,1,3})));


  return 0;
}
