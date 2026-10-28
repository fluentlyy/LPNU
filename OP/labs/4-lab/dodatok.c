#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
    time_t rawtime;
    time(&rawtime);
    struct tm *info = localtime(&rawtime);  

    FILE *log;

    log = fopen("app.log", "a");
    if(log != NULL){
        fprintf(log, "[%04d.%02d.%02d %02d:%02d:%02d] Program started.\n",
                info->tm_year + 1900, 
                info->tm_mon + 1, 
                info->tm_mday,
                info->tm_hour, 
                info->tm_min, 
                info->tm_sec);
        fclose(log);
    }


    double parametrs_output[2] = {4.8, 0.512};
    double parametrs_input[2];
    int userOutputChoise;
    
    char inputFilename[256];

    printf("Enter a name of file which you want to input(example: input.bin): ");
    scanf("%s", inputFilename);

    FILE *pIFile = fopen(inputFilename, "wb");
    fwrite(parametrs_output, sizeof(double), 2, pIFile);
    fclose(pIFile);

    FILE *pIFile1 = fopen(inputFilename, "rb");
    fread(parametrs_input, sizeof(double), 2, pIFile1);
    fclose(pIFile1);

    double x = parametrs_input[0];
    double z = parametrs_input[1];

    log = fopen("app.log", "a");
    if(log != NULL){
        fprintf(log, "[%04d.%02d.%02d %02d:%02d:%02d] Parameters file 'C:\\Documents:\\Github:\\LPNU:\\OP:\\labs:\\4-lab:\\%s' opened. X=%f, Z=%f.\n",
                info->tm_year + 1900, 
                info->tm_mon + 1, 
                info->tm_mday,
                info->tm_hour, 
                info->tm_min, 
                info->tm_sec, inputFilename, x, z);
        fclose(log);
    }

    double b = sqrt(exp(x - 1.0 / sin(z)));

    log = fopen("app.log", "a");
    if(log != NULL){
        fprintf(log, "[%04d.%02d.%02d %02d:%02d:%02d] Expression calculated. Result = %lf.\n",
                info->tm_year + 1900, 
                info->tm_mon + 1, 
                info->tm_mday,
                info->tm_hour, 
                info->tm_min, 
                info->tm_sec, b);
        fclose(log);
    }

    printf("Enter type of file you want to output(0 - binary | 1 - text): ");
    scanf("%d", &userOutputChoise);

    if(userOutputChoise == 1){
        FILE *pOFile = fopen("output.txt", "w");
        fprintf(pOFile, "Result: %lf\n", b);
        fclose(pOFile);

        log = fopen("app.log", "a");
        if(log != NULL){
        fprintf(log, "[%04d.%02d.%02d %02d:%02d:%02d] Output file 'C:\\Documents:\\Github:\\LPNU:\\OP:\\labs:\\4-lab:\\output.txt' saved.\n",
                info->tm_year + 1900, 
                info->tm_mon + 1, 
                info->tm_mday,
                info->tm_hour, 
                info->tm_min, 
                info->tm_sec, b);
        fclose(log);
        }
    }else if(userOutputChoise == 0){
        FILE *pOFile = fopen("output.bin", "wb");
        fwrite(&b, sizeof(double), 1, pOFile);
        fclose(pOFile);

        log = fopen("app.log", "a");
        if(log != NULL){
        fprintf(log, "[%04d.%02d.%02d %02d:%02d:%02d] Output file 'C:\\Documents:\\Github:\\LPNU:\\OP:\\labs:\\4-lab:\\output.bin' saved.\n",
                info->tm_year + 1900, 
                info->tm_mon + 1, 
                info->tm_mday,
                info->tm_hour, 
                info->tm_min, 
                info->tm_sec, b);
        fclose(log);
        }
    }else{
        printf("Error, incorrect input");
    }
    log = fopen("app.log", "a");
    if(log != NULL){
        fprintf(log, "[%04d.%02d.%02d %02d:%02d:%02d] Program ended.\n",
                info->tm_year + 1900, 
                info->tm_mon + 1, 
                info->tm_mday,
                info->tm_hour, 
                info->tm_min, 
                info->tm_sec);
        fclose(log);
    }
    

    return 0;
}