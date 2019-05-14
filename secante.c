#include <stdio.h>
#include <math.h>

void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones);
double evaluarEn(double x);
double formula(double n0, double n1);

int main(){

printf("La funcion elegida es: 3 * sen(x) + 2\n");

int i;
int iteraciones;

double a;
double b;
double c;//Variable temporal usada para las iteraciones
double epsilon;

valoresIniciales(&a,&b,&epsilon,&iteraciones);

c = formula(a,b);
printf("x1 = %lf\n",c);


//TODO - Calcular el error
for(i = 0; i < iteraciones /*|| error(c) < epsilon*/; i++){

    c = formula(a,b);

    printf("x%d = %lf\n",i+2,c);


    //chequeo el caso y piso la variable a o b con la informacion de c segun corresponda

    //TODO - Chequear si ya encontre la solucion

    }

}


double formula(double n0, double n1){

    double temp;
    temp = n1 - ((n1-n0)/(evaluarEn(n1)-evaluarEn(n0))) * evaluarEn(n1);

    return temp;


}

double evaluarEn(double x){

double temp;
temp = 3 * sin(x) + 2;

return temp;
}





void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones){

printf("Ingrese un numero real A:\n");
scanf("%lf",a);

printf("Ingrese un numero real B:\n");
scanf("%lf",b);

printf("Ingrese un Epsilon:\n");
scanf("%lf",epsilon);

printf("Ingrese la cantidad maxima de iteraciones:");
scanf("%d",iteraciones);

}

