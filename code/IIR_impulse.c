#include<stdio.h>
double y_impulse[512] = { 0 };
double y_step[512] = { 0 };
double temp[552] = { 0 };


void calculateImpulseResponse(double* y, double* temp)
{

	int n;
	for (n = 0; n < 552; n++)
	{
		if (n == 3)
			temp[n + 8] = -0.41 * temp[n + 6] +0.0604 * temp[n + 4] - 0.066 * temp[n + 2]  - 0.0067 * temp[n] + 1;
		else if (n == 5)
			temp[n + 8] = -0.41 * temp[n + 6] + 0.0604 * temp[n + 4] - 0.066 * temp[n + 2] - 0.0067 * temp[n] - 1.25 * 1;
		else if (n == 7)
			temp[n + 8] = -0.41 * temp[n + 6] + 0.0604 * temp[n + 4] - 0.066 * temp[n + 2] - 0.0067 * temp[n] + 0.25 * 1;
		else
			temp[n + 8] = -0.41 * temp[n + 6] + 0.0604 * temp[n + 4] - 0.066 * temp[n + 2] - 0.0067 * temp[n];
		
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
	calculateImpulseResponse(y_impulse, temp);
	printf("Impulsni odziv IIR filtra: \n");
	printArray(y_impulse, 512);

	return 0;
}