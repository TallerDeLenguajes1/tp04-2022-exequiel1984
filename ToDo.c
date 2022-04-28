#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Trabajo{ 
    int TareaID;    //Numerado en ciclo iterativo 
    char *Descripcion;  // 
    int Duracion; // entre 10 – 100 
}typedef Tarea;

struct TNodo{
    Tarea T;
    struct TNodo *siguiente;
} typedef Nodo;

//********************DECLARO FUNCIONES***************

void CrearListaVacia(Nodo **);
void MostrarLista(Nodo *);
void CargarListaAlFinal(Nodo **, int, char *);
void LiberarLista(Nodo *);

//*********************MAIN***************************

int main(){

    int CantidadTareasACargar;
    char *Buff;
    int ControlTarea; //1=Si, 0=No
    int ContadorTareasRealizadas = 0;
    char *PalabraClave;

    Buff = (char *) malloc(100 * sizeof(char));

    srand(time(NULL));
    Nodo *TareasPendientes, *TareasRealizadas;
    
    CrearListaVacia(&TareasPendientes);
    CrearListaVacia(&TareasRealizadas);

    printf("\nIngrese la cantidad de tareas a cargar: ");
    scanf("%d", &CantidadTareasACargar);
    getchar();

    for (int i = 0; i < CantidadTareasACargar; i++)
    {
        CargarListaAlFinal(&TareasPendientes, i, Buff);
    }
    

    printf("\n*****LISTA DE TAREAS PENDIENTES*****\n");
    MostrarLista(TareasPendientes);


    


    // printf("\n\n*****CONTROL DE TAREAS PENDIENTES CARGADAS*****\n");

        

    //     printf("\n¿La tarea se realizo (Si = 1, No = 0? ");
    //     scanf("%d", &ControlTarea);

    //     if (ControlTarea)
    //     {
    //         TareasRealizadas[ContadorTareasRealizadas] = TareasPendientes[i];
    //         TareasPendientes[i] = NULL;
    //         ContadorTareasRealizadas++;
    //     } 
    // }

    // printf("\n*****LISTA DE TAREAS REALIZADAS*****\n");

    // for (int i = 0; i < ContadorTareasRealizadas; i++)
    // {
    //     printf("\nTarea: %d", TareasRealizadas[i]->TareaID);
    //     printf("\nDescripcion: %s", TareasRealizadas[i]->Descripcion);
    //     printf("\nDuracion: %d\n", TareasRealizadas[i]->Duracion);
    // }

    // printf("\n\n*****TAREAS PENDIENTES*****\n");

    //   for (int i = 0; i < cantidadTareas; i++)
    // {
    //     if (TareasPendientes[i] != NULL)
    //     {
    //         printf("\nTarea: %d", TareasPendientes[i]->TareaID);
    //         printf("\nDescripcion: %s", TareasPendientes[i]->Descripcion);
    //         printf("\nDuracion: %d\n", TareasPendientes[i]->Duracion);
    //     }
    // }
    
    // puts("\n*****BUSCADOR DE TAREA*****");

    // printf("\nIngrese la palabra clave: ");
    // gets(Buff);

    // PalabraClave = (char *) malloc(strlen(Buff)+1 * sizeof(char));
    // strcpy(PalabraClave, Buff);

    // for (int i = 0; i < cantidadTareas; i++)
    // {
    //     if (!strcmp(PalabraClave, TareasPendientes[i]->Descripcion))
    //     {
    //         printf("Tarea Pendiente");
    //         printf("\nTarea: %d", TareasPendientes[i]->TareaID);
    //         printf("\nDescripcion: %s", TareasPendientes[i]->Descripcion);
    //         printf("\nDuracion: %d\n", TareasPendientes[i]->Duracion);
    //     } 
    // }

    //Libero memorias
    free(Buff);

    LiberarLista(TareasPendientes);
    
    
    // free(TareasRealizadas);

    // free(PalabraClave);

    getchar();
    return 0;
}

//**************************FUNCIONES******************

void CrearListaVacia(Nodo **Lista){
    *Lista=NULL;
}


void CargarListaAlFinal(Nodo **NuevoNodo, int i, char *Buff){
    Nodo *NodoAux;
    Nodo *Aux2 = *NuevoNodo;
    NodoAux = (Nodo *) malloc(sizeof(Nodo));

    NodoAux->T.TareaID = i+1;
    printf("\nTarea %d", NodoAux->T.TareaID);
    printf("\nDescripcion: ");
    gets(Buff);
    NodoAux->T.Descripcion = (char *) malloc(strlen(Buff)+1 * sizeof(char));
    strcpy(NodoAux->T.Descripcion, Buff);
    NodoAux->T.Duracion = 10 + rand() % 100 - 10;
    printf("Duracion: %d\n", NodoAux->T.Duracion);

    NodoAux->siguiente = NULL;
    if (Aux2 != NULL)
    {
        while (Aux2->siguiente != NULL)
        {
            Aux2 = Aux2->siguiente;
        }
        Aux2->siguiente = NodoAux;
    } else{
        *NuevoNodo = NodoAux;//estoy cargando al final de la fila
    }
}

void MostrarLista(Nodo *Lista){
    int i=0;

    while (Lista!=NULL)
    {
        printf("\nTarea %d", Lista->T.TareaID);
        printf("\nDescripcion: %s", Lista->T.Descripcion);
        printf("\nDuracion: %d\n", Lista->T.Duracion);

        Lista = Lista->siguiente;
        i++;
    }
}

void LiberarLista(Nodo *Lista){
    Nodo *Aux;
    while (Lista != NULL)
    {
        Aux = Lista;
        Lista = Lista->siguiente;
        free(Aux->T.Descripcion);
        free(Aux);
    }
    
}