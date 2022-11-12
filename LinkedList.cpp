#include<iostream>

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
      tail = tail->next
   }

   return (dummy.next);
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

  return 0;
}