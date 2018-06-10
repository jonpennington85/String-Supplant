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
	char temp[strlen(string)];
	// Move the pointer to the beginning of toReplace
	while((spplntPtr=strstr(spplntPtr,toReplace))!=NULL){
		// Move the copy pointer to right after the substring we're going to replace
		cpPtr=spplntPtr+strlen(toReplace);
		// Copy cpPtr to temp
		strcpy(temp,cpPtr);
		// Add a null to the beginning of spplntPtr
		*spplntPtr='\0';
		// Concatenate replaceWith to spplntPtr
		strcat(spplntPtr,replaceWith);
		spplntPtr+=strlen(replaceWith);
		// Concatenate rest of string afterwards
		strcat(spplntPtr,temp);
	}
	return string;
}

char * strnspplnt(char * string,char * toReplace,char * replaceWith,size_t maxlen){
	char temp[strnlen(string,maxlen)+1];
	char temp2[strnlen(string,maxlen)+1];
	char * spplntPtr=temp2;
	char * cpPtr=temp2;
	memset(temp,0,strnlen(string,maxlen)+1);
	memset(temp2,0,strnlen(string,maxlen)+1);
	strncpy(temp2,string,maxlen);
	// Move the pointer to the beginning of toReplace
	while((spplntPtr=strstr(spplntPtr,toReplace))!=NULL){
		// Move the copy pointer to right after the substring we're going to replace
		cpPtr=spplntPtr+strnlen(toReplace,maxlen);
		// Copy cpPtr to temp
		strncpy(temp,cpPtr,maxlen);
		// Add a null to the beginning of spplntPtr
		*spplntPtr='\0';
		// Concatenate replaceWith to spplntPtr
		strncat(spplntPtr,replaceWith,maxlen-strnlen(temp2,maxlen));
		spplntPtr+=strnlen(replaceWith,maxlen);
		// Concatenate rest of string afterwards
		strncat(spplntPtr,temp,maxlen-strnlen(temp2,maxlen));
	}
	memset(string,0,strlen(string));
	strncpy(string,temp2,maxlen);
	return string;
}
