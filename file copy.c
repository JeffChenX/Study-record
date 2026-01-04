#include <stdio.h>

int file_copy(const char* d_file, const char* s_file) {
	FILE *d = NULL, *s = NULL;
	if ((s = fopen(s_file, "r")) == NULL) {
		printf("\"%s\" 源文件打开失败\n", s_file);
		return -1;
	}
	if ((d = fopen(d_file, "w")) == NULL) {
		printf("\"%s\" 目的地文件打开失败\n", d_file);
		fclose(s);
		return -1;
	}
	int c;
	while ((c = fgetc(s)) != EOF) fputc(c, d);
	fclose(s);
	fclose(d);
	return 0;
}

int main(void) {
	FILE* s = fopen("source.txt", "w");
	FILE* d = fopen("destination.txt", "w");

	fprintf(s, "Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point)."
					"\n\nTo avoid overflows, the size of the array pointed by destination shall be long enough to contain the same C string as source(including the terminating null character), and should not overlap in memory with source.");
	fprintf(d, "恭喜大家完成了第一部分语言入门，相信大家已经可以使用 C++ 写出一些简单程序了。"
					"\n\n各位读者有听说过“建模”一词吗？所谓“建模”，就是把事物进行抽象，根据实际问题来建立对应的数学模型。“抽象”并不意味着晦涩难懂；相反，它提供了大量的便利。计算机很难直接去解决实际问题，但是如果把实际问题建模成数学问题，就会大大地方便计算机来“理解”和“解决”。"
					"\n\n举个生活中常见的例子：我们拿到了某次数学考试的成绩单，现在需要知道谁考得最好。当然不能把成绩单对着电脑晃一晃，然后问“谁考得最好？”。需要通过一种途径让计算机来理解这个问题。这个问题可以建模成：“给定数组 score[]，问数组内元素的最大值”。这样建模后，就能很方便的写程序解决问题了。对于这个问题，采用之前讨论过的“擂台法”，就可以给出答案。"
					"\n\n如何把实际问题建模成数学问题，主要依靠我们的经验和直觉、当然还有你灵动的思维；而算法与数据结构，正是解决数学问题的两把利剑。从这一章开始会介绍一些程序设计竞赛中的一些常见套路算法，而下一部分会介绍基础的数据结构。如果已经认真学习完了第一部分，相信这一部分也不在话下。"
					"\n\n这一章是语言部分的延伸，会介绍一些竞赛中会出现的“模拟题目”——这里的“模拟”不是指模拟某场比赛的模拟题，而是指让程序完整的按照题目叙述的方式执行运行得到最终答案。同时也会介绍可以计算很大整数的高精度运算方法。这一章对思维与算法设计的要求不高，但是会考验编程的基本功是否扎实。");
	fclose(s);
	fclose(d);
	if (file_copy("destination.txt", "source.txt") == 0)
		printf("文件拷贝成功\n");
	else
		printf("文件拷贝失败\n");

	return 0;
}