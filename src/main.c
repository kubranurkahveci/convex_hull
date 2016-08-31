
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "convex.h"

#define LINE_SIZE1 (23)
#define LINE_SIZE2 (23)

int main (int argc, char **argv)
{
	struct point k1;
	struct point array[LINE_SIZE1];
	struct point convex[LINE_SIZE2];
	FILE *file;
	char line1[LINE_SIZE1];
	int i = 0;
if ((file = fopen ("point.txt","r")) == NULL ) {
		puts ("Failed to open file \n");
		return 0;
	}
while (fgets(line1, LINE_SIZE1, file) != NULL) {
	sscanf (line1, "(%f,%f)",&k1.x, &k1.y);
	array[i].x = k1.x;
	array[i].y = k1.y;
	i++;
	}
int convex_size = find_points ( array, convex, LINE_SIZE1, LINE_SIZE2 );

for (i = 0; i < convex_size; i++) {

	printf("%.1f %.1f\n", convex[i].x, convex[i].y );
}
fclose(file);
return 0;
}
