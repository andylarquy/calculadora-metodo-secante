#include <stdio.h>
#include <math.h>

void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones);
double evaluarEn(double x);
double formula(double n0, double n1);
double error(double x0, double x1);

int main(){

printf("La funcion elegida es: 3 * sen(x) + 2\n");

int i;
int iteraciones;

double a;
double b;
double c;//Variable temporal usada para las iteraciones
double chequeoAltaConvergencia;

double epsilon;

valoresIniciales(&a,&b,&epsilon,&iteraciones);

for(i = 0; i < iteraciones && error(a,b) > epsilon; i++){

    chequeoAltaConvergencia = c;
    c = formula(a,b);

    printf("\nx%d = %.15lf\n dif: %.15lf\n\n",i+2,c,error(c,b));

    a = b;
    b = c;


    if(chequeoAltaConvergencia == c){
        printf("Hay una alta convergencia en x = %.15f",c);
        break;
    }


}

}


double formula(double n0, double n1){

    double temp;
    double fx0 = evaluarEn(n0);
    double fx1 = evaluarEn(n1);
    temp = n1 - ((n1 - n0) * fx1 ) / (fx1 - fx0); //Formula con pequeña simplificacion

    return temp;


}

double evaluarEn(double x){

double temp;
temp = (3 * sin(x)) + 2;

return temp;
}


double error(double x0, double x1){
    return fabs(x1 - x0);
}




void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones){

printf("Ingrese un numero real A:\n");
scanf("%lf",a);

//Este bucle evita que A y B sean iguales
do{
    printf("Ingrese un numero real B:\n");
    scanf("%lf",b);
}while(*a == *b);


printf("Ingrese un Epsilon:\n");
scanf("%lf",epsilon);

printf("Ingrese la cantidad maxima de iteraciones:");
scanf("%d",iteraciones);

printf("\n");
}
