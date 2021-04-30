#include <iostream>

using namespace std;

int sig_primo(int);

void invertir_array(char a[],int tam);
void array_original(char array[],int num);
void array_sin_repetir(char array[],int num);
void array_solo_caracter(char array[],int num);
void array_alfanumerico(char array[],int num);
int convertir_entero(char *cadena,int i);
int invertirNumero(int num);
int suma_particiones(int valor,int n);
int **puntero_matriz,nfilas,ncol;//variables globales problema cine
void iniciarCine ();
void asientosReservados (int **puntero,int nfilas,int ncol);
void realizarReserva (int **puntero);
void cancelarReserva (int **puntero);
int cantidad_estrellas(int *dir_fila);
int sum_divisores(int numero);

int main()
{
//                 Case      1,2,3,4,5,6, 7, 8,  9
//Grupo 4 (6-7) problemas : {3,5,7,8,9,11,13,16,17}
    int opcion=1;    //en la variable opcion es el numero del ejercicio que se quiere correr

    while(opcion!=0) // este ciclo es para tener un menu de los diferentes puntos del Laboratorio #1
    {
     system("cls");
     cout <<"Menu practica 1"<<endl<<endl;
     cout <<"1. Compara 2 cadenas y retorna Verdadero o falso "<<endl;
     cout <<"2. Ingresa un numero entero y retorna una cadena de caracteres."<<endl;
     cout <<"3. Recibe una cadena de caracter y elimina los caracteres repetidos"<<endl;
     cout <<"4. Recibe una cadena de caracter y separa los enteros"<<endl;
     cout <<"5. Recibe un entero y separa en n cifras para sumar"<<endl;
     cout <<"6. Programa sala de cine"<<endl;
     cout <<"7. Cuenta las estrellas de una galaxia"<<endl;
     cout <<"8. Reciba un numero n y calcule el numero de caminos posibles en una cuadricula de nxn. "<<endl;
     cout <<"9. Halla el numero amigable de un numero n"<<endl;
     cout <<"0. para salir"<<endl;
     cout<<endl;
     cin>>opcion;

     system("cls");
     switch (opcion) {

     case 1:{//ploblema 3 - Lab-2
         //Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son iguales y falso
         // en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa de prueba.
        char cad1[30];
        char cad2[30];

        cout<<"ingrese la cadena 1: "<<endl;cin>>cad1;
        cout<<"ingrese la cadena 2:"<<endl;cin>>cad2;
        cout<<endl;
        int i=0;
        bool fal;
       
        while (cad1[i]||cad2[i]!='\0'){
            if (cad1[i]!=cad2[i]){
                fal =false;
                break;
            }
            else
                fal=true;
            i++;
        }
        if (fal==true)
            cout<<"Verdadero"<<endl;
        else
            cout<<"Falso"<<endl;

         break;
     }
     case 2:{//ploblema 5 - Lab-2
         //Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use parámetros por referencia
         //para retornar la cadena. Escriba un programa de prueba. Ej: si recibe un int con valor 123, la cadena que se retorne debe ser “123”.

        cout<<"ingrese el numero entero mayor que cero para convertir a cadena de caracter"<<endl;
        int num,i=0;
        cin>>num;
        char array[12];


        while  (num>0){
            array[i]=(num%10)+48;
            num/=10;
            i++;
        }
        invertir_array(array,i);

         break;
    }
     case 3:{//ploblema 7 - Lab-2
         //Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos. Ej: se recibe bananas debe mostrar bans.
         //Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.
        char arreglo[50];
        int i=0;
        cout<< "Ingrese su cadena para eliminar los caracteres repetidos"<<endl;
        cin >> arreglo;
        while (arreglo[i]!='\0'){//saber el tamaño del arreglo
         i++;
        }
        array_original(arreglo,i);
        array_sin_repetir(arreglo,i);
        cout<<endl;

         break;
     }
     case 4:{//ploblema 8 - Lab-2
         //Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres, generando una cadena
         //que no tiene números y otra con los números que había en la cadena original. Ej: Si se recibe abc54rst el programa debe imprimir
         //las cadenas: abcrst y 54. Nota: la salida del programa debe ser: Original: abc54rst. Texto: abcrst. Numero: 54.

        char arreglo[50];
        int i=0;
        cout<< "Ingrese su cadena para separar los caracteres de los numeros "<<endl;
        cin >> arreglo;
        while (arreglo[i]!='\0'){//contar el tamaño del arreglo
            i++;
        }
         array_original(arreglo,i);
         array_solo_caracter(arreglo,i);
         array_alfanumerico(arreglo,i);

         break;
     }
     case 5:{//ploblema 9 - Lab-2
         //Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa debe separar la cadena de
         //caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse dividir exactamente en
         //números de n cifras se colocan ceros a la izquierda del primer número. Ej: Si n=3 y se lee el arreglo 87512395 la suma seria
         //087+512+395=994. Nota: la salida del programa debe ser: Original: 87512395. Suma: 994.

        char arreglo[30];
        int n,i=0,a,b;
        cout<< "Ingrese su cadena de caracter alfanumerico "<<endl;
        cin >> arreglo;
        cout<< "Ingrese un numero en el cual quieres dividir la cadena "<<endl;
        cin >> n;

        char *cadena = arreglo;
        while (arreglo[i]!='\0'){//contar el tamaño del arreglo
                i++;
        }
        a=convertir_entero(cadena,i);
        b=invertirNumero(a);
        suma_particiones(b,n);

         break;
     }
     case 6:{//ploblema 11 - Lab-2
         // Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de la sala de cine están
         //organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación de la sala que indique que asientos
         //están disponibles y cuales se encuentran reservados. Además debe permitir realizar reservas o cancelaciones al ingresar la fila
         //(letras A-O) y el número del asiento (números 1-20). Nota: un ejemplo de visualización de una sección de la sala es el siguiente:
         //+ + + +
         //- - + +
         //+ - - - Donde + representa los asientos reservados y - representa los asientos disponibles.

        int menu =1;
        //int **puntero_matriz,nfilas=15,ncol=20;//Son variables globales

        iniciarCine(); //inicializar sala de cine
        while (menu!=0){

            cout << "*** MENU CINE ***"<<endl<<endl;
            cout << "escoge opcion: \n1 - Asientos reservados.\n2 - Realizar reserva.\n3 - Cancelar reserva.\n0 - Salir.\n";
            cout<<"Ingrese opcion ->";cin>>menu;
            switch (menu){
            case 1:
                asientosReservados (puntero_matriz,nfilas,ncol);
                break;
            case 2:
                realizarReserva (puntero_matriz);
                break;
            case 3:
                cancelarReserva (puntero_matriz);
                break;
            case 0:
                cout <<" Gracias por utilizar nuestro servicio"<<endl;
                break;
            default:
                cout<<"Valor ingresado es incorrecto"<<endl;
                break;

        }

    }

         break;
     }
     case 7:{//ploblema 13 - Lab-2
         //Se tiene una fotografía digitalizada de una porción de la galaxia NGC 1300 que está ubicada a 61.000.000 de años luz del planeta Tierra.
         //La representación digital de la imagen está constituida por una matriz de números enteros; en la cual, cada uno representa la cantidad
         //de luz en ese punto de la imagen

        // inicializo la matriz
        int matriz[6][8]={{0,3,4,0,0,0,6,8},{5,13,6,0,0,0,2,3},{2,6,2,7,3,0,10,0},
                          {0,0,4,15,4,1,6,0},{0,0,7,12,6,9,10,4},{5,0,6,10,6,4,8,0}};
        int *fila; //inicializo puntero, que apuntara a la primera fila
        fila = matriz[0]; //inicializo el puntero
        int c=0; //variale que recibira la cantidad de estrellas
        c=cantidad_estrellas(fila); //capturar la cantidad de estrellas

        cout<<"contiene : "<<c<<" estrellas."<<endl;

         //char origin[100];


         break;
     }
     case 8:{//ploblema 16 - Lab-2
         //En una malla de 2x2, realizando únicamente movimientos hacia la derecha y hacia abajo hay 6 posibles caminos para llegar de la esquina
         //superior izquierda a la inferior derecha:Escriba un programa que reciba un numero n y calcule el número de caminos posibles en una cuadricula de nxn.
         //Nota: la salida del programa debe ser: Para una malla de 2x2 puntos hay 6 caminos.

        long long int n,num=1,den=1;
        cout << "ingrese el tamaño de la malla NxN: ";cin>>n;

            //formula: (factorial de la suma de dos lados (l+l)! /
            //dividido la muntiplicacion del factorial de cada lado l! x l!
            // (l+l)! / (l! x l!)

            for (int i=1;i<=(n*2);i++){
                num*=i;
                if (i<=n){
                    den*=i;
                }
            }
            cout<<"Una maya de "<<n<<"x"<<n<<"puntos hay "<< num/(den*den)<<" caminos"<<endl;

         break;
     }
     case 9:{//ploblema 17 - Lab-2
         //Dos números a y b (a 6= b) son amigables si la suma de los divisores de a (excluyéndose el mismo) es igual a b, y viceversa.
         //Ej: los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110; y suman 284. Los divisores de 284 son 1, 2, 4, 71 y 142;
         //y suman 220. Entonces 220 y 284 son amigables. Escribir un programa que reciba un número y halle la suma de todos los números
         //amigables menores al número ingresado. Nota: la salida del programa debe ser: El resultado de la suma es: 504.
        int suma,amigable,size;
        cout<<"Ingrese un numero: "; cin>>size;
        if(size > 0){                  
           suma = sum_divisores(size);
           amigable=sum_divisores(suma);
           if (amigable==size)
                  cout<<"El resultado de la suma es: "<<(suma+amigable)<<endl;
           else
               cout <<"El numero no es amigable con ningun otro numero"<<endl;

        }
        else cout<<"Ingrese un numero positivo!"<<endl;

         break;
     }

     default:
         cout<<"opcion no valida"<<endl;
         break;

     }
     system("PAUSE");

    }
    return 0;
}

void invertir_array(char a[],int tam)//funcion para el punto 5-case 2:
{
    char aux;
    for (int i=0;i<(tam/2);i++){
        aux=a[i];
        a[i]=a[tam-1-i];
        a[tam-1-i]=aux;

    }
    cout<<"La cadena es: \"" <<a<<"\""<<endl;
}
void array_original(char array[],int num){
    cout<<"Original: ";
    for (int i=0;i<num;i++){
        cout<<array[i];
    }
    cout<<endl;
}
void array_sin_repetir(char array[],int num){
    int cont=0;
    cout<<endl<<"Sin repetidos: ";
    for(int i=0;i<num;i++){
        cont=0;
        for(int j=0;j<=i;j++){
            if(array[i]==array[j]){//compara si las posiciones en el arreglo son iguales
                cont++;
            }
        }
        if(cont==1){
            cout<<array[i];//imprime el arreglo si no esta repetido
        }
    }
    cout<<endl;
}
void array_solo_caracter(char array[],int num){

    cout<<"Texto: ";
    for(int i=0;i<num;i++){

        if((array[i]>='A' && array[i]<='Z') || (array[i]>='a' && array[i]<='z')){
            cout<<array[i];//imprime el arreglo en la posicion i, si es un caracter.
        }
    }
    cout<<endl;
}
int convertir_entero(char *cadena,int lon)//funcion que puntero del arreglo y lo convierte en un entero
{
   int i,potencia=1;
   int valor = 0;
   for(i=0;i<lon;i++){ //este condicional convierte la cadena en numero entero
       if (i==0){
           valor += (cadena[ i ]-'0');
            //cout<<valor;
       }
       else{
            valor += (cadena[i]-'0') * (potencia*=10);//[ lon-i-1 ];
            //cout<<valor;
       }
   }
   //invertirEntero(valor);
   return valor;
}

int invertirNumero(int num){

     int inv=0;
     while(num>0){
        inv=inv * 10 + (num % 10);
        num = num / 10;
     }
     return inv;
}
int suma_particiones(int valor,int n){

    int mod,total=0,pot=1,inv=0;
    while(inv<n){
        pot*=10;
        inv++;}
    while(valor!=0){
       mod=valor%pot;
       valor/=pot;
       total+=mod;
       if (mod==0 && valor!=0)
           total+=valor;
    }
    cout <<"Suma -> "<<total<<endl;

    return 0;
}

void iniciarCine (){
    nfilas=15;ncol=20;

    puntero_matriz= new int*[nfilas];
    for(int i=0; i<nfilas;i++){
        puntero_matriz[i] = new int [ncol];

    }
    for(int i=0; i<nfilas;i++){
        for(int j=0; j<ncol; j++){
            *(*(puntero_matriz+i)+j)=0;
        }

    }
}

void asientosReservados (int **puntero,int nfilas,int ncol){
    cout << endl;
    for (int i=0;i<nfilas;i++){
        cout << char(i+65)<<"-> ";
        for (int j=0; j<ncol;j++){
            cout <<*(*(puntero+i)+j)<<"  ";
        }
        cout<<endl;
    }
}


void realizarReserva (int **puntero_matriz){
    cout<<"       RESERVAR ASIENTO        "<<endl;
    char fila;
    int colum=0;

    cout<<"Ingrese fila desde A-O: ";cin>>fila;
    cout<<"Ingrese el numero del asiento: ";cin>>colum;
    int f;
    if (fila>'A' && fila<'Z')
        f =fila-65;
    else
        f=fila-97;

    *(*(puntero_matriz+f)+(colum-1))=1;
}

void cancelarReserva (int **puntero){
    cout<<"       CANCELAR ASIENTO        "<<endl;
    char fila;
    int colum=0;
    cout<<"Ingrese fila desde A-O: ";cin>>fila;
    cout<<"Ingrese el numero del asiento: ";cin>>colum;
    int f;
    if (fila>'A' && fila<'Z')
        f =fila-65;
    else
        f=fila-97;
    *(*(puntero+f)+(colum-1))=0;
}
int cantidad_estrellas(int *dir_fila){ //funcion para contar las estrellas, se le entrega un puntero que apunta a la matriz
    int *fila;
    fila=dir_fila;
    dir_fila=dir_fila + 8; //modificar el puntero de tal manera que apunta a la segunda fila, ya que no hay estrellas en los bordes de la matriz
    float estrellas[(6-2)*(8-2)]; //matriz de tamaño (filas-2)(columnas-2) donde se guardaran todas las sumas
    for(int m=0;m<(6-2)*(8-2);m++) //ciclo para llenar el arreglo de suma en 0, o inicializar el vector
    {
        estrellas[m]=0; //dar el valor de cero a todos los elementos.
    }
    int contador=0; //variable contadora de estrellas
    int p=0; //indice de arreglo "estrellas[p]"
    for(int a=1;a<5;a++) //ciclo que correra (filas-2) veces
    {
        for(int b=1;b<7;b++) //ciclo que correra (columnas - 2) veces, b = 1 porque se omiten los borden de la matriz
        {
            estrellas[p]=*(dir_fila+b)+ *(dir_fila+b+1)+ *(dir_fila+b-1) + *(dir_fila-8+b)+ *(dir_fila+8+b); //imprime el valor guardado
            if (estrellas[p]>30)
            {
                //cout<<"las estrellas son los elementos: "<<*(dir_fila+b)<<" porque suman: "<<estrellas[p]<<endl;
                contador++;
            }
        }
        dir_fila=dir_fila+8; //pasar a la siguiente fila, se pone ocho debido a que hay ocho columnas
    }

    //imprimir la matriz
    cout<<"la matriz: "<<endl;
    for(int a=0;a<6;a++) //ciclo que correra (filas-2) veces
    {
        for(int b=0;b<8;b++) //ciclo que correra (columnas - 2) veces, b = 1 porque se omiten los borden de la matriz
        {
            cout<<(fila[b])<<"  "; //imprime el valor guardado
        }
        cout<<endl;
        fila=fila+8; //pasar a la siguiente fila, se pone ocho debido a que hay ocho columnas
    }
    return contador;
}

void array_alfanumerico(char array[],int num){

    cout<<"Numero: ";
    for(int i=0;i<num;i++){

        if(array[i]>='0' && array[i]<='9'){
            cout<<array[i];//imprime el arreglo en la posicion i, si es de tipo alfanumerico.
        }
    }
    cout<<endl;
}
int sum_divisores(int numero){ //funcion para encontrar los divisores del numero
    int i, resto,suma=0;
    //cout << "Sus divisores son: ";
        for (i=1; i<numero ; i++){
            resto = numero%i;
            if (resto==0)
                {
                suma+=i;
                //cout << i << " ";
                //cout <<"Suma: "<<suma<<endl;
                }
            }
    return suma;
    }
