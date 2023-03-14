#include <iostream>
using namespace std;

ListNode* middleNode(ListNode* head) {
    ListNode *curr = head;
    ListNode *temp = head;

    int count =0;
    int start;
    while(curr!=NULL){
        count ++;
        curr = curr->next;
    }

    start = (count/2)+1;


    for(int i=1; i<start; i++){
        temp = temp->next;
    }
    return temp;
}