#include <stdio.h>

char* my_strcpy(char* destination, const char* source) {
	if (!destination || !source) 
		return NULL;
	char* ret = destination;

	/*int i;
	for (i = 0; source[i]; i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';*/
	
	while ( (*destination++ = *source++) != '\0');
	return ret;
}
int main(void) {
	char d[500], s[500];
	scanf("%s%s", d, s);
	my_strcpy(d, s);
	printf("%s\n%s\n", d, s);
	return 0;
}