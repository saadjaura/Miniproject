
#include <Dynamixel2Arduino.h> //Used for controlling the dynamixel servos

  #define PERIOD 100000  // period in us
  
  #define  NEW_PROPORTIONAL_GAIN  950  

  #define DXL_SERIAL Serial1 //Serial that RS485 is connected to

  #define COM_SERIAL Serial //Serial from computer

  uint8_t DXL_ID1 = 1; //Starting id of 1st servo
  uint8_t DXL_ID2 = 2; //Starting id of 2nd servo
  uint8_t DXL_ID3 = 3; //Starting id of 3rd servo
  uint8_t DXL_ID4 = 4; //Starting id of 4th servo
  uint8_t DXL_ID5 = 5; //Starting id of 5th servo  
  uint8_t newID   = 100; //New id to change any one servo to 
  unsigned long last_us = 0L; // last microsecond value 
  
  const uint8_t DXL_DIR_PIN = 4; // RS485 direction (LED) pin

  const int max_temp = 75; // Max Temperature Threshold 

  const float DXL_PROTOCOL_VERSION = 2.0;



  

  Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN); //Creating object for dynamixel communication



void setup() {

  COM_SERIAL.begin(115200); //Computer serial baudrate

  dxl.begin(57600); //Dynamixel baudrate, has to be the same as on the servos
  
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);//Sets dynamixel protocol

  dxl.scan();


  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID4);
  dxl.setOperatingMode(DXL_ID4, OP_POSITION);
  dxl.torqueOn(DXL_ID4);

  delay(500);

  dxl.torqueOff(DXL_ID5);
  dxl.setOperatingMode(DXL_ID5, OP_POSITION);
  dxl.torqueOn(DXL_ID5);

  delay(500);

  /*
  if(dxl.ping(DXL_ID1) == true) {
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID1);
    
    // set a new ID for ID1. Do not use ID 200
    dxl.setID(DXL_ID1, newID);
    COM_SERIAL.println("ID1 has been successfully changed to :");
    COM_SERIAL.println(newID);
    

    dxl.setID(newID, DXL_ID1);
    COM_SERIAL.println("ID1 has been successfully changed back to Original ID");
  }
  else{
    COM_SERIAL.println("ping failed!");
  }

  delay(500);
  */


  /*
  if(dxl.ping(DXL_ID2) == true) {
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID2);
    
    // set a new ID for ID2. Do not use ID 200
    dxl.setID(DXL_ID2, newID);
    COM_SERIAL.println("ID2 has been successfully changed to :");
    COM_SERIAL.println(newID);

    dxl.setID(newID, DXL_ID2);
    COM_SERIAL.println("ID2 has been successfully changed back to Original ID");
  }
  else{
    COM_SERIAL.println("ping failed!");
  }

  delay(500);
  */

  /*
  if(dxl.ping(DXL_ID3) == true) {
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID3);
    
    // set a new ID for ID3. Do not use ID 200
    dxl.setID(DXL_ID3, newID);
    COM_SERIAL.println("ID3 has been successfully changed to :");
    COM_SERIAL.println(newID);

    dxl.setID(newID, DXL_ID3);
    COM_SERIAL.println("ID3 has been successfully changed back to Original ID");
  }
  else{
    COM_SERIAL.println("ping failed!");
  }

  delay(500);
*/  
  if(dxl.ping(DXL_ID4) == true) {
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID4);
    
    // set a new ID for ID4. Do not use ID 200
    dxl.setID(DXL_ID4, newID);
    COM_SERIAL.println("ID4 has been successfully changed to :");
    COM_SERIAL.println(newID);

    dxl.setID(newID, DXL_ID4);
    COM_SERIAL.println("ID4 has been successfully changed back to Original ID");
  }
  else{
    COM_SERIAL.println("ping failed!");
  }

  delay(500);
  
  if(dxl.ping(DXL_ID5) == true) {
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID5);
    
    // set a new ID for ID5. Do not use ID 200
    dxl.setID(DXL_ID5, newID);
    COM_SERIAL.println("ID5 has been successfully changed to :");
    COM_SERIAL.println(newID);

    dxl.setID(newID, DXL_ID5);
    COM_SERIAL.println("ID5 has been successfully changed back to Original ID");
  }
  else{
    COM_SERIAL.println("ping failed!");
  }

  delay(500);

  
  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID4, 1);

  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID5, 1);

  delay(5000);
  
  Reset();

  delay(500);

  dxl.writeControlTableItem(P_GAIN, DXL_ID2, NEW_PROPORTIONAL_GAIN); // sets a new proportional gain value

  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID4, 1);

  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID5, 1);
  
  delay(5000);
  
  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID4, 0);

  dxl.writeControlTableItem(TORQUE_ENABLE, DXL_ID5, 0);
  
  delay(5000);
  
}


void Reset(){
  

 dxl.writeControlTableItem(SHUTDOWN, DXL_ID1, 1);
 dxl.writeControlTableItem(SHUTDOWN, DXL_ID2, 1);
 dxl.writeControlTableItem(SHUTDOWN, DXL_ID3, 1);
 dxl.writeControlTableItem(SHUTDOWN, DXL_ID4, 1);
 dxl.writeControlTableItem(SHUTDOWN, DXL_ID5, 1);

      
 delay(5000);

 dxl.reboot(DXL_ID1, 1);
 dxl.torqueOn(DXL_ID1);
 dxl.reboot(DXL_ID2, 1);
 dxl.torqueOn(DXL_ID2);
 dxl.reboot(DXL_ID3, 1);
 dxl.torqueOn(DXL_ID3);
 dxl.reboot(DXL_ID4, 1);
 dxl.torqueOn(DXL_ID4);
 dxl.reboot(DXL_ID5, 1);
 dxl.torqueOn(DXL_ID5);   


}


void sample()
{
  COM_SERIAL.println("The present Temperature value on ID4 is :");
  COM_SERIAL.println(dxl.readControlTableItem(PRESENT_TEMPERATURE, DXL_ID4));

  if(dxl.readControlTableItem(PRESENT_TEMPERATURE, DXL_ID4)>=max_temp){
     Reset();
  }
  else{
     COM_SERIAL.println("Dynamixel can work properly");
  } 
}

void loop() {


  if (micros() - last_us > PERIOD)
  {
  last_us += PERIOD ;
  
  sample () ;
  
  }
  
}
