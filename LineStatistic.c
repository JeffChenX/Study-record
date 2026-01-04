#include <stdio.h>
int count_file_line(const char* path) {
	FILE* test = NULL;
	if ((test = fopen(path, "r")) == NULL) {
		printf("%s 打开失败\n", path);
		return -1;
	}
	int c = 0, cnt = 0;
	while ((c = fgetc(test)) != EOF) {
		if (c == '\n')
			cnt++;
	}
	cnt++;
	fclose(test);
	return cnt;
}
int main(void) {
	const char* p = "test.txt";
	FILE* wFile = fopen(p, "w");
	fprintf(wFile, "Print error message\n\
Interprets the value of errno as an error message, and prints it to stderr(the standard error output stream, usually the console), optionally preceding it with the custom message specified in str.\n\n\
errno is an integral variable whose value describes the error condition or diagnostic information produced by a call to a library function(any function of the C standard library may set a value for errno, even if not explicitly specified in this reference, and even if no error happened), see errno for more info.\n\n\
The error message produced by perror is platform - depend.\n\n\
If the parameter str is not a null pointer, str is printed followed by a colon(:) and a space.Then, whether str was a null pointer or not, the generated error description is printed followed by a newline character('\\n').\n\n\
perror should be called right after the error was produced, otherwise it can be overwritten by calls to other functions.\n");
	fclose(wFile);
	int ans = count_file_line(p);
	if (ans < 0)
		printf("%s 打开失败\n", p);
	else
		printf("%s 共 %d 行文本\n", p, ans);
	return 0;
}