#include"application.h"

//method declare to enter name
void enter_name(){ 

    FILE *tmp1; 
    FILE *tmp2;

    printf("\nEnter guest name --> ");
    scanf("%9s",h.name);
    printf("\nEnter their room number --> ");
    scanf("%9s",h.room);
    printf("\n Enter wifi plan (1GB/5GB) --> ");
    scanf("%9s",h.wifi);
    printf("\nEnter if breakfast is included --> ");
    scanf("%9s",h.bf);
    
    //entering guests
    fp = fopen("hotelnew.txt","a");

    if( fp == NULL){
        printf("\nFile not found");
        exit(1);
    }
    else{
        fprintf(fp,"%s %s %s %s",h.name,h.room,h.wifi,h.bf);
        printf("\nDone\n");
    }
    fprintf(fp,"\n");

    //
    char remove_guest[20];
    strcpy(remove_guest,h.name);
    char remove_room[20];
    strcpy(remove_room,h.room);

    //removing booking
    tmp1 = fopen("tmp1.txt","a");
    enter = fopen("bookings.txt","r");
 
    while(fscanf(enter,"%9s %9s %9s",h.name,h.room,h.wifi) != -1){
            fgetc(enter);	
		    fgets(h.bf, 20, (FILE*)enter);
			    if(strcmp(h.name,remove_guest) != 0){
                    fprintf(tmp1,"%s %s %s %s",h.name,h.room,h.wifi,h.bf);
                }
        }
    fclose(enter);
    fclose(tmp1);
    remove("bookings.txt");
    rename("tmp1.txt","bookings.txt");
    fclose(fp);

    //removing room
    tmp2 = fopen("tmp2.txt","a");
    view = fopen("rooms.txt","r");

    
    while(fscanf(view,"%9s",h.room) != -1){
			    if(strcmp(h.room,remove_room) != 0){
                    fprintf(tmp2,"%s",h.room);
                    fprintf(tmp2,"\n");
                }
        }
    fclose(view);
    fclose(tmp2);
    remove("rooms.txt");
    rename("tmp2.txt","rooms.txt");


    fclose(fp);
}

//method defined to find quest name
void find_name(){
    char buffer[20];
    char entered_name[20];
    int guestFound =0;

    printf("\nEnter guest name to find -->");
    scanf("%9s",entered_name);   
  
    fp = fopen("hotelnew.txt","r");	
    while(fscanf(fp,"%9s %9s %9s",h.name,h.room,h.wifi) != -1){	
    fgets(h.bf, 255, (FILE*)fp);
    if(strcmp(h.name,entered_name) == 0){
                     guestFound = 1;
                    printf("\n Guest found!");
                    printf("\n Name  is %s",h.name);
                    printf("\n Room number is %s",h.room);
                    printf("\n WiFi plan is %s",h.wifi);
                    printf("\n Breakfast included %s",h.bf);

      }
   }
   if(guestFound == 0){
         printf("\nGuest %s not found!\n", entered_name);
      }
   fclose(fp);
}

//method definition for guest checkout
void checkout_guest(){
    char buffer2[20];
    char checkout_name[20];
    char add_room[20];

    FILE *tmp;

    printf("Enter guest too checkout ");
    scanf("%9s",checkout_name);

    fp = fopen("hotelnew.txt","r");
    tmp = fopen("tmp.txt","w");

    if(fp == NULL){
    printf("File not found");
    exit(1);
    }
	else{
        while(fscanf(fp,"%9s %9s %9s",h.name,h.room,h.wifi) != -1){
            fgetc(fp);	
		    fgets(h.bf, 20, (FILE*)fp);
			    if(strcmp(h.name,checkout_name) != 0){
                    fprintf(tmp,"%s %s %s %s",h.name,h.room,h.wifi,h.bf);
                }
                else{
                   strcpy(add_room,h.room);
                }
        }
        printf("Room checked out!");
    }

    fclose(fp);
    fclose(tmp);
    remove("hotelnew.txt");
    rename("tmp.txt","hotelnew.txt");

    //enter room back into available rooms list
    view = fopen("rooms.txt","a");
    printf(" add is %s",add_room);
    fprintf(view,"%s",add_room);
    fclose(view);

}

//method definition for finding rooms avalaible
void find_room(){
    char buffer[20];
    char entered_room[20];
    int roomFound =0;
    FILE *fp;
    printf("\nEnter room number to find -->");
    scanf("%9s",entered_room);   
  
    fp = fopen("hotelnew.txt","r");	
    while(fscanf(fp,"%s %s %s",h.name,h.room,h.wifi) != -1){	
    fgets(h.bf, 255, (FILE*)fp);
    if(strcmp(h.room,entered_room) == 0){
                     roomFound = 1;
                    printf("\n Room found!");
                    printf("\n Name  is %s",h.name);
                    printf("\n Room number is %s",h.room);
                    printf("WiFi plan is %s",h.wifi);
                    printf("\n Breakfast included %s",h.bf);
      }
    }
    if(roomFound == 0){
         printf("\nRoom %s not found!\n", entered_room);
      }
   fclose(fp);
}

//method defined to view bookings
void view_bookings(){

    enter = fopen("bookings.txt","r");	

    while(fscanf(enter,"%s %s %s",h.name,h.room,h.wifi) != -1){	
        fgets(h.bf, 255, (FILE*)enter);
        printf("%s %s %s %s \n",h.name,h.room,h.wifi,h.bf);
    }
}
