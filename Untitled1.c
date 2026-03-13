#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct author{
    char name[50];
    char nationality[50];
};

struct book{
    int bookId;
    char title[50];
    float price;
    struct author auth;
};

struct book library[50];

void addBook( struct book lib[], int *count);
void viewAll(struct book lib[], int count);
void searchBook(struct book lib[], int count);


int main(){

    int menu=0;
    int count=0;

    printf("_____________________ Menu _____________________\n");
    printf("\n 1: Add new Book\n 2: View all Book\n 3: Search a Book\n 4: Edit Book Details\n 5: Remove Book\n 6: Total Value of all Books\n 7: Highest & Lowest valued Books\n 8: Search Books by Author's name\n 9: Book full info\n10: Search by keywords ");
    printf("\n\nChoose an option : ");
    scanf("%d",&menu);

    switch(menu){
    case 1:
        //function
        break;
    case 2:
        //func
        break;
    case 3:
        //func
        break;
    case 4:
        //func
        break;
    case 5:
        //func
        break;
    case 6:
        //func
        break;
    case 7:
        //func
        break;
    case 8:
        //func
        break;
    case 9:
        //func
        break;
    case 10:
        //func
        break;
    default:
        printf("Invalid selection!");
    }

}

// add new books
void addBook(struct book lib[], int *count){

    if (*count >=50){
        printf("Library is full \n");
        return;
    }

    printf("Enter Book ID : ");
    scanf("%d",&lib[*count].bookId);
    getchar();

    printf("Enter Book Title : ");
    fgets(lib[*count].title,50,stdin);

    printf("Enter Author Name : ");
    fgets(lib[*count].auth.name,50,stdin);

    printf("Enter Author Nationality : ");
    fgets(lib[*count].auth.nationality,50,stdin);

    printf("Enter Book Price : ");
    scanf("%f",&lib[*count].price);

    (*count)++;

    printf("Book added successfully \n");
}

//view all books
void viewAll(struct book lib[], int count){

    for(int i=0;i<count;i++){
        printf("%d\t%d\t%s\n",i+1,lib[i].bookId,lib[i].title);
    }
}

//search a book
void searchBook(struct book lib[],int count){

    int bookId;
    int found=false;

    printf("Enter Book Id ");
    scanf("%d",&bookId);

    for(int i=0;i<count;i++){
        if(bookId==lib[i].bookId){
            printf("Book is : %s",lib[i].title);
            found=true;
        }
    }
    if(!found)
        printf("Book not found");
}
