#include <stdio.h>

typedef int bool;
#define true 1
#define false 0
#define MAX_COLUMNS 16
#define MAX_ROWS 2

/*ändra encodingen i filen för in- och utdata till UTF-8 annars kommer det med junk
-chars som ställer till det och åäö skrivs inte ut som de ska*/

void CheckFileStatus(FILE *fptr);
int NextLineFirstPosition(int c, FILE *fptr, FILE *fptrMod, int column);
void SendNextChar(int c, FILE *fptr, FILE *fptrMod);
void CheckIfDashNeeded(bool *dashNeeded, bool *space, FILE *fptrMod);

int main() {
	FILE *fptr, *fptrMod;
	int c;
	bool dashNeeded = false, space = false;

	fopen_s(&fptr, "C:\\Users\\Isa\\Desktop\\Tatoeba.txt", "r");

	CheckFileStatus(fptr);

	if (fptr) {
		fopen_s(&fptrMod, "C:\\Users\\Isa\\Desktop\\TatoebaModified.txt", "w");
		c = fgetc(fptr);

		while (c != EOF) {
			for (int row = 0; row < MAX_ROWS; row++) {
				for (int column = 0; column < MAX_COLUMNS; column++) {

					//gör ny rad och nollställ kolumner när punkt hittas
					if (c == '.') {
						column = NextLineFirstPosition(c, fptr, fptrMod, column);
					}

					//om första char är space, skicka nästa istället
					else if (column == 0 && c == ' ') {
						SendNextChar(c, fptr, fptrMod);
					}

					//printa char till mod-filen
					else if (c != EOF) {
						fprintf(fptrMod, "%c", c);
					}

					//kolla positionerna innan du vill sätta ett dash
					if ((column == 14 && c == ' ') || (column == 15 && c == ' ')) {
						space = true;
					}

					c = fgetc(fptr);

					//kolla om dash behövs, om kolumn 15 är en char och kolumn 14 inte är ett space
					if ((column == 14) && (c != ' ')) {
						dashNeeded = true;
						break;
					}

				}
				//om sista char inte är ' ' eller '.' eller sista i filen 
				if (((c != ' ') && (c != '.') && (c != EOF))) {
					CheckIfDashNeeded(&dashNeeded, &space, fptrMod);
				}
				fprintf(fptrMod, "\n"); //efter 16 chars, gör ny line
			}
		}
		fclose(fptrMod);
		printf("File succesfully modified! Press ENTER to exit.");
	}

	fclose(fptr);
	getchar();

	return 0;
}

void CheckFileStatus(FILE *fptr) {
	if (fptr == NULL) {
		printf("Could not open file");
	}
}

int NextLineFirstPosition(int c, FILE *fptr, FILE *fptrMod, int column) {
	fprintf(fptrMod, "%c\n", c);
	c = fgetc(fptr);
	fprintf(fptrMod, "%c", c);
	return 0;
}

void SendNextChar(int c, FILE *fptr, FILE *fptrMod) {
	c = fgetc(fptr);
	fprintf(fptrMod, "%c", c);
}

void CheckIfDashNeeded(bool *dashNeeded, bool *space, FILE *fptrMod) {
	if (*dashNeeded == true && *space == false) {
		fprintf(fptrMod, "-");
	}
	(*dashNeeded) = false;
	(*space) = false;
}