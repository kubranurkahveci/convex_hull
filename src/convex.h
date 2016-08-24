
#ifndef CONVEX_H_
#define CONVEX_H_

struct point {
	float x;
	float y;
};

int find_leftmost ( struct point *array, int array_size);
int cross_product ( struct point *array, int o, int a, int b);
int find_points ( struct point *array, struct point *convex, int array_size, int convex_size);

#endif /* CONVEX_H_ */
