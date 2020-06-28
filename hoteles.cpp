#include <iostream>
using namespace std;

#define CANT_DESTINOS 30
#define CANT_HABITACIONES 60

struct ST_DESTINOS{

    string nombreDestino;
    string descripcion;
    string pais;
    char temporada;
    int hoteles;
};

struct ST_HABITACION{

    int numeroHabitacion;
    int cantOcupantes;
    char estado;
};

int buscarDestino(ST_DESTINOS vecDestinos[], string destino){

    int n = CANT_DESTINOS;
    int inicio = 0;
    int fin = n - 1;

    while (fin >= inicio){
        int mitad = inicio + (fin - inicio) / 2;
        
        if (vecDestinos[mitad].nombreDestino == destino)
            return mitad;

        if (vecDestinos[mitad].nombreDestino > destino){
            fin = mitad - 1;
        }
        else{
            inicio = mitad + 1;
        }
    }

    return -1;
}

void ordenarDestinos(ST_DESTINOS vecDestinos[]){

   ST_DESTINOS aux; 
   int n = CANT_DESTINOS;

   for (int i = 0; i < n-1; i++) {
      
      for (int j = 0; j < n-i-1; j++){

         if (vecDestinos[j].nombreDestino > vecDestinos[j+1].nombreDestino){

              aux = vecDestinos[j];
              vecDestinos[j] = vecDestinos[j+1];
              vecDestinos[j+1] = aux;
            }
        }
    }

    return;
}

void imprimirDestinosMasOcupados(ST_DESTINOS vecDestinos[], int mayor, int medio, int menor, string temporada, int ocupadas[]){

    cout << "Los 3 destinos más ocupados de " << temporada  << " son: " << endl;

    cout << "1- " << vecDestinos[mayor].nombreDestino << " - " << ocupadas[mayor] << " habitaciones ocupadas" << endl;
    cout << "2- " << vecDestinos[medio].nombreDestino << " - " << ocupadas[medio] << " habitaciones ocupadas" << endl;
    cout << "3- " << vecDestinos[menor].nombreDestino << " - " << ocupadas[menor] << " habitaciones ocupadas" << endl;
    cout << endl;

    return;
}

void calcularTresDestinosMayores(int i, int cantHabitacionesOcupadas[], int& habitacionMayor, int& habitacionMedio, int& habitacionMenor, int& posFinalMayor, int& posFinalMedio, int& posFinalMenor){

    if(cantHabitacionesOcupadas[i] > habitacionMayor){

        posFinalMenor = posFinalMedio;
        habitacionMedio = habitacionMayor;
        posFinalMedio = posFinalMayor;

        habitacionMayor = cantHabitacionesOcupadas[i];
        posFinalMayor = i;
                
    }
    else if(cantHabitacionesOcupadas[i] > habitacionMedio){

        habitacionMenor = habitacionMedio;
        posFinalMenor = posFinalMedio;

        habitacionMedio = cantHabitacionesOcupadas[i];
        posFinalMedio = i;
    }
    else if(cantHabitacionesOcupadas[i] > habitacionMenor){

        habitacionMenor = cantHabitacionesOcupadas[i];
        posFinalMenor = i;
    }

    return;
}

int sumatoriaDeHabitaciones(int posicion, ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES], int& ocupadas){

    ocupadas = 0;

    for(int j = 0; j < CANT_HABITACIONES; j++){

        if(matHabitaciones[posicion][j].estado == 'O'){

            ocupadas += 1;
        }
    }

    return ocupadas;
}

void destinosMayorOcupacion(ST_DESTINOS vecDestinos[], ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES]){

    string temporada;
    int habitacionesOcupadas = 0;
    int habitacionMayor = 0, habitacionMedio = 0, habitacionMenor = 0;
    int posFinalMayor = 0, posFinalMedio = 0, posFinalMenor = 0;
    int cantHabitacionesOcupadas[CANT_DESTINOS];

    cout << "Ingrese una temporada (Invierno o Verano): ";
    cin >> temporada;
    cout << endl;

    for(int i = 0; i < CANT_DESTINOS; i++){

        if(vecDestinos[i].temporada == 'I' && temporada == "Invierno"){
 
            cantHabitacionesOcupadas[i] = sumatoriaDeHabitaciones(i, matHabitaciones, habitacionesOcupadas);
            calcularTresDestinosMayores(i, cantHabitacionesOcupadas, habitacionMayor, habitacionMedio, habitacionMenor, posFinalMayor, posFinalMedio, posFinalMenor);

        }   
        else if(vecDestinos[i].temporada == 'V' && temporada == "Verano"){    

            cantHabitacionesOcupadas[i] = sumatoriaDeHabitaciones(i, matHabitaciones, habitacionesOcupadas);
            calcularTresDestinosMayores(i, cantHabitacionesOcupadas, habitacionMayor, habitacionMedio, habitacionMenor, posFinalMayor, posFinalMedio, posFinalMenor); 
        }
    }

    imprimirDestinosMasOcupados(vecDestinos, posFinalMayor, posFinalMedio, posFinalMenor, temporada, cantHabitacionesOcupadas);

    return;
}

void imprimirHabitacionLiberada(ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES], int posDestino, int habitacion){

    if(posDestino > -1){

        matHabitaciones[posDestino][habitacion - 1].estado = 'D';

        cout << endl;
        cout << "HABITACION LIBERADA!" << endl;
        cout << endl;

        cout << "El numero de la habitación libre es el: " << matHabitaciones[posDestino][habitacion - 1].numeroHabitacion << endl;
        cout << endl;
    }
    else{
        cout << "El destino no existe" << endl;
        cout << endl;
    }

    return;
}

void liberarHabitacion(ST_DESTINOS vecDestinos[], ST_HABITACION matHabitacion[CANT_DESTINOS][CANT_HABITACIONES]){
    
    string destino;
    int habitacion;

    cout << "Ingrese el destino: ";
    cin >> destino;

    cout << "Ingrese el número de la habitación a desocupar: ";
    cin >> habitacion;
    
    ordenarDestinos(vecDestinos);
    int posDestino = buscarDestino(vecDestinos, destino);
    imprimirHabitacionLiberada(matHabitacion, posDestino, habitacion);

    return;
}

void imprimirHabitacionReservada(int posDestino, int posHabitacionLibre, ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES]){

    if(posDestino > -1){

        if(posHabitacionLibre > -1){

              matHabitaciones[posDestino][posHabitacionLibre].estado = 'O';

              cout << "HABITACION RESERVADA!" << endl;
              cout << endl;

              cout << "El numero de habitación es el: " << matHabitaciones[posDestino][posHabitacionLibre].numeroHabitacion << endl;
              cout << endl;
        }
        else{
            cout << "No hay habitaciones disponibles" << endl;
            cout << endl;
        }     
    }
    else{
        cout << "El destino no existe" << endl;
        cout << endl;
    }

    return;
}

int buscarHabitacionLibre(ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES], int cantPersonas, int posDestino){
    
    for(int i = 0; i < CANT_HABITACIONES; i++){

        if((cantPersonas <= matHabitaciones[posDestino][i].cantOcupantes) 
            && (matHabitaciones[posDestino][i].estado == 'D')){

           return i;
        }
    }

    return -1;
}

void reservarHabitacion(ST_DESTINOS vecDestinos[], ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES]){

    string destino;
    int cantPersonas;

    cout << "¿A que destino desea ir?: ";
    cin >> destino;

    cout << "¿Cuantas personas son?: ";
    cin >> cantPersonas;
    cout << endl;

    ordenarDestinos(vecDestinos);
    int posDestino = buscarDestino(vecDestinos, destino);
    int posHabitacionLibre = buscarHabitacionLibre(matHabitaciones, cantPersonas, posDestino);
    imprimirHabitacionReservada(posDestino, posHabitacionLibre, matHabitaciones);

    return;
}

void menu(ST_DESTINOS vecDestinos[], ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES]){

    int opcion = 0;

    while(opcion != 4){

        switch(opcion){

          case 1: reservarHabitacion(vecDestinos, matHabitaciones);
          break;
          case 2: liberarHabitacion(vecDestinos, matHabitaciones);
          break;
          case 3: destinosMayorOcupacion(vecDestinos, matHabitaciones);
          break;
          default:
          break;
        }   

        cout << "1- Reservar Habitación" << endl;
        cout << "2- Liberar Habitación" << endl;
        cout << "3- Consultar Destinos Más Ocupados" << endl;
        cout << "4- Salir" << endl;
        cout << endl;

        cout << "Elija una opción: ";
        cin >> opcion;
        cout << endl;
    }

    cout << "¡Hasta Luego!" << endl;

    return;
}

void cargarHabitaciones(ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES]);

void cargarDestinos(ST_DESTINOS vecDestinos[]);

void cargarHoteles(ST_HOTELES vecHoteles[]);

int main(){

    ST_DESTINOS vecDestinos[CANT_DESTINOS];
    ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES];

    cargarDestinos(vecDestinos);

    cargarHabitaciones(matHabitaciones);

    menu(vecDestinos, matHabitaciones);

    return 0;
}

void cargarDestinos(ST_DESTINOS vecDestinos[]){

    int k = 0;

    vecDestinos[k++] = {"Bariloche",  "****", "Argentina", 'I'};
    vecDestinos[k++] = {"Brasilia",   "****", "Brasil",    'V'};
    vecDestinos[k++] = {"Santiago",   "****", "Chile",     'I'};
    vecDestinos[k++] = {"Asuncion",   "****", "Paraguay",  'V'};
    vecDestinos[k++] = {"Montevideo", "****", "Uruguay",   'I'};
    vecDestinos[k++] = {"Cochabamba", "****", "Bolivia",   'V'};
    vecDestinos[k++] = {"Lima",       "****", "Perú",      'I'};
    vecDestinos[k++] = {"Bogota",     "****", "Colombia",  'V'};
    vecDestinos[k++] = {"Quito",      "****", "Ecuador",   'I'};
    vecDestinos[k++] = {"Caracas",    "****", "Venezuela", 'V'};
    vecDestinos[k++] = {"Cancun",     "****", "México",    'I'};
    vecDestinos[k++] = {"Miami",      "****", "USA",       'V'};
    vecDestinos[k++] = {"Lisboa",     "****", "Portugal",  'I'};
    vecDestinos[k++] = {"Barcelona",  "****", "España",    'V'};
    vecDestinos[k++] = {"Paris",      "****", "Francia",   'I'};
    vecDestinos[k++] = {"Napoles",    "****", "Italia",    'V'};
    vecDestinos[k++] = {"Bruselas",   "****", "Bélgica",   'I'};
    vecDestinos[k++] = {"Amsterdam",  "****", "Holanda",   'V'};
    vecDestinos[k++] = {"Londres",    "****", "Inglaterra",'I'};
    vecDestinos[k++] = {"Dublin",     "****", "Irlanda",   'V'};
    vecDestinos[k++] = {"Berlin",     "****", "Alemania",  'I'};
    vecDestinos[k++] = {"Varsovia",   "****", "Polonia",   'V'};
    vecDestinos[k++] = {"Ginebra",    "****", "Suiza",     'I'};
    vecDestinos[k++] = {"Oslo",       "****", "Noruega",   'V'};
    vecDestinos[k++] = {"Estocolmo",  "****", "Suecia",    'I'};
    vecDestinos[k++] = {"Helsinki",   "****", "Finlandia", 'V'};
    vecDestinos[k++] = {"Moscu",      "****", "Rusia",     'I'};
    vecDestinos[k++] = {"Shanghai",   "****", "China",     'V'};
    vecDestinos[k++] = {"Tokyo",      "****", "Japón",     'I'};
    vecDestinos[k++] = {"Melbourne",  "****", "Australia", 'V'};

    return;
}

void cargarHabitaciones(ST_HABITACION matHabitaciones[CANT_DESTINOS][CANT_HABITACIONES]){
    
    for(int i = 0; i < CANT_DESTINOS; i++){

         for(int j = 0; j < CANT_HABITACIONES; j++){

           //CARGA NUMERO DE HABITACIONES
           matHabitaciones[i][j].numeroHabitacion = j + 1;

           //CARGA ESTADO DE LAS HABITACIONES. LAS IMPARES QUEDAN OCUPADAS Y LAS PARES DISPONIBLES
           if((j + 1) % 2 == 0){
             matHabitaciones[i][j].estado = 'D';
           }
           else{
             matHabitaciones[i][j].estado = 'O';
            }
        
           //CARGA LA CANTIDAD DE OCUPANTES DE LAS HABITACIONES
           if(matHabitaciones[i][j].numeroHabitacion >= 1 && matHabitaciones[i][j].numeroHabitacion <= 20){

             matHabitaciones[i][j].cantOcupantes = 2;
            }
            else if(matHabitaciones[i][j].numeroHabitacion >= 21 && matHabitaciones[i][j].numeroHabitacion <= 40){
            
               matHabitaciones[i][j].cantOcupantes = 4;
            }
            else{
                matHabitaciones[i][j].cantOcupantes = 8;
            }
        }
    }

    return;
}
