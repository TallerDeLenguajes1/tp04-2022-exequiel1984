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

//********************DECLARO FUNCIONES***********************************

void CrearListaVacia(Nodo **);
void CargarTarea(Nodo **Cabecera, int i, char *Buff);
void InsertarTareAlFinal(Nodo **Cabecera);
void ControlTarea(Nodo *, char *);
void MostrarLista(Nodo *);
void LiberarLista(Nodo *);

//*********************MAIN***********************************************

int main(){

    int CantidadTareasACargar;
    char *Buff;
    
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
        CargarTarea(TareasPendientes, i, Buff);
        InsertarTareAlFinal(&TareasPendientes);
    }

    //ControlTarea(&TareasRealizadas, Buff);

    printf("\n*****LISTA DE TAREAS REALIZADAS*****\n");
    MostrarLista(TareasRealizadas);

    printf("\n*****LISTA DE TAREAS PENDIENTES*****\n");
    MostrarLista(TareasPendientes);


    


    
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
    
    LiberarLista(TareasRealizadas);

    // free(PalabraClave);

    getchar();
    return 0;
}

//**************************FUNCIONES******************

void CrearListaVacia(Nodo **Lista){
    *Lista=NULL;
}

void CargarTarea(Nodo **Cabecera, int i, char *Buff){
    Nodo *TareaACargar;
    Nodo *TareaACargar = *Cabecera;
    TareaACargar = (Nodo *) malloc(sizeof(Nodo));

    TareaACargar->T.TareaID = i+1;
    printf("\nTarea %d", TareaACargar->T.TareaID);
    printf("\nDescripcion: ");
    gets(Buff);
    TareaACargar->T.Descripcion = (char *) malloc(strlen(Buff)+1 * sizeof(char));
    strcpy(TareaACargar->T.Descripcion, Buff);
    TareaACargar->T.Duracion = 10 + rand() % 100 - 10;
    printf("Duracion: %d\n", TareaACargar->T.Duracion);
    
}

void InsertarTareAlFinal(Nodo **Cabecera){
    Nodo *NodoAAgregar;
    Nodo *RecorredorDeLista = *Cabecera;

    NodoAAgregar->siguiente = NULL;
    if (RecorredorDeLista != NULL)
    {
        while (RecorredorDeLista->siguiente != NULL){
            RecorredorDeLista = RecorredorDeLista->siguiente;
        }
        RecorredorDeLista->siguiente = NodoAAgregar;
    } else{
        *Cabecera = NodoAAgregar;
    }
}



// void ControlTarea(Nodo *ListaPendiente,Nodo *ListaRealizada, char *Buff){
//     int i=0;
//     int ControlTarea; //1=Si, 0=No
//     Nodo *TareaPendienteActual;

//     TareaPendienteActual=ListaPendiente;

//     while (TareaPendienteActual!=NULL)
//     {
//         printf("\n*****CONTROL DE TAREAS PENDIENTES CARGADAS*****\n");

//         printf("\nTarea %d", ListaPendiente->T.TareaID);
//         printf("\nDescripcion: %s", ListaPendiente->T.Descripcion);
//         printf("\nDuracion: %d\n", ListaPendiente->T.Duracion);

//         printf("\n¿La tarea se realizo (Si = 1, No = 0? ");
//         scanf("%d", &ControlTarea);
//         getchar();

//         if (ControlTarea){
//             insertarnodoalfinal(tareapendienteactual, ListaRealizada);
//             quitardelista(ListaPendiente, TareaPendienteActual);
//         } 
//     }
//     i++;
// }

   // quitardelista

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