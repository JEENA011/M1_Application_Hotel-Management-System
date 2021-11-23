/**
 * @file header.h
 * @author Manish Jeena
 * @brief 
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef HEADER_H
#define HEADER_H

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

#include"header.h"

// FUNCTION PROTOTYPE

void add(); 
void list();
void edit();  
void delete1();
void search();
void setcolor(int);
void login();
#endif //#ifndef HEADER_H
