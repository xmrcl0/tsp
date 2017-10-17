#include "graphviz.h"
#include <stdio.h>

void gen_graphviz (float ** c, int * m, int n) {
    FILE * outfile = fopen("minpath.dot", "w");

    fprintf(outfile, "digraph minpath {\n");

    for(int i = 0; i < n; i++) {
	fprintf(outfile, "\"%d\" [pos=\"%f,%f\"];\n", i, c[i][0], c[i][1]);

    }

    fprintf(outfile, "}");

    fclose(outfile);
}
