// Programa Transmisor RF433 de NOVA Electronics
// Este codigo envia una cadena por RF433 mediante un pulsador.
//Compra tu material en www.nova.com.bo
//Codigo testeado con nuestros productos.

#include <VirtualWire.h>

int pulsador=2; //tipo pulldown
int estado = 0;

void setup()
{
    Serial.begin(9600);	  // abre el puerto de serie
    Serial.println("Transmisor listo"); // Imprime "listo" en el monitor serial
    pinMode(pulsador, INPUT); //configura el pin 2 como entrada.
   
    vw_set_tx_pin(12);          // Configura el pin 12 como TX, conectar el pin ATAD del modulo al pint 12 del arduino
    vw_set_ptt_inverted(true);  // Requerido para DR3100
    vw_setup(4000);	        // Bits por segundo
}

void loop()
{
    // digitalWrite(13, HIGH);      // Parpadeo para mostrar actividad
  if (digitalRead(pulsador)==HIGH)
   {
    if(estado ==0){
    char msg[] = "Apagar";   // Mensaje a enviar
    vw_send((uint8_t *)msg, strlen(msg)); //Enviando...
    vw_wait_tx(); // espera hasta que el mensaje se haya enviado
    Serial.println("Transmitido."); // Imprime confirmacion de la transmision en el monitor serial
    delay(125);                 // Pausa antes repetir el ciclo
    delay(125);                 // Pausa antes repetir el ciclo
    estado=1;
    }
    else {
      char msg[] = "Encender";   // Mensaje a enviar
    vw_send((uint8_t *)msg, strlen(msg)); //Enviando...
    vw_wait_tx(); // espera hasta que el mensaje se haya enviado
    Serial.println("Transmitido."); // Imprime confirmacion de la transmision en el monitor serial
    delay(125);                 // Pausa antes repetir el ciclo
    delay(125);                 // Pausa antes repetir el ciclo
    estado=0;
    }
    }
     
   }
             

