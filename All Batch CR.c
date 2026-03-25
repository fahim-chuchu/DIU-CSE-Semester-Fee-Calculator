#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	printf("\t╔─────═════════════════════════════─────┐\n\t║   Daffodil International University   ║\n\t║   \"Payment Before Final Calculator\"   ║\n\t║         For CSE Department CRs        ║\n\t║                                       ║\n\t║ Author  : Fahim Faysal Khan           ║\n\t║ Version : 1.0                         ║\n\t║                                       ║\n\t║  You can calculate your Semester Fee  ║\n\t║            with this tool.            ║\n\t└─────═════════════════════════════─────╝\n\n");
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
	printf("\n");
	
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
	printf("\n");

	// Waiver
	float Waiver_10 = 10.0f / 100;
	float Waiver_20 = 20.0f / 100;
	float Waiver_25 = 25.0f / 100;
	float Waiver_30 = 30.0f / 100;
	float Waiver_50 = 50.0f / 100;
	float Waiver_75 = 75.0f / 100;

	// Calculation
	printf("Showing Semester Fees...\n");
	int Core_Fee = core * Core;
	int GED_Fee = ged * GED;
	int Lab_Fee = (int)(lab * Lab);
	int Total = Core_Fee + GED_Fee + Lab_Fee;
	int Reg = Total + A;
	int Paid = A + B;
	int Payment = Total - B;
	int Payment_10 = (int)(Total - Total * Waiver_10) - B;
	int Payment_20 = (int)(Total - Total * Waiver_20) - B;
	int Payment_25 = (int)(Total - Total * Waiver_25) - B;
	int Payment_30 = (int)(Total - Total * Waiver_30) - B;
	int Payment_50 = (int)(Total - Total * Waiver_50) - B;
	int Payment_75 = (int)(Total - Total * Waiver_75) - B;

	// Print
	printf("Registration Fee: %d Taka\n", A);
	printf("%d credits Core Course Fee: %d * %d = %d Taka\n", Core, core, Core, Core_Fee);
	printf("%d credits GED Course Fee: %d * %d = %d Taka\n", GED, ged, GED, GED_Fee);
	printf("%.1f credits Lab Course Fee: %d * %.1f = %d Taka\n", Lab, lab, Lab, Lab_Fee);
	printf("Total Course Fee (Without Waiver): %d Taka\n", Total);
	printf("With Registration Fee (Without Waiver): %d + %d = %d Taka\n", Total, A, Reg);
	printf("Already Paid: %d Taka (Registration Fee: %d + Semester Fee: %d)\n", Paid, A, B);
	printf("\nPayment before the Final Exam:\n");
	printf("Without Waiver -> %d Taka\n", Payment);
	printf("10% Waiver -> %d Taka\n", Payment_10);
	printf("20% Waiver -> %d Taka\n", Payment_20);
	printf("25% Waiver -> %d Taka\n", Payment_25);
	printf("30% Waiver -> %d Taka\n", Payment_30);
	printf("50% Waiver -> %d Taka\n", Payment_50);
	printf("75% Waiver -> %d Taka\n", Payment_75);
	return 0;
}
