#include <stdio.h>
#include <math.h>

void valoresIniciales(float *a, float *b, float *epsilon, int *iteraciones);
float evaluarEn(float x);
float formula(float n0, float n1);

int main(){

printf("La funcion elegida es: 3 * sen(x) + 2\n");

int i;
int iteraciones;

float a;
float b;
float c;//Variable temporal usada para las iteraciones
float chequeoAltaConvergencia;

float epsilon;

valoresIniciales(&a,&b,&epsilon,&iteraciones);

c = formula(a,b);
printf("x1 = %.15f\n",c);

if (abs(evaluarEn(a)) < abs(evaluarEn(b))){
    float aux = a;
    a = b;
    b = aux;
}

a = c;

//TODO - Calcular el error
for(i = 0; i < iteraciones /*|| error(c) < epsilon*/; i++){

    chequeoAltaConvergencia = c;
    c = formula(a,b);



    printf("x%d = %.15f\n",i+2,c);

    if (abs(evaluarEn(a)) < abs(evaluarEn(b))){
        float aux = a;
        a = b;
        b = aux;
    }

    a = c;

    if(chequeoAltaConvergencia == c){
        printf("Hay una alta convergencia en x = %.15f",c);
        i = iteraciones; //Ya no es necessario seguir iterando
    }


}

}


float formula(float n0, float n1){

    float temp;
    temp = n1 - ((n1-n0)/(evaluarEn(n1)-evaluarEn(n0))) * evaluarEn(n1);

    return temp;


}

float evaluarEn(float x){

float temp;
temp = 3 * sin(x) + 2;

return temp;
}





void valoresIniciales(float *a, float *b, float *epsilon, int *iteraciones){

printf("Ingrese un numero real A:\n");
scanf("%f",a);

printf("Ingrese un numero real B:\n");
scanf("%f",b);

printf("Ingrese un Epsilon:\n");
scanf("%f",epsilon);

printf("Ingrese la cantidad maxima de iteraciones:");
scanf("%d",iteraciones);

}

