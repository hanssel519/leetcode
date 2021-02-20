#include<iostream>
using namespace std;

class Node{
  public:
    int val;
    Node *next;
    Node(int num, Node *ptr): val(num), next(ptr){ }
};
class MyLinkedList {
public:
    Node *head;
    int length;
    /** Initialize your data structure here. */
    MyLinkedList() {
      head = NULL;
      length = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node *cur = head;
        //if(cur == NULL)return -1;
        int count = 0;
        while (cur) {
          if(count == index){
            return cur->val;
          }
          cur = cur->next;
          count++;
        }return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *ptr = new Node(val, head);
        head = ptr;
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      Node *cur = head;
      if(length == 0){
            addAtHead(val);
            return;
        }
      while (cur->next) {
        cur = cur->next;
      }
      Node *ptr = new Node(val, NULL);
      cur->next = ptr;
      length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *cur = head;
        Node *ptr = new Node(val, NULL);
        if (index == 0) {
          addAtHead(val);
          length++;
          return;
        }
        index--;
        while (index--) {
          if(!cur->next)return;
          cur = cur->next;
        }
        ptr->next = cur->next;
        cur->next = ptr;
        length++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
      Node *cur = head;
      Node *ptr = nullptr;
      if (length == 0)return;
      if(index > length-1)return;
      if (index == 0) {
        ptr = head;
        head = head->next;
        delete ptr;
        length--;
        return;
      }

      index--;

        while(index--){
          if(cur->next==NULL) return;
          cur = cur->next;
        }
        ptr = cur->next;
        std::cout << "ptr: "<<ptr->val << '\n';
        if(cur->next!=NULL&&(cur->next)->next!=NULL){
            std::cout << "cur->next: "<< cur->next->val<< '\n';
            std::cout << "cur->next->next: "<< (cur->next)->next->val<< '\n';
            cur->next = (cur->next)->next;
        }
        else{
            cur->next = NULL;
        }
        delete ptr;
        length--;
        return;

    }
    void printList() {
      Node *ptr = head;
      while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
      }
      printf("\n");
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main(int argc, char const *argv[]) {
  MyLinkedList* obj = new MyLinkedList();
  obj->addAtHead(38);
  obj->addAtTail(66);
  obj->printList();
  obj->addAtTail(61);
  obj->printList();
  obj->addAtTail(76);
  obj->printList();
  obj->addAtTail(26);
  obj->printList();
  obj->addAtTail(37);
  obj->printList();
  obj->addAtTail(8);
  obj->printList();
  obj->deleteAtIndex(5);
  obj->printList();
  obj->addAtHead(4);
  obj->printList();
  obj->addAtHead(45);
  obj->printList();
  std::cout << obj->get(4) << '\n';
  obj->printList();
  obj->addAtTail(85);
  obj->printList();
  obj->addAtHead(37);
  obj->printList();
  std::cout << obj->get(5) << '\n';
  obj->printList();
  obj->addAtTail(93);
  obj->printList();

/*  obj->printList();
  obj->addAtHead(2);
  obj->printList();
  obj->addAtHead(1);
  obj->printList();
  obj->addAtIndex(3,0);
  obj->printList();
  obj->deleteAtIndex(2);
  obj->printList();
  obj->addAtHead(6);
  obj->printList();
  obj->addAtTail(4);
  obj->printList();
  obj->get(4);
  obj->printList();
  obj->addAtHead(4);
  obj->printList();
  obj->addAtIndex(5,0);
  obj->printList();
  obj->addAtHead(6);*/

  return 0;
}
