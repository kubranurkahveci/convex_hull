#include <stdio.h>
#include <math.h>
#include "convex.h"

int find_leftmost ( struct point *array, int array_size) {

	int i, index;
	float min_x, y;
	for (i=0; i < array_size; i++) {
		printf("%.1f, %.1f\n", array[i].x, array[i].y);
	}
	printf("\n");
	min_x=array[0].x;
	for (i=1; i < array_size ; i++) {
		if (min_x > array[i].x) {
			min_x = array[i].x;
			y = array[i].y;
			index = i;
		}
	}
	return index;
}
int cross_product( struct point *array, int o, int a, int b ) {

	int det;
	float xa, ya, xb, yb;

	xa = (array[a].x - array[o].x);
	ya = (array[a].y - array[o].y);

	xb = (array[b].x - array[o].x);
	yb = (array[b].y - array[o].y);

	det = (xa * yb) - (ya * xb);
	return det;
}
int find_points ( struct point *array, struct point *convex, int array_size, int convex_size ) {

	int left, o, a, b;
	left = find_leftmost( array, array_size);

	o = left;
	convex[0] = array[o];
	int j = 0;

	do {
		a = 0;
		for (b=1; b < array_size; b++) {

			if ( cross_product (array, o, a, b) == 0) {
				continue;
			} else if (cross_product (array, o, a, b) < 0) {
				a = b;
			}
		}
		j++;
		o = a;
		convex[j] = array[o];
	} while (left != o);
	return j;
}
