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
void editBook(struct book lib[], int count);
void removeBook(struct book lib[],int *count);
void totalBooks(struct book lib[], int count);
void HighestAndLowestValuedBooks(struct book lib[], int count);


int main(){

    int menu=0;
    int count=0;

    printf("_____________________ Menu _____________________\n");
    printf("\n 1: Add new Book\n 2: View all Book\n 3: Search a Book\n 4: Edit Book Details\n 5: Remove Book\n");
    printf(" 6: Total Value of all Books\n 7: Highest & Lowest valued Books\n 8: Search Books by Author's name\n 9: Book full info\n10: Search by keywords ");
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

/*
    there is an issue, if user enter an existing id?
*/

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

//edit book details
void editBook(struct book lib[], int count){

    int bookId;
    int found=false;

    printf("Enter book ID");
    scanf("%d",&bookId);

    for(int i=0;i<count;i++){
        if(lib[i].bookId==bookId){

            printf("Enter new book title :");
            fgets(lib[i].title,50,stdin);

            printf("Enter new Price :");
            scanf("%f",&lib[i].price);

            printf("Enter new Author name :");
            fgets(lib[i].auth.name,50,stdin);

            printf("Enter New Author Nationality: ");
            fgets(lib[i].auth.nationality,50,stdin);

            found=true;
            printf("Book details updated successfully\n");
            return;
        }
    }
    if(!found)
    printf("Book not found\n");
}

//remove book from list
void removeBook(struct book lib[], int *count){

    int bookId;
    int found = true;

    printf("Enter Book ID to remove: ");
    scanf("%d",&bookId);

    for(int i=0;i<*count;i++){

        if(lib[i].bookId == bookId){

            for(int j=i;j<*count-1;j++){
                lib[j] = lib[j+1];
            }
            (*count)--;

            printf("Book removed successfully\n");
            found = true;
            break;
        }
    }

    if(!found){
        printf("Book not found\n");
    }
}

// total value of all books
void totalBooks(struct book lib[], int count){

    float total = 0;

    for(int i=0; i<count; i++){
        total += lib[i].price;
    }

    printf("Total value of all books: %.2f\n", total);
}

// highest and lowest value books
void HighestAndLowestValuedBooks(struct book lib[], int count){

    if(count == 0){
        printf("No books in library\n");
        return;
    }
    int highest = 0;
    int lowest = 0;

    for(int i=1; i<count; i++){
        if(lib[i].price > lib[highest].price){
            highest = i;
        }
        if(lib[i].price < lib[lowest].price){
            lowest = i;
        }
    }
    printf("\nHighest Valued Book is: %s\n",lib[highest].title);
    printf("\nLowest Valued Book is: %s\n",lib[lowest].title);
}


