#include "lists.h"

/**
* print_list - Print all the elements of a list
* @h: pointer to the first node
* Return: Number of nodes
*/

size_t print_list(const list_t *h)
{
  size_t count;

  for (count = 0; h != NULL; count++)
  {
    if (h->str == NULL)
      printf("[0] (nil)");
    else
      printf("[%u] %s\n", h->len, h->str);
  }
  
  return (count);
}
