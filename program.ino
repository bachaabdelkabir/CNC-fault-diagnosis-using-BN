
// ****************************************************************************************
// BACHA Abdelkabir - Equipe EAP- Laboratoire LISER - ENSEM - UH2C 

// Mesure de température inspiré de https://arduino-info.wikispaces.com/MultipleTemperatureSensorsToLCD
// Mesure de tension inspiré de http://startingelectronics.org/articles/arduino/measuring-voltage-with-arduino/
// Mesure de vitesse de rotation inspiré de http://www.instructables.com/id/Measure-RPM-DIY-Portable-Digital-Tachometer/?ALLSTEPS
// ****************************************************************************************

//*****************************************************************************************
// Inclusions des bibliothèques

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7                   // Data wire is plugged into pin 7 on the Arduino

//*****************************************************************************************
// Initialisation de la bibliothèque One Wire
  OneWire oneWire(ONE_WIRE_BUS);         // Setup a oneWire instance to communicate with 
                                         // any OneWire devices (not just Maxim/Dallas 
                                         // temperature ICs)
                                         
//*****************************************************************************************
// Initialisation de la bibliothèque Dallas Temperature
// Pass our oneWire reference to Dallas Temperature.
  DallasTemperature temperture_sensors(&oneWire);   
  
//*****************************************************************************************
// Déclaration des variables

#define X_volt_sensor A0
#define X_Curr_sensor A1

const int ledPin =  13;                  // the number of the LED pin

      int courant_mot;
      int mVperAmp = 66;                 // use 100 for 20A Module and 66 for 30A Module
      float RawValue= 0;
      int ACSoffset = 2500; 
      double AmpsVoltage = 0;
      double Amps = 0;


      double sum1 = 0;                      // sum of samples taken for motor current measerment
      double sum2 = 0;                      // sum of samples taken for motor voltage measurment 
      double sum3 = 0;                      // sum of samples taken for generator voltage measurment  
      unsigned char sample_count = 0;         // current sample number
      float Tension_moteur = 0.0;              // calculated voltage
      float Tension_gen = 0.0;

  DeviceAddress Probe01 = { 0x28, 0xFF, 0xA3, 0x27, 0x68, 0x14, 0x03, 0x76 }; 
  DeviceAddress Probe02 = { 0x28, 0xFF, 0x6C, 0x4C, 0x6D, 0x14, 0x04, 0x89 };
  DeviceAddress Probe03 = { 0x28, 0xFF, 0x74, 0x63, 0x6D, 0x14, 0x04, 0x21 };

float Volt_X = 0.00 ;
float Curr_X = 0.00 ;
float Tem_X = 0.00 ;
float Lim_X = 0.00 ;
float Volt_Y = 0.00 ;
float Curr_Y = 0.00 ;
float Tem_Y = 0.00 ;
float Lim_Y = 0.00 ;
float Volt_Z = 0.00 ;
float Curr_Z = 0.00 ;
float Tem_Z = 0.00 ;
float Lim_Z = 0.00 ;
float Volt_Spdle = 0.00 ;
float Curr_Spdle = 0.00 ;
float Tem_Spdle = 0.00 ;
float Duty_Cycl_Spdle = 0.00 ;



//*****************************************************************************************
// initialisations Générales 
void setup() {

  Serial.begin(9600);                    // initialize serial communication at 9600 bits 
                                         // per second:
  temperture_sensors.begin();            // Start up the library
                                         // IC Default 9 bit. If you have troubles consider 
                                         // upping it 12. Ups the delay giving the IC more 
                                         // time to process the temperature measurement
                                         // set the resolution to 9 bit (Can be 9 to 12 bits .. lower is faster)
  temperture_sensors.setResolution(Probe01, 9);
  temperture_sensors.setResolution(Probe02, 9);
  temperture_sensors.setResolution(Probe03, 9); 
  
  pinMode(ledPin, OUTPUT);               // initialize the LED pin as an output:

}



//*****************************************************************************************
// Boocle Principale
void loop() {

//---------------------------Acquisition des Données--------------------------------------




//---------------------Trasmission des Données Via port série--------------------------------


  Serial.print(temperture_sensors.getTempC(Probe01));
  Serial.print("\t");
  Serial.print(temperture_sensors.getTempC(Probe02));
  Serial.print("\t");
  Serial.print(temperture_sensors.getTempC(Probe03));











}
