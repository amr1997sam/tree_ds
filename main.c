#include <stdio.h>
#include <stdlib.h>
#include "menu.h"



// binary search tree node
struct bst_node
{
    int data;
    struct bst_node* left_node;
    struct bst_node* right_node;
};

struct bst_node* insert(struct bst_node* proot, int n_data);
struct bst_node* create_bst_node(int n_data);
void preorder_print(struct bst_node* proot);
void inorder_print(struct bst_node* proot);
void postorder_print(struct bst_node* proot);

//
// main
//
int main()
{
    struct bst_node* proot = NULL;
    int n_data;

    int prompt =1; // flag for prompting loop. 1: prompt     0:finish
    int inserted=0;

    // start 
    // start menu
    PrintMenu();

    // console screen cursor coordinations
    int x =0;
    int y =3;
    returnToMainMenu(&y);


    while(prompt)
    {
        // get user input
        char ch;
        ch = getch();
        if (ch == 27){ // Escape sequence
            if (getchar() == 91){ // '['
            ch=getch();
            }
        }        

        switch (ch)
        {
            case DOWN_KEY:
                y++;
                if (y > MENU_L+2) {y = 3;}
                gotoxy(x,y);
                break;
            case UP_KEY:
                y--;
                if (y < 3) {y = MENU_L+2;}
                gotoxy(x,y);
                break;
            case ESC_KEY:
                system("clear");
                printf("terminating ...");
                return 0;
            case ENTER_KEY:
                switch(y)
                {
                    case 3: // add_node
                        system("clear");
                        
                        printf("Enter an integer to be inserted.\n");
                        printf("> ");
                        scanf("%d", &n_data);
                        proot = insert(proot, n_data);
                        
                        printf("\nPress any key to continue.\n");
                        getch();
                        returnToMainMenu(&y);
                        break;

                    case 4: // print tree preorder
                        system("clear");

                        preorder_print(proot);

                        printf("\nPress any key to continue.\n");
                        getch();
                        returnToMainMenu(&y);
                        break;

                    case 5: // print tree inorder
                        system("clear");

                        inorder_print(proot);

                        printf("\nPress any key to continue.\n");
                        getch();
                        returnToMainMenu(&y);
                        break;

                    case 6: // print tree posorder
                        system("clear");

                        postorder_print(proot);

                        printf("\nPress any key to continue.\n");
                        getch();
                        returnToMainMenu(&y);
                        break;

                    
                    case 7: // exit
                        system("clear");
                        printf("terminating ...\n");
                        prompt =0;
                        break;
                    
                    default:
                        break;
                }
        }
    }
    
    return 0;
}


//
// create node
//
struct bst_node* create_bst_node(int n_data){
    struct bst_node* ptr;
    ptr = (struct bst_node*) malloc(sizeof(struct bst_node));
    if(ptr){
        ptr->data = n_data;
        ptr->left_node = NULL;
        ptr->right_node= NULL;
    }
    return ptr;
}

//
// insert data into node
//
struct bst_node* insert(struct bst_node* proot, int n_data){
    struct bst_node* pnode;

    if (proot == NULL){
        pnode = create_bst_node(n_data);
        if(pnode){
            proot = pnode;
        }
    
    }else if (n_data < proot->data){
        proot->left_node =insert(proot->left_node, n_data);
    }else{
        proot->right_node =insert(proot->right_node, n_data);
    }

    return proot;
}




//
// traverse preorder
//
void preorder_print(struct bst_node* proot){
    struct bst_node* pnode = proot;
    if (!pnode){
        return;
    }else{  
        printf("%d ", pnode->data);
        preorder_print(pnode->left_node);
        preorder_print(pnode->right_node);
    }
}

//
// traverse inorder
//
void inorder_print(struct bst_node* proot){
    struct bst_node* pnode = proot;
    if (!pnode){
        return;
    }else{  
        inorder_print(pnode->left_node);
        printf("%d ", pnode->data);
        inorder_print(pnode->right_node);
    }
}

//
// traverse postorder
//
void postorder_print(struct bst_node* proot){
    struct bst_node* pnode = proot;
    if (!pnode){
        return;
    }else{  
        postorder_print(pnode->left_node);
        postorder_print(pnode->right_node);
        printf("%d ", pnode->data);

    }
}