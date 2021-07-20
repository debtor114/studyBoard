#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <malloc.h>


#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

typedef struct node* pNode;

typedef struct node{
	int item;
	pNode next;
}node;

typedef struct list* pList;

typedef struct list{
	pNode 	head;
	pNode   tail;						// not used for Step 1    
	int     size;   
	int     maxPrintSize;				// set to 10 initially
}list;


pNode newNode(int item);                // instantiates a node 
pNode newNodeX(pNode next, int item);   // instantiates a node, sets item and next	
pList newList();						// initialize a linked list

void freeNode(pNode p);					// internal use
void freeList(pList p);					// frees a linked list
bool isEmptyList(pList p);				// true if empty, false if no empty
int size(pList p);						// returns size in the list
int getSize(pList p);					// internal use - count nodes in list

void insertFront(pList p, int item);	// inserts a node at front of linked 
void insertLast(pList p, int item);		// internal use - inserts a node at the end
										// scan the list to find the end, O(n)
void insertAtTail(pList p, int item);	// inserts a node at the end, O(1)
void insertIndex(pList p, int item, int x); // inserts a node at an index, front=0
void insertSorted(pList p, int item);	// inserts a node in sorted order
void insertSortedN(pList p, int N);	    // inserts N nodes in sorted order, O(n)
void insertAtTailN(pList p, int N);	    // inserts N nodes at the end, O(1)

void deleteFront(pList p);              // deletes the first node in the list
void deleteLast(pList p);               // deletes the last node in the list, O(n)

void deleteNode(pList p, int item);		// deletes the node with the item
void deleteAtLastN(pList p);			// deletes all the nodes O(n)
void deleteAtTailN(pList p);			// deletes all the nodes O(1) - Using doubly linked list

int search(pList p, int item);			// returns index of item if found, -1 if not
void traverse(pList p);					// shows all items in linked list 
bool verify(pList p);		


// instantiates a node
pNode newNode(int item) {
	pNode aNode = (pNode)malloc(sizeof(node));
	assert(aNode != NULL);
	aNode->item = item;
	aNode->next = NULL;
	return aNode;
}

// instantiates a new node, sets item and next
pNode newNodeX(pNode next, int item) {
	pNode aNode = (pNode)malloc(sizeof(node));
	assert(aNode != NULL);
	aNode->item = item;
	aNode->next = next;
	return aNode;
}

/** frees nodes in a linked list */
void freeNode(pNode headNode) {
 	pNode temp;

	if (headNode->next == NULL)
		free(headNode);

	else {
		while (headNode != NULL) {
			temp = headNode;
			headNode = headNode->next;
			free(temp);
		}
	}
}

/** frees a linked list */
void freeList(pList p) {
	if (!isEmptyList(p)) {
		freeNode(p->head);
		free(p);
	}
}

pList newList() {
	pList aList = (pList)malloc(sizeof(list));
	assert(aList != NULL);
	aList->head = NULL;
	aList->tail = NULL;
	aList->size = 0;
	return aList;
}

/** returns true if empty, false if no empty */
bool isEmptyList(pList p) {
	return p == NULL || p->head == NULL;
}

int size(pList p) {
	return p->size;
}

int getSize(pList p) {
	if (isEmptyList(p)) return 0;
	int count = 0;
	for (pNode x = p->head; x != NULL; x = x->next) count++;
	return count;
}

// deletes the first node in the list
void deleteFront(pList p) {
	DPRINT(printf(">deleteFront\n"));
	if (isEmptyList(p))
		return;    // nothing to delete

	pNode curr = p->head;
	pNode aNode = curr->next;
	free(curr);
	p->head = aNode;
	p->size--;

	if (p->size == 0)
		p->tail = NULL;

	DPRINT(printf("<deleteFront\n"));
}

// deletes the last node in the list, O(n)
void deleteLast(pList p) {
	DPRINT(printf(">deleteLast(size=%d)\n", p->size));
	pNode head = p->head;
	pNode aNode = head->next;

	p->size--;
	if (p->size == 0)
		p->head = NULL;

	if (isEmptyList(p))
		return;    // nothing to delete

	else {
		while (aNode->next != NULL) {
			head = head->next;
			aNode = head->next;
		}

		head->next = aNode->next;
		free(aNode);
	}
	DPRINT(printf("<deleteLast(size=%d)\n", p->size));
}


// deletes a node at the end, O(1)
// this is a challenging problem.
void deleteAtTail(pList p) {
	DPRINT(printf("<deleteAtTail\n"));

	printf("Not implemented\n");

	DPRINT(printf("<insertAtTail(size=%d)\n", p->size));
}

// deletes the node by the item
void deleteNode(pList p, int item) {
	DPRINT(printf(">deleteNode(item=%d)\n", item));
	if (isEmptyList(p))
		return;    // nothing to delete

	pNode curr = p->head;
	pNode aNode = curr->next;
	// if item to delete is the head(first) node
	if (curr->item == item) {
		deleteFront(p);
	}

	else {  // search for the item to delete in the list
		while (curr->next != NULL) {
			if(aNode->item == item) {
					if (aNode->next == NULL)
						curr->next = NULL;
					else
						curr->next = aNode->next;

					p->size--;
					free(aNode);
					break;
			}
			curr = curr->next;
			aNode = curr->next;
		}
	}
	DPRINT(printf("<deleteNode(size=%d)\n", p->size));
}


// delete N nodes at the end, O(1)
void deleteAtTailN(pList p) {
	DPRINT(printf(">deleteAtTailN(N=%d)\n", size(p)));

	srand((unsigned)time(NULL));
	for (int i = size(p); i > 0; i--) {
		printf("\r\tdeleting in [%7d]", i);
		deleteAtTail(p);
	}
	printf("\n");
	DPRINT(printf("<deleteAtTailN(size=%d)\n", p->size));
}

// delete N nodes at the end, O(N)
void deleteAtLastN(pList p) {
	DPRINT(printf(">deleteAtLastN(N=%d)\n", size(p)));

	for (int i = size(p); i > 0; i--) {
		printf("\r\tdeleting in [%7d]", i);
		deleteLast(p);
	}
	printf("\n");
	DPRINT(printf("<deleteAtLastN(size=%d)\n", p->size));
}

// inserts a node at front of linked list
void insertFront(pList p, int item) {
	DPRINT(printf(">insertFront(item=%d)\n", item));

	p->head = newNodeX(p->head, item);
	p->size++;

	if (p->size == 1)
		p->tail = p->head;	// only one node

	DPRINT(printf("<insertFront(size=%d)\n", p->size));
}

// inserts a node at the last of linked list
void insertLast(pList p, int item) {
	DPRINT(printf(">insertLast(item=%d)\n", item));

	if (p->head == NULL)
		p->head = newNode(item);

	else {
		pNode node = p->head;
		while (node->next != NULL)
			node = node->next;

		node->next = newNode(item);

	}
	p->size++;

	DPRINT(printf("<insertLast(size=%d)\n", p->size));
}


/** // inserts a node at the end, O(1) */
void insertAtTail(pList p, int item) {
	DPRINT(printf("<insertAtTail(item=%d)\n", item));
	printf("Your code comes here\n");
	DPRINT(printf("<insertAtTail(size=%d)\n", p->size));
}

// inserts N nodes at the end, O(1)
void insertAtTailN(pList p, int N) {
	DPRINT(printf("<insertAtTailN(N=%d)\n", N));
	printf("Your code comes here\n");
	DPRINT(printf("<insertAtTailN(size=%d)\n", p->size));
}

/** inserts a node in sorted order */
void insertSorted(pList p, int item) {
	DPRINT(printf("<insertSorted(item=%d)\n", item));
    // there is no item or item is smaller than first item
	pNode head = p->head;

	if (head == NULL || item < head->item)
		insertFront(p, item);

	else {
		pNode node = newNode(item);

		while(head->next != NULL) {
			if(head->item <= node->item && (head->next)->item > node->item) {
				node->next = head->next;
				head->next = node;
				p->size++;
				break;
			}
			head = head->next;
		}

		if (head->next == NULL) {
			head->next = node;
			p->size++;
		}
	}

	DPRINT(printf("<insertSorted(size=%d)\n", p->size));
}

// inserts N number of nodes in sorted order
void insertSortedN(pList p, int N) {
	DPRINT(printf("<insertSortedN(N=%d)\n", N));

	printf("Your code comes here\n");

	DPRINT(printf("<insertSortedN(total size=%d)\n", p->size));
}

// inserts a node at an index, 0 for front
void insertIndex(pList p, int item, int index) {
	if (index < 0)
		return;

	pNode head = p->head;
	pNode node = newNode(item);
	int i=0;

	for (i=0; i<index; i++) {
		head = head->next;
	}
	node->next = head->next;
	head->next = node;
	p->size++;
}

/** returns index of item if found, -1 if not */
int search(pList p, int item) {
	int index = 0;

	pNode curr = p->head;
	do {
		if (curr->item == item) {
			return index;
		}
		index++;
		curr = curr->next;
	} while (curr != NULL);
	return -1;
}

/** shows all items in linked list */
void traverse(pList p) {
	if (isEmptyList(p)) {
		printf("\n\tThe list is empty.\n");
		return;
	}

	printf("\n\tList[0..%d]: ", size(p)-1);
	pNode curr = p->head;

	printf("%d", curr->item);
	curr = curr->next;
	while (curr != NULL) {
		printf(" -> %d" , curr->item);
		curr = curr->next;
	};
	printf("\n");
}

// verify size and tail information in linked list header
bool verify(pList p) {
	bool verified = true;

	if (isEmptyList(p)) {
		if (p->size != 0) {
			printf("\tIts length(%d) should be 0.", p->size);
			verified = false;
		}
		if (p->tail != NULL) {
			printf("\tIts tail should be NULL.");
			verified = false;
		}
		return verified;
	}

	// Count the number of nodes and get the last node in the list.
	pNode curr, prev;
	int nodeCount = 0;
	curr = p->head;
	do {
		prev = curr;
		++nodeCount;
		curr = curr->next;
	} while (curr != NULL);

	if (p->size != nodeCount) {
		printf("\tThe size(%d) in the list is different from the actual node count(%d).\n",
			p->size, nodeCount);
		verified = false;
	}
	if (prev != p->tail) {
		printf("\tThe tail is different from the actual tail of the list.\n");
		verified = false;
	}

	return verified;
}


int main(int argc, char **argv) {
	char c;
	int item, index;

	pList p = newList();
	do {
		printf("\n\tLinked List MENU\n"
			"\tf - insert at front\n"
			"\tl - insert at last, O(n)\n"
			"\tt - insert at tail, O(1)\n"
			"\ti - insert sorted\n"
			"\tn - insert at index\n"
			"\n"
			"\tx - delete at front\n"
			"\ty - delete at last, O(n)\n"
			"\td - delete by item\n"
			"\ts - search\n"
			"\tv - verify header(size,tail) and prev link info.\n"
			"\tI - stress test: insert  sorted, O(n)\n"
			"\tT - stress test: insert at tail, O(1)\n"
			"\tY - stress test: delete at last, O(n)\n"
			"\tc - clear the list\n");
		printf("\tCommand[q to quit]: ");
		c = getchar();

		// try to execute the command
		switch (c) {
		case 'f':
		case 'l':
		case 't':
		case 'n':
		case 'i':
			printf("\tEnter a number to insert: ");
            scanf("%d", &item);
            // item = GetInt();
			
			switch (c) {

			case 'f':
				insertFront(p, item);
				break;
			case 'l':
				insertLast(p, item);
				break;
			case 't':
				insertAtTail(p, item);
				break;
			case 'i':
				insertSorted(p, item);
				break;
			case 'n':
				printf("\tEnter an index[0..%d]: ", size(p) - 1);
                scanf("%d", &index);
				// index = GetInt();
				insertIndex(p, item, index);
			}
			break;

		case 'x':  // deletes the first node in the list
			if (isEmptyList(p)) break;
			deleteFront(p);
			break;
		case 'y':  // deletes the last node in the list, O(n)
			if (isEmptyList(p)) break;
			deleteLast(p);
			break;
		case 'd':  // deletes node by item
			if (isEmptyList(p)) break;
			printf("\tEnter a number to delete: ");
            scanf("%d", &item);
            // item = GetInt();
			deleteNode(p, item);
			break;
		case 's':
			if (isEmptyList(p)) break;
			printf("\tEnter a number to search: ");
            scanf("%d", &item);
            // item = GetInt();
			index = search(p, item);
			if (index < 0)
				printf("\n\t\"%d\" is not found.\n", item);
			else
				printf("\n\t\"%d\" is found at [%d].\n", item, index);
			break;
		case 'v':
			if (verify(p))
				printf("\tThe verfication was successful.\n");
			else
				printf("\tThe verification was failed.");
			break;
		case 'I':
			printf("\tHow many nodes to insert(Sorted)?: ");
            scanf("%d", &item);
            // item = GetInt();
			insertSortedN(p, item);
			break;
		case 'T':
			printf("\tHow many nodes to insert(AtTail)?: ");
            scanf("%d", &item);
            // item = GetInt();
			insertAtTailN(p, item);
			break;
		case 'Y':
			deleteAtLastN(p);
			break;
		case 'c':
			if (isEmptyList(p)) break;
			freeList(p);
			p = newList();
			break;
		}
		traverse(p);
	} while (c != 'q');

	freeList(p);
	printf("\n\t--Happy Coding!--\n");
	return EXIT_SUCCESS;
}