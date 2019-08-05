#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

/*
 * Search specified value in a list.
 * Return node which contained value or NULL if not found
 */
Node *search(Node *l, int key) {
    while (l != NULL) {
        if (l->value == key) {
            return l;
        }

        l = l->next;
    }

    return NULL;
}

/*
 * Insert new value at the begin of a list
 */
void insert_head(Node **l, int value) {
    /* allocate new node */
    Node *new_header = malloc(sizeof(Node));
    
    /* set value in new node */
    new_header->value = value;

    /* new node point to current header */
    new_header->next = *l;

    /* set new node as header */
    *l = new_header;
}

/*
 * Insert new value at the end of a list
 */
void insert_tail(Node *l, int value) {
    /* point to the last node in the list */
    while (l->next != NULL) {
        l = l->next;
    }

    /* create new node which will be the last node */
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    /* make new node the last node */
    l->next = new_node;
}

/*
 * Insert after a node
 */
void insert_after(Node *node, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;
}

/*
 * Delete node which contains the specified value
 */
void delete(Node **l, int value) {
    Node *node_to_del = search(*l, value);

    if (node_to_del == NULL) {
        return;
    }

    /* node to delete is the first node */
    if ((*l)->value == node_to_del->value) {
        *l = node_to_del->next;
        free(node_to_del);
        return;
    }

    /* find the node right before node to delete */
    Node *p = *l;
    while (1) {
        if (p->next->value == node_to_del->value){
            break;
        }
        p = p->next;
    }

    p->next = node_to_del->next;
    free(node_to_del);
}

/*
 * Helper function to initialize a list from given array
 */
Node *initialize_list(int arr[], int size) {
    Node *list = malloc(sizeof(Node));
    list->value = arr[0];
    list->next = NULL;

    Node *current_node = list;

    for (int i = 1; i < size; i++) {
        Node *node = malloc(sizeof(Node));
        node->value = arr[i];
        node->next = NULL;
        current_node->next = node;
        current_node = node;
    }

    return list;
}

/*
 * Helper function to print a list
 */
void print_list(Node *l) {
    if (l == NULL) {
        printf("Empty list\n");
        return;
    }

    while (1) {
        printf("%d", l->value);
        l = l->next;
        if (l != NULL) {
            printf(" -> ");
        } else {
            printf("\n");
            break;
        }
    }
}

int main() {

    Node *list = NULL; /* should always set to NULL */
    print_list(list);

    printf("\ninsert 1 to head\n");
    insert_head(&list, 1);
    print_list(list);

    printf("\ninsert 0 to head\n");
    insert_head(&list, 0);
    print_list(list);

    printf("\ninsert 3 to tail\n");
    insert_tail(list, 3);
    print_list(list);

    printf("\ninsert 2 after 1\n");
    Node *node = search(list, 1);
    if (node != NULL) {
        insert_after(node, 2);
    }
    print_list(list);

    printf("\ndelete 1\n");
    delete(&list, 1);
    print_list(list);

    printf("\ndelete 0\n");
    delete(&list, 0);
    print_list(list);
 
    printf("\ndelete 3\n");
    delete(&list, 3);
    print_list(list);
    
    printf("\ndelete 2\n");
    delete(&list, 2);
    print_list(list);

    return 0;
}
