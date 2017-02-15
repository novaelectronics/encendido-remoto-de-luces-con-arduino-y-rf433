// Programa Receptor RF433 de NOVA Electronics
// Este codigo recibe una cadena por RF433 y enciende un foco mediante un rele.
//Compra tu material en www.nova.com.bo
//Codigo testeado con nuestros productos.

#include <VirtualWire.h>
int lampara=2; //pin de la lampara
byte message[VW_MAX_MESSAGE_LEN]; 
byte messageLength = VW_MAX_MESSAGE_LEN; 

void setup()
{
  pinMode(lampara,OUTPUT); //conectar a IN1 del modulo rele de 2 canales
  digitalWrite(lampara,HIGH); //en HIGH el rele esta apagado,y en LOW el rele hace contacto
    Serial.begin(9600);	// inicia el puerto de serie
    Serial.println("Receptor listo"); //Imprime "listo" en el monitor serial
   
    vw_set_rx_pin(3);       //Configura el pin 3 como TX, conectar cualquiera de los dos pines del medio del modulo al pin 3 del arduino
    vw_set_ptt_inverted(true); //Requerido para DR3100
    vw_setup(4000);	     //  Bits por segundo
    vw_rx_start();       // Inciar el receptor
}

void loop()
{
  if (vw_get_message(message, &messageLength))
  {
      if(comparar("Encender") == 0){
        digitalWrite(lampara, LOW);
        Serial.write("Foco Encendido\n");
      }
      else if(comparar("Apagar") == 0)
      {
        digitalWrite(lampara,HIGH);
        Serial.write("Foco Apagado\n");
      }
  
  }
} 
 
char comparar(char* cadena) {
  //Esta funcion compara el string cadena con el mensaje recibido.
  //Si son iguales, devuelve 1. Si no, devuelve 0.
  
  for(int i = 0; i<messageLength; i++)
  {
    if(message[i] != cadena[i])
    {
      return 1;
    }
  }
 
    return 0;
}
