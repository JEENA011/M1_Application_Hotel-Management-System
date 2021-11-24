/**
 * @file application.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef APPLICATION_H
#define APPLICATION_H


//structure defined to store name, room, bf and wifi required
struct hotel
{
    char name[20];
    char room[20];
    char bf[20];
    char wifi[20];

}h;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Method Declaration

void enter_name();
void find_name();
void find_room();
void checkout_guest();
void view_bookings();

//Instance Field Declaration
FILE* view;
FILE *fp;
FILE* enter;
char admin_entry[20] = {'y'};
char user_entry[20] = {'y'};


#endif //#ifndef APPLICATION_H
