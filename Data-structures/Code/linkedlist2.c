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
    pNode aNode = (pNode)malloc(sizeof(pNode));
    aNode->item = item;
    aNode->next = NULL;
    return aNode;
}

// instantiates a new node, sets item and next
pNode newNodeX(pNode next, int item) {
    pNode aNode = (pNode)malloc(sizeof(pNode));
    aNode->item = item;
    aNode->next = next;
    return aNode;
}

/** frees nodes in a linked list */
void freeNode(pNode headNode) {
    if (headNode->next == NULL) free(headNode);
    else {
        pNode temp = (pNode)malloc(sizeof(pNode));
        while (headNode != NULL) {
            temp = headNode;
            headNode = headNode->next;
            free(temp);
        }
    }
}

/** frees a linked list */
void freeList(pList p) {
    if (!isEmptyList) {
        free(p->head);
        free(p);
    }
}

pList newList() {
    pList p = (pList)malloc(sizeof(pList));
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
    return p;
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
	for (pNode x = p->head; x != NULL; x = x->next) 
        count++;
	return count;
}


// deletes a node at the end, O(1)
// this is a challenging problem.
void deleteAtTail(pList p) {
	DPRINT(printf("<deleteAtTail\n"));


	DPRINT(printf("<insertAtTail(size=%d)\n", p->size));
}


// delete N nodes at the end, O(1)
void deleteAtTailN(pList p) {
	DPRINT(printf(">deleteAtTailN(N=%d)\n", size(p)));

	
	DPRINT(printf("<deleteAtTailN(size=%d)\n", p->size));
}

// delete N nodes at the end, O(N)
void deleteAtLastN(pList p) {
	DPRINT(printf(">deleteAtLastN(N=%d)\n", size(p)));

    for (int i = 0; i < size(p); i++) {
        deleteLast(p);
    }


	DPRINT(printf("<deleteAtLastN(size=%d)\n", p->size));
}


/** // inserts a node at the end, O(1) */
void insertAtTail(pList p, int item) {
	DPRINT(printf("<insertAtTail(item=%d)\n", item));
	
	DPRINT(printf("<insertAtTail(size=%d)\n", p->size));
}

// inserts N nodes at the end, O(1)
void insertAtTailN(pList p, int N) {
	DPRINT(printf("<insertAtTailN(N=%d)\n", N));

	DPRINT(printf("<insertAtTailN(size=%d)\n", p->size));
}


// inserts N number of nodes in sorted order
void insertSortedN(pList p, int N) {
	DPRINT(printf("<insertSortedN(N=%d)\n", N));


	DPRINT(printf("<insertSortedN(total size=%d)\n", p->size));
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

}