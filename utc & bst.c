#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t seconds;
	time(&seconds);
	printf("自 UTC 1970-01-01 00:00:00 起，到现在经过了 %lld 秒\n", (long long)seconds);
	struct tm* p_tm = gmtime(&seconds);
	int year = 1900 + p_tm->tm_year;
	int month = 1 + p_tm->tm_mon;
	int day = p_tm->tm_mday;
	int hour = p_tm->tm_hour;
	int minute = p_tm->tm_min;
	int second = p_tm->tm_sec;
	printf("世界统一时间是 %d年%02d月%02d日 %02d:%02d:%02d\n", year, month, day, hour, minute, second);
	
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year%4==0 && year%100 || year%400==0) days[1] = 29;
	if (hour + 8 >= 24) {
		day++;
		if (day > days[month-1]) {
			month++, day=1;
			if (month > 12) {
				month = 1;
				year++;
			}
		}
	}
	hour = (hour+8)%24;	
	printf("北京时间是 %d年%02d月%02d日 %02d:%02d:%02d", year, month, day, hour, minute, second);
	return 0;
}
