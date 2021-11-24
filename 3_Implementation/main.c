#include"application.h"

//main method
int main(){ 

    int a,b,c;

     //Welcome screen

 	printf("\n\n\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*              WELCOME TO HOTEL              *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");

    printf("\n>>>>>>>>>>>>\tFor ADMIN access enter --> 1 \t\t\t<<<<<<<<<<<<");
    printf("\n>>>>>>>>>>>>\tFor USER access enter --> 2 \t\t\t<<<<<<<<<<<<");
    printf("\n>> ");
     scanf("%d",&a);

        switch(a){
            case 1:{
                char pass[10];
                char filepass[10];
                int i;

                FILE *passw;
                passw = fopen("pass.txt","r");

                //admins password prompt
                printf("\n Hello admin!\n Please enter the password to continue --> ");

                for(i=0; i<6; i++){
                    scanf("%9s",pass);
                    fscanf(passw,"%9s",filepass);
                    if (strcmp(filepass,pass) == 0) {
                        printf("\n\nAccess granted!\n");
                        fclose(passw);
                        break;
                    }
                    else{
                     printf("\nIncorrect password, please try again.");
                     printf("\nYou have %d trys left ",5-i-1);
                     printf("\n\nEnter password >> ");
                    }
                    if(i==4){
                        fclose(passw);
                        return 0;
                    }

               
                }

                 //re-entry if
                while(admin_entry[0] =='y'){

                printf("\n>>>>>>>>>>>>\tTo VIEW booking requests --> 1 \t\t\t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\tTo VIEW booked guests details --> 2 \t\t\t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\tTo ENTER new guest --> 3 \t\t\t<<<<<<<<<<<<");
   	            printf("\n>>>>>>>>>>>>\tTo FIND room number of existing guest --> 4 \t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\tTo FIND guest of occupied room --> 5 \t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\tTo CHECKOUT room number of existing guest --> 6 <<<<<<<<<<<<\n");
                printf(">> ");
                scanf("%d",&b);

                switch(b){
                    case 1:{
                        view_bookings();
                        break;
                    }
                    case 2:{
                        FILE* fpi;
                        fpi = fopen("hotelnew.txt","r");	

                        while(fscanf(fpi,"%9s %9s %9s",h.name,h.room,h.wifi) != -1){	
                          fgets(h.bf, 255, (FILE*)fpi);
                          printf("%s %s %s %s \n",h.name,h.room,h.wifi,h.bf);
                         }
                         break;
                    }
                    case 3:{
                        enter_name();
                        break;
                    }
                    case 4:{
                        find_name();
                        break;
                    }
                    case 5:{
                        find_room();
                        break;
                    }
                case 6:{
                    checkout_guest();
                    break;
                    }
                    default:{
                        printf("\n Wrong entry!");
                    }
                }
                //enter again?
                printf("Would you like to continue? (y/n)\n");
                scanf("%9s",admin_entry);

                }
                if(strcmp(admin_entry,"n") == 0){
                    printf("Exiting...\n");
                    printf("\e[1;1H\e[2J");
                    printf("\n >Exited<\n\n");
                    //system("clear");
                    return 0;
                }
                else{
                    printf("Wrong entry!\nExiting...\n");
                    return 0;
                }
                break;
            }
            
                     
            case 2:{
                while(user_entry[0] =='y'){
                printf("\nHello user and welcome to Hotel!");
                printf("\n>>>>>>>>>>>>\tTo view available rooms --> 1 \t\t\t<<<<<<<<<<<<");
   	            printf("\n>>>>>>>>>>>>\tTo request booking of room --> 2 \t<<<<<<<<<<<<");
                printf("\n>> ");
                scanf("%d",&c);
                switch(c){
                    case 1:{
                        FILE* view;
                        view = fopen("rooms.txt","r");
                        printf("Available rooms are:\n");
                        while(fscanf(view,"%9s",h.room) != -1){	
                        printf("%s \n",h.room);
                        }
                        fclose(view);
                        break;
                    }

                    case 2:{
                        printf("Enter your name: ");
                        scanf("%9s",h.name);
                        printf("Enter room to book: ");
                        scanf("%9s",h.room);
                        printf("Enter WiFI plan (1GB/5GB): ");
                        scanf("%9s",h.wifi);
                        printf("Enter if bf (yes/no): ");
                        scanf("%9s",h.bf);

                        enter = fopen("bookings.txt","a");

                        fprintf(enter,"%s %s %s %s",h.name,h.room,h.wifi,h.bf);
                        fprintf(enter,"\n");

                        printf("Succesfully requested booking\n");
                        fclose(enter);

                    }
                }
                    
                printf("Would you like to continue? (y/n)\n");
                scanf("%9s",user_entry);

                }
                if(strcmp(user_entry,"n") == 0){
                    printf("Exiting...\n");
                    printf("\e[1;1H\e[2J");
                    printf("\n >Exited<\n\n");
                    //system("clear");
                    return 0;
                }
                else{
                    printf("Wrong entry!\nExiting...\n");
                    return 0;
                }
                break;
            }
        }
}
