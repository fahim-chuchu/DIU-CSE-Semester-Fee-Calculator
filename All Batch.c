#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	printf("\t╔─────═════════════════════════════─────┐\n\t║   Daffodil International University   ║\n\t║   \"Payment Before Final Calculator\"   ║\n\t║          For CSE Department           ║\n\t║                                       ║\n\t║ Author  : Fahim Faysal Khan           ║\n\t║ Version : 1.0                         ║\n\t║                                       ║\n\t║  You can calculate your Semester Fee  ║\n\t║            with this tool.            ║\n\t└─────═════════════════════════════─────╝\n\n");
	printf("!!! Don't add retake course credits here. You have to add them later.\n");
	
	// Regular Course Info
	printf("Enter Regular Course credits...\n");
	int Core, GED;
	float Lab;
	printf("Core Course credits: ");
	scanf("%d", &Core);
	printf("GED Course credits: ");
	scanf("%d", &GED);
	printf("Lab Course credits: ");
	scanf("%f", &Lab);
	while (getchar() != '\n');
	printf("\n");
	
	// Retake Course Info
	int Re_Core = 0, Re_GED = 0;
	float Re_Lab = 0;
	while (1) {
		printf("Do you have any retake course? [Type Yes/No. Or press enter to skip this.]\n");
		char choice[10];
		fgets(choice, sizeof(choice), stdin);
		if (choice[0] == '\n')
			break;
		char ch = tolower(choice[0]);
		if (ch == 'y') {
			printf("Enter Retake Course credits... [Press enter to skip any course.]\n");
			char credits[10];
			printf("Retake Core Course credits: ");
			fgets(credits, sizeof(credits), stdin);
			if (credits[0] != '\n')
				Re_Core = atoi(credits);
			printf("Retake GED Course credits: ");
			fgets(credits, sizeof(credits), stdin);
			if (credits[0] != '\n')
				Re_GED = atoi(credits);
			printf("Retake Lab Course credits: ");
			fgets(credits, sizeof(credits), stdin);
			if (credits[0] != '\n')
				Re_Lab = atof(credits);
			printf("\n");
			break;
		}
		else if (ch == 'n') {
			printf("\n");
			break;
		}
	}

	// Fee Info
	int core, ged, lab;
	printf("Enter course fees per credit...\n");
	printf("Per credit Core Course fee: ");
	scanf("%d", &core);
	printf("Per credit GED Course fee: ");
	scanf("%d", &ged);
	printf("Per credit Lab Course fee: ");
	scanf("%d", &lab);
	printf("\n");

	// Registration Info
	int A, B;
	printf("Enter informations from the \"Registration Amount\" sheet...\n");
	printf("Fees for registration (A): ");
	scanf("%d", &A);
	printf("4 credit fees (B): ");
	scanf("%d", &B);
	while (getchar() != '\n');
	printf("\n");

	// Waiver
	float Waiver = 0;
	char amount[10];
	printf("Enter your waiver amount [Press enter to skip]: ");
	fgets(amount, sizeof(amount), stdin);
	if (amount[0] != '\n')
		Waiver = atof(amount) / 100;
	printf("\n");

	// Calculation
	printf("Showing Semester Fees...\n");
	int Core_Credits = Core + Re_Core;
	int GED_Credits = GED + Re_GED;
	float Lab_Credits = Lab + Re_Lab;
	int Core_Fee = core * Core_Credits;
	int GED_Fee = ged * GED_Credits;
	int Lab_Fee = (int)(lab * Lab_Credits);
	int Total = Core_Fee + GED_Fee + Lab_Fee;
	int Reg = Total + A;
	int Paid = A + B;
	int Regular_Core = core * Core;
	int Regular_GED = ged * GED;
	int Regular_Lab = (int)(lab * Lab);
	int Regular_Total = Regular_Core + Regular_GED + Regular_Lab;
	int Waiver_Total = (int)(Regular_Total - Regular_Total * Waiver);
	int Retake_Core = core * Re_Core;
	int Retake_GED = ged * Re_GED;
	int Retake_Lab = (int)(lab * Re_Lab);
	int Retake_Total = Retake_Core + Retake_GED + Retake_Lab;
	int Total_Payment = Waiver_Total + Retake_Total;
	int Payment = Total_Payment - B;

	// Print
	printf("Registration Fee: %d Taka\n", A);
	printf("%d credits Core Course Fee: %d * %d = %d Taka\n", Core_Credits, core, Core_Credits, Core_Fee);
	printf("%d credits GED Course Fee: %d * %d = %d Taka\n", GED_Credits, ged, GED_Credits, GED_Fee);
	printf("%.1f credits Lab Course Fee: %d * %.1f = %d Taka\n", Lab_Credits, lab, Lab_Credits, Lab_Fee);
	printf("Total Course Fee (Without Waiver): %d Taka\n", Total);
	printf("With Registration Fee (Without Waiver): %d + %d = %d Taka\n", Total, A, Reg);
	if (Waiver != 0)
		printf("With Waiver: %d Taka\n", Total_Payment);
	printf("Already Paid: %d Taka (Registration Fee: %d + Semester Fee: %d)\n", Paid, A, B);
	printf("\nYour payment before the Final Exam: %d Taka\n", Payment);
	return 0;
}
