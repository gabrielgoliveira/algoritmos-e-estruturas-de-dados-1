#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int x;
    struct _node *previous, *next;
} node;

typedef struct _list {
    int size;
    node *start, *end; 
} list;

list* createList(){
    list* lista = (list*) malloc(sizeof(list));
    if(lista == NULL){
        return NULL;
    }
    lista->size = 0;
    lista->start = NULL;
    lista->end = NULL;
    return lista;
}

bool emptyList(list* lista){
    if(lista == NULL){
        return true;
    }
    return (lista->size == 0);
}

void push(list* lista, int id){
    node *temp = (node*) malloc(sizeof(node));
    if(lista == NULL || temp == NULL){
        return ;
    }
    temp->x = id;
    temp->next = NULL;
    if(emptyList(lista)){
        //if be list empty
        lista->start = temp;
        lista->end = temp;
        temp->previous = NULL;
    } else {
        lista->end->next = temp;
        temp->previous = lista->end;
        lista->end = temp;
    }
    lista->size++;
}

void printList(list *lista){
    node *temp = lista->start;
    if(emptyList(lista) || temp == NULL){
        printf("Lista Vazia!!\n");
        return ;
    }
    while(temp != NULL){
        printf("%d ", temp->x);
        temp = temp->next;
    }
    printf("\n");
}

void pop(list *lista){
    node *temp;
    temp = lista->start;
    lista->start = lista->start->next;
    free(temp);
    lista->size--;
}
node* searshElement(list *lista, int element){
    node *temp = lista->start;
    while(temp != NULL){
        if(temp->x == element){
            return temp;
        } 
        temp = temp->next;
    }
    return NULL;
}
void eraseList(list *list){
    node *temp, *aux;
    temp = list->start;
    while(temp!=NULL){
        aux = temp;
        temp = temp->next;
        free(aux);
        list->size--;
    }
}
int firstElement(list *lista){
    if(emptyList(lista)){
        return -1;
    }
    return lista->start->x;
}
bool removeElementList(list *lista, int aux){
    node *temp = lista->start;
    node *previous;

    while(temp != NULL){
        if(temp->x == aux){
            if(temp->next == NULL){
                //last element in list
                previous = temp->previous;
                previous->next = NULL;
                free(temp);
                lista->size--;
                return true;
            } else if(lista->start->x == temp->x){
                //first element in list
                pop(lista);
                return true;
            } else {
                //between first and last element
                previous = temp->previous; //element previous x
                previous->next = temp->next;
                previous->next->previous = previous;
                free(temp);
                lista->size--;
                return true;
            }
            
        } else {
            temp = temp->next;
        }
        
    }
    return false;
  
}

int main(){
    int n, m, i, aux;
    list *fila = createList();
    list *dropouts = createList();
    node *temp; 
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &aux);
        push(fila, aux);
    }
    scanf("%d", &m);
    for(i=0;i<m;i++){
        scanf(" %d", &aux);
        push(dropouts, aux);
    }
    while(!emptyList(dropouts)){
        aux = firstElement(dropouts);
        removeElementList(fila, aux);
        pop(dropouts);    
    }
    printList(fila);
    eraseList(fila);
    eraseList(dropouts);
    return 0;
}