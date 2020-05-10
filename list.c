#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static Node * Node_construct(int v)
{
  Node * n = malloc(sizeof(Node));
  n -> value = v;
  n -> next = NULL;
  return n;
}

Node * List_insert_last(Node * head, int v)
{
    if (head == NULL)
    {
        printf("Error there is no head node");
        return NULL;
    }
    else
    {
        printf("Inserting Tail: %d\n", v);
        while (head -> next != NULL)
        {
            head = head -> next;
        }
        head -> next = Node_construct(v);
        return head -> next;
    }
}

Node * List_insert(Node * head, int v)
{
  printf("Inserting: %d\n", v);
  Node * p = Node_construct(v); 
  p -> next = head;
  return p;   /* insert at the beginning */
}

Node * List_search(Node * head, int v)
{
  Node * p = head;
  while (p != NULL)
    {
      if ((p -> value) == v)
	{
	  return p;
	}
      p = p -> next;
    }
  return p;
}

Node * List_delete(Node * head, int v)
{
  printf("List_delete(): %d\n", v);
  Node * p = head;
  if (p == NULL) /* empty list, do nothing */
    {
      return p;
    }
  /* delete the first node (i.e. head node)? */
  if ((p -> value) == v)
    {
      p = p -> next;
      free (head);
      return p;
    }

  /* not deleting the first node */

  Node * q = p -> next;
  while ((q != NULL) && ((q -> value) != v))
    {
      /* must check whether q is NULL 
	 before checking q -> value */
      p = p -> next;
      q = q -> next;
    }
  if (q != NULL) 
    { 
      /* find a node whose value is v */
      p -> next = q -> next;
      free (q);
    }
  return head; 
}

void List_destroy(Node * head)
{
  while (head != NULL)
    {
      Node * p = head -> next;
      free (head);
      head = p;
    }
}

void List_print(Node * head)
{
    printf("Current List: ");
    while (head != NULL)
    {
        printf("%d ", head -> value);
        head = head -> next;
    }
    printf("\n");
}
