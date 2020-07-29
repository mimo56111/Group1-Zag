#include "linked list functions.h"
int main()
{
    int value;
    node* head='\0' ;
    push_head(&head,25);
    push_end(head,&head,30);
    print_list(head);
    printf("\n");
    push_head(&head,5);
    print_list(head);
    printf("\n");
    value= pop_head(&head);
    printf("the popped value is: %i\n",value);
    print_list(head);
    printf("\n");
    value= remove_last(head,&head);
    printf("the last item is: %i\n",value);
    print_list(head);
    printf("\n");
    push_end(head,&head,300);
    print_list(head);
    printf("\n");
    insert_by_index(head,&head,50,1);
    print_list(head);
    printf("\n");
    remove_by_index(&head,1);
    print_list(head);
    printf("\n");
    remove_by_index(&head,0);
    print_list(head);
    printf("\n");
    remove_by_index(&head,0);
    print_list(head);
    printf("\n");
    return 0;
}
