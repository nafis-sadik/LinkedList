#include <iostream>

using namespace std;

class MyLinkedList {
private:
    struct node{
        int value;
        node *next;
    };

    node *Head, *Pointer, *Tail, *TempVar;

    bool TryTraverse(int index){
        Pointer = Head;
        if(index != -1){
            for(int i = 0; i < index; i++){
                cout << Pointer->value << " ";
                if(Pointer != nullptr && Pointer->next != nullptr){
                    Pointer = Pointer->next;
                }
                else{
                    Tail = Pointer;
                    Pointer = Head;
                    return false;
                }
            }
        }
        else{
            while(Pointer->next != nullptr){
                Pointer = Pointer->next;
            }
            Tail = Pointer;
        }
        return true;
    }
    bool TryAddNewNode(int val){
        try{
            if(Pointer != nullptr){
                if(Pointer->next != nullptr){
                    TempVar = Pointer->next;
                    Pointer->next = new node();
                    Pointer = Pointer->next;
                    Pointer->value = val;
                    Pointer->next = TempVar;
                    TempVar = Head;
                    return true;
                }else{
                    Pointer->next = new node();
                    Pointer = Pointer->next;
                    Pointer->value = val;
                    Tail = Pointer;
                    return true;
                }
            }
            return false;
        }
        catch(int num){
            return false;
        }
    }
public:
	void TestPrint(){
		Pointer = Head;
        while(Pointer->next != nullptr){
        	cout << Pointer->value << " ";
            Pointer = Pointer->next;
        }
        cout << endl;
	}
    /** Initialize your data structure here. */
    MyLinkedList() {
        Head = new node();
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(TryTraverse(index))
            return Pointer->value;
        else
            return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        // Traversing to first node
        Pointer = Head->next;
        // Trying to add a node after that
        if(TryAddNewNode(val))
            // Traversing to last node to set tail
            TryTraverse(-1);
        else
        	cout << "Error at adding new node at head" << endl;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(Tail == nullptr)
            return;
        if(Tail->next != nullptr){
            while(Tail->next != nullptr){
                Tail = Tail->next;
            }
        }
        Tail->next = new node();
        Tail = Tail->next;
        Tail->value = val;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        // Traversing to index node
        if(TryTraverse(index)){
            // Trying to add a node after that
            if(TryAddNewNode(val))
                // Traversing to last node to set tail
                TryTraverse(-1);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index){
        // Traversing to index - 1 node
        if(TryTraverse(index-1)){
            // Setting TempVar to index
            if(Pointer->next != nullptr){
                TempVar = Pointer->next;
                // If TempVar is not tail
                if(TempVar->next != nullptr){
                    TempVar = TempVar->next;
                    Pointer->next = TempVar;
                }
                // If TempVar is tail
                else{
                    TempVar = Pointer;
                    Tail = Pointer;
                    Tail->next = nullptr;
                }
            }
        }
    }
};

int main()
{
	// your code goes here
	MyLinkedList *test = new MyLinkedList();
	test->addAtHead(1);
	test->TestPrint();
	test->addAtTail(3);
	test->TestPrint();
	test->addAtIndex(1,2);
	test->TestPrint();
	test->get(1);
	test->TestPrint();
	test->deleteAtIndex(1);
	test->TestPrint();
	test->get(1);
	test->TestPrint();
	return 0;
    return 0;
}
