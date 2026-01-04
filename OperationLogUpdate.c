#include <stdio.h>
#include <time.h>

int main(void) {
	// # 2026-01-01 12:02:23 # 1th run of the program #
	
	FILE* op_log = NULL;
	if ((op_log = fopen("op_log.txt", "a+")) == NULL)
		printf("运行日志：%s 打开失败\n");
	else
		printf("运行日志：op_log.txt 打开成功\n");

	int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;
	int times = 0;
	int ret = 0;
	while ((ret = fscanf(op_log, "# %d-%d-%d %d:%d:%d # %dth run of the program #\n",
		&year, &month, &day, &hour, &min, &sec, &times)) > 0) {
		printf("成功读取到 %10d 个字段：%d-%02d-%02d %02d:%02d:%02d, times: %d\n", ret, year, month, day, hour, min, sec, times);
	}

	time_t seconds;
	time(&seconds);
	struct tm* rt = localtime(&seconds);
	ret = fprintf(op_log, "# %d-%02d-%02d %02d:%02d:%02d # %10dth run of the program #\n",
		1900+rt->tm_year, 1+rt->tm_mon, rt->tm_mday, rt->tm_hour, rt->tm_min, rt->tm_sec, ++times);
	
	if (ret > 0)
		printf("成功写入 %d 个字节\n", ret);
	else
		printf("写入失败\n");

	if (fclose(op_log) == EOF)
		printf("op_log.txt 关闭失败\n");
	return 0;
}