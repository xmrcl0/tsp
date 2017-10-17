#include "graphviz.h"
#include <stdio.h>

void gen_graphviz (float *** d, int * m, int n) {
    FILE * outfile = fopen("minpath.dot", "w");

    fprintf(outfile, "digraph minpath {\n");

    for(int i = 0; i < n; i++) {
	fprintf(outfile, "\"%d\" [pos=\"%f,%f\"];\n", i, d[i][0], d[i][1]);

    }

    fprintf(outfile, "}");

    fclose(outfile);
}
