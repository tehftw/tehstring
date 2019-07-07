#include "tehstring.h"


struct string
string_create (size_t cap)
{
	struct string str = {
		cap ,
		0 ,
		malloc (sizeof(struct string) + cap)
	} ;

	assert(str.ch != 0);

	return str;
}


void
string_free( struct string * s )
{
	assert( s );
	assert( s->ch );
	free( s->ch );
	s->cap = 0;
	s->len = 0;
	s->ch = 0;
}


struct string
string_create_from_cstring (const char *cstring)
{
	size_t cstring_len = strlen( cstring );
	struct string str = string_create( cstring_len );

	strcpy( str.ch, cstring );

	return str;
}




int string_compare (struct string *str1, struct string *str2)
{
	assert( str1 );
	assert( str1->ch );
	assert( str2 );
	assert( str2->ch );
	return strcmp (str1->ch , str2->ch);
}




unicodepoint
string_get_utf8_codepoint( char * s , char ** endptr  )
{

	union unicodepoint_union ucp = { .ucp = 0 };
	unsigned char c = *s;
	size_t len = 0;
	unsigned char chars[6];


	/* handle ASCII : 0xxxxxxx */
	if( ((c) & 0x80) == 0x00 ) {
		ucp.ucp = c;
		++s;
		goto end;
	}


	/* first char */
	if( (c & 0xe0) == 0xc0) { /* nothing worked because I wrote '0xc' instead of '0xc0' grr. */
	/* len=1 : 110x xxxx */
		len = 1;
		chars[0] = (c & 0x1f);
	} else if( (c & 0xf0) == 0xe0) {
	/* len=2 : 1110 xxxx */
		len = 2;
		chars[0] = (c & 0x0f);
	} else if( (c & 0xf8) == 0xf0) {
	/* len=3 : 1111 0xxx */
		len = 3;
		chars[0] = (c & 0x07);
	} else if( (c & 0xfc) == 0xf8) {
	/* len=4 : 1111 10xx */
		len = 4;
		chars[0] = (c & 0x03);
	} else if( (c & 0xfe) == 0xfc) {
	/* len=5 : 1111 110x */
		len = 5;
		chars[0] = (c & 0x01);
	}
	assert(len);


	/* parse continuation bytes: */
	for( size_t i = 1; i <= len; ++i) {
		++s;
		c = *s;
		/* ensure is a valid next UTF8 byte: b10xxxxxx */
		assert( ((c) & 0xc0)  == 0x80 );
		chars[i] = (c & 0x3f);
	}


	/* build codepoint from bytes */
//	printf( "decoded as %hhx %hhx %hhx %hhx %hhx %hhx\n"
//			,chars[0]
//			,chars[1]
//			,chars[2]
//			,chars[3]
//			,chars[4]
//			,chars[5] );


	size_t advance = 0;
	for( size_t i = 0; i <= len; ++i ) {
		ucp.ucp += ( chars[len-i] << advance );
		advance += 6;
	}
//	if( len == 1 ) {
//		ucp.ucp += ( chars[1]  );
//		ucp.ucp += ( chars[0] << 6  );
//	}
//
//	if( len == 2 ) {
//		ucp.ucp += ( chars[2]    );
//		ucp.ucp += ( chars[1] << 6  );
//		ucp.ucp += ( chars[0] << 12  );
//	}
//
//	if( len == 3 ) {
//		ucp.ucp += ( chars[3]  );
//		ucp.ucp += ( chars[2] << 6  );
//		ucp.ucp += ( chars[1] << 12  );
//		ucp.ucp += ( chars[0] << 18  );
//	}

end:
	if( endptr ) {
		*endptr = s;
	}
	return ucp.ucp;
}




