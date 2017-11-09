#include "LDLL.cpp"

void main()
{

	LDLL<int> obj;

	obj.insertAtHead(4);
	obj.insertAtHead(3);
	obj.insertAtHead(2);
	obj.insertAtHead(1);
	
	obj.traverse();

}