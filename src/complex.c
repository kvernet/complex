#include "complex.h"

#include <stdlib.h>
#include <math.h>

#ifndef PI
#define PI 3.1415
#endif

static double norm(complex * c);

static double arg(complex * c);

static void add(complex ** c, complex * other);

static void mult(complex ** c, complex * other);

static void cfree(complex ** c);

complex * complex_create(
	double real, double img
) {
	complex * c = (complex*)malloc(sizeof(*c));
	*(double*)(&c->real) = real;
	*(double*)(&c->img) = img;
	
	c->norm = &norm;
	c->arg  = &arg;
	c->add  = &add;
	c->mult = &mult;
	c->free = &cfree;
	
	return c;
}

double norm(complex * c) {
	return sqrt(c->real*c->real + c->img*c->img);
}

double arg(complex * c) {
	if(c->img == 0 && c->real < 0) return 180;
	return 2*atan(c->img / c->real) * 180 / PI;
}

void add(complex ** c, complex * other) {
	complex * tmp = *c;
	*(double*)(&tmp->real) = tmp->real + other->real;
	*(double*)(&tmp->img) = tmp->img + other->img;
}

void mult(complex ** c, complex * other) {
	complex * tmp = *c;
	*(double*)(&tmp->real) = tmp->real*other->real - tmp->img*other->img;
	*(double*)(&tmp->img) = tmp->real*other->img + tmp->img*other->real;
}

void cfree(complex ** c) {
	if(*c == NULL) return;
	free(*c);
	c = NULL;
}
