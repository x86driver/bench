#include <stdio.h>
#include <time.h>

static const unsigned long COUNT = 1000000000;

int main()
{
	clock_t start, end;
	unsigned long number = 0;
	double cpu_time;

	start = clock();
	__asm__ volatile("movq %0, %%r8\n\t"
			"movq %1, %%rcx\n\t"
			".1:\n\t"
			"incq %%r8\n\t"
			"loop .1\n\t"
			"movq %%r8, %0\n\t"
			::"r"(number), "g"(COUNT));
	end = clock();

	cpu_time = (double)((double)(end - start) / CLOCKS_PER_SEC * 1.0);
	printf("number: %lu\n", number);
	printf("time: %f\n", cpu_time);
	return 0;
}
