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