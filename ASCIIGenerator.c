#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXLEN 100

int main(int argc, const char * argv[]) {

    if(argc != 2 && argc != 3){
        fprintf(stderr, "Usage:./conversion inputfile outputfile\n");
        exit(1);
    }

    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    char s[MAXLEN];
    const char* names[] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "TAB", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2","DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US", "SPACE"};
    memset(s, 0, sizeof(s));

    int ch;
    int result = 0;
    int index = 0;

    fprintf(fout, "\n Binary | ASCII | Base 10 | Parity \n");
    fprintf(fout, "--------|-------|---------|--------\n");

    while((ch=fgetc(fin)) != EOF){
        if(ch == '0' || ch == '1'){
            s[index] = ch;
            index++;
        }
        else if(ch == ' '){
            int len = strlen(s)-1;
            int power = 0;

           while(len >= 0){
                   result += (s[len] - '0') * pow(2, power);
                   power++;
                   len--;
           }
            if(result <= 32){
                fprintf(fout, "%8s %5s %7d ", s, names[result], result);
            }
            else if (result > 32 && result <127){
                fprintf(fout, "%8s %3c %9d ", s, result, result);
            }
            if(result == 127){
                fprintf(fout, "%8s   DEL %7d ", s, result);
            }
            if(result % 2 == 0){
                fprintf(fout, "      EVEN\n");
            }
            else if( result % 2 == 1){
                fprintf(fout, "      ODD\n");
            }

            //resets all the value for the next binary number
            index = 0;
            result = 0;
            memset(s, 0, sizeof(s));
        }
    }
    fclose(fin);
    fclose(fout);
}
