#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sRow {
	char row[50];
	struct sBreadboard*next;
} tRow;

typedef struct sBreadboard {
	char name[50];
	tRow *firstRow;
	struct sRow *next;
} tBreadboard;

void *chkMalloc(size_t sz) {
	void *mem = malloc(sz);

	// Just fail immediately on error.

	if (mem == NULL) {
		printf("Out of memory! Exiting.\n");
		exit(1);
	}

	// Otherwise we know it worked.

	return mem;
}

void addBreadboard(tBreadboard **first, char *name) {
	// Insert new item at start.

	tBreadboard *newest = chkMalloc(sizeof(*newest));
	strcpy_s(newest->name, sizeof(*newest), name);
	newest->next = *first;
	*first = newest;
}

void addRow(tBreadboard *first, char *row) {
	// Insert at start of list.

	tRow *newest = chkMalloc(sizeof(*newest));
	strcpy_s(newest->row, sizeof(*newest), row);
	newest->next = first->firstRow;
	first->firstRow = newest;
}

void dumpDetails(tBreadboard *currBreadboard) {
	// For every breadboard

	while (currBreadboard != NULL) {
		printf("%s has:\n", currBreadboard->name);

		// For every row that breadboard has.
		tRow *currRow = currBreadboard->firstRow;
		if (currRow == NULL) {
			printf("   <<no rows>>\n");
		}
		else {
			while (currRow != NULL) {
				printf("	%s\n", currRow->row);
				currRow = currRow->next;
			}
		}
		currBreadboard = NULL;
	}
}

int main(void) {
	tBreadboard *firstBreadboard = NULL;

	addBreadboard(&firstBreadboard, "Breadboard 1");
	for (int i = 0; i < 10; i++) {
		addRow(firstBreadboard, "XXXXXXXXXXXXXXX");
	}
	dumpDetails(firstBreadboard);
	getchar();

	printf("HELLO");
	return 0;
}
