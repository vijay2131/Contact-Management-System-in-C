/*  ****** MINI PROJECT ON CONTACT MANAGEMENT SYSTEM ****** */

#include <stdio.h>                               // 150 178

#include <string.h>               

#include <stdlib.h>


struct contact

{

    long ph;

    char name[20], add[20];

} list;

char query[20], nm[20];

FILE *fp, *ft;

int i,vij,j,n,l,found;
char ch;

int main()

{


main:
    system("clear");
    //system("clrscr");
    /* ************Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice: ");

    scanf("%c", &ch);

    switch(ch)

    {

    case '0':

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* *********************Add new contacts************  */

    case '1':

        system("clear");

        fp=fopen("contact.txt","a+");

        for (;;)

        {
            getchar();

            printf("To exit, enter * symbol in the name input\n");
            printf("Enter Name : ");
            
            scanf("%[^\n]s", list.name);
            
            //fprintf(fp,"%s",list.name);
            if (strcmp(list.name,"*")==0)
                break;

            printf("Phone: ");

            scanf("%ld",&list.ph);

            //fprintf(fp,"%ld", list.ph);
            getchar();
            printf("Address: ");

           scanf("%[^\n]s", list.add);

            
            //fflush(stdin);

            //printf("email address:");

            //gets(list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);
            
      // fprintf(fp,"%s\n" "%ld\n" "%s\n",list.name,list.ph,list.add);
            
        }

        fclose(fp);

        break;

        /* *********************list of contacts*************************  */

    case '2':

           system("clear");

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.txt","a+");

            fflush(stdin); 

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\n", list.name, list.ph, list.add);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
        //        scanf("%c",&ch);
        //      getchar();
            }

            fclose(fp);

        }

        break;

        /* *******************search contacts**********************  */

    case '3':

           system("clear");

        do

        {

            found=0;
            getchar();
            
            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

            scanf("%[^\n]s", query);
            
            fp=fopen("contact.txt","a+");
        //    fprintf(fp,"%s", query);

            l=strlen(query);



               system("clear");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<l; i++)

                    nm[i]=list.name[i];

                nm[l]='\0';

                if(strcmp(nm,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n",list.name,list.ph,list.add);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");
                        scanf("%c",&ch);
                        getchar();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf(" %c",&ch);

        }
        while(ch=='1');

        break;

        /* *********************edit contacts************************/

    case '4':

        system("clear");

        getchar();
        fp=fopen("contact.txt","a+");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
        
        scanf("%[^\n]s",nm);
        
        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(strcmp(nm,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",nm);

        printf("..::Name(Use identical):");
        getchar();

        scanf("%[^\n]s", list.name);

        fflush(stdin);

        printf("..::Phone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::address:");
        getchar();

        scanf("%[^\n]s", list.add);

        fflush(stdin);

       //printf("..::email address:");

        //gets(list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.dat","contact.txt");

        break;

        /* ********************delete contacts**********************/

    case '5':

        system("clear");

        fflush(stdin);
        int kk=0;
        getchar();
        
        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%[^\n]s", nm);

        fp=fopen("contact.txt","a+");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)
        {
            if (strcmp(nm,list.name)!=0)
            {
                fwrite(&list,sizeof(list),1,ft);
            }
        
            else
            kk=1;
        }
        if(kk!=1)
        printf("Contact not found");
        
        else
        printf("Contact deleted");
        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.dat","contact.txt");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&vij);
    getchar();
    switch (vij)

    {

    case 1:

        main();

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}
