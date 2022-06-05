#include<bits/stdc++.h>
using namespace std;


class Node {
 	public:
	int  data;

	// this is storing address of node 
	// why Node type coz pointer pointing to the adress of node
	Node* next;

	// constructor function. which construct single node
	Node (int data){
		this-> data = data;
		this-> next = NULL;
	}

	// destructor 
	~Node (){
		int value = this-> data;
		if(this->next != NULL){
			delete next;
			this->next = NULL;
		}

	}
};

void print(Node* &head){
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
	
		Node* temp = head;

		// stop when temp = NULL
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
    	cout<<endl;
}

void InseartAthead(Node* &head, int data){
	// creation of node here is the data = passed data and next of temp is NULL heer initially
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}

void InseartAttail(Node* &tail, int data){
	Node* temp = new Node(data);
	tail->next = temp;
	tail = tail->next;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int data) {


    //insert at Start
    // if(position == 1) {
    //     InsertAthead(head,data);
    //     return;
    // }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    // if(temp -> next == NULL) {
    //     InsertAttail(tail,data);
    //     return ;
    // }

    //creating a node for d
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deletion(Node* &head,int position){
	if(position==1){
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else {
		Node* current = head;
		Node* prev = NULL;

		int cnt = 1;
		while(cnt < position){
			prev = current;
			current = current->next;
			cnt++;
		}

		prev->next = current->next;
		current->next = NULL;
		delete current;
	}
}

// floyd's algo
bool detectloop(Node* &head)
{

	if(head==NULL){
		return 0;
	}

    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && slow!=NULL){
    	// slow will change by 1 step

        // fast will change by 2 step
        fast = fast->next;
        if(fast!=NULL){
        	fast=fast->next;
        }
        slow = slow->next;  

        // if while not break the slow == fast
        if(slow==fast){
        	return 1;
        }   
    }

     return 0;

}

void reverseLL(Node* &head){

	Node* prev = NULL;
	Node* curr = head;
	Node* forward = NULL;

	// Logic of reverseLL
	while(curr!=NULL){
		forward = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forward;

	}

	// printing reverseLL
	head = prev;
  	curr = head;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr = curr->next;
	}

}

int main(){
	
	// create a objBect here 

	Node* node1 = new Node(10);
	Node* head = node1;
    Node* tail = node1;
	// cout<< node1->data <<endl;
	// cout<< node1->next <<endl;
	print(head);


	InseartAthead(head,80);
	print(head);
	InseartAttail(tail,90);
	print(head);
	InseartAttail(tail,900);
	print(head);
	insertAtPosition(head,tail,2,60);
	print(head);

	// reverseLL(head);
	// print(head);

	
	if(detectloop(head)==0){
		cout<<"No loop present";
	}
	else cout<<"loop detected";
	// print(head);


	return 0;
}