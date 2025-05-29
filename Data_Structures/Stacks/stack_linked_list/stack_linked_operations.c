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
*                 filo
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
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    return newNode;//cette node qu'on va returner va etre le nouveau top mais dans le main
}
