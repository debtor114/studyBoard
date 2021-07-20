#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <assert.h>

typedef int Key;

typedef struct tree_struct *tree;
typedef struct queue_struct *queue;


typedef struct tree_struct {
	tree    left;			// left child 
	tree    right;			// right child 
	Key		key;			// sorted by key
}tree_struct;

typedef struct queue_struct {		// not a SL list, but an array of BT node
	tree item;				// "queue or stack" called in the "Horwitz" book
	int capacity;			// queue size
	int N;					// the number of items queued
	int rear;				// rear of the queue - most recently added in FIFO
	int front;				// front of the queue - least recently added in FIFO
} queue_struct;


tree newTree();	                // instantiates a new tree
tree newNode(Key key);
tree freeNode(tree node);       // frees one node, returns NULL; useful for debugging
tree freeTree(tree root);       // frees all nodes in root and tree

tree insert(tree t, Key key);   // inserts a node with key
								// inserts a node at the node specified
tree insertAt(tree t, Key key, Key atNode, bool atLeft); // used to test isBST()
                                
tree delete(tree t, Key key);   // deletes a node with key

int maxHeightTree(tree node);		// returns the height of a tree. 
int sizeTree(tree node);			// returns number of nodes in tree
bool isEmptyTree(tree t);		    // true if tree is empty

bool contains(tree root, Key key);	   // does a node with the key exist?
bool contains2(tree root, Key key);
bool containsIteration(tree root, Key key);

tree getNode(tree node, Key key);   // returns a node with a key given 
tree minNode(tree node);			// returns the left most leaf 
tree maxNode(tree node);			// returns the right most leaf 
Key minKey(tree node);				// returns the left most leaf key 
Key maxKey(tree node);				// returns the right most leaf key 

tree predecessor(tree node);		// returns max node in left subtree
tree successor(tree node);		    // returns min node in right subtree 
Key predecessorKey(tree t);         // returns max key in left subtree
Key successorKey(tree t);           // returns min key in right subtree

void inorder(tree t);	            // prints binary tree in inorder
void postorder(tree t);		        // prints binary tree in postorder 
void preorder(tree t);	            // prints binary tree in preorder 
void levelOrder(tree t);            // prints binary tree in level-order 

bool isLeaf(tree node);             // returns true if a leaf node
bool isBST(tree t);				    // checks whether it is BST or not
bool isBST2(tree node, Key min, Key max);
bool isBSTinOrder(tree root);	// using in-order traversal

////////////////////// AVL Tree /////////////////////////////
bool isAVL(tree root);              // returns true if AVL Tree
bool isAVL2(tree root);

bool isBalanced(tree node);         // checks the balance factor 
int getBalanceFactor(tree node);	// height diff(left - right)
tree insertAVL(tree t, Key key);    // inserts a node with key
tree deleteAVL(tree t, Key key);    // deletes a node with key
tree rebalance(tree node);	        // rebalances at a node
tree rebalanceTree(tree root);	    // rebalances at the first 
                                    // unbalanced node once only

///////////////// AVL/BST Tree Testing ///////////////////
tree insertN(tree root, int N, bool AVLtree); // insert N nodes
tree deleteN(tree root, int N, bool AVLtree); // delete N nodes
											  
void shuffleArray(int N, int *arr); // shuffles the array
void getKeys(tree t, Key *keys, int N);   // returns N keys in level order
void randomN(int start, int N, int *arr); // returns N random ints


////////////////// queue tree ////////////////////
queue newTreeQueue(int capacity);	// queue is created with capacity(or array size)
void freeQueue(queue q);			// deallocate queue
int sizeQueue(queue q);			// return nItems queued currently
int capacity(queue q);				// return its capacity (array size)
int doubling(queue q);				// double the capacity of the queue

tree enqueue(queue s, tree n);	// return node if enqueued, otherwise return NULL
tree dequeue(queue q);			// delete node at front in the queue

int isFull(queue q);				// return true/false
int isEmptyQueue(queue q);	


void printTree(tree t);        // print the tree on console graphically


					   
// initializes the pointer to the tree root
// When the first key (node) is inserted, then it becomes the root actually.
tree newTree() {
	return NULL;
}

// instantiates a new node with a key and 
// returns the pointer of the new node which becomes a tree root. 
// Its left child and right child are set to NULL. 
tree newNode(Key key) {
	tree node = (tree)malloc(sizeof(tree_struct));
	assert(node != NULL);

	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// frees one node, not the tree
tree freeNode(tree node) {
	if (node != NULL) {
		DPRINT(printf(" freeNode(%d)\n", node->key));
		free(node);
	}
	return NULL;
}

// frees all nodes while traversing the tree like postorder
// recursively. Use freeNode() instead of free() for debugging.
tree freeTree(tree t) {

	if (t != NULL) {
		freeTree(t->left);
		freeTree(t->right);
	}

	t = freeNote(t);

	return freeNode(t);
}

// Inserts a new node with the key in given binary tree and 
// returns the new node such that client use it properly.

tree insert(tree node, Key key) {
	if (node == NULL) return newNode(key);

	if (key < node->key)	// recur down the tree
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	// do nothing, the duplicate key is not allowed
	return node;
}

// inserts a node at the node specified, used to test isBST()
tree insertAt(tree root, Key key, Key keyAtNode, bool atLeft) {
	if (root == NULL) return newNode(key);

	tree node = getNode(root, keyAtNode);
	if (node == NULL) return root;  // not found, return root

	if (node->left)
		node->right = newNode(key);
	else if (node->right)
		node->left = newNode(key);
	else if (node->left == NULL && node->right == NULL) {
		if (atLeft)
			node->left = newNode(key);
		else
			node->right = newNode(key);
	}
	else {
		// assert(node->left && node->right);  // has two children
	}

	return root;
}

///////////////////////////////////////////////////////////////////
// Delete
///////////////////////////////////////////////////////////////////
tree successor(tree node) {
	node = node->right;
	while (node->left != NULL) {
		node = node->left;
	}

	return node;
}

Key successorKey(tree root) {
	tree node = successor(root);
	if (node != NULL) return node->key;
	return (Key)NULL;
}

tree predecessor(tree node) {
	node = node->left;
	while (node->right != NULL) {
		node = node->right;
	}

	return node;
}

Key predecessorKey(tree root) {
	tree node = predecessor(root);
	if (node != NULL) return node->key;
	return (Key)NULL;
}

// deletes the node with the key in a tree and returns the new root
tree delete(tree root, Key key) {
	if (root == NULL) return root;	 // base case
	DPRINT(printf(">delete: now we are at %d\n", root->key));

	// then node to delete must be in left subtree.
	if (key < root->key)
		root->left = delete(root->left, key);

	// then node to delete must be in right subtree.
	else if (key > root->key)
		root->right = delete(root->right, key);

	// node with two childeren: replace it with the successor or predecessor
	else if (root->left && root->right) {
		printf("Your code here\n");
		Key target;

		if (maxHeightTree(root->left) < maxHeightTree(root->right))
			target = predecessorKey(root);

		else target = successorKey(root);



		// Implement using successor first, add predecessor logic later. 
		// get the successor: smallest in right subtree
		// copy the successor's content to this node
		// delete the successor recursively - call delete() 

	}
	else if (root->left) { // One Child Left Case
		DPRINT(printf(" One Child Case(%d)\n", root->key));
		printf("Your code here\n");
	}
	else if (root->right) { // One Child Right Case
		DPRINT(printf(" One Child Case(%d)\n", root->key));
		printf("Your code here\n");
	}
	else { // node with no child 
		DPRINT(printf(" No Child Case(%d)\n", root->key));
		root = freeNode(root);
	}

	return root;
}

// Computes the size of the binary tree dyamically by
// traversing the nodes recursively.
int sizeTree(tree node) {
	if (node == NULL) return 0;
	return 1 + sizeTree(node->left) + sizeTree(node->right);
}

bool isEmptyTree(tree t) {
	return t == NULL;
}

// Compute the max depth of a tree. It is the number of edges along
// the longest path from the root node down to the farthest leaf node.
// height 0 (undefined) for empty tree, 1 for root only tree;
int maxHeightTree(tree node) {
	if (isEmptyTree(node)) return 0;
	// compute the depth of each subree and return the larger one.
	printf("Your code here, fix return\n");
	return 0;
}

// This prints out nodes in inorder traveral of a binary tree.
// Given a binary search tree, print out its key in increasing sorted order
void inorder(tree node) {
	if (node == NULL) return;

	inorder(node->left);
	printf("%d", node->key);
	inorder(node->right);
}

// Given a binary tree, print out its nodes in postorder traversal.
void postorder(tree node) {
	if (node == NULL) return;
	// first of all recur on both subtrees
	postorder(node->left);
	postorder(node->right);
	printf("%d", node->key);
}

// Given a binary tree, print out its nodes in preorder traversal.
void preorder(tree node) {
	if (node == NULL) return;

	printf("%d", node->key);
	preorder(node->left);
	preorder(node->right);
}

// Given a binary tree, print out its nodes in level-order traversal
// using a queue.
void levelOrder(tree node) {
	if (node == NULL) return;

	queue_struct *q = newTreeQueue(sizeTree(node));
	enqueue(q, node);
	while (1) {
		node = dequeue(q);
		if (node == NULL) break;
		printf("%d ", node->key); 
		if (node->left) 	enqueue(q, node->left);
		if (node->right)	enqueue(q, node->right);
	}
	freeQueue(q);
}

// Given a binary search tree, return the min or max key in the tree.
// Don't need to traverse the entire tree.
Key minIteration(tree node) {
	while (node->left != NULL) {	// find the left most leaf
		node = node->left;
	}
	return node->key;
}

tree minNode(tree node) {			// returns min node
	if (node->left == NULL) return node;
	return minNode(node->left);
}

Key minKey(tree node) {
	if (node != NULL)return minNode(node)->key;
	else return node->key;
}

tree maxNode(tree node) {			// returns max node
	if (node->right == NULL) return node;
	return maxNode(node->right);
}

Key maxKey(tree node) {
	if (node != NULL) return maxNode(node)->key;
	else return node->key;
}

// does there exist a key-value pair with given key?
// search a key in binary search tree recursively.
bool contains(tree t, Key key) {
	if (isEmptyTree(t))   return false;
	return contains2(t, key);
}

bool contains2(tree node, Key key) {
	if (isEmptyTree(node)) return false;

	printf("Your code here, fix return\n");
	return 0;
}

// returns a node with a key given if found, otherwise NULL.
tree getNode(tree node, Key key) {
	if (isEmptyTree(node)) return NULL;

	if (key == node->key) return node;
	if (key < node->key)
		return getNode(node->left, key);
	return getNode(node->right, key);
}

// does there exist a key-value pair with given key?
// search a key in binary search tree iteratively
bool containsIteration(tree node, Key key) {
	if (node == NULL) return false;
	while (node) {
		if (key == node->key) return true;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return false;
}

bool isLeaf(tree node) {
	if (isEmptyTree(node)) return true;
	return node->left == NULL && node->right == NULL;
}

// does this binary tree satisfy symmetric order?
// Note: this test also ensures that data structure is a binary tree 
// since order is strict
bool isBST(tree root) {
	if (isEmptyTree(root)) return true;

	Key min = minKey(root);
	Key max = maxKey(root);
	return isBST2(root, min, max);
}

// is the tree rooted at x a BST with all keys between min and max?
bool isBST2(tree x, Key min, Key max) {
	
	printf("Your code here, fix return\n");

	return 0;
}

// While doing Inorder traversal, we can keep track of previously visited node.
// If the value of the currently visited node is less than the previous value, 
// then tree is not BST.
bool isBSTinOrder2(tree root, tree *prev) {
	// traverse the tree in inorder fashion and keep track of prev node
	if (root == NULL) return true;

	if (!isBSTinOrder2(root->left, prev)) return false;

	// Allows only distinct valued nodes 
	if (*prev != NULL && root->key <= (*prev)->key) return false;
	*prev = root;
	return isBSTinOrder2(root->right, prev);
}

bool isBSTinOrder(tree root) {
	tree prev = NULL;
	return isBSTinOrder2(root, &prev);
}

////////////////////////// AVL Tree ///////////////////////////////
bool isBalanced(tree node) {
	int factor = getBalanceFactor(node);
	return (factor >= -1 && factor <= 1) ? true : false;
}

// returns the balance factor or (height of left - height of right)
int getBalanceFactor(tree node) {
	if (node == NULL) return 0;
	int left = maxHeightTree(node->left);
	int right = maxHeightTree(node->right);
		return left - right;
}

bool isAVL(tree root) {
	if (root == NULL) return true;
	if (!isBST(root)) return false;
	return isAVL2(root);
}

bool isAVL2(tree root) {
	if (!isBalanced(root)) return false;
	if (root->left != NULL && !isAVL2(root->left))  return false;
	if (root->right != NULL && !isAVL2(root->right)) return false;
	return true;
}

tree rotateLL(tree node) {
	printf("\t[LL]rotation at %d\n", node->key);
	tree child = node->left;
	node->left = child->right;
	child->right = node;
	return child;
}

tree rotateRR(tree node) {
	printf("\t[RR]rotation at %d\n", node->key);
	tree child = node->right;
	node->right = child->left;
	child->left = node;
	return child;
}

tree rotateLR(tree node) {
	printf("\t[LR]rotation at %d\n", node->key);
	tree child = node->left;
	node->left = rotateRR(child);
	return rotateLL(node);
}

tree rotateRL(tree node) {
	printf("\t[RL]rotation at %d\n", node->key);
	tree child = node->right;
	node->right = rotateLL(child);
	return rotateRR(node);
}

// rebalnces at the node only, not recursively, and 
// returns the node that may be different from the input node
tree rebalance(tree node) {
	if (isBalanced(node)) return node;

	////// for tracing ////////
#ifdef DEBUG
	printTree(node);
	printf("Need rebalancing at (%d)\n", node->key);
#endif
	////// for tracing ////////

	int diff = getBalanceFactor(node);
	if (diff >= 2) {
		printf("Your code here\n");
	}
	else if (diff <= -2) {
		printf("Your code here\n");
	}
	return node;
}

// inserts a node in the AVL tree and rebalance it.
tree insertAVL(tree node, Key key) {
	if (node == NULL) return newNode(key);

	if (key < node->key) { // recur down the tree
		printf("Your code here\n");
	}
	else if (key > node->key) {
		printf("Your code here\n");
	}
	else 				  // if same key, update the value only
		;
	return node;
}

// deletes a node with key in the AVL tree and rebalance it.
tree deleteAVL(tree node, Key key) {
	// step 1 - delete a node as usual
	node = delete(node, key);

	// step 2 - get the balance factor of this node
	return rebalance(node);
}

// rebalances AVL tree at the root just once; 
// It finds the first unbalanced node and invokes rebalance() at that node.
// You may have to repeat this process as necessary to change a binary
// search to into a valid AVL tree
tree rebalanceTree(tree node) {
	if (node == NULL) return NULL;

	printf("Your code here\n");

	DPRINT(printf("Found 1st unbalanced node at %d\n", node->key));

	printf("Your code here\n");

	return node;
}

///////////////// stress test - insert, delete /////////////

// shuffles the array contents
void shuffleArray(int N, int *arr) {
	if (N <= 1) return;
	for (int i = 0; i < N; i++) {
		int x = rand() % (N - 1);
		int t = arr[i];
		arr[i] = arr[x];
		arr[x] = t;
	}
}
// returns an int array that has randomly mixed numbers 
// between start to start + N 
void randomN(int start, int N, int *arr) {
	for (int i = 0; i < N; i++) arr[i] = start + i;
	shuffleArray(N, arr);

#ifdef DEBUG
	printf("randomN: ");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
#endif
}

// inserts N numbers of keys in the tree(AVL or BST).
// If it is an empty tree, the value of keys to add ranges 
// from 0 to N-1.
// If there exists some nodes in the tree, the value of 
// keys to add ranges from max + 1 to max + 1 + N.
// 
tree insertN(tree root, int N, bool AVLtree) {
	Key max = isEmptyTree(root) ? 0 : maxKey(root) + 1;

	int *keys = (int *)malloc(sizeof(int) * N);
	assert(keys != NULL);

	randomN(max, N, keys);

	/*****************
	if (AVLtree)
	  for (int i = 0; i < N; i++) root = insertAVL(root, keys[i]);
	else
	  for (int i = 0; i < N; i++) root = insert(root, keys[i]);
	********or**********
	for (int i = 0; i < N; i++)
	  root = AVLtree ? insertAVL(root, keys[i]) : insert(root, keys[i]);
	******************/
	// using a function pointer 
	tree(*func)(tree root, Key key) = AVLtree ? insertAVL : insert;
	for (int i = 0; i < N; i++) root = func(root, keys[i]);
	
	free(keys);
	return root;
}

// returns N keys in an array from the tree (level order)
void getKeys(tree node, Key *keys, int N) {
	if (node == NULL) return;

	printf("Your code here\n");

#ifdef DEBUG
	printf("Keys(level-order): ");
	for (int i = 0; i < N; i++)
		printf("%d ", keys[i]);
	printf("\n");
#endif
}

// deletes randomly N numbers of nodes in the tree(AVL or BST).
// It gets N node keys from the tree, delete one by one in 
// random order.
tree deleteN(tree root, int N, bool AVLtree) {

	printf("Your code here\n");

	return root;
}






int main(int argc, char **argv) {
	char c;
	Key item;
	bool AVLtree = false;
	bool printTreeOn = true;     // invoke printTree() if true
	char *menuBST = "Binary Search Tree(BST) Menu";
	char *menuAVL = "Adelson-Velskii and Landis(AVL) Tree Menu";
	char *menuTitle;
	char *menuTreeDisplay;
	char *menuTreeDisplayOn  = "turn ON - 'tree display'";
	char *menuTreeDisplayOff = "turn OFF - 'tree display'";

	tree root = argc < 2 ? newTree() : treeFromArgs(argc, argv, AVLtree);
	if(printTreeOn) printTree(root);

	do {
		menuTitle = AVLtree ? menuAVL : menuBST;
		menuTreeDisplay = printTreeOn ? menuTreeDisplayOff : menuTreeDisplayOn;
		printf("\n\t%s \n"
			"\ti - insert\n"
			"\tj - insert at[BST only, Use with caution]\n"
			"\td - delete\n"
			"\ts - search\n"
			"\tm - min, max, size, and height\n"
			"\tp - predecessor and successor\n"
			"\tt - traverse\n"
			"\to - is this a BST or an AVL Tree?\n"
			"\tr - remove the tree and restart\n"
			"\tw - switch to AVL or BST\n"
			"\tx - stress test - insert\n"
			"\ty - stress test - delete\n"
			"\tg - %s\n",	menuTitle, menuTreeDisplay);
		printf("\tCommand(q to quit): ");
		c = GetChar();

		// try to execute the command
		switch (c) {
		case 'i':
			printf("\tEnter a key to insert: ");
			item = GetInt();
			root = AVLtree ? insertAVL(root, item) : insert(root, item);
			break;

		case 'j':
			if (AVLtree) break;
			printf("\tEnter a node key where to insert at: ");
			item = GetInt();
			if (!contains(root, item)) {
				printf("\tEnter a node key(%d) is not found)", item);
				break;
			}
			tree node = getNode(root, item);
			bool atLeft = true;
			printf("\tEnter l for left, r for right subtree: ");
			if (GetChar() == 'r') atLeft = false;
			
			printf("\tEnter a key to insert: ");
			int key = GetInt();
			root = insertAt(root, key, item, atLeft); 
			break;

		case 'd':
			if (isEmptyTree(root)) break;
			printf("\tEnter a key to delete: ");
			item = GetInt();
			root = AVLtree ? deleteAVL(root, item) : delete(root, item);
			break;

		case 's':
			if (isEmptyTree(root)) break;
			printf("\tEnter a key to search: ");
			item = GetInt();
			if (contains(root, item))
				printf("\n\t%d is found\n", item);
			else
				printf("\n\t%d is not found\n", item);
			break;

		case 'm':
			if (isEmptyTree(root)) break;
			printf("\n\tMin: %d \t Max: %d \t Size: %d \t Height: %d\n", 
				minKey(root), maxKey(root), sizeTree(root), maxHeightTree(root));
			break;

		case 'p':
			if (isEmptyTree(root)) break;
			Key pred = predecessorKey(root);
			Key succ = successorKey(root);
			if (pred && succ) 
				printf("\n\tPredecessor: %d\tSuccessor: %d\n", pred, succ);
			else if (pred) 
				printf("\n\tPredecessor: %d\tSuccessor: undefined\n", pred);
			else if (succ) 
				printf("\n\tPredecessor: undefined \tSuccessor: %d\n", succ);
			break;

		case 't':
			printf("\n\tInorder:     ");   inorder(root);
			printf("\n\tPreorder:    ");   preorder(root);
			printf("\n\tPostorder:   ");   postorder(root);
			printf("\n\tLevel-Order: ");   levelOrder(root);
			printf("\n");
			break;
		case 'o':
			if (isEmptyTree(root)) break;
			printf("\n\tBST: %s\n", isBSTinOrder(root) ? "true" : "false");
			printf("\tAVL: %s\n", isAVL(root) ? "true" : "false");
			break;
		case 'r':
			freeTree(root);
			root = newTree();
			break;
		case 'w':
			if (AVLtree)
				AVLtree = false;
			else {
				if (!isAVL(root)) {
					printf("\n\tUnbalanced AVL Tree\n");
					printf("\tTrying rebalance at root just once...\n");
					root = rebalanceTree(root);
				}
				if (isAVL(root)) AVLtree = true;
			}
			break;
		case 'x':
			printf("\tEnter a number of nodes to insert: ");
			item = GetInt();
			root = insertN(root, item, AVLtree);
			if (!isEmptyTree(root))
				printf("\n\tMin: %d \t Max: %d \t Size: %d \t Height: %d\n",
				minKey(root), maxKey(root), sizeTree(root), maxHeightTree(root));
			break;

		case 'y':
			printf("\tEnter a number of nodes to delete(max=%d): ", 
				sizeTree(root));
			item = GetInt();
			root = deleteN(root, item, AVLtree);
			if (!isEmptyTree(root)) 
				printf("\n\tMin: %d \t Max: %d \t Size: %d \t Height: %d\n",
				minKey(root), maxKey(root), sizeTree(root), maxHeightTree(root));
			break;

		case 'g':
			printTreeOn = printTreeOn ? false : true;  // toggle the tree display
			break;

		case 'q':
			break;
		}
		printf("\n");
		if (printTreeOn) printTree(root);
	} while (c != 'q');

	freeTree(root);
	printf("\n\t--Happy Coding!--\n");
	return EXIT_SUCCESS;
}
