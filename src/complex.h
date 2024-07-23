#ifndef complex_h
#define complex_h

#ifdef __cplusplus
extern "C" {
#endif

typedef struct complex complex;

struct complex {
	const double real;
	const double img;
	
	double (*norm)(complex * self);
	double (*arg)(complex * self);
	void (*add)(complex ** self, complex * other);
	void (*mult)(complex ** self, complex * other);
	void (*free)(complex ** self);
};

complex * complex_create(
	double real, double img
);

#ifdef __cplusplus
}
#endif

#endif
