#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
struct book
{
    char bookname[100];
    char author[100];
    int id;
};
struct login
{
    char username[100];
    char password[100];

};
void head_text()
{
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      LIBRARY MANAGEMENT SYSTEM PROJECT IN C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------");
}
void welcome_text()
{
    head_text();
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t\t        =                   TO                      =");
    printf("\n\t\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
    system("cls");
}
//admin mode
void View_Books()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                   VIEW BOOKS                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n");

    struct book b;
    FILE *file = fopen("book.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    else
    {
        while(fread(&b,sizeof(b),1,file))
        {
            printf("\n\n\t\t\tBook Name: %s\n\t\t\tAuthor Name: %s\n\t\t\tBook Id: %d\n",b.bookname,b.author,b.id);
        }
        fclose(file);
    }
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        admin();
    }
}
//admin mode
void Add_Books()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                      ADD BOOK                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct book b;
    FILE *file;
    file = fopen("book.txt","a");
    int n,count=0;
    if(file==NULL)
    {
        printf("File is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter How Many Book Do You Want To Add: ");
    scanf("%d",&n);
    while(count<n)
    {
        printf("\n\t\t\tEnter Book Name: ");
        fflush(stdin);
        gets(b.bookname);
        printf("\n\t\t\tEnter Author Name: ");
        fflush(stdin);
        gets(b.author);
        printf("\n\t\t\tEnter ID: ");
        scanf("%d",&b.id);
        fwrite(&b,sizeof(b),1,file);
        count++;

    }
    printf("\n\n\n\t\t\tBook Information Added Successfully");
    fclose(file);
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        admin();
    }
}
//admin mode
void Search_book_by_name()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  SEARCH BOOK BY ID                ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct book b;
    int id,flag=0;
    FILE *file;
    file = fopen("book.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter The Book Id Which You Want To Search: ");
    scanf("%d",&id);
    while(fread(&b,sizeof(b),1,file))
    {
        if(id==b.id)
        {
            flag=1;
            printf("\n\n\t\t\tBook Name: %s\n\t\t\tAuthor Name: %s\n\t\t\tBook Id: %d\n",b.bookname,b.author,b.id);
        }
    }
    if(!flag)
    {
        printf("\n\n\n\t\t\tBook is not Found");
    }
    fclose(file);

    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        admin();
    }
}
//admin mode
void Total_Books()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                     TOTAL BOOKS                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct book b;
    FILE *file;
    file = fopen("book.txt","r");
    fseek(file,0,SEEK_END);
    int n=ftell(file)/sizeof(b);
    printf("\n\n\n\t\t\tTotal Book = %d",n);
    fclose(file);

    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        admin();
    }
}
//admin mode main
void admin()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############             WELCOME TO ADMIN MODE                 ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.View Books"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Add Books"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"3.Search book by Category/By name"};
    printf("\n\t\t\t%s",c);
    char d[100]= {"4.Total Books"};
    printf("\n\t\t\t%s",d);
    char e[100]= {"5.Back"};
    printf("\n\t\t\t%s",e);
    char f[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        View_Books();
        break;
    case 2:
        Add_Books();
        break;
    case 3:
        Search_book_by_name();
        break;
    case 4:
        Total_Books();
        break;
    case 5:
        admin_user();
        break;
    }
}
//user mode
void Search_books()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                     SEARCH BOOK                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct book b;
    int id,flag=0;
    FILE *file;
    file = fopen("book.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter The ID Number of Book That You Need: ");
    scanf("%d",&id);
    while(fread(&b,sizeof(b),1,file))
    {
        if(id==b.id)
        {
            flag=1;
            printf("\n\n\t\t\tBook Name: %s\n\t\t\tAuthor Name: %s\n\t\t\tBook Id: %d\n",b.bookname,b.author,b.id);
        }
    }
    if(!flag)
    {
        printf("\n\n\n\t\t\tBook is not Found");
    }
    fclose(file);

    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        user();
    }
}
//user mode
void  Book_lists()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                    BOOK LIST                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n\n");

    struct book b;
    FILE *file = fopen("book.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    else
    {
        while(fread(&b,sizeof(b),1,file))
        {
            printf("\n\n\t\t\tBook Name: %s\n\t\t\tAuthor Name: %s\n\t\t\tBook Id: %d\n",b.bookname,b.author,b.id);
        }
        fclose(file);
    }
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        user();
    }
}
//user mode
void Borrow_Books()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                     BORROW BOOK                   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct book b;
    int id,flag=0;
    FILE *file;
    file = fopen("book.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter The Book Id Which You Want To Borrow: ");
    scanf("%d",&id);
    while(fread(&b,sizeof(b),1,file))
    {
        if(id==b.id)
        {
            flag=1;
            printf("\n\n\t\t\tBook Borrowed Successsfully!!");
            printf("\n\n\t\t\tBook Name: %s\n\t\t\tAuthor Name: %s\n\t\t\tBook Id: %d\n",b.bookname,b.author,b.id);
        }
    }
    if(!flag)
    {
        printf("\n\n\n\t\t\tBook is not Found");
    }
    fclose(file);

    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        user();
    }
}
//user mode
void Deposit_Books()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                    DEPOSITE BOOK                  ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct book b;
    FILE *file;
    file = fopen("book.txt","a");
    int n,count=0;
    if(file==NULL)
    {
        printf("File is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter How Many Book Do You Want To Add: ");
    scanf("%d",&n);
    while(count<n)
    {
        printf("\n\t\t\tEnter Book Name: ");
        fflush(stdin);
        gets(b.bookname);
        printf("\n\t\t\tEnter Author Name: ");
        fflush(stdin);
        gets(b.author);
        printf("\n\t\t\tEnter ID: ");
        scanf("%d",&b.id);
        fwrite(&b,sizeof(b),1,file);
        count++;

    }
    printf("\n\n\n\t\t\tBook Information Deposited Successfully");;
    fclose(file);
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        user();
    }
}
//user mode main
void user()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              WELCOME TO USER MODE                 ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.Book lists"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Search book"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"3.Borrow Books"};
    printf("\n\t\t\t%s",c);
    char d[100]= {"4.Deposit Books"};
    printf("\n\t\t\t%s",d);
    char e[100]= {"5.Back"};
    printf("\n\t\t\t%s",e);
    char f[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        Book_lists();
        break;
    case 2:
        Search_books();
        break;
    case 3:
        Borrow_Books();
        break;
    case 4:
        Deposit_Books();
        break;
    case 5:
        admin_user();
        break;
    }
}
void admin_pass()
{
    system("cls");

    char userName[100]= {"cgpa1.1"};
    char password[100]= {"211"};
    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                   LOGIN HERE                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\n\n\t\t\tUser Name :");
    scanf("%s",userName);
    printf("\n\t\t\tPassword  :");
    scanf("%s",password);
    if (strcmp(userName,"cgpa1.1") == 0 && strcmp(password,"211")==0)
    {
        system("cls");

        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t############                  LOGIN SUCCESSFUL                 ############");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t###########################################################################");

        printf("\n\n\n\n\t\t\tEnter any key to continue.....");
        getch();
        admin();
    }
    else
    {
        system("cls");

        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t############            WRONG USERNAME OR PASSWORD             ############");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t###########################################################################");

        printf("\n\n\n\t\t\tEnter any Key to Try again...");
        getch();
        admin_pass();

    }
}
void admin_user()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  SELECT HERE                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.ADMIN"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.USER"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",c);
    int choice;
    scanf("%d",&choice);

    if(choice == 1)
    {
        admin_pass();
    }
    else if(choice == 2)
    {
        user_pass();
    }
}
void log()
{

    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                    LOGIN HERE                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    char username[100];
    char password[100];
    struct login b;
    FILE *file;
    file = fopen("login.txt","r");
    printf("\n\n\n\t\t\tEnter User Name: ");
    fflush(stdin);
    gets(username);
    printf("\n\t\t\tEnter Password: ");
    fflush(stdin);
    gets(password);
    while(fread(&b,sizeof(b),1,file))
    {
        if (strcmp(username,b.username) == 0 && strcmp(password,b.password)==0)
        {
            system("cls");

            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t############                  LOGIN SUCCESSFUL                 ############");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t###########################################################################");

            printf("\n\n\n\n\t\t\tEnter any key to continue.....");
            getch();
            user();
        }
        else
        {
            system("cls");

            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t############            WRONG USERNAME OR PASSWORD             ############");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t###########################################################################");

            printf("\n\n\n\t\t\tEnter any key to  Try again...");
            getch();
            log();
        }
    }
    fclose(file);
}
void reg()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              REGISTRTION HERE                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    struct login b;
    FILE *file;
    file = fopen("login.txt","w");
    printf("\n\n\n\t\t\tEnter User Name: ");
    fflush(stdin);
    gets(b.username);
    printf("\n\t\t\tEnter Password: ");
    fflush(stdin);
    gets(b.password);
    fwrite(&b,sizeof(b),1,file);
    fclose(file);

    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############             REGISTRTION SUCCESSFUL                ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\n\n\n\t\t\tEnter any key to go to the Login page.....");
    getch();
    log();
}

void user_pass()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  SELECT HERE                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    char a[100]= {"1.Registration"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Login"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",c);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        reg();
        break;
    case 2:
        log();
        break;
    }

}
int main()
{
    welcome_text();
    admin_user();
    getch();
}

