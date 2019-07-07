#include "tehstring.h"

void
print_emoji_with_unicode( char * s )
{
	printf( "%s " ,s );
	char * p;
	union unicodepoint_union u = { 
		.ucp = string_get_utf8_codepoint( s , &p ) };

	printf( "U+%x\n" , u.ucp );

	printf( "%hhx %hhx %hhx %hhx\n\n"
			, s[0]
			, s[1]
			, s[2]
			, s[3]
	      );
}

char c0[6] = "🌒"; // U+1F312	\xF0\x9F\x8C\x92	WAXING CRESCENT MOON SYMBOL
char c1[6] = "😠"; // U+1F620	\xF0\x9F\x98\xA0	ANGRY FACE
char c2[6] = "😴"; // U+1F634	\xF0\x9F\x98\xB4	SLEEPING FACE

char greek_0[6] = "α" ; // 03b1
char greek_1[6] = "A" ; // 0391
char greek_2[6] = "β" ; // 03b2
char greek_3[6] = "B" ; // 0392
char greek_4[6] = "γ" ; // 03b3
char greek_5[6] = "Γ" ; // 0393
char greek_6[6] = "δ" ; // 03b4
char greek_7[6] = "Δ" ; // 0394
char greek_8[6] = "ϵ" ; // 03b5
char greek_9[6] = "E" ; // 0395
char greek_10[6] = "ζ" ; // 03b6
char greek_11[6] = "Z" ; // 0396
char greek_12[6] = "η" ; // 03b7
char greek_13[6] = "H" ; // 0397
char greek_14[6] = "θ" ; // 03b8
char greek_15[6] = "Θ" ; // 0398
char greek_16[6] = "ι" ; // 03b9
char greek_17[6] = "I" ; // 0399
char greek_18[6] = "κ" ; // 03ba
char greek_19[6] = "K" ; // 039a
char greek_20[6] = "λ" ; // 03bb
char greek_21[6] = "Λ" ; // 039b
char greek_22[6] = "μ" ; // 03bc
char greek_23[6] = "M" ; // 039c
char greek_24[6] = "ν" ; // 03bd
char greek_25[6] = "N" ; // 039d
char greek_26[6] = "ξ" ; // 03be
char greek_27[6] = "Ξ" ; // 039e
char greek_28[6] = "o" ; // 03bf
char greek_29[6] = "O" ; // 039f
char greek_30[6] = "π" ; // 03c0
char greek_31[6] = "Π" ; // 03a0
char greek_32[6] = "ρ" ; // 03c1
char greek_33[6] = "P" ; // 03a1
char greek_34[6] = "σ" ; // 03c3
char greek_35[6] = "Σ" ; // 03a3
char greek_36[6] = "τ" ; // 03c4
char greek_37[6] = "T" ; // 03a4
char greek_38[6] = "υ" ; // 03c5
char greek_39[6] = "ϒ" ; // 03a5
char greek_40[6] = "ϕ" ; // 03c6
char greek_41[6] = "Φ" ; // 03a6
char greek_42[6] = "χ" ; // 03c7
char greek_43[6] = "X" ; // 03a7
char greek_44[6] = "ψ" ; // 03c8
char greek_45[6] = "Ψ" ; // 03a8
char greek_46[6] = "ω" ; // 03c9
char greek_47[6] = "Ω" ; // 03a9


int main ()
{

/*
😠
U+1F620
\xF0\x9F\x98\xA0 
ANGRY FACE
*/




	print_emoji_with_unicode( c0 );
	print_emoji_with_unicode( c1 );
	print_emoji_with_unicode( c2 );

	print_emoji_with_unicode( greek_2 );
	print_emoji_with_unicode( "a\0\0\0\0" );




	return EXIT_SUCCESS;
}



