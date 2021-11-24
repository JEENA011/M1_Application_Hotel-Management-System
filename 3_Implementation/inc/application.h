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

/* Included to allow users to call functions from math library if required */


/* strcture definition must be reused by the users in their code */



struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

void add();
void list();
void edit();
void delete1();
void search();

#endif //#ifndef APPLICATION_H
