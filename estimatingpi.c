
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<float.h>

#define PI_STRING "3.141592653589793238"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void long_double_info();
void print_as_text(long double pi);

void fractions();
void francois_viete();
void john_wallis();
void john_machin();
void gregory_leibniz();
void nilakantha();

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("-----------------");
    puts("| codedrome.com |");
    puts("| Estimating Pi |");
    puts("-----------------\n");

    //long_double_info();

    //fractions();

    //francois_viete();

    //john_wallis();

    //john_machin();

    //gregory_leibniz();

    //nilakantha();

    return EXIT_SUCCESS;
}

//--------------------------------------------------------
// FUNCTION long_double_info
//--------------------------------------------------------
void long_double_info()
{
    printf("sizeof(long double) %ld\n", sizeof(long double));
    printf("LDBL_MIN            %Lg\n", LDBL_MIN);
    printf("LDBL_MAX            %Lg\n", LDBL_MAX);
    printf("LDBL_DIG            %d\n", LDBL_DIG);
}

//--------------------------------------------------------
// FUNCTION print_as_text
//--------------------------------------------------------
void print_as_text(long double pi)
{
    char pi_string[21];

    sprintf(pi_string, "%1.18Lf", pi);

    printf("Definitive %s\nCalculated ", PI_STRING);

    for(int i = 0, l = strlen(pi_string); i < l; i++)
    {
        if(pi_string[i] == PI_STRING[i])
        {
            printf(GRN "%c" RESET, pi_string[i]);
        }
        else
        {
            printf(RED "%c" RESET, pi_string[i]);
        }
    }

    puts("\n");
}

//--------------------------------------------------------
// FUNCTION fractions
//--------------------------------------------------------
void fractions()
{
    long double pi;

    pi = 22.0L / 7.0L;
    puts("22/7\n====");
    print_as_text(pi);

    pi = 333.0L / 106.0L;
    puts("333/106\n=======");
    print_as_text(pi);

    pi = 355.0L / 113.0L;
    puts("355/113\n=======");
    print_as_text(pi);

    pi = 52163.0L / 16604.0L;
    puts("52163/16604\n===========");
    print_as_text(pi);

    pi = 103993.0L / 33102.0L;
    puts("103993/33102\n============");
    print_as_text(pi);

    pi = 245850922.0L / 78256779.0L;
    puts("245850922/78256779\n==================");
    print_as_text(pi);
}

//--------------------------------------------------------
// FUNCTION francois_viete
//--------------------------------------------------------
void francois_viete()
{
    puts("Francois Viete\n==============");

    const int iterations = 28;
    long double numerator = 0.0L;
    long double pi = 1.0L;

    for(int i = 1; i <= iterations; i++)
    {
        numerator = sqrt(2.0L + numerator);

        pi*= (numerator / 2.0L);
    }

    pi = (1.0L / pi) * 2.0L;

    print_as_text(pi);
}

//--------------------------------------------------------
// FUNCTION john_wallis
//--------------------------------------------------------
void john_wallis()
{
    puts("John Wallis\n===========");

    int iterations = 1000000;
    long double numerator = 2.0L;
    long double denominator = 1.0L;
    long double pi = 1.0L;

    for(int i = 1; i <= iterations; i++)
    {
        pi*= (numerator / denominator);

        ((i%2) == 1) ? (denominator+= 2.0L) : (numerator+= 2.0L);
    }

    pi*= 2.0L;

    print_as_text(pi);
}

//--------------------------------------------------------
// FUNCTION john_machin
//--------------------------------------------------------
void john_machin()
{
    puts("John Machin\n===========");

    long double pi = (4.0L * atanl(1.0L/5.0L) - atanl(1.0L/239.0L)) * 4.0L;

    print_as_text(pi);
}

//--------------------------------------------------------
// FUNCTION gregory_leibniz
//--------------------------------------------------------
void gregory_leibniz()
{
    puts("Gregory-Leibniz\n===============");

    int iterations = 400000;
    long double denominator = 1.0L;
    long double multiplier = 1.0L;
    long double pi = (4.0L / denominator);

    for(int i = 2; i <= iterations; i++)
    {
        pi += ( (4.0L / (denominator += 2.0L)) * (multiplier *= -1.0L) );
    }

    print_as_text(pi);
}

//--------------------------------------------------------
// FUNCTION nilakantha
//--------------------------------------------------------
void nilakantha()
{
    puts("Nilakantha\n=========");

    int iterations = 50;
    long double multiplier = -1.0L;
    long double start_denominator = 2.0L;
    long double pi = 3.0L;

    for(int i = 1; i <= iterations; i++)
    {
        pi += ( (4.0L / (start_denominator * (start_denominator + 1.0L) * (start_denominator + 2.0L)) ) * (multiplier *= -1.0L));

        start_denominator += 2.0L;
    }

    print_as_text(pi);
}
