/**
 * Methods and declarations for Queue and Node
 */

#include "constants.h"
#include "tcb.h"
#include "malloc.h"

/**
 * nodes for the queue
 */
typedef struct _TCB_t
{
	ucontext_t context;
	struct _TCB_t *prev;
	struct _TCB_t *next;
	int dummy; // Only for tracking the queue and assist while printing
} TCB_t;

bool init_q(TCB_t * head);
bool add(TCB_t * head, ucontext_t context, int dummy);
bool del(TCB_t * head, TCB_t * to_delete);
bool rotate(TCB_t * head);

/**
 * Creates a new node with default settings
 * @return pointer to the new node created
 */
TCB_t * new_node() {
	TCB_t * new_node = (TCB_t *)malloc(sizeof(TCB_t));
	new_node -> next = NULL;
	new_node -> prev = NULL;
	// ALERT - context variable not set

	return new_node;
}

bool init_q(TCB_t * head, int dummy) {
	head -> next = head;
	head -> prev = head;
	head -> dummy = dummy;
}

/**
 * Add a node to the end of the queue
 * @param head of the queue
 * @param context for the new node
 * @return true if successful else false
 */
bool add(TCB_t * head, ucontext_t context, int dummy) {
	TCB_t * new_node = new_node();
	new_node -> context = context;
	new_node -> next = head;
	new_node -> prev = head -> prev;
	new_node -> dummy = dummy;

	head -> prev = new_node;
	new_node -> prev -> next = new_node;

	return true;
}

/**
 * deletes the given node from the queue
 * @param head of the queue
 * @param node to delete
 * @return true if successful
 */
bool del(TCB_t * head, TCB_t * to_delete){

}

/**
 * Moves the head node to the end of the queue 
 * @param pointer the head
 * @return true if succesful, else false
 */
bool rotate(TCB_t * head){

}