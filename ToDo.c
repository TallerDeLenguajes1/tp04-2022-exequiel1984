#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Tarea { 
    int TareaID;    //Numerado en ciclo iterativo 
    char *Descripcion;  // 
    int Duracion; // entre 10 – 100 
};

void buscarTarea(struct Tarea **, struct Tarea **, int, char *);

int main(){
    int cantidadTareas,j;
    struct Tarea **TareasPendientes;
    struct Tarea **TareasRealizadas;
    char *Buff;
    int ControlTarea; //1=Si, 0=No
    int ContadorTareasRealizadas = 0;
    char *PalabraClave;

    srand(time(NULL));

    Buff = (char *) malloc(100 * sizeof(char));

    printf("\nIngrese la cantidad de tareas a cargar: ");
    scanf("%d", &cantidadTareas);
    getchar();
//Reservo memoria de tareas pendientes
    TareasPendientes = (struct Tarea **) malloc(cantidadTareas * sizeof(struct Tarea *));
    TareasRealizadas = (struct Tarea **) malloc(cantidadTareas * sizeof(struct Tarea*));

    for (int i = 0; i < cantidadTareas; i++)
    {
        TareasPendientes[i] = (struct Tarea *) malloc(sizeof(struct Tarea));
    }
    
//Cargo datos

    for (int i = 0; i < cantidadTareas; i++)
    {
        TareasPendientes[i]->TareaID = i+1;
        printf("\nTarea %d", TareasPendientes[i]->TareaID);
        printf("\nDescripcion: ");
        gets(Buff);

        TareasPendientes[i]->Descripcion = (char *) malloc(strlen(Buff)+1 * sizeof(char));
        strcpy(TareasPendientes[i]->Descripcion, Buff);

        TareasPendientes[i]->Duracion = 10 + rand() % 100 - 10;

        printf("Duracion: %d\n", TareasPendientes[i]->Duracion);
    }

//Muestro tareas cargadas
    printf("\n\n*****CONTROL DE TAREAS PENDIENTES CARGADAS*****\n");

    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("\nTarea %d", TareasPendientes[i]->TareaID);
        printf("\nDescripcion: %s", TareasPendientes[i]->Descripcion);
        printf("\nDuracion: %d", TareasPendientes[i]->Duracion);

        printf("\n¿La tarea se realizo (Si = 1, No = 0? ");
        scanf("%d", &ControlTarea);

        if (ControlTarea)
        {
            TareasRealizadas[ContadorTareasRealizadas] = TareasPendientes[i];
            TareasPendientes[i] = NULL;
            ContadorTareasRealizadas++;
        } 
    }

    printf("\n*****LISTA DE TAREAS REALIZADAS*****\n");

    for (int i = 0; i < ContadorTareasRealizadas; i++)
    {
        printf("\nTarea: %d", TareasRealizadas[i]->TareaID);
        printf("\nDescripcion: %s", TareasRealizadas[i]->Descripcion);
        printf("\nDuracion: %d\n", TareasRealizadas[i]->Duracion);
    }

    printf("\n\n*****TAREAS PENDIENTES*****\n");

      for (int i = 0; i < cantidadTareas; i++)
    {
        if (TareasPendientes[i] != NULL)
        {
            printf("\nTarea: %d", TareasPendientes[i]->TareaID);
            printf("\nDescripcion: %s", TareasPendientes[i]->Descripcion);
            printf("\nDuracion: %d\n", TareasPendientes[i]->Duracion);
        }
    }
    
    puts("\n*****BUSCADOR DE TAREA*****");

    printf("\nIngrese la palabra clave: ");
    gets(Buff);

    PalabraClave = (char *) malloc(strlen(Buff)+1 * sizeof(char));
    strcpy(PalabraClave, Buff);

    for (int i = 0; i < cantidadTareas; i++)
    {
        if (!strcmp(PalabraClave, TareasPendientes[i]->Descripcion))
        {
            printf("Tarea Pendiente");
            printf("\nTarea: %d", TareasPendientes[i]->TareaID);
            printf("\nDescripcion: %s", TareasPendientes[i]->Descripcion);
            printf("\nDuracion: %d\n", TareasPendientes[i]->Duracion);
        } 
    }

    //Libero memorias
    free(Buff);

    for (int i = 0; i < cantidadTareas; i++)
    {
        free(TareasPendientes[i]);
    }
    
    free(TareasPendientes);
    
    free(TareasRealizadas);

    free(PalabraClave);

    getchar();
    return 0;
}