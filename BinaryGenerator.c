#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

void swap(char* a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* str_reverse(char* s){
    char* p = s;
    size_t len = strlen(s);
    char* t = s + len -1 ;
    for(int i = 0; i < len/2; i++){
        swap(s++, t--);
    }
    return p;
}

char* bin2a(size_t n){
    static char buff[MAXLEN];
    size_t idx = 0;
    memset(buff, 0, sizeof(buff));
    
    while(n > 0){
        size_t rem = n % 2;
        n /= 2;
        buff[idx++] = rem + '0';
    }
    size_t len = strlen(buff);
    for(size_t i = 0; i < 8 - len; ++i){
        buff[len + i] = '0';
    }
    str_reverse(buff);
    return buff;
}

//This function is commented out but
//can be used instead of the above one
//to generate a number at different bases.
//COMMENT THE OTHER ONE ABOVE OUT IF GENERATING NUMBERS USING DIFFERENT BASES

// char* bin2a(size_t n, int base){
//     static char buff[MAXLEN];
//     size_t idx = 0;
//     memset(buff, 0, sizeof(buff));
    
//     while(n > 0){
//         size_t rem = n % base;
//         n /= base;
//         buff[idx++] = rem + '0';
//     }
//     size_t len = strlen(buff);
//     for(size_t i = 0; i < 8 - len; ++i){
//         buff[len + i] = '0';
//     }
//     str_reverse(buff);
//     return buff;
// }


int main(int argc, const char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage:./genbin fileout\n");
        exit(1);
    }
    FILE* fout = fopen(argv[1], "w");
    
// These nested loops can only be used when wantinf to 
// generate numbers based of different bases
//IF WANT TO GENERATE USING DIFFERNT BASES USE THIS ONE
//COMMENT OUT THE ONE BELOW
//    for(size_t base  = 2; base <= 10; ++base){
//        fprintf(fout, "Base %zu ---------------------------------------------------------------\n", base);
//          for(size_t number = 0; number <= 127; ++number){
//              fprintf(fout,"%s ", bin2a(number, base));
//                   if( number % 8 == 7){
//                   fprintf(fout, "\n");
//               }
//           }
//      }
   
        
    for(size_t number = 0; number <= 127; ++number){
        fprintf(fout,"%s ", bin2a(number));
        if( number % 8 == 7){
            fprintf(fout, "\n");
        }
    }
    }
    

