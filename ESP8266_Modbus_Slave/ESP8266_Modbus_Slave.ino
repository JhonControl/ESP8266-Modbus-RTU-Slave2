#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

//https://code.google.com/p/arduino-modbus-slave/downloads/detail?name=MODBUS.zip&can=2&q=/
/*
This example code shows a quick and dirty way to get an
arduino to talk to a modbus master device with a
device ID of 1 at 9600 baud.
*/

//Setup the brewtrollers register bank
//All of the data accumulated will be stored here
modbusDevice regBank;
//Create the modbus slave protocol handler
modbusSlave slave;

///salida pwm pin 9
//-#define  LED 9 

  
 unsigned int conta=0;
 
void setup()
{   
  
//pinMode(13, OUTPUT);
//pinMode(3, INPUT); 


//Assign the modbus device ID.  
  regBank.setId(1);

/*
registros Modbus seguir el siguiente formato
00001-09999 Salidas digitales, un dispositivo maestro puede leer y escribir en estos registros
10001 a 19.999 entradas digitales, un dispositivo maestro sólo pueden leer los valores de estos registros
30001-39999 Entradas analógicas, un dispositivo maestro sólo pueden leer los valores de estos registros
40.001 a 49.999 salidas analógicas, un dispositivo maestro puede leer y escribir en estos registros

Los valores analógicos son 16 palabras sin signo de bits almacenados con un rango de 0 a 32.767
Los valores digitales se almacenan como bytes, el valor cero está apagado y cualquier valor nonzer está activado

Lo mejor es configurar los registros de tipo similar en bloques contiguos. este
permite una más eficiente de búsqueda y registro y reduce el número de mensajes
requerido por el maestro para recuperar los datos
*/

  regBank.add(1);
  regBank.add(2);
  regBank.add(3);
  regBank.add(4);
  regBank.add(5);
  regBank.add(6);
  regBank.add(7);
  regBank.add(8);
  regBank.add(9);
  regBank.add(10);
 // regBank.add(11);
 // regBank.add(12);
 // regBank.add(13);
 // regBank.add(14);
 // regBank.add(15);
 //regBank.add(16);
 // regBank.add(17);
 // regBank.add(18);
 // regBank.add(19);
 // regBank.add(20);
 // regBank.add(21);
 // regBank.add(22);
 // regBank.add(23);
 // regBank.add(24);
 // regBank.add(25);
 // regBank.add(26);

// Añadir entrada digital registra 10001-10008 al banco de registros
  regBank.add(10001);  
  regBank.add(10002);  
  regBank.add(10003);  
  regBank.add(10004);  
  regBank.add(10005);  
  regBank.add(10006);  
  regBank.add(10007);  
  regBank.add(10008);  
  regBank.add(10009);  
  regBank.add(10010);  
 // regBank.add(10011);  
 // regBank.add(10012);  
 // regBank.add(10013);  
 // regBank.add(10014);  
 // regBank.add(10015);  
 // regBank.add(10016); 
 // regBank.add(10017);  
 // regBank.add(10018);  
 // regBank.add(10019);  
 // regBank.add(10020);  
 // regBank.add(10021);  
 // regBank.add(10022);  
 // regBank.add(10023);  
 // regBank.add(10024); 

 // Añadir entrada analógica registros 30001 a 10010 del banco de registros
  regBank.add(30001);  
  regBank.add(30002);  
  regBank.add(30003);  
  regBank.add(30004);  
  regBank.add(30005);  
  regBank.add(30006);  
  regBank.add(30007);  
  regBank.add(30008);  
  regBank.add(30009);  
  regBank.add(30010); 
 // regBank.add(30011);  
 // regBank.add(30012);  
 // regBank.add(30013);  
 // regBank.add(30014);  
 // regBank.add(30015);  
 // regBank.add(30016);  
 // regBank.add(30017);  
 // regBank.add(30018);  
 // regBank.add(30019);  
 // regBank.add(30020);  
 // regBank.add(30021);  

// Añade Salida analógica registra 40.001-40.020 al banco de registros

  regBank.add(40001);  
  regBank.add(40002);  
  regBank.add(40003);  
  regBank.add(40004);  
  regBank.add(40005);  
  regBank.add(40006);  
  regBank.add(40007);  
  regBank.add(40008);  
  regBank.add(40009);  
  regBank.add(40010);  
 //regBank.add(40011);  
 // regBank.add(40012);  
 // regBank.add(40013);  
 // regBank.add(40014);  
 // regBank.add(40015);  
 // regBank.add(40016);  
 // regBank.add(40017);  
 // regBank.add(40018);  
 // regBank.add(40019);  
 // regBank.add(40020);  
 // regBank.add(40021); 

/*
Asigne el objeto de dispositivo Modbus para el controlador de protocolo
Aquí es donde el controlador de protocolo se verá a leer y escribir
registrar los datos. En la actualidad, un controlador de protocolo esclavo Modbus puede
sólo tienen un dispositivo asignado a la misma.
*/
  slave._device = &regBank;  

// Initialize the serial port for coms at 9600 baud  
  slave.setBaud(19200);   
}

void loop()
{    
 while(1)
  {
      ////Genera un valor ramdom en el registro 10001 
    //regBank.set(10001, (byte) random(0, 2));     
    //INPUT REGISTERS  
    ///////////// Guarda el valor de ADC 0  a los registros del 30001 
    regBank.set(30001,  random(1, 50));         
     //regBank.set(40000, random(0, 10));

     delay(1000);
   
     slave.run();  
  }
}

