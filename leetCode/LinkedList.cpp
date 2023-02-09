#include<iostream>
#include<vector>

struct ListNode
{
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push(ListNode **head, int val )
{
   ListNode *newNode = new ListNode(val);
   newNode->next = *head;
   *head = newNode;
}

ListNode * build(std::vector<int> &&vec){
   ListNode *head=nullptr;
   for(const auto &ee : vec){
      push(&head, ee);
   }
   return head;
}
ListNode * buildReverse(std::vector<int> &&vec){
   ListNode *head=nullptr;
   for(int ii=vec.size()-1; ii>=0; --ii){
      push(&head, vec[ii]);
   }
   return head;
}
void print(ListNode *head){

   ListNode *cur = head;
   while(cur)
   {
      printf("%8d", cur->val);
      cur = cur->next;
   }
   printf("\n");

}

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
//[leetcode 25](https://leetcode.com/problems/reverse-nodes-in-k-group/description/) :Reverse Nodes in k-Group in a linked list
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

int main()
{
  ListNode *list1 =nullptr;
  push(&list1, 6);
  push(&list1, 3);
  push(&list1, 1);
  print(list1);

  ListNode *list2 = nullptr;
  push(&list2,5);
  push(&list2,4);
  push(&list2,2);
  print(list2);


  print(merge(list1, list2));

// list1 and list2 are interconnected; needs to create news ones.
  list1 =nullptr;
  push(&list1, 6);
  push(&list1, 3);
  push(&list1, 1);
  print(list1);

  list2 = nullptr;
  push(&list2,5);
  push(&list2,4);
  push(&list2,2);
  print(list2);

  ListNode *list3 = nullptr;
  push(&list3,9);
  push(&list3,6);
  push(&list3,1);
  print(list3);


  ListNode *list4 = nullptr;
  push(&list4,20);
  push(&list4,15);
  push(&list4,8);
  push(&list4,8);
  print(list4);


  ListNode *list5 = nullptr;
  push(&list5,20);
  push(&list5,15);
  push(&list5,4);
  push(&list5,4);
  print(list5);

  std::vector<ListNode*> kLists{list1, list2, list3, list4, list5};
  print(mergeKLists(kLists));

  auto lkrvs = buildReverse({1,2,3,4,5,6,7});
  print(reverseKGroup(lkrvs,4));

  print(rotateRight(buildReverse({1,2,3, 4,5,6,7}),3));


  return 0;
}
