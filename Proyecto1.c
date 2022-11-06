#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct fecha
{
    int AAAA;
    int MM; 
    int DD;
}fecha;

typedef struct cliente
{
    int idCliente;
    char Nombre[30];
    char ApPaterno[30];
    char ApMaterno[30];
    fecha date;
    double Credito;
    double Deuda;
}cliente;

int ValidarFecha(int AAAA, int MM, int DD)
{
    //Verificar año
    if(AAAA>=1000 && AAAA<=9999)
    {
        //Verificar mes
        if(MM>=1 && MM<=12)
        {
            //Verificar dia
            if(DD>=1 && DD<=31) 
            {
                printf("Fecha Valida.\n");
                return 1;
            }
            else
            {
                printf("Dia no valido.\n");
                return 0;
            }
        }
        else
        {
            printf("Mes no valido.\n");
            return 0;
        }
    }
    else
    {
        printf("Ano no valido.\n");
        return 0;
    }

}

int ValidarID(int id)
{
    cliente c;
    FILE *fp;

    fp = fopen("Clientes.txt","r");

    while(fread(&c,sizeof(cliente),1,fp)>0)
        if(c.idCliente==id)
            return 0;
    
    fclose(fp);
    return 1;
  
}

void Crear()
{
    cliente c;
    char otro;
    FILE *fp;
    int n,i;

    do{
    printf("\t\t\t\t=======Escribe la informacion del Cliente=======\n\n\n"); 
    fp = fopen("Clientes.txt","a");
  
        fflush(stdin);
        printf("\nIntroduce el id del cliente: ");
        scanf("%d",&c.idCliente);

            if( !ValidarID(c.idCliente))
            {
                printf("\nID invalido, adios.\n");
                break;
            }

        fflush(stdin);
        printf("\nIntroduce el nombre del cliente: ");
        scanf("%s",&c.Nombre);
        fflush(stdin);
        printf("\nIntroduce el apellido paterno del cliente: ");
        scanf("%s",&c.ApPaterno);
        fflush(stdin);
        printf("\nIntroduce el apellido materno del cliente: ");
        scanf("%s",&c.ApMaterno);
        fflush(stdin);
        printf("\nIntroduce la fecha de registro (AAAA/MM/DD): ");
        scanf("%d/%d/%d",&c.date.AAAA,&c.date.MM,&c.date.DD);
            if(!ValidarFecha(c.date.AAAA,c.date.MM,c.date.DD))
            {
                printf("\nFecha no valida, adios.\n");
                break;
            }
        fflush(stdin);
        printf("\nIntroduce el credito del cliente: ");
        scanf("%lf",&c.Credito);
            if(c.Credito < 0)
            {
                printf("\nCredito no valido, adios.\n");
                break;
            }
        printf("\nCredito valido.");
        fflush(stdin);
        printf("\nIntroduce la deuda del cliente: ");
        scanf("%lf",&c.Deuda);
            if(c.Deuda < 0)
            {
                printf("\nDeuda no valida, adios.\n");
                break;
            }
        printf("\nDeuda valida.");
        printf("\n\t\t\t______________________________\n");

    if(fp == NULL)
        fprintf(stderr,"\nNo se puede abrir el archivo.");
    else 
        printf("\t\t\tRegistro guardado satisfactoriamente.");

    
    fwrite(&c, sizeof(cliente),1,fp);
    fclose(fp);

    printf("\n\t\t\tQuieres agregar otro registro? (s/n): ");
    scanf("%s",&otro);

    }while(otro == 'S' || otro == 's');
}

void Desplegar()
{
    FILE *fp;
    cliente c;
    int op;
    fp=fopen("Clientes.txt","r");
    
    printf("\t\t\t\t=======Registro Clientes=======\n\n\n");
      
    if(fp==NULL)
    {
        fprintf(stderr,"No se puede abrir el archivo.\n");
        exit(0);
    }
    else
        printf("=====MENU REGISTRO=====\n");

    
            printf("\n1. Mostrar id");
            printf("\n2. Mostrar Nombre");
            printf("\n3. Mostrar Apellido Paterno");
            printf("\n4. Mostrar Apellido Materno");
            printf("\n5. Mostrar fecha de registro");
            printf("\n6. Mostrar credito");
            printf("\n7. Mostrar deuda");
            printf("\n8. Mostrar todos los datos");
            printf("\n0. Salir");

            printf("\nIntroduce tu eleccion: ");
            scanf("%d",&op);

                switch (op)
                {
                case 1:
                    while(fread(&c,sizeof(cliente),1,fp))
                        printf("\n\t\t\t\t ID            : %d",c.idCliente);
                            fclose(fp);
                    break;
                case 2:
                    while(fread(&c,sizeof(cliente),1,fp))
                        printf("\n\t\t\t\t Nombre        : %s",c.Nombre);
                            fclose(fp);
                    break;
                case 3:
                    while(fread(&c,sizeof(cliente),1,fp))
                        printf("\n\t\t\t\t Ap. Paterno   : %s",c.ApPaterno);
                            fclose(fp);
                    break;
                case 4:
                    while(fread(&c,sizeof(cliente),1,fp))
                        printf("\n\t\t\t\t Ap. Materno   : %s",c.ApMaterno);
                            fclose(fp);
                    break;
                case 5:
                    while(fread(&c,sizeof(cliente),1,fp))
                        printf("\n\t\t\t\t Fecha registro: %d/%d/%d",c.date.AAAA,c.date.MM,c.date.DD);
                            fclose(fp);
                    break;
                case 6:
                    while(fread(&c,sizeof(cliente),1,fp))
                        printf("\n\t\t\t\t Credito       : %lf",c.Credito);
                            fclose(fp);
                    break;
                case 7:
                    while(fread(&c,sizeof(cliente),1,fp))
                        printf("\n\t\t\t\t Deuda         : %lf",c.Deuda);
                            fclose(fp);
                    break;
                case 8:
                    while(fread(&c,sizeof(cliente),1,fp))
                    {
                        printf("\n\t\t\t\t Nombre        : %s",c.Nombre);
                        printf("\n\t\t\t\t Ap. Paterno   : %s",c.ApPaterno);
                        printf("\n\t\t\t\t Ap. Materno   : %s",c.ApMaterno);
                        printf("\n\t\t\t\t Fecha registro: %d/%d/%d",c.date.AAAA,c.date.MM,c.date.DD);
                        printf("\n\t\t\t\t ID            : %d",c.idCliente);
                        printf("\n\t\t\t\t Credito       : %lf",c.Credito);
                        printf("\n\t\t\t\t Deuda         : %lf",c.Deuda);
                        printf("\n\t\t\t\t ________________________________\n");
                    }
                        fclose(fp);
                    break;
                case 0:
                    printf("\nSaliendo al menu principal...\n");
                            fclose(fp);
                    break;
                default:
                    printf("\n\t\t\t\t\tIntroduce un numero valido\n\n");
                    printf("\t\t\t\tPresiona cualquier tecla para continuar.......");
                    getch();
                    break;
                }
      
}

void Buscar()
{
    cliente c;
    FILE *fp;
    int id,Encontrado=0;

    fp = fopen("Clientes.txt","r");
    printf("\t\t\t\t=======BUSCAR REGISTRO DE CLIENTE=======\n\n\n");
    printf("\t\t\tIntroduce el id del cliente : ");

    scanf("%d",&id);

    while(fread(&c,sizeof(cliente),1,fp)>0)
    { 
        if(c.idCliente==id)
        {
        Encontrado=1;
        printf("\n\t\t\t\t Nombre        : %s %s %s",c.Nombre,c.ApPaterno,c.ApMaterno);
        printf("\n\t\t\t\t Fecha registro: %d/%d/%d",c.date.AAAA,c.date.MM,c.date.DD);
        printf("\n\t\t\t\t ID            : %d",c.idCliente);
        printf("\n\t\t\t\t Credito       : %lf",c.Credito);
        printf("\n\t\t\t\t Deuda         : %lf",c.Deuda);
        printf("\n\t\t\t\t ________________________________\n");
        }
    }   

    if(!Encontrado)
    printf("\n\t\t\tRegistro no encontrado.\n");

    fclose(fp);
}

void BuscarNombre()
{
    cliente c;
    FILE *fp;
    int Encontrado=0;
    char name[30];

    fp = fopen("Clientes.txt","r");
    printf("\t\t\t\t=======BUSCAR REGISTRO DE CLIENTE=======\n\n\n");
    printf("\t\t\tIntroduce el nombre del cliente : ");

    scanf("%s",&name);

    while(fread(&c,sizeof(cliente),1,fp)>0)
    { 
        if(strcmp(name,c.Nombre)==0)
        {
        Encontrado=1;
        printf("\n\t\t\t\t Nombre        : %s %s %s",c.Nombre,c.ApPaterno,c.ApMaterno);
        printf("\n\t\t\t\t Fecha registro: %d/%d/%d",c.date.AAAA,c.date.MM,c.date.DD);
        printf("\n\t\t\t\t ID            : %d",c.idCliente);
        printf("\n\t\t\t\t Credito       : %lf",c.Credito);
        printf("\n\t\t\t\t Deuda         : %lf",c.Deuda);
        printf("\n\t\t\t\t ________________________________\n");
        }
    }   

    if(!Encontrado)
    printf("\n\t\t\tRegistro no encontrado.\n");

    fclose(fp);
}

void Borrar()
{
    cliente c;
    FILE *fp, *fp1;
       
    int id,Encontrado=0;
    
    printf("\t\t\t\t======BORRAR REGISTRO DE CLIENTE=======\n\n\n");
    fp=fopen("Clientes.txt","r");
    fp1=fopen("temp.txt","w");

    printf("\t\t\t\tIntroduce el id del cliente : ");
    fflush(stdin);
    scanf("%d",&id);
    
    if(fp==NULL){
        fprintf(stderr,"No se puede abrir el archivo\n");
        exit(0);
      }
    
    while(fread(&c,sizeof(cliente),1,fp))
    {
        if(c.idCliente == id)
            Encontrado=1;
        else
           fwrite(&c,sizeof(cliente),1,fp1);
    }
    fclose(fp);
    fclose(fp1);

    if(!Encontrado)
        printf("\n\t\t\t\tRegistro no encontrado\n");
    
    if(Encontrado)
    { 
        remove("Clientes.txt");
        rename("temp.txt","Clientes.txt");
        
        printf("\n\t\t\t\tRegistro borrado satisfactoriamente\n");
    }
}

void Modificar()
{
    cliente c;
    FILE *fp,*fp1;
    int id,Encontrado=0,op;

    fp = fopen("Clientes.txt","r");
    fp1 = fopen("temp.txt","w");
    printf("\t\t\t\t=======ACTUALIZAR REGISTRO DE CLIENTE=======\n");
    printf("\t\t\tIntroduce el id del cliente : ");

    scanf("%d",&id);

    while(fread(&c,sizeof(cliente),1,fp)>0)
    { 
        if(c.idCliente==id)
        {
        Encontrado=1;

            do
            {
            printf("\n1. Modificar id");
            printf("\n2. Modificar Nombre");
            printf("\n3. Modificar Apellido Paterno");
            printf("\n4. Modificar Apellido Materno");
            printf("\n5. Modificar fecha de registro");
            printf("\n6. Modificar credito");
            printf("\n7. Modificar deuda");
            printf("\n0. Salir");

            printf("\nIntroduce tu eleccion: ");
            scanf("%d",&op);

                switch (op)
                {
                case 1:
                    fflush(stdin);
                    printf("\nIntroduce el nuevo id del cliente: ");
                    scanf("%d",&id);

                    if( !ValidarID(id))
                    {
                        printf("\nID invalido, adios.\n");
                        op=0;
                        break;
                    }
                    c.idCliente=id;
                    break;
                case 2:
                    fflush(stdin);
                    printf("\nIntroduce el nuevo nombre del cliente: ");
                    scanf("%s",&c.Nombre);
                    break;
                case 3:
                    fflush(stdin);            
                    printf("\nIntroduce el nuevo apellido paterno del cliente: ");
                    scanf("%s",&c.ApPaterno);
                    break;
                case 4:
                    fflush(stdin);
                    printf("\nIntroduce el nuevo apellido materno del cliente: ");
                    scanf("%s",&c.ApMaterno);
                    break;
                case 5:
                    fflush(stdin);
                    printf("\nIntroduce la nueva fecha de registro (AAAA/MM/DD): ");
                    scanf("%d/%d/%d",&c.date.AAAA,&c.date.MM,&c.date.DD);
                        if(!ValidarFecha(c.date.AAAA,c.date.MM,c.date.DD))
                        {
                            printf("\nFecha no valida, adios.\n");
                            break;
                        }
                    break;
                case 6:
                    fflush(stdin);
                    printf("\nIntroduce el nuevo credito del cliente: ");
                    scanf("%lf",&c.Credito);
                        if(c.Credito < 0)
                        {
                            printf("\nCredito no valido, adios.\n");
                            break;
                        }
                    printf("\nCredito valido.");
                    break;
                case 7:
                    fflush(stdin);
                    printf("\nIntroduce la nueva deuda del cliente: ");
                    scanf("%lf",&c.Deuda);
                        if(c.Deuda < 0)
                        {
                            printf("\nDeuda no valida, adios.\n");
                            break;
                        }
                    printf("\nDeuda valida.");
                    break;
                case 0:
                    printf("\nSaliendo al menu principal...\n");
                    break;
                default:
                    printf("\n\t\t\t\t\tIntroduce un numero valido\n\n");
                    printf("\t\t\t\tPresiona cualquier tecla para continuar.......");
                    getch();
                    break;
                }

            }while(op != 0);
        }
        fwrite(&c,sizeof(cliente),1,fp1);
    }   
    fclose(fp);
    fclose(fp1);

    if(Encontrado)
    {
        fp1 = fopen("temp.txt","r");
        fp = fopen("Clientes.txt","w");

        while(fread(&c,sizeof(cliente),1,fp1))
        {
            fwrite(&c,sizeof(cliente),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\n\t\t\tRegistro no encontrado.\n");

    fclose(fp);
}

int main()
{
    int op;
    do
    {
        printf("\n=======MENU PRINCIPAL=======\n");
        printf("\n1. Agregar registro");
        printf("\n2. Mostrar todos los registros");
        printf("\n3. Buscar por id");
        printf("\n4. Buscar por nombre");
        printf("\n5. Borrar un registro");
        printf("\n6. Modificar registro");
        printf("\n0. Salir");

        printf("\nIntroduce tu eleccion: ");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            Crear();
            break;
        case 2:
            Desplegar();
            break;
        case 3:
            Buscar();
            break;
        case 4:
            BuscarNombre();
            break;
        case 5: 
            Borrar();
            break;
        case 6:
            Modificar();
            break;
        case 0:
            printf("\nSaliendo.");
            exit(0);
            break;
        
        default:
        printf("\n\t\t\t\t\tIntroduce un numero valido\n\n");
        printf("\t\t\t\tPresiona cualquier tecla para continuar.......");
        getch();
       
        break;
        }

    }while(op != 0);

    return 0;
}