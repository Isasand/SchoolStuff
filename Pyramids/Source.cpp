#include <windows.h> 
#include <Iostream> 
#include <stdlib.h>//srand
#include <time.h>//time
#include <iomanip>//setwith, setprecision, setiosflags
#include "Pyramid.h" 
#include <vector>

using namespace std;

void setnumber(int &randomnumber); //funktion som skapar ett random nummer
int NumberOfPyramids();
void CreateTwoRandomFloats(int &rand_number, int &rand_number2, float &rand_float, float &rand_bredd, float &rand_hojd);
void Goodbye();
int main() {
	
	/*
	The different color codes are

	0   BLACK
	1   BLUE
	2   GREEN
	3   CYAN
	4   RED
	5   MAGENTA
	6   BROWN
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW
	15  WHITE
	*/

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	

	srand(time(0));
	/*vector<Pyramid> pyramider; //vector för lagring av pyramid-objekt

	int antal = 0;
	int rand_number;
	int rand_number2;
	float rand_float;
	float rand_hojd;
	float rand_bredd;
	int j = 1;

	antal = NumberOfPyramids();


	for (int i = 0; i < antal; i++) {
		CreateTwoRandomFloats(rand_number, rand_number2, rand_float, rand_bredd, rand_hojd);
		Pyramid pyramid;
		pyramider.push_back(pyramid);
		(pyramider.at(i)).setx(rand_bredd);
		(pyramider.at(i)).sety(rand_hojd);
	}

	for (int i = 0; i <antal; i++) {//utskrift av mått på de skapade Pyramiderna, samt area, volym och ny höjd och bredd efter change();
		
		cout << "M\x86tt f\x94r Pyramid " << j << ": " <<
			endl << "Bredd: " << setiosflags(ios::fixed) << setw(12) << setprecision(2) << (pyramider.at(i)).x() << " cm" << endl
			<< "H\x94jd: " << setw(13) << setprecision(2) << (pyramider.at(i)).y() << " cm" << endl
			<< "Basarea: " << setw(10) << setprecision(2) << (pyramider.at(i)).area() << " cm^2" << endl
			<< "Volym: " << setw(12) << setprecision(2) << (pyramider.at(i)).Volym() << " cm^3" << endl << endl
			<< "Nu byter bredd och h\x94jd plats!" << endl;
		(pyramider.at(i)).change(rand_bredd, rand_hojd);
		cout << "Ny bredd: " << setw(9) << setprecision(2) <<(pyramider.at(i)).x() << " cm" << endl
			<< "Ny h\x94jd: " << setw(10) << setprecision(2) << (pyramider.at(i)).y() << " cm" << endl << endl << endl;
		j++;
	}
	*/
	cin.get();
	cin.get();

	for (int i = 2; i < 14; i++) {

		SetConsoleTextAttribute(hConsole, i);
		Goodbye();
	}
	Sleep(200);

	SetConsoleTextAttribute(hConsole, wOldColorAttrs);

	return 0;
}

void setnumber(int &randomnumber) {
	randomnumber = rand() % 50;//rand()%50 används för att skapa en random int mellan 0-49
	while (randomnumber == 0) {//om numrerna blir 0 eller mindre så gör vi om, Pyramiden kan inte vara negativ
		randomnumber = rand() % 50;
	}
}

int NumberOfPyramids() {
	int antal; 
	cout << "Hur m\x86nga Pyramider ska skapas? (1-30): ";
	cin >> antal;
	return antal;
}

void CreateTwoRandomFloats(int &rand_number, int &rand_number2, float &rand_float, float &rand_bredd, float &rand_hojd) {
	setnumber(rand_number);//skapar två random nummer
	setnumber(rand_number2);
	rand_float = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);//genererar ett nummer mellan 0.0 och 1.0
	rand_bredd = rand_number / rand_float;//delar random bredd och höjd med floaten för att få ett random decimaltal
	rand_hojd = rand_number2 / rand_float;
}

void Goodbye() {
	int colour = 2;
	//while (colour < 255) {

	system("CLS");
	cout << " o \n"
		<< "/|\\ \n"
		<< "/ \\ \n";

	Sleep(150);
	system("CLS");
	cout << "\\ o / \n"
		<< "  | \n"
		<< " / \\ \n";

	Sleep(150);
	system("CLS");
	cout << " _ o \n"
		<< "  /\\ \n"
		<< " | \\ \n";

	Sleep(150);
	system("CLS");
	cout << "\n"
		<< "  ___\\o  \n"
		<< " /)  |  \n";

	Sleep(150);
	system("CLS");

	cout << "  __|   \n"
		<< "    \\o  \n"
		<< "    ( \\ \n";

	Sleep(150);
	system("CLS");
	cout << "    \\ /     \n"
		<< "     |    \n"
		<< "    /o\\  \n";

	Sleep(150);
	system("CLS");
	cout << "      |__   \n"
		<< "    o/     \n"
		<< "   / )   \n";

	Sleep(150);
	system("CLS");
	cout << " \n"
		<< "  o/__    \n"
		<< "  |  (\\  \n";

	Sleep(150);
	system("CLS");
	cout << "   o _  \n"
		<< "   /\\     \n"
		<< "   / |    \n";

	Sleep(180);
	system("CLS");
	cout << "   \\ o /  \n"
		<< "     |     \n"
		<< "    / \\  \n";

	Sleep(150);
	system("CLS");
	cout << "    o \n"
		<< "   /|\\   \n"
		<< "   / \\ \n";

	//cout << "*** GOOD BYE ***";
	//colour++;
	//}
}