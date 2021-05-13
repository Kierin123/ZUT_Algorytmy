#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// gcc -pthread -g -Wpedantic -Wall -Werror -pedantic-errors list.c main.c -o list

int main(int argc, char *argv[])
{
  List *A = create_list();

  // for (int i = 0; i < 10; i++)
  // {
  append_to_list(A, 2);
  append_to_list(A, -2);
  append_to_list(A, 5);
  append_to_list(A, 0);
  append_to_list(A, 9);
  append_to_list(A, -7);
  append_to_list(A, -10);

  // }

  //printf("Element [%d]: %d\n", 0, get_nth_element(A, 0));
  //printf("Element [%d]: %d\n", 1, get_nth_element(A, 1));
  //printf("Element [%d]: %d\n", 2, get_nth_element(A, 2));
  //printf("Element [%d]: %d\n", 3, get_nth_element(A, 3));

  //remove_nth_element(A, 3);
  //remove_nth_element(A, 2);
  //remove_nth_element(A, 1);
  //remove_nth_element(A, 0);

  //printf("Element [%d]: %d\n", 0, get_nth_element(A, 0));
  //printf("Element [%d]: %d\n", 1, get_nth_element(A, 1));
  //printf("Element [%d]: %d\n", 2, get_nth_element(A, 2));
  //printf("Element [%d]: %d\n", 3, get_nth_element(A, 3));
  //clear_list(A);
  printf("Counted A not insert: %d\n", count_elements(A));

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
  destroy_list(&A);
  // printf("Counted A: %d\n", count_elements(A));
  return 0;
}
