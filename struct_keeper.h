#ifndef STRUCT_KEEPER_H_INCLUDED
#define STRUCT_KEEPER_H_INCLUDED






typedef enum eng_enum {diesel=1,gas,electric}eng_type;

typedef enum transmission {akpp=0,mkpp,variator,robot}kpp;

typedef struct gas_inf {
kpp Gkpp;
float vol;
int h_pow;
} gas_eng;

typedef struct diesel_inf{
double vol;
int k_moment;
kpp Dkpp;
} diesel_eng;

typedef struct Electro_eng{
int el_pow;
int k_moment; }el_eng;

typedef union engine_type{
el_eng Eeng;
gas_eng g_eng;
diesel_eng d_eng;}engine;

typedef struct car_info {
char mark[20];
char model[20];
char body[20];
int year;
engine eng1;
eng_type type1; }car;



#endif // STRUCT_KEEPER_H_INCLUDED
