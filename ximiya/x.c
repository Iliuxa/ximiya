#include <stdio.h>

void getData(
	int   mode[6],
	double params[3],
	double var_1[8],
	double var_ch_1[49],
	double var_2[8],
	double var_ch_2[49],
	double var_3[8],
	double var_4[8],
	double var_5[6],
	double var_6[4],
	double var_7[8]
);

void output_1(int mode);
void output_2(int mode);
void output_ch(int mode, double var_2[8], double var_ch[49], double v_a[8]);
void xzxzxz(double x, double symvols[8], double v_xx[37], double v_xz);


int main(void)
{
	char line[80 + 1];

	int mode[6];
	double params[3];
	double var_1[8];
	double var_ch_1[49];
	double var_2[8];
	double var_ch_2[49];
	double var_3[8];
	double var_4[8];
	double var_5[6];
	double var_6[4];
	double var_7[8];

	getData(mode, params, var_1, var_ch_1, var_2, var_ch_2, var_3, var_4, var_5, var_6, var_7);

	if (mode[0] == 0) {
		var_1[0] = 0;
	}

	var_ch_1[48] += 1;
	var_ch_2[48] += 1;

	var_4[6] += 1;
	var_5[3] += 1;
	var_6[0] += 1;

	double zero_kelvin = 273.16;

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

	double var_a[8];
	for (int i = 0; i < 8; i++) {
		var_a[i] = 0;
	}

	printf("FEED GAS \n");

	output_ch(0, var_2, var_ch_2, var_a);

	if (mode[0] == 0) {
		var_1[1] = (var_1[1] / 100) / (1 - (var_1[1] / 100));
		var_1[0] = var_1[0] / (var_1[1] + 1);

		for (int i = 2; i < 8; i++) {
			var_1[i] = var_1[i] * (1 + var_1[1]);
		}

		for (int i = 0; i < 49; i++) {
			var_ch_1[i] = var_ch_1[i] * (1 + var_1[1]);
		}

		printf("PROD.GAS TO SECONDARY REFORMER\n");
		output_ch(0, var_1, var_ch_1, var_a);

		if (params[2] > 0) {
			printf("GAS after saturation to SECONDARY REFORMER\n");
			var_1[1] = params[2];
			output_ch(0, var_1, var_ch_1, var_a);
		}

		if (params[0] > 0) {
			double v_xx[37]; //??????????????
			for (int i = 0; i < 49; i++) {
				v_xx[i] = 0.0;
			}

			v_xx[6] = 1; /// ?????????????

			double v_9cc = params[1] + zero_kelvin;

			//xzxzxz(v_9cc, symvols, v_xx, v_xz);

		}
	}

	double v_9cc = 0;
	double symvols[8];
	double v_xx[37];
	xzxzxz(v_9cc, symvols, v_xx, 1.1);

	return 0;
}

void getData(
	int mode[6],
	double params[3],
	double var_1[8],
	double var_ch_1[49],
	double var_2[8],
	double var_ch_2[49],
	double var_3[8],
	double var_4[8],
	double var_5[6],
	double var_6[4],
	double var_7[8]
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
		fscanf_s(fp, "%lf", &params[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%lf", &var_1[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 49; i++) {
		fscanf_s(fp, "%lf", &var_ch_1[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%lf", &var_2[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 49; i++) {
		fscanf_s(fp, "%lf", &var_ch_2[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%lf", &var_3[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%lf", &var_4[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 6; i++) {
		fscanf_s(fp, "%lf", &var_5[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 4; i++) {
		fscanf_s(fp, "%lf", &var_6[i]);
		while (fgetc(fp) != '\n');
	}

	for (int i = 0; i < 8; i++) {
		fscanf_s(fp, "%lf", &var_7[i]);
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

void output_ch(int mode, double var_2[8], double var_ch[49], double v_a[8])
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

	double b[6];
	for (int i = 0; i < 6; i++) {
		b[i] = var_2[i + 2] / (var_2[1] + 1);
	}

	double x1 = (var_2[1] / (var_2[1] + 1)) * 100;

	double b1[49];
	for (int i = 0; i < 49; i++) {
		b1[i] = var_ch[i] / (var_2[1] + 1);
	}

	printf("ã==========================================================¬\n");
	printf("¦ compo- ¦                                                 ¦\n");
	printf("¦ nents  ¦  moist gas %%       dry gas %%           m3/h     ¦\n");
	printf("¦==========================================================¦\n");

	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;

	if (b[0] != 0) {
		if (var_2[2] != 0) {
			double x = (var_2[2] * var_2[0]) / 100;
			printf("¦   CO2  ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[0], var_2[2], x);
			sum1 += b[0];
			sum2 += var_2[2];
			sum3 += x;
		}
	}

	if (b[1] != 0) {
		if (var_2[3] != 0) {
			double x = (var_2[3] * var_2[0]) / 100;
			printf("¦   CO   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[1], var_2[3], x);
			sum1 += b[1];
			sum2 += var_2[3];
			sum3 += x;
		}
	}

	if (b[2] != 0) {
		if (var_2[4] != 0) {
			double x = (var_2[4] * var_2[0]) / 100;
			printf("   H2   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[2], var_2[4], x);
			sum1 += b[2];
			sum2 += var_2[4];
			sum3 += x;
		}
	}

	if (b[3] != 0) {
		if (var_2[5] != 0) {
			double x = (var_2[5] * var_2[0]) / 100;
			printf("¦   N2   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[3], var_2[5], x);
			sum1 += b[3];
			sum2 += var_2[5];
			sum3 += x;
		}
	}

	if (b[4] != 0) {
		if (var_2[6] != 0) {
			double x = (var_2[6] * var_2[0]) / 100;
			printf("¦   AR   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[4], var_2[6], x);
			sum1 += b[4];
			sum2 += var_2[6];
			sum3 += x;
		}
	}

	if (b[5] != 0) {
		if (var_2[7] != 0) {
			double x = (var_2[7] * var_2[0]) / 100;
			printf("¦   O2   ¦ %10.5f        %10.5f        %10.3f  ¦\n", b[5], var_2[7], x);
			sum1 += b[5];
			sum2 += var_2[7];
			sum3 += x;
		}
	}

	if (x1 != 0) {
		double x = var_2[1] * var_2[0];
		printf("¦   H2O  ¦ %10.5f        %10.5f        %10.3f  ¦\n", x1, 0.0, x);
		sum1 += x1;
		sum2 += 0;
		sum3 += x;
	}

	for (int i = 0; i < 47; i++) {
		if (b1[i] != 0) {
			if (var_ch[i] != 0) {
				double x = (var_ch[i] * var_2[0]) / 100;
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

void xzxzxz(double x, double symvols[8], double v_xx[37], double v_xz)
{
	double numbers[345];
	numbers[0] = 3.982394375527551E+234;
	numbers[1] = 1.0234132710648603E+139;
	numbers[2] = 1.4442756608353007E-307;
	numbers[3] = -5.4325078108570244E+125;
	numbers[4] = -2.1857442648637842E-150;
	numbers[5] = 4.370229177559733E+86;
	numbers[6] = -2.534486308824747E+123;
	numbers[7] = 7.145069956622545E-240;
	numbers[8] = 7.325385407714964E-36;
	numbers[9] = -2.83766155538454E-196;
	numbers[10] = -9.577348419295664E+61;
	numbers[11] = -1.819961900882751E+197;
	numbers[12] = 9.622679444321505E+17;
	numbers[13] = 8.124749589394375E-172;
	numbers[14] = 1.192401532925256E+80;
	numbers[15] = -1.049619235400569E-86;
	numbers[16] = 1.3475358133422691E+116;
	numbers[17] = 9.829845964446491E+260;
	numbers[18] = 7.421132307929523E+81;
	numbers[19] = 2.6407240151509097E-74;
	numbers[20] = 2.4096946648130503E-259;
	numbers[21] = -6.651191063202938E+22;
	numbers[22] = -2.3147899493973996E-205;
	numbers[23] = 1.1682426162800745E+291;
	numbers[24] = 151.87538457613664;
	numbers[25] = 2.3452049703101166E-111;
	numbers[26] = 1.0950567018782773E+55;
	numbers[27] = 3.790619758916885E+131;
	numbers[28] = -5.588091587862853E-274;
	numbers[29] = -6.310145199443948E-143;
	numbers[30] = 3.982394168984285E+234;
	numbers[31] = -3.102785073397982E+298;
	numbers[32] = -1.7408244620702085E+25;
	numbers[33] = 9.27159951292501;
	numbers[34] = -6.804461463067047E+202;
	numbers[35] = -1.9870547486329755E+111;
	numbers[36] = 3.4013581623502913E-267;
	numbers[37] = 0.003964662847309219;
	numbers[38] = -5.092746677992343E+101;
	numbers[39] = -3.9904971892936806E+305;
	numbers[40] = 4.667263051321119E-62;
	numbers[41] = -8.856714725196739E+117;
	numbers[42] = 1.09420205424027E+51;
	numbers[43] = 2.477016113726157E+156;
	numbers[44] = -3.489448367872649E+123;
	numbers[45] = 1.9035990253075095E+185;
	numbers[46] = 4.796466011867674E-242;
	numbers[47] = 9.535273332089685E-234;
	numbers[48] = 2.088005850480681E+35;
	numbers[49] = -5.750974871657976E-201;
	numbers[50] = -5.265575494305869E-284;
	numbers[51] = 2.8138807246202733E-247;
	numbers[52] = 1.6961416890197686E-11;
	numbers[53] = 9.91279819243117E-234;
	numbers[54] = -1.1958310264764044E-47;
	numbers[55] = -4.995948833339427E-136;
	numbers[56] = -1.5766837412598434E-105;
	numbers[57] = 2.6502861938780073E-233;
	numbers[58] = -1.0587347633692002E-19;
	numbers[59] = -2.168258036896465E-102;
	numbers[60] = 8.2157656035152E+283;
	numbers[61] = 1.2379576467228518E+68;
	numbers[62] = 2.571536543317243E-172;
	numbers[63] = -3.1606803760365706E-227;
	numbers[64] = 5.6284816376645845E+202;
	numbers[65] = 1.1078234842464544E-160;
	numbers[66] = 9.289296934130263E-106;
	numbers[67] = -4.494919438779889E-78;
	numbers[68] = -6.5637075370913885E-196;
	numbers[69] = 17405060185503.098;
	numbers[70] = 9.361684792650828E+135;
	numbers[71] = 6.316620101180966E+240;
	numbers[72] = 2.7156630299420992E-276;
	numbers[73] = -4.0558660301526205E+258;
	numbers[74] = -4.449244153431439E-148;
	numbers[75] = 1.9035987522547523E+185;
	numbers[76] = 8.795948341799005E+240;
	numbers[77] = 1.157733016231396E-154;
	numbers[78] = 3.409722288033101E-299;
	numbers[79] = 102362.49481033614;
	numbers[80] = 2.0257438596538992E+37;
	numbers[81] = 5.8328254457639005E-297;
	numbers[82] = 4.49422043008275E-214;
	numbers[83] = -2.13871243610815E-194;
	numbers[84] = -1.1840211945653E-178;
	numbers[85] = -1.8604214417674598E+259;
	numbers[86] = 1.0536762169072303E-307;
	numbers[87] = -3.5473806854393875E-130;
	numbers[88] = -2.4028078916655548E-67;
	numbers[89] = -1.1050193501974917E+211;
	numbers[90] = 1.0140868113701623E-12;
	numbers[91] = 7.794830523540737E-21;
	numbers[92] = -1.9804737802702856E-175;
	numbers[93] = 1.439435928841598E-37;
	numbers[94] = -4.5022064682759185E-177;
	numbers[95] = 1.107823160647577E-160;
	numbers[96] = 1.6461767243831615E-298;
	numbers[97] = -3.6021542211131703E-54;
	numbers[98] = 2.0970106234771615E-121;
	numbers[99] = -6.462113387827298E+93;
	numbers[100] = -8.925787762189777E+209;
	numbers[101] = -2.3673187864687364E-290;
	numbers[102] = 2.1294393767634985E-210;
	numbers[103] = -2.245273879115707E+113;
	numbers[104] = -1.590424395860317E+110;
	numbers[105] = 1.1078231819282611E-160;
	numbers[106] = 4.837774137354143E-296;
	numbers[107] = 2.986651900486723E-107;
	numbers[108] = 1.0482352627192967E+166;
	numbers[109] = -2.331583097953135E-121;
	numbers[110] = 4.667262986573028E-62;
	numbers[111] = 8.035772763920336E-293;
	numbers[112] = -2.6660300561000025E+103;
	numbers[113] = -1.887269025423831E-166;
	numbers[114] = -9.067260737303569E+114;
	numbers[115] = -4.2317900655169774E+160;
	numbers[116] = -1.797739899698225E+77;
	numbers[117] = 5.686351319303651E-143;
	numbers[118] = 6.649714725759856E+113;
	numbers[119] = -9.562317481964981E+69;
	numbers[120] = -1.9870547598317072E+111;
	numbers[121] = -1.2476201854689225E+63;
	numbers[122] = 1.5141123746288356E-248;
	numbers[123] = -6.475865965296821E+249;
	numbers[124] = 8.553716859517102E-09;
	numbers[125] = -1.0496192599325552E-86;
	numbers[126] = -8.793617577393636E-147;
	numbers[127] = 0.8453434221100823;
	numbers[128] = -4.8255800668798216E-61;
	numbers[129] = -5.5048197241140755E-204;
	numbers[130] = -4.995948478970661E-136;
	numbers[131] = -3.2645488154816146E-113;
	numbers[132] = 3.252088271584371E+219;
	numbers[133] = -7.941614831217425E+287;
	numbers[134] = 7.344059065854182E+142;
	numbers[135] = -4.995948478970661E-136;
	numbers[136] = -3.2645488154816146E-113;
	numbers[137] = 3.252088271584371E+219;
	numbers[138] = -7.941614831217425E+287;
	numbers[139] = 7.344059065854182E+142;
	numbers[140] = 4.370229428810496E+86;
	numbers[141] = -4.692599373842625E+106;
	numbers[142] = 9.245958777806107E-287;
	numbers[143] = -6.828585303770379E-234;
	numbers[144] = 1.828384439633989E+90;
	numbers[145] = -2.1770144103709403E-37;
	numbers[146] = 1.1342290922615098E-228;
	numbers[147] = 7.393497387814832E+225;
	numbers[148] = 4.419998434331084E+305;
	numbers[149] = -1.1413428760400745E-114;
	numbers[150] = -4.995949356683904E-136;
	numbers[151] = -1.065539503745753E+180;
	numbers[152] = -8.920425417673616E+34;
	numbers[153] = 7.673941318566971E-306;
	numbers[154] = 1.259016951508718E-27;
	numbers[155] = 1.1078231339018074E-160;
	numbers[156] = -6.708081748615466E+205;
	numbers[157] = 6.817795758247911E+83;
	numbers[158] = -7.869869316726995E-114;
	numbers[159] = -6.173060222869719E-249;
	numbers[160] = 2.0257441079227606E+37;
	numbers[161] = 7.307750366747095E-30;
	numbers[162] = -1.182766212987867E-24;
	numbers[163] = 1.0774936858039061E-302;
	numbers[164] = 1.3457413836133646E+261;
	numbers[165] = 3.982394074226122E+234;
	numbers[166] = -3.074340250982548E+18;
	numbers[167] = -4.194900694027977E-38;
	numbers[168] = 3.936471372338645E-96;
	numbers[169] = -2.8513872976064804E-95;
	numbers[170] = 2.345205760899736E-111;
	numbers[171] = 1.5913156275252295E+58;
	numbers[172] = 5.410574437960875E+307;
	numbers[173] = 1.5464368722479238E+226;
	numbers[174] = 2.2175522585784916E+55;
	numbers[175] = -1.0496191037518257E-86;
	numbers[176] = 5.242364213861411E-262;
	numbers[177] = -4.218087624892928E+32;
	numbers[178] = 3.4236464768616917E-225;
	numbers[179] = -4.143165808588156E-133;
	numbers[180] = 2.0257438905404933E+37;
	numbers[181] = 1.064642088174967E-99;
	numbers[182] = 6.772227086356877E-78;
	numbers[183] = 9.051889388746103E-53;
	numbers[184] = 0.0247146207958037;
	numbers[185] = -5.265575733553453E-284;
	numbers[186] = 5.42752125629913E-113;
	numbers[187] = 1.6219086100730708E+196;
	numbers[188] = -5.419610968138383E+110;
	numbers[189] = -7.907067166197714E+105;
	numbers[190] = -1.9870549815664282E+111;
	numbers[191] = -1.6528379034089278E+287;
	numbers[192] = 4.5103711542061374E-278;
	numbers[193] = 189886411383.4917;
	numbers[194] = -2.8488529733851087E+102;
	numbers[195] = 2.0257434775636974E+37;
	numbers[196] = 3.829773629151119E-183;
	numbers[197] = -9.087452286439992E-303;
	numbers[198] = 4.619986244959804E-124;
	numbers[199] = 8.441422473834305E+89;
	numbers[200] = 4.3702275929269414E+86;
	numbers[201] = -2.417819348119181E+191;
	numbers[202] = -1.863713167049587E-31;
	numbers[203] = -3.5689876402312364E+244;
	numbers[204] = -1.8316722286764447E-274;
	numbers[205] = -4282596530584.103;
	numbers[206] = -4.3350372285353584E+158;
	numbers[207] = 1.6322081911695043E+274;
	numbers[208] = 1.7098290173266012E-118;
	numbers[209] = 7.231148178878803E+20;
	numbers[210] = 1.1078230400018332E-160;
	numbers[211] = 2.8515780018798957E-276;
	numbers[212] = -7.588876988457798E+88;
	numbers[213] = -8.378613993588962E+61;
	numbers[214] = -7.906223454258509E+158;
	numbers[215] = -1.98705428500582E+111;
	numbers[216] = 1.0360579127826428E+159;
	numbers[217] = 3.924782451135345E+103;
	numbers[218] = 1.1859788837103921E-231;
	numbers[219] = 1.379988783952512E+229;
	numbers[220] = -2.1770160148713908E-37;
	numbers[221] = 7.677301046832107E+231;
	numbers[222] = 9.28662770549052E+106;
	numbers[223] = -9.721610476855072E-88;
	numbers[224] = 2.2751950893011987E+173;
	numbers[225] = 3.982395153951241E+234;
	numbers[226] = -3.3251440640112125E+214;
	numbers[227] = -2.0742901694362122E-221;
	numbers[228] = -2.089529470640951E-84;
	numbers[229] = -1.1940648940719715E-56;
	numbers[230] = 2.3452052402297664E-111;
	numbers[231] = 5.515407925903337E+188;
	numbers[232] = 3.3349512073203286E-240;
	numbers[233] = -1.7360767825053E-213;
	numbers[234] = 1.1061165592099931E+250;
	numbers[235] = 1.107823364511558E-160;
	numbers[236] = 4.0966836183813496E-280;
	numbers[237] = -2.2167926240088566E+136;
	numbers[238] = -1.4847729986017373E+242;
	numbers[239] = -1.0444446598440923E-304;
	numbers[240] = 9.361682852552007E+135;
	numbers[241] = 1.217366204620588E+230;
	numbers[242] = 1.6656462704489002E+17;
	numbers[243] = 2.1264890980491847E-74;
	numbers[244] = 1.051869332164794E-297;
	numbers[245] = -4.9959505627137525E-136;
	numbers[246] = 8.244944368155611E-278;
	numbers[247] = -8.065071200364587E-108;
	numbers[248] = -9.71608316802449E+32;
	numbers[249] = -1.1599376712244505E+80;
	numbers[250] = -1.0496186790242903E-86;
	numbers[251] = -1.9746447734375552E+220;
	numbers[252] = -5.969319448173778E+288;
	numbers[253] = 1.734486781766643E-98;
	numbers[254] = -3.0512892265548105E-28;
	numbers[255] = 4.3702290663811886E+86;
	numbers[256] = 4.983463848608275E+250;
	numbers[257] = 6.30626283359409E+38;
	numbers[258] = 6.0201502944685315E-307;
	numbers[259] = -1.0168733415415428E-303;
	numbers[260] = 2.0257438395296058E+37;
	numbers[261] = -2.51025137880017E-53;
	numbers[262] = -1.8449467182952645E+243;
	numbers[263] = -2.086061548641226E-209;
	numbers[264] = -2.1846062983343096E+38;
	numbers[265] = 1.109038106760596E-234;
	numbers[266] = 7.42806260289526E+291;
	numbers[267] = -1.8530450963534602E-25;
	numbers[268] = -7.91616102501795E-98;
	numbers[269] = 3.879341044037669E-188;
	numbers[270] = 3.006252554014356E-293;
	numbers[271] = -3.425697871664386E+81;
	numbers[272] = 7.73669273096679E-155;
	numbers[273] = 1.5459467725205104E-154;
	numbers[274] = 1.5722879200394156E-255;
	numbers[275] = 1.061022227E-314;
	numbers[276] = 9.702482991701489E-62;
	numbers[277] = -1.6115679156286727E-205;
	numbers[278] = 4.64203547217796E+101;
	numbers[279] = 1.4683272042918939E-89;
	numbers[280] = 4.667260932263921E-62;
	numbers[281] = 4.9374592679633066E-76;
	numbers[282] = -5.995203043948706E-56;
	numbers[283] = -1.217997875178966E+304;
	numbers[284] = -2.9578167617271463E+63;
	numbers[285] = 3.982396579580731E+234;
	numbers[286] = -6.2735059488715016E+32;
	numbers[287] = 5.538256212825386E-248;
	numbers[288] = -4.749298913475617E-249;
	numbers[289] = 1.4669188273310936E+118;
	numbers[290] = 2.409695059441427E-259;
	numbers[291] = -1.1798241192496622E+139;
	numbers[292] = 3.770807467232805E-53;
	numbers[293] = 4.003323667894225E-234;
	numbers[294] = 1.431755379217319E-183;
	numbers[295] = -8.925790520107931E+209;
	numbers[296] = 3.2534798187996373E+39;
	numbers[297] = 3.671917789358894E+177;
	numbers[298] = 4.7702867108969686E-179;
	numbers[299] = -1.3107505080192167E+271;
	numbers[300] = -9.577347569800736E+61;
	numbers[301] = -2.0299839474275817E-203;
	numbers[302] = 2.726383227795389E+256;
	numbers[303] = -1.2089774259635274E+307;
	numbers[304] = -3.767171989275696E+79;
	numbers[305] = 4.37022752868042E+86;
	numbers[306] = -1.1123431106287138E-72;
	numbers[307] = -5.2842779284269315E-230;
	numbers[308] = 3.871521166367586E-17;
	numbers[309] = 3.6255011838157816E-83;
	numbers[310] = -4.231789196083967E+160;
	numbers[311] = -5.162443309726587E-46;
	numbers[312] = -6.666811286084542E-105;
	numbers[313] = 7.056873516062005E-43;
	numbers[314] = 7.41637740151182E+44;
	numbers[315] = 8.215767273987502E+283;
	numbers[316] = -5.502982521393616E+75;
	numbers[317] = 1.6098385364632483E+66;
	numbers[318] = 3.148443351842473E-285;
	numbers[319] = 9.693338519161473E-177;
	numbers[320] = 4.667263879915761E-62;
	numbers[321] = 1.6163431089228083E-35;
	numbers[322] = -2.3752413410072604E+185;
	numbers[323] = 6.977485193536129E+210;
	numbers[324] = 8.881326234671518E+105;
	numbers[325] = 5.186178025096808E-210;
	numbers[326] = 4.1773140143402885E-137;
	numbers[327] = 7.048350431633719E+267;
	numbers[328] = -1.0873874225667986E-32;
	numbers[329] = -8.672147010472776E+247;
	numbers[330] = -1.9870546600230824E+111;
	numbers[331] = -1.2567867770571558E+260;
	numbers[332] = -5.488328707874988E-66;
	numbers[333] = -4.0609454684502674E-235;
	numbers[334] = 7.102568934240478E-88;
	numbers[335] = -4.23178930216227E+160;
	numbers[336] = 1.5596201417097843E-252;
	numbers[337] = -1.233367919801239E+56;
	numbers[338] = -4.586005546038769E-213;
	numbers[339] = -1.1987545273022591E-73;
	numbers[340] = -2.44536780688408E-185;
	numbers[341] = 4.6357638747456025E-265;
	numbers[342] = 4.760105337318323E-290;
	numbers[343] = 1.333866469379382E-257;
	numbers[344] = -1.6008563924948793E+209;



	int xxxx = 0;


	for(int i = 0; i < 37; i++) {

	}
}
