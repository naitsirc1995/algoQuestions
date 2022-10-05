using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {

  LinkedList* curr = linkedList;
  while (curr->next != nullptr){
    if (curr->next->value == curr->value ){
        curr->next = curr->next->next;

        continue;
    }

    curr = curr->next;
  }
  return linkedList;
}
