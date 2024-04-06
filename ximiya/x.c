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

		if (mode[3] = 0 && mode[2] == 0) {
			x = 1;
		}

		if (mode[3] = 0 && mode[2] == 1) {
			x = 2;
		}

		if (mode[3] = 1 && mode[2] == 0) {
			x = 3;
		}

		if (mode[3] = 01 && mode[2] == 1) {
			x = 4;
		}

		if (mode[0] == 0) {
			output_2(x);
		}
		else {
			output_1(x);
		}


	}






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
		printf("Îøèáêà îòêğûòèÿ ôàéëà.\n");
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
		printf("ñûğüå¦ ã=¦=¬     ã=========¬          ã==========¬ oxygen air mi");
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
		printf("ñûğüå¦ ã=¦=¬  ¦  ã=========¬          ã====¦=====¬ oxygen air mi");
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