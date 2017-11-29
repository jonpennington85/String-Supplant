/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                               *
 * Author: Jonathan Pennington                                   *
 *                                                               *
 * A simple method that supplants a substring with               *
 * another substring, which the string library lacks             *
 *                                                               *
 * Also includes a method that ensures string is not larger than *
 * a given size                                                  *
 *                                                               *
 * Implemented in C                                              *
 *                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define _GNU_SOURCE // Required for strnlen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strspplnt(char * string,char * toReplace,char * replaceWith){
	char * spplntPtr=string;
	char * cpPtr=string;
	char * temp=malloc(strlen(string));
	// Locate the pointer to the beginning of toReplace
	while((spplntPtr=strstr(spplntPtr,toReplace))!=NULL){
		// Move the copy pointer to right after what you want to replace
		cpPtr=spplntPtr+strlen(toReplace);
		// Copy cpPtr to temp
		strcpy(temp,cpPtr);
		// Add a null to the beginning of cpPtr
		*spplntPtr='\0';
		// Add replaceWith tospplntPtr
		strcat(spplntPtr,replaceWith);
		spplntPtr+=strlen(replaceWith);
		// Add rest of string afterwards
		strcat(spplntPtr,temp);
	}
	free(temp);
	return string;
}

char * strnspplnt(char * string,char * toReplace,char * replaceWith,size_t maxlen){
	char * temp=malloc(strnlen(string,maxlen)+1);
	char * temp2=malloc(strnlen(string,maxlen)+1);
	char * spplntPtr=temp2;
	char * cpPtr=temp2;
	memset(temp,0,strnlen(string,maxlen)+1);
	memset(temp2,0,strnlen(string,maxlen)+1);
	strncpy(temp2,string,maxlen);
	// Locate the pointer to the beginning of toReplace
	while((spplntPtr=strstr(spplntPtr,toReplace))!=NULL){
		// Move the copy pointer to right after what you want to replace
		cpPtr=spplntPtr+strnlen(toReplace,maxlen);
		// Copy cpPtr to temp
		strncpy(temp,cpPtr,maxlen);
		// Add a null to the beginning of cpPtr
		*spplntPtr='\0';
		// Add replaceWith tospplntPtr
		strncat(spplntPtr,replaceWith,maxlen-strnlen(temp2,maxlen));
		spplntPtr+=strnlen(replaceWith,maxlen);
		// Add rest of string afterwards
		strncat(spplntPtr,temp,maxlen-strnlen(temp2,maxlen));
	}
	memset(string,0,strlen(string));
	strncpy(string,temp2,maxlen);
	free(temp);
	free(temp2);
	return string;
}
