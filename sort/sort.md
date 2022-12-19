# Comparision of Selection Sort, Bubble Sort, and Insertion Sort

| Parameter |  Selection Sort | Insert Sort | Bubble Sort | Merge Sort| Quick Sort| 
| :---:     |    :----:       | :---:      | :----:   | :-----:|  :-----:|
| Definition|select min element and put into the right position| Insert the incoming element into the right position of the already sorted sequence| swap adjacent elements to the required order in a pass, making passes until there are no swaps in a pass| Divide and conquer into halves | Using a pivot to divide the dataset, the split can be in any ratio|
|Best Case Time Complexity (sorted)| O(N<sup>2</sup>) (`Not knowing sorted, selection continues`) | O(N) (`No swap/insertion needed if sorted`) | O(N) (`No Swap needed if sorted`)| O(NlogN) | O(NlogN)|
|Worst Case Time Complexity| O(N<sup>2</sup>)|O(N<sup>2</sup>)|O(N<sup>2</sup>)| O(NlogN) |O(NlogN)|
|Average Case Time Complexity|O(N<sup>2</sup>)|O(N<sup>2</sup>)|O(N<sup>2</sup>)| O(NlogN)|O(N<sup>2</sup>)|
|NComp(number of Comparision) & NSwap(Number of Swapping)|NComp>NSwap|NComp<NSwap| NComp>NSwap|NComp>NSwap |NComp>NSwap|
|Space Complexity| O(1) |O(1)|O(1)| O(N)|O(1)|
|Stable|  No(Changed the order of the same key due to swap between the smallest key) | Yes|Yes| Yes| No (Swap changes the order of the same key|
|In-place|Yes|Yes|Yes| No| Yes|
|Adaptive<sup>*</sup>|No|Yes|Yes| No|No|
|Applications| sort linked list(?)|on-fly sort | detecting minor errors and sort an almost sorted array quickly| Best for huge dataset|for huge dataset but not sorted|
|Advantage| efficient when swap is expensive|effective when comparision is costly|simplest easy to code|efficient for large dataset| works well for arrays|
|Disadvantage| a lot of comparision| a lot of swaps| a lot of comparison and swaps|Extra space| Slow for almost sorted dataset|



 -*  Adaptive: performing less operations if the sequence is partially sorted

 - [x] Insertion sort works quite fast for nearly sorted arrays and is a good option for a doubly linked list. The swap of the insertion sort is local, i.e., the swap happens between two neigboring node, and the doulbly linked list has both forward and backward pointers. 
 - [x] For linked lists, merge sort can be performed in place, not using extra memory, since the merging of the nodes in a linked list can be done in O(1) time without using an extra array.  Quick sort is worse for linked lists, the swapping is more of global, and this is something that linked structures are bad at. 
 - [x] Choosing a simple algorith, Selection sort is usually never the best choice since it always performs O(N<sup>2</sup>) comparision. Bubble sort and insert sort can be chosed for smaller sized or almost sorted sequences.
 - [x] Insertion sort does not perform well on a singly linked list since we cannot move backwards efficiently, only forward. Insertion sort works backward.  However, bubble sort works fine as bubble sort works forward. For doubly linked list, both Insertion and Bubble sorts works fine. 