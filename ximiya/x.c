#include <stdio.h>

void getData(
	int   mode[6],
	float params[3],
	float var_1[8],
	float var_ch_1[49],
	float var_2[8],
	float var_ch_2[49],
	float var_3[8],
	float var_4[8],
	float var_5[6],
	float var_6[4],
	float var_7[8]
);

void output_1(int mode);
void output_2(int mode);
void output_ch(int mode, float var_2[8], float var_ch[49], float v_a[8]);


int main(void)
{
	char line[80 + 1];

	int mode[6];
	float params[3];
	float var_1[8];
	float var_ch_1[49];
	float var_2[8];
	float var_ch_2[49];
	float var_3[8];
	float var_4[8];
	float var_5[6];
	float var_6[4];
	float var_7[8];

	getData(mode, params, var_1, var_ch_1, var_2, var_ch_2, var_3, var_4, var_5, var_6, var_7);

	if (mode[0] == 0) {
		var_1[0] = 0;
	}

	var_ch_1[48] += 1;
	var_ch_2[48] += 1;

	var_4[6] += 1;
	var_5[3] += 1;
	var_6[0] += 1;

	float zero_kelvin = 273.16;

	if (mode[4] > 0) {
		int x = 0;

		if (mode[3] == 0 && mode[2] == 0) {
			x = 1;
		}

		if (mode[3] == 0 && mode[2] == 1) {
			x = 2;
		}

		if (mode[3] == 1 && mode[2] == 0) {
			x = 3;
		}

		if (mode[3] == 01 && mode[2] == 1) {
			x = 4;
		}

		if (mode[0] == 0) {
			output_2(x);
		}
		else {
			output_1(x);
		}
	}

	if (mode[1] == 1) {
		printf("TANDEM for NH3\n");
	}

	float var_a[8];
	for (int i = 0; i < 8; i++) {
		var_a[i] = 0;
	}

	printf("FEED GAS \n");

	output_ch(0, var_2, var_ch_2, var_a);






	return 0;
}

void getData(
	int mode[6],
	float params[3],
	float var_1[8],
	float var_ch_1[49],
	float var_2[8],
	float var_ch_2[49],
	float var_3[8],
	float var_4[8],
	float var_5[6],
	float var_6[4],
	float var_7[8]
)
{
	char* filename = "D:\\Internet Exploer\\ximiya\\x64\\Debug\\VXMEPRSH.txt";
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Îøèáêà îòêðûòèÿ ôàéëà.\n");
		return 1;
	}


	for (int i = 0; i < 6; i++) {
		fscanf_s(fp, "%u", &mode[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 3; i++) {
		fscanf_s(fp, "%f", &params[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%f", &var_1[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 49; i++) {
		fscanf_s(fp, "%f", &var_ch_1[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%f", &var_2[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 49; i++) {
		fscanf_s(fp, "%f", &var_ch_2[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%f", &var_3[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%f", &var_4[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 6; i++) {
		fscanf_s(fp, "%f", &var_5[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 4; i++) {
		fscanf_s(fp, "%f", &var_6[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%f", &var_7[i]);
		while (fgetc(fp) != '\n');
	}

	fclose(fp);
}

void output_1(int mode)
{
	switch (mode)
	{
	case 1:
		printf("    steam¦                              ¦ prod.gas              \n");
		printf("         ¦                              ¦                       \n");
		printf("  feed   ¦     ã=========¬          ã==========¬  oxygen air mix\n");
		printf("---------+---->¦         ¦--------->¦          ¦<--------T------\n");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject\n");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam \n");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      \n");
		printf("               L====T====-          L====T=====-                \n");
		printf("                    ¦                    ¦                      \n");
		printf("                    L---------<-----------                      \n");
		break;
	case 2:
		printf("steam¦   ¦hydrogen                       ¦Prod.                 \n");
		printf("     ¦   ¦fraction                       ¦gas                   \n");
		printf("     ¦   ¦                               ¦                      \n");
		printf(" feed¦ ã=¦=¬     ã=========¬          ã==========¬ oxygen air mi\n");
		printf("-----+-¦mix¦---->¦         ¦--------->¦          ¦<------T------\n");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject\n");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam \n");
		printf("<----------------¦         ¦          ¦          ¦       ¦      \n");
		printf("                 L====T====-          L====T=====-              \n");
		printf("                      ¦                    ¦                    \n");
		printf("                      L---------<-----------                    \n");
		break;
	case 3:
		printf("                     bypass                                     \n");
		printf("         ------------------>-----------¬                        \n");
		printf("         ¦                             ¦   ¦pr.gas              \n");
		printf("         ¦                             ¦   ¦                    \n");
		printf("  feed   ¦     ã=========¬          ã==¦===¦===¬ oxygen air mixt\n");
		printf("---------+---->¦         ¦--------->¦          ¦<--------T------\n");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject\n");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam \n");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      \n");
		printf("               L====T====-          L====T=====-                \n");
		printf("                    ¦                    ¦                      \n");
		printf("                    L---------<-----------                      \n");
		break;
	case 4:
		printf("steam¦   ¦hydrogen                                              \n");
		printf("     ¦   ¦fraction       bypass                                 \n");
		printf("     ¦   ¦    ------------->---------------¬                    \n");
		printf(" feed¦ ã=¦=¬  ¦  ã=========¬          ã====¦=====¬ oxygen air mi\n");
		printf("-----+-¦mix¦--+->¦         ¦--------->¦          ¦<------T------\n");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject\n");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam \n");
		printf("<----------------¦         ¦          ¦          ¦       ¦      \n");
		printf("                 L====T====-          L====T=====-              \n");
		printf("                      ¦                    ¦                    \n");
		printf("                      L---------<-----------                    \n");
		break;
	}
}

void output_2(int mode)
{
	switch (mode)
	{
	case 1:
		printf("    steam¦                                                      \n");
		printf("         ¦                                                      \n");
		printf("  feed   ¦     ã=========¬          ã==========¬  oxygen air mix\n");
		printf("---------+---->¦         ¦--------->¦          ¦<--------T------\n");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject\n");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam \n");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      \n");
		printf("               L====T====-          L====T=====-                \n");
		printf("                    ¦                    ¦                      \n");
		printf("                    L---------<-----------                      \n");
		break;
	case 2:
		printf("steam¦   ¦hydrogen                                              \n");
		printf("     ¦   ¦fraction                                              \n");
		printf("     ¦   ¦                                                      \n");
		printf("ñûðüå¦ ã=¦=¬     ã=========¬          ã==========¬ oxygen air mi\n");
		printf("-----+-¦mix¦---->¦         ¦--------->¦          ¦<------T------\n");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject\n");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam \n");
		printf("<----------------¦         ¦          ¦          ¦       ¦      \n");
		printf("                 L====T====-          L====T=====-              \n");
		printf("                      ¦                    ¦                    \n");
		printf("                      L---------<-----------                    \n");
		break;
	case 3:
		printf("                     bypass                                     \n");
		printf("            --------------->--------------¬                     \n");
		printf("    steam¦  ¦                             ¦                     \n");
		printf("         ¦  ¦                             ¦                     \n");
		printf("  feed   ¦  ¦  ã=========¬          ã=====¦====¬ oxygen air mixt\n");
		printf("---------+--+->¦         ¦--------->¦          ¦<--------T------\n");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject\n");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam \n");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      \n");
		printf("               L====T====-          L====T=====-                \n");
		printf("                    ¦                    ¦                      \n");
		printf("                    L---------<-----------                      \n");
		break;
	case 4:
		printf("steam¦   ¦hydrogen                                              \n");
		printf("     ¦   ¦fraction       bypass                                 \n");
		printf("     ¦   ¦    ------------->---------------¬                    \n");
		printf("ñûðüå¦ ã=¦=¬  ¦  ã=========¬          ã====¦=====¬ oxygen air mi\n");
		printf("-----+-¦mix¦--+->¦         ¦--------->¦          ¦<------T------\n");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject\n");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam \n");
		printf("<----------------¦         ¦          ¦          ¦       ¦      \n");
		printf("                 L====T====-          L====T=====-              \n");
		printf("                      ¦                    ¦                    \n");
		printf("                      L---------<-----------                    \n");
		break;
	}
}

void output_ch(int mode, float var_2[8], float var_ch[49], float v_a[8])
{
	char* printCh[49];
	printCh[0] = "¦   CH4  ¦ ";
	printCh[1] = "¦   C2H6 ¦ ";
	printCh[2] = "¦   C3H8 ¦ ";
	printCh[3] = "¦   C4H10¦ ";
	printCh[4] = "¦   C5H12¦ ";
	printCh[5] = "¦   C6H14¦ ";
	printCh[6] = "¦   C7H16¦ ";
	printCh[7] = "¦   C8H18¦ ";
	printCh[8] = "¦   C9H20¦ ";
	printCh[9] = "¦  C10H22¦ ";
	printCh[10] = "¦  C11H24¦ ";
	printCh[11] = "¦  C12H26¦ ";
	printCh[12] = "¦   C4H10¦ ";
	printCh[13] = "¦   C5H12¦ ";
	printCh[14] = "¦   C5H12¦ ";
	printCh[15] = "¦   C6H14¦ ";
	printCh[16] = "¦   C6H14¦ ";
	printCh[17] = "¦   C6H14¦ ";
	printCh[18] = "¦   C6H14¦ ";
	printCh[19] = "¦   C2H4 ¦ ";
	printCh[20] = "¦   C3H6 ¦ ";
	printCh[21] = "¦   C4H8 ¦ ";
	printCh[22] = "¦   C4H8 ¦ ";
	printCh[23] = "¦   C4H8 ¦ ";
	printCh[24] = "¦   C4H8 ¦ ";
	printCh[25] = "¦   C5H10¦ ";
	printCh[26] = "¦   C5H10¦ ";
	printCh[27] = "¦   C5H10¦ ";
	printCh[28] = "¦   C5H10¦ ";
	printCh[29] = "¦   C5H10¦ ";
	printCh[30] = "¦   C5H10¦ ";
	printCh[31] = "¦   C2H2 ¦ ";
	printCh[32] = "¦   C5H10¦ ";
	printCh[33] = "¦   C6H12¦ ";
	printCh[34] = "¦   C7H14¦ ";
	printCh[35] = "¦   C6H12¦ ";
	printCh[36] = "¦   C7H14¦ ";
	printCh[37] = "¦   C8H16¦ ";
	printCh[38] = "¦   C9H18¦ ";
	printCh[39] = "¦   C6H6 ¦ ";
	printCh[40] = "¦   C7H8 ¦ ";
	printCh[41] = "¦   C8H10¦ ";
	printCh[42] = "¦   C8H10¦ ";
	printCh[43] = "¦   C8H10¦ ";
	printCh[44] = "¦   C8H10¦ ";
	printCh[45] = "¦   C4H6 ¦ ";
	printCh[46] = "¦   CH30H¦ ";


	if (mode == 1) {
		printf("Q  = %.4f kkal/h;\n", v_a[5]);
	}

	if (mode != 1 && mode != 2) {

		if (v_a[0] != 0) {
			printf("T inlet  = %.1f  *C ;\n", v_a[0]);
		}

		if (v_a[6] != 0) {
			printf("V dry bypass gas = %.2f  m3/h;\n", v_a[6]);
		}

		if (v_a[7] != 0) {
			printf("V bypass steam = %.2f  m3/h ;\n", v_a[7]);
		}

		if (v_a[4] != 0) {
			printf("T outlet from tandem = %.1f *C ;\n", v_a[5]);
		}
	}

	if (var_2[1] != 0) {
		printf("steam / gas = %.4f;\n", var_2[1]);
	}

	if (var_ch[47] != 0) {
		printf("T = %.1f  *C ;\n", var_ch[47]);
	}

	if (var_ch[48] != 0) {
		printf("P = %.2f  ati;\n", var_ch[48]);
	}

	printf("V dry gas  = %.2f  m3/h;\n", var_2[0]);

	float b[6];
	for (int i = 0; i < 6; i++) {
		b[i] = var_2[i + 2] / (var_2[1] + 1);
	}

	float x1 = (var_2[1] / (var_2[1] + 1)) * 100;

	float b1[49];
	for (int i = 0; i < 49; i++) {
		b1[i] = var_ch[i] / (var_2[1] + 1);
	}

	printf("ã==========================================================¬\n");
	printf("¦ compo- ¦                                                 ¦\n");
	printf("¦ nents  ¦  moist gas %%       dry gas %%           m3/h     ¦\n");
	printf("¦==========================================================¦\n");

	float sum1 = 0;
	float sum2 = 0;
	float sum3 = 0;

	if (b[0] != 0) {
		if (var_2[2] != 0) {
			float x = (var_2[2] * var_2[0]) / 100;
			printf("¦   CO2  ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[0], var_2[2], x);
			sum1 += b[0];
			sum2 += var_2[2];
			sum3 += x;
		}
	}

	if (b[1] != 0) {
		if (var_2[3] != 0) {
			float x = (var_2[3] * var_2[0]) / 100;
			printf("¦   CO   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[1], var_2[3], x);
			sum1 += b[1];
			sum2 += var_2[3];
			sum3 += x;
		}
	}

	if (b[2] != 0) {
		if (var_2[4] != 0) {
			float x = (var_2[4] * var_2[0]) / 100;
			printf("   H2   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[2], var_2[4], x);
			sum1 += b[2];
			sum2 += var_2[4];
			sum3 += x;
		}
	}

	if (b[3] != 0) {
		if (var_2[5] != 0) {
			float x = (var_2[5] * var_2[0]) / 100;
			printf("¦   N2   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[3], var_2[5], x);
			sum1 += b[3];
			sum2 += var_2[5];
			sum3 += x;
		}
	}

	if (b[4] != 0) {
		if (var_2[6] != 0) {
			float x = (var_2[6] * var_2[0]) / 100;
			printf("¦   AR   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[4], var_2[6], x);
			sum1 += b[4];
			sum2 += var_2[6];
			sum3 += x;
		}
	}

	if (b[5] != 0) {
		if (var_2[7] != 0) {
			float x = (var_2[7] * var_2[0]) / 100;
			printf("¦   O2   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[5], var_2[7], x);
			sum1 += b[5];
			sum2 += var_2[7];
			sum3 += x;
		}
	}

	if (x1 != 0) {
		float x = var_2[1] * var_2[0];
		printf("¦   H2O  ¦ %10.5f        %10.5f        %10.3f  ¦\n", x1, 0.0, x);
		sum1 += x1;
		sum2 += 0;
		sum3 += x;
	}

	for (int i = 0; i < 47; i++) {
		if (b1[i] != 0) {
			if (var_ch[i] != 0) {
				float x = (var_ch[i] * var_2[0]) / 100;
				printf("%s %10.5f        %10.5f        %10.3f  ¦\n", printCh[i], b1[i], var_ch[i], x);
				sum1 += b1[i];
				sum2 += var_ch[i];
				sum3 += x;
			}
		}
	}
	printf("¦==========================================================¦\n");
	printf("¦        ¦ %10.3f        %10.3f        %10.3f  ¦\n", sum1, sum2, sum3);

	printf("¦==========================================================¦\n"); //õç õç
}