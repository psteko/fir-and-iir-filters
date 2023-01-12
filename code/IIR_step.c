#include<stdio.h>
double y_impulse[512] = { 0 };
double y_step[512] = { 0 };
double temp[552] = { 0 };


void calculateStepResponse(double* y, double* temp)
{
	int n;
	for (n = 0; n < 552; n++)
	{
		if ((n >= 3) && (n < 5))
			temp[n + 8] = -0.41 * temp[n + 6] + 0.0604 * temp[n + 4] - 0.066 * temp[n + 2] - 0.0067 * temp[n] + 1;
		else if ((n >= 5) && (n < 7))
			temp[n + 8] = -0.41 * temp[n + 6] + 0.0604 * temp[n + 4] - 0.066 * temp[n + 2] - 0.0067 * temp[n] - 1.25 + 1;
		else if (n == 7)
			temp[n + 8] = -0.41 * temp[n + 6] + 0.0604 * temp[n + 4] - 0.066 * temp[n + 2] - 0.0067 * temp[n]+ 1 - 1.25 + 0.25;
		else
			temp[n + 8] = -0.41 * temp[n + 6] + 0.0604 * temp[n + 4] - 0.066 * temp[n + 2] - 0.0067 * temp[n] + 1 - 1.25 + 0.25;

		y[n] = temp[n + 8];
	}
}

void printArray(double* array, int size) {
	int i;
	for (i = 3; i < size; i++)
		printf("%0.15f, ", array[i]);
}

int main(void)
{

	calculateStepResponse(y_step, temp);
	printf("Odziv na step IIR filtra: \n");
	printArray(y_step, 512);

	return 0;
}