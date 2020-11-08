#include <iostream>
#include <windows.h>
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
        cout << "=====================================" << endl;
        cout << "Head    : " << Head->value << endl;
        cout << "Tail    : " << Tail->value << endl;
        cout << "Pointer : " << Pointer->value << endl;
		cout << endl;
		cout << "Linked List" << endl;
		while(Pointer->next != nullptr){
        	cout << Pointer->value << " ";
            Pointer = Pointer->next;
		}
        cout << Pointer->value << " ";
        if(Tail->next != nullptr){
            cout << "Wrong tail detected" << endl;
        }
		cout << endl;
        cout << "=====================================" << endl;
	}
    /** Initialize your data structure here. */
    MyLinkedList() {
        Head = nullptr;
        Pointer = nullptr;
        Tail = nullptr;
        TempVar = nullptr;
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
        if(Head == nullptr){
            Head = new node();
            Head->value = val;
            Pointer = Head;
            Tail = Head;
            TempVar = Head;
            return;
        }
        // Traversing to first node
        Pointer = Head->next;
        // Trying to add a node after Head
        Head->next = new node();
        // Setting new node with TempVar pointer
        TempVar = Head->next;
        TempVar->next = Pointer;
        TempVar->value = val;
        // Setting tail
        if(TryTraverse(-1)){ return; }
        else{
            cout << "Error at adding new node at head " << endl;
        }
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
        if(TryTraverse(index-1)){
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
	cout << "Test # 1" << endl;
	cout << endl;
	// Test # 1
	MyLinkedList *test = new MyLinkedList();

	cout << "Operation : Add Head" << endl;
	test->addAtHead(1);
	test->TestPrint();

	cout << "Operation : Add at Tail 3" << endl;
	test->addAtTail(3);
	test->TestPrint();

	cout << "Operation : Add at Index [1, 2]" << endl;
	test->addAtIndex(1,2);
	test->TestPrint();

	cout << "Operation : Get at Index 1 => " << test->get(1) << endl;
	test->get(1);
	test->TestPrint();

	cout << "Operation : Delete at Index 1" << endl;
	test->deleteAtIndex(1);
	test->TestPrint();

	cout << "Operation : Get at Index 1 => " << test->get(1) << endl;
	test->TestPrint();

	cout << endl;
	cout << "Test # 2" << endl;
	cout << endl;

	// Test # 2
	test = new MyLinkedList();

	cout << "Operation : Add Head" << endl;
	test->addAtHead(7);
	test->TestPrint();

	cout << "Operation : Add Head" << endl;
	test->addAtHead(2);
	test->TestPrint();

	cout << "Operation : Add Head" << endl;
	test->addAtHead(1);
	test->TestPrint();

	cout << "Operation : Add at Index [3, 0]" << endl;
	test->addAtIndex(3, 0);
	test->TestPrint();

	cout << "Operation : Delete at Index 2" << endl;
	test->deleteAtIndex(2);
	test->TestPrint();

	cout << "Operation : Add Head" << endl;
	test->addAtHead(6);
	test->TestPrint();

	cout << "Operation : Add at Tail 4" << endl;
	test->addAtTail(4);
	test->TestPrint();

	cout << "Operation : Get at Index 1 => " << test->get(4) << endl;
	test->TestPrint();

	cout << "Operation : Get at Index 1 => " << test->get(4) << endl;
	test->TestPrint();

	cout << "Operation : Add Head" << endl;
	test->addAtHead(4);
	test->TestPrint();

	cout << "Operation : Add at Index [3, 0]" << endl;
	test->addAtIndex(5,0);
	test->TestPrint();

	cout << "Operation : Add Head" << endl;
	test->addAtHead(6);
	test->TestPrint();
	return 0;
}
