#include "complex.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	complex * z1 = complex_create(1, 2);
	complex * z2 = complex_create(sqrt(3), 1);
	
	printf("z = %.2f + i%.2f = [%.2f, %.2f]\n",
		z1->real, z1->img, z1->norm(z1), z1->arg(z1));
	
	printf("z = %.2f + i%.2f = [%.2f, %.2f]\n",
		z2->real, z2->img, z2->norm(z2), z2->arg(z2));
	
	z1->add(&z1, z2);
	printf("z = %.2f + i%.2f = [%.2f, %.2f]\n",
		z1->real, z1->img, z1->norm(z1), z1->arg(z1));
	
	z2->mult(&z2, z1);
	printf("z = %.2f + i%.2f = [%.2f, %.2f]\n",
		z2->real, z2->img, z2->norm(z2), z2->arg(z2));
	
	// free allocated memory
	z1->free(&z1);
	z2->free(&z2);
	
	return EXIT_SUCCESS;
}
