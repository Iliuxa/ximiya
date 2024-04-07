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

	var_ch_1[0] = 0; // õç
	var_ch_2[0] = 0; // õç

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
		printf("TANDEM for NH3");
	}

	float var_8[8];
	for (int i = 0; i < 8; i++) {
		var_8[i] = 0;
	}

	printf("FEED GAS ");

	output_ch(0, di, var_ch_2, var_8);






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
		printf("    steam¦                              ¦ prod.gas              ");
		printf("         ¦                              ¦                       ");
		printf("  feed   ¦     ã=========¬          ã==========¬  oxygen air mix");
		printf("---------+---->¦         ¦--------->¦          ¦<--------T------");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam ");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      ");
		printf("               L====T====-          L====T=====-                ");
		printf("                    ¦                    ¦                      ");
		printf("                    L---------<-----------                      ");
		break;
	case 2:
		printf("steam¦   ¦hydrogen                       ¦Prod.                 ");
		printf("     ¦   ¦fraction                       ¦gas                   ");
		printf("     ¦   ¦                               ¦                      ");
		printf(" feed¦ ã=¦=¬     ã=========¬          ã==========¬ oxygen air mi");
		printf("-----+-¦mix¦---->¦         ¦--------->¦          ¦<------T------");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam ");
		printf("<----------------¦         ¦          ¦          ¦       ¦      ");
		printf("                 L====T====-          L====T=====-              ");
		printf("                      ¦                    ¦                    ");
		printf("                      L---------<-----------                    ");
		break;
	case 3:
		printf("                     bypass                                     ");
		printf("         ------------------>-----------¬                        ");
		printf("         ¦                             ¦   ¦pr.gas              ");
		printf("         ¦                             ¦   ¦                    ");
		printf("  feed   ¦     ã=========¬          ã==¦===¦===¬ oxygen air mixt");
		printf("---------+---->¦         ¦--------->¦          ¦<--------T------");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam ");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      ");
		printf("               L====T====-          L====T=====-                ");
		printf("                    ¦                    ¦                      ");
		printf("                    L---------<-----------                      ");
		break;
	case 4:
		printf("steam¦   ¦hydrogen                                              ");
		printf("     ¦   ¦fraction       bypass                                 ");
		printf("     ¦   ¦    ------------->---------------¬                    ");
		printf(" feed¦ ã=¦=¬  ¦  ã=========¬          ã====¦=====¬ oxygen air mi");
		printf("-----+-¦mix¦--+->¦         ¦--------->¦          ¦<------T------");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam ");
		printf("<----------------¦         ¦          ¦          ¦       ¦      ");
		printf("                 L====T====-          L====T=====-              ");
		printf("                      ¦                    ¦                    ");
		printf("                      L---------<-----------                    ");
		break;
	}
}

void output_2(int mode)
{
	switch (mode)
	{
	case 1:
		printf("    steam¦                                                      ");
		printf("         ¦                                                      ");
		printf("  feed   ¦     ã=========¬          ã==========¬  oxygen air mix");
		printf("---------+---->¦         ¦--------->¦          ¦<--------T------");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam ");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      ");
		printf("               L====T====-          L====T=====-                ");
		printf("                    ¦                    ¦                      ");
		printf("                    L---------<-----------                      ");
		break;
	case 2:
		printf("steam¦   ¦hydrogen                                              ");
		printf("     ¦   ¦fraction                                              ");
		printf("     ¦   ¦                                                      ");
		printf("ñûðüå¦ ã=¦=¬     ã=========¬          ã==========¬ oxygen air mi");
		printf("-----+-¦mix¦---->¦         ¦--------->¦          ¦<------T------");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam ");
		printf("<----------------¦         ¦          ¦          ¦       ¦      ");
		printf("                 L====T====-          L====T=====-              ");
		printf("                      ¦                    ¦                    ");
		printf("                      L---------<-----------                    ");
		break;
	case 3:
		printf("                     bypass                                     ");
		printf("            --------------->--------------¬                     ");
		printf("    steam¦  ¦                             ¦                     ");
		printf("         ¦  ¦                             ¦                     ");
		printf("  feed   ¦  ¦  ã=========¬          ã=====¦====¬ oxygen air mixt");
		printf("---------+--+->¦         ¦--------->¦          ¦<--------T------");
		printf("               ¦  tube   ¦          ¦ secondary¦         ¦inject");
		printf(" conver. gas   ¦ reactor ¦          ¦ reformer ¦         ¦steam ");
		printf(" <-------------¦         ¦          ¦          ¦         ¦      ");
		printf("               L====T====-          L====T=====-                ");
		printf("                    ¦                    ¦                      ");
		printf("                    L---------<-----------                      ");
		break;
	case 4:
		printf("steam¦   ¦hydrogen                                              ");
		printf("     ¦   ¦fraction       bypass                                 ");
		printf("     ¦   ¦    ------------->---------------¬                    ");
		printf("ñûðüå¦ ã=¦=¬  ¦  ã=========¬          ã====¦=====¬ oxygen air mi");
		printf("-----+-¦mix¦--+->¦         ¦--------->¦          ¦<------T------");
		printf("       L===-     ¦  tube   ¦          ¦ secondary¦       ¦inject");
		printf(" conver. gas     ¦ reactor ¦          ¦ reformer ¦       ¦steam ");
		printf("<----------------¦         ¦          ¦          ¦       ¦      ");
		printf("                 L====T====-          L====T=====-              ");
		printf("                      ¦                    ¦                    ");
		printf("                      L---------<-----------                    ");
		break;
	}
}

void output_ch(int mode, int di, float var_2[8], float var_ch[49], float v_a[8])
{
	if (mode == 1) {
		printf("Q  = %.4f kkal/h;", v_a[5]);
	}

	if (mode != 1 && mode != 2) {

		if (v_a[0] != 0) {
			printf("T inlet  = %.1f  *C ;", v_a[0]);
		}

		if (v_a[6] != 0) {
			printf("V dry bypass gas = %.2f  m3/h;", v_a[6]);
		}

		if (v_a[7] != 0) {
			printf("V bypass steam = %.2f  m3/h ;", v_a[7]);
		}

		if (v_a[4] != 0) {
			printf("T outlet from tandem = %.1f *C ;", v_a[5]);
		}
	}

	if (var_2[1] != 0) {
		printf("steam / gas = %.4f;", var_2[1]);
	}

	if (var_ch[47] != 0) {
		printf("T = %.1f  *C ;", var_ch[47]);
	}

	if (var_ch[48] != 0) {
		printf("P = %.2f  ati;", var_ch[48]);
	}

	printf("V dry gas  = %.2f  m3/h;", var_2[0]);

	float b[6];
	for (int i = 0; i < 6; i++) {
		b[i] = var_2[i + 2] / (var_2[1] + 1);
	}

	float x1 = (var_2[1] / (var_2[1] + 1)) * 100;

	float b1[49];
	for (int i = 0; i < 49; i++) {
		b1[i] = var_ch[i] / (var_2[1] + 1);
	}

	printf("ã==========================================================¬");
	printf("¦ compo- ¦                                                 ¦");
	printf("¦ nents  ¦  moist gas %%       dry gas %%           m3/h     ¦");
	printf("¦==========================================================¦");




}