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

void print(ListNode *head){

   ListNode *cur_node = head;
   while(cur_node)
   {
      printf("%8d", cur_node->val);
      cur_node = cur_node->next;
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


  ListNode *merged_list=merge(list1, list2);

  print(merged_list);
  
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
  ListNode* merged_klists = mergeKLists(kLists);
  print(merged_klists);
  return 0;
}
