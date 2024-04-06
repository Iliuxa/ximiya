#include <stdio.h>

int main(void)
{
    char str;
    int mode[6];




    char* filename = "D:\\Internet Exploer\\ximiya\\x64\\Debug\\VXMEPRSH.txt";

    FILE* fp = fopen(filename, "r");
    if (fp)
    {

        for (int i = 0; i < 6; i++) {
            fscanf_s(fp, "%u", &mode[i]);
            fgets(str, 80, fp);
        }


        int a = 0;
       


         

        fclose(fp);
    }







    return 0;
}