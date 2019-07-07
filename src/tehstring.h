#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>


/* Variadic macros are so fuken weird xD

	`print(format, ...)` is good, but:
	`print (format, ...)` does not work. It's due to this fucking extra space before '(' xDDD wtf ???!?!??!?!?!

	And don't forget to use `##__VA_ARGS__` - this ensures that the comma ',' will be eaten if not needed.
*/


#define printwarning(format, ...) fprintf (stderr, "error: " format , ##__VA_ARGS__);
#define printerror(format, ...)   fprintf (stderr, "error: " format , ##__VA_ARGS__);


struct string {
	size_t cap;
	size_t len;
	char * ch;
};


typedef
	uint32_t
	unicodepoint;

union unicodepoint_union{
	unicodepoint ucp ;
	char ch[4] ;
};



struct string
string_create(
		size_t cap
		);

void
string_free(
		struct string * s
		);

struct string
string_create_from_cstring(
		const char *cstring 
		);




int
string_compare(
/* Simple wrapper over <string.h> C function `strcmp(char *s1, char *s2)`  */
	 struct string *str1
	,struct string *str2
	);






unicodepoint
string_get_utf8_codepoint( char *s , char ** ptr );
