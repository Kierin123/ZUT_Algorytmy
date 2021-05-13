#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// gcc -pthread -g -Wpedantic -Wall -Werror -pedantic-errors list.c main.c -o list

int main(int argc, char *argv[])
{
  List *A = create_list();

  // for (int i = 0; i < 10; i++)
  // {
  append_to_list(A, 500);
  append_to_list(A, -2);
  append_to_list(A, 1);
  append_to_list(A, -5);
  append_to_list(A, 0);
  append_to_list(A, 9);
  append_to_list(A, -7);
  append_to_list(A, -10);

  // }

  printf("Counted A before insert: %d\n", count_elements(A));
  for (int i = 0; i < count_elements(A); i++)
  {
    printf("List[%d] element: %d\n", i, get_nth_element(A, i));
  }

  insert_to_list(A, -2, 5);
  insert_to_list(A, 2, 1);
  insert_to_list(A, 221, 8);
  insert_to_list(A, -92, 4);

  printf("Counted A after insert: %d\n", count_elements(A));
  for (int i = 0; i < count_elements(A); i++)
  {
    printf("List[%d] element: %d\n", i, get_nth_element(A, i));
  }

  reverse_list(A);

  printf("Counted A after reverse: %d\n", count_elements(A));
  for (int i = 0; i < count_elements(A); i++)
  {
    printf("List[%d] element: %d\n", i, get_nth_element(A, i));
  }

  sort_list(A);

  printf("Counted A after sort: %d\n", count_elements(A));
  for (int i = 0; i < count_elements(A); i++)
  {
    printf("List[%d] element: %d\n", i, get_nth_element(A, i));
  }

  clear_list(A);

  printf("Counted A after clear: %d\n", count_elements(A));
  for (int i = 0; i < count_elements(A); i++)
  {
    printf("List[%d] element: %d\n", i, get_nth_element(A, i));
  }

  destroy_list(&A);
  return 0;
}
