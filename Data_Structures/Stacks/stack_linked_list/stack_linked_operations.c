/*      
*	    _____        _____________
*	   /     |      /             | 
*	  /      ▼     /              ▼
*	 E     │  'E'   │ ← top       E
*	       ├────────┤ 
*	       │  'D'   │
*	       ├────────┤
* 	       │  'C'   │
*              ├────────┤
* 	       │  'B'   │
*    	       ├────────┤
*	       │  'A'   │ ← Base de la pile
*	       └────────┘
*
*           First In, Last Out
*         
*                 lifo
*/	




#include <stdio.h>
#include <stdlib.h>

// 1
typedef struct Node {
    char data;
    struct Node *next;
} Node;

// 2.initialisation du pile par null
Node* init_stack() {
    return NULL;
}

//3.Empiler
Node* push(Node* top, char value) {
	Node* nv_Node = (Node*) malloc(sizeof(Node));
	if (!nv_Node) {
		printf("Erreur d'allocation mémoire\n");
		exit(1);
	}
	nv_Node->data = value;
	nv_Node->next = top;
	return nv_Node;//cette node qu'on va returner va etre le nouveau top mais dans le main
	}

//4.depiler un caractere
Node* pop(Node* top) {
    if (top == NULL) {
        printf("La pile est vide, rien à dépiler.\n");
        return NULL;
    }

    printf("Élément dépilé : %c\n", top->data);

    Node* temp = top;
    top = top->next;
    free(temp); // Libérer l'ancienne tête

    return top;
}

//5.vider le pile
Node *vider(Node *top){
	while (top != NULL){
		top = pop(top);
	}
	return top;
}


//6.aficher les caracters du pile 
void print_stack(Node* top) {
    if (top == NULL) {
        printf("La pile est vide.\n");
        return; //c quoi le vraiment deffirence entre exit et return
    }

    printf("Contenu de la pile (du sommet vers la base) :\n");
    while (top != NULL) {
        printf("%c\n", top->data);
        top = top->next;
    }
}


