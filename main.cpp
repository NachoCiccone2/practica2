// Alumno:Ignacio Ciccone.                    Fecha:19/06/2025
/* Ejercicio 1
    1) Una agencia de reparto posee dos canales para recibir pedidos, uno es 
    la página web de la empresa y el otro un operador que atiende la línea 
    telefónica. La operatoria es que al finalizar el horario de toma de 
    pedidos (de 6.00hs a 12.00hs), se juntan todos los pedidos por orden 
    de llegada y se genera un listado único con los repartos del día. De 
    cada pedido se tiene la siguiente información:
    • Hora Pedido (hora en formato HHMM)
    • Codigo de cliente (numérico)
    • Tipo de paquete: (1-Liviano / 2-Medio / 3-Pesado)
    • Origen(texto)
    • Destino(texto)

    La capacidad de reparto varía según cuántos móviles disponga la empresa en el 
    momento y las horas que se dispongan para realizar repartos, por lo cual la 
    cantidad máxima de pedidos que puede tener el listado unificado resultará de 
    un cálculo: 
    Pedidos_Max = Móviles * Horas_Reparto * 3

    a. Definir las estructuras necesarias para el enunciado descrito y para 
    los puntos siguientes:
    b. Realizar codificación de un procedimiento que reciba los pedidos de 
    ambos canales de atención y genere un listado de pedidos unificado a 
    atender y otro de los que no entran en el reparto diario por la capacidad 
    máxima.
    c. Realizar diagrama de un procedimiento que reciba el listado de pedidos 
    a realizar en el día y genere el siguiente listado agrupado por hora del pedido recibido:
    HORA	LIVIANOS	MEDIO		PESADO	    TOTAL X HORA
    6		2	        0		     1	        3

    d. Al finalizar el listado imprimir los siguientes datos de reporte:
    TOTAL LIVIANOS: 99 	TOTAL MEDIO: 99	TOTAL PESADOS: 99
    HORA CON MENOS ENVIOS: 13

    Consideraciones: Los listados de ambos canales de atención se encuentran 
    ordenados en forma ascendente por hora de pedido.
    Restricciones: Solo se puede recorrer secuencialmente una vez cada vector
 */

const int TIPO_PAQUETE_LIVIANO = 1;
const int TIPO_PAQUETE_MEDIO = 2;
const int TIPO_PAQUETE_PESADO = 3;
/**************************************ACA MODIFICO CANT MAX PARA PROBAR LOS RECHAZADOS******************************************************/
const int MAX_CANT_PEDIDOS = 4;
#include <iostream>
#include <string>

using namespace std;

struct PEDIDO {
    int hora;
    long codigo_cliente;
    int tipo_paquete;
    string origen;
    string destino;
};

int carga_de_pedidos (PEDIDO pedidos[]){
    int bandera = 1;
    int i = 0;
    int cantidad_pedidos = 0;

    //cout << "CARGA DE DATOS" << endl;
    while (bandera == 1 && i<MAX_CANT_PEDIDOS){
        int hora;
        long codigo_cliente;
        int tipo_paquete;
        string origen;
        string destino;
        cout << "Ingrese la hora del pedido en formato HHMM: ";
        cin >> hora;
        cout << "Ingrese el codigo del cliente: ";
        cin >> codigo_cliente;
        cout << "Ingrese el tipo de paquete (1_ liviano, 2_ medio, 3_pesado): ";
        cin >> tipo_paquete;
        cin.ignore();
        cout << "Ingrese el origen del envio: ";
        getline(cin, origen);
        cout << "Ingrese el destino del envio: ";
        getline(cin, destino);
        
        /* Aca puede haber verificacion de datos */
        
        pedidos[i].hora = hora;
        pedidos[i].codigo_cliente = codigo_cliente;
        pedidos[i].tipo_paquete = tipo_paquete;
        pedidos[i].origen = origen;
        pedidos[i].destino = destino;
        i++;
        cout << "Desea seguir cargando datos?(1: si, 0: no): ";
        cin >> bandera;

        if(i == MAX_CANT_PEDIDOS){
            cout<< "No se pueden cargar mas datos para esta instancia." << endl;
        }
    }

    cantidad_pedidos = i;
    return cantidad_pedidos;
}

void unificacion_de_listados(PEDIDO pedidos_web[], PEDIDO pedidos_telefonicos[], PEDIDO pedidos_a_atender[], PEDIDO pedidos_rechazados[],  int cant_pedidos_web , int cant_pedidos_telefonicos, int &cant_pedidos_a_atender, int &cant_pedidos_rechazados)
{
    /*
        i: indice de pedidos_Web
        j: indice de pedidos_telefonicos
        k: indice de pedidos_a_atender
        l: indice de pedidos_rechazados
    */
    int i=0,j=0,k=0,l=0;

    while(i<cant_pedidos_web && j<cant_pedidos_telefonicos){
        if(k<MAX_CANT_PEDIDOS){
            if(pedidos_web[i].hora <= pedidos_telefonicos[j].hora){
                pedidos_a_atender[k] = pedidos_web[i];
                i++;
            } else {
                pedidos_a_atender[k] = pedidos_telefonicos[j];
                j++;
            }
            k++;
        } else {
            if(pedidos_web[i].hora <= pedidos_telefonicos[j].hora){
                pedidos_rechazados[l] = pedidos_web[i];
                i++;
            } else {
                pedidos_rechazados[l] = pedidos_telefonicos[j];
                j++;
            }
            l++;
        }
    }

    while(i<cant_pedidos_web){
        if(k<MAX_CANT_PEDIDOS){
            pedidos_a_atender[k] = pedidos_web[i];
            i++;
            k++;
        } else {
            pedidos_rechazados[l] = pedidos_web[i];
            i++;
            l++;
        }
    }

    while(j<cant_pedidos_telefonicos){
        if(k<MAX_CANT_PEDIDOS){
            pedidos_a_atender[k] = pedidos_telefonicos[j];
            j++;
            k++;
        } else {
            pedidos_rechazados[l] = pedidos_telefonicos[j];
            j++;
            l++;
        }
    }

    cant_pedidos_a_atender = k;
    cant_pedidos_rechazados = l;
}

void mostrar_pedidos(PEDIDO pedidos[], int cant_pedidos){
    for(int i=0;i<cant_pedidos;i++){
        string tipo_paquete;
        switch (pedidos[i].tipo_paquete){
            case TIPO_PAQUETE_LIVIANO:
                tipo_paquete = "liviano";
                break;
            
            case TIPO_PAQUETE_MEDIO:
                tipo_paquete = "medio";
                break;

            case TIPO_PAQUETE_PESADO:
                tipo_paquete = "pesado";
                break;

            default:
                break;
        }
        cout << "\nPedido numero " << i+1 << ": " << endl;
        cout << "Hora del pedido: " << pedidos[i].hora << endl;
        cout << "Codigo del cliente: " << pedidos[i].codigo_cliente << endl;
        cout << "Tipo de paquete: " << tipo_paquete << endl;
        cout << "Origen del pedido: " << pedidos[i].origen << endl;
        cout << "Destino del pedido: " << pedidos[i].destino << endl;
    }
    if(cant_pedidos==0){
        cout<<"No hay pedidos para mostrar"<<endl;
    }
}

int print_listado(int hora, int cant_livianos, int cant_medio, int cant_pesados){
    int cant_total = cant_livianos + cant_medio + cant_pesados;
    cout<< "\nHORA	LIVIANOS	MEDIO		PESADO	    TOTAL X HORA" << endl;
    cout << hora << "	" << cant_livianos << "       	" << cant_medio << "    		" << cant_pesados << "     	    " << cant_total << endl;
    return cant_total;
}

void print_datos_finales (int cant_livianos, int cant_medio, int cant_pesados, int hora_menos_envio){
    cout<< "\nTOTAL LIVIANOS: " << cant_livianos << "; TOTAL MEDIO: " << cant_medio << "; TOTAL PESADOS: " << cant_pesados << endl;
    cout << "HORA CON MENOS ENVIOS: " << hora_menos_envio << endl;
    return;
}

void mostrar_listado_por_hora(PEDIDO pedidos[], int cant_pedidos){
    int cant_livianos = 0, cant_medio = 0, cant_pesados = 0;
    int total_livianos = 0, total_medio = 0, total_pesados = 0;
    int cant_menos_envios = 99999;
    int hora_menos_envio;
    int i=0;
    bool bandera_fin_array = true;

    for(int hora=6; hora<13; hora++){
        while( (pedidos[i].hora/100) == hora && bandera_fin_array){
            switch (pedidos[i].tipo_paquete){
                case TIPO_PAQUETE_LIVIANO:
                    cant_livianos++;
                    break;
                
                case TIPO_PAQUETE_MEDIO:
                    cant_medio++;
                    break;

                case TIPO_PAQUETE_PESADO:
                    cant_pesados++;
                    break;

                default:
                    break;
            }
            i++;
            if(i == cant_pedidos){
                bandera_fin_array = false;
                total_livianos += cant_livianos;
                total_medio += cant_medio;
                total_pesados += cant_pesados;
                int cant_total = print_listado(hora, cant_livianos, cant_medio, cant_pesados);
                if(cant_total < cant_menos_envios){
                    cant_menos_envios = cant_total;
                    hora_menos_envio = hora;
                }
                print_datos_finales(total_livianos,total_medio,total_pesados,hora_menos_envio);
            }
            if( (pedidos[i].hora/100) > hora){
                if(cant_livianos || cant_medio || cant_pesados){
                    int cant_total = print_listado(hora, cant_livianos, cant_medio, cant_pesados);
                    if(cant_total < cant_menos_envios){
                        cant_menos_envios = cant_total;
                        hora_menos_envio = hora;
                    }
                }
                total_livianos += cant_livianos;
                total_medio += cant_medio;
                total_pesados += cant_pesados;
                cant_livianos = 0;
                cant_medio = 0;
                cant_pesados = 0;
            }
        }
    }
    
    return;
}

void ejercicio1(){
    PEDIDO pedidos_web[MAX_CANT_PEDIDOS];
    PEDIDO pedidos_telefonicos[MAX_CANT_PEDIDOS];
    PEDIDO pedidos_a_atender[MAX_CANT_PEDIDOS];
    PEDIDO pedidos_rechazados[MAX_CANT_PEDIDOS];
    int cant_pedidos_web, cant_pedidos_telefonicos, cant_pedidos_a_atender, cant_pedidos_rechazados;

    cout << "\n********************* CARGA DE PEDIDOS WEB *********************" << endl;
    cant_pedidos_web = carga_de_pedidos(pedidos_web);
    cout << "\n************************* PEDIDOS WEB *************************" << endl;
    mostrar_pedidos(pedidos_web, cant_pedidos_web);
    cout << "\n***************** CARGA DE PEDIDOS TELEFONICOS *****************" << endl;
    cant_pedidos_telefonicos = carga_de_pedidos(pedidos_telefonicos);
    cout << "\n********************* PEDIDOS TELEFONICOS **********************" << endl;
    mostrar_pedidos(pedidos_telefonicos, cant_pedidos_telefonicos);

    cout << "\n********************* UNIFICANDO PEDIDOS *********************" <<endl;
    unificacion_de_listados(pedidos_web, pedidos_telefonicos, pedidos_a_atender, pedidos_rechazados, cant_pedidos_web, cant_pedidos_telefonicos, cant_pedidos_a_atender, cant_pedidos_rechazados);
    cout << "\n********************** PEDIDOS A ATENDER **********************" << endl;
    mostrar_pedidos(pedidos_a_atender, cant_pedidos_a_atender);
    cout << "\n********************** PEDIDOS RECHAZADOS **********************" << endl;
    mostrar_pedidos(pedidos_rechazados, cant_pedidos_rechazados);

    cout << "\n********************** LISTA A ATENDER POR HORA **********************" << endl;
    mostrar_listado_por_hora(pedidos_a_atender, cant_pedidos_a_atender);

    return;
}

/*  Ejercicio2:
    2) Realizar diagrama del procedimiento intersección que dados dos arreglos 
    de entrada uno de N y otro de M elementos genere un nuevo arreglo de 
    salida sólo con los elementos que  están en ambos conjuntos ordenado en 
    forma ascendente. 
    Ejemplo: vecA = {0, 2, 4, 9} y vecB = {9, 5, 3, 2, 1) => vecC = {2, 9} 

    Consideraciones: Ambos arreglos de entrada están ordenados pero el primero 
    en forma ascendente y el segundo en forma descendente. Ambos son conjuntos 
    sin elementos repetidos 
    Restricciones: Sólo se puede recorrer una vez cada vector de entrada
*/

int interseccion (int a[], int len_a, int b[], int len_b, int res[]){
    int len_c=0;
    int i=0, j=(len_b-1), k=0;

    while(i<len_a && j>=0){
        if(a[i] == b[j]){
            res[k] = a[i];
            k++;
            i++;
            j--;
        } else if(a[i] > b[j]){
            j--;
        } else {
            i++;
        }
    }

    len_c = k;
    return len_c;
}

void ejercicio2 (){
    int a[] = {0,1,2,4,5,9, 10, 11, 12, 13,14,15}, b[] = {17,14,9,5,3,2,1};
    int len_a = 12, len_b = 7, len_c;
    int res[len_b]; 
    //Lo inicializo del menor largo de array, ya que en la intersección el maximo de numeros que puede llegar a albergar es el del array mas corto.
    
    len_c = interseccion(a,len_a,b,len_b,res);

    cout << "len_c: " << len_c << endl;

    for(int i=0;i<len_c;i++){
        cout << "res[" << i << "]: " << res[i] << endl;
    }
    return;
}

int main (){
    ejercicio1();
    //ejercicio2();

    return 0;
}