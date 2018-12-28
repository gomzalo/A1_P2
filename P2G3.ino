
//************************************************************************************************************
//************************************************************************************************************
//********************   Arquitectura de ensambladores y computadores 1 "B"               ********************
//********************   Grupo 3                                                          ********************
//********************   Proyecto 2                                                       ********************
//********************   Cubo 8x8x8                                                       ********************
//************************************************************************************************************
//************************************************************************************************************

#include "letras.h"
#include "figurasAndroid.h"
#include "figurasReposo.h"
 #include <Time.h>
#include <ArduinoJson.h>
//_________________________________________________________
//........................  WIFI  .........................
//.........................................................
#define ESP8266 Serial3
#define DEBUG true
String SSID = "CBW383G2N-6179-G";
String PASSWORD = "2fea0b08fb1f0";

int LED = 13;

boolean FAIL_8266 = false;

#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];
//.........................................................
//.........................................................
//_________________________________________________________
//..................... Pines a usar .......................
//..........................................................
//                MEGA

int dataPin = 10;
int latchPin = 11;
int clockPin = 12;

int piso1 = 31;
int piso2 = 33;
int piso3 = 35;
int piso4 = 37;
int piso5 = 39;
int piso6 = 41;
int piso7 = 43;
int piso8 = 45;
//..........................................................
//..........................................................
//_________________________________________________________
//....................... tiempos .........................
//..........................................................
int tiempoMedio = 50;
int tiempoRapido = 10;
int tiempo = 100;
int tiempo1 = 250;
//..........................................................
//..........................................................
//_________________________________________________________
//....................... snake ............................
//..........................................................
byte Snake[8][8]={ {1,1,1,1,1,1,1,1},
                  {1,0,0,0,0,0,0,1},
                  {1,0,0,0,0,0,0,1},
                  {1,0,0,0,0,0,0,1},
                  {1,0,0,0,0,0,0,1},
                  {1,0,0,0,0,0,0,1},
                  {1,0,0,0,0,0,0,1},
                  {1,1,1,1,1,1,1,1}};


int pintar=10;
int modo=0;
int posx=10;
int posy=10;
int nivel=10;
int modoArchivo=10;
int salida=1;
int ob1x=10;
int ob1y=10;
int ob2x=10;
int ob2y=10;
int ob3x=10;
int ob3y=10;
int ob4x=10;
int ob4y=10;
int caracter=10;
int bandera=1;
//..........................................................
//..........................................................
//_________________________________________________________
//....................... Musica ............................
//..........................................................
int volumen;
int minimo;
int nivelMuisica;
//..........................................................
//..........................................................
//________________________________________________________________________________________________________________________________
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::   S  E  T  U  P   :::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void setup() {
  //..................... Modos de los pines ......................................
  //                    MEGA
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(piso1, OUTPUT);
  pinMode(piso2, OUTPUT);
  pinMode(piso3, OUTPUT);
  pinMode(piso4, OUTPUT);
  pinMode(piso5, OUTPUT);
  pinMode(piso6, OUTPUT);
  pinMode(piso7, OUTPUT);
  pinMode(piso8, OUTPUT);
  Serial.begin(9600);
//............................  Musica .......................................
  nivelMuisica=0;
  minimo=400;
//............................  WiFi .......................................
wifiSetup();
   
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//________________________________________________________________________________________________________________________________
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::   L   O   O   P   :::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void loop() {
  //..................... Mandando a llamar a los metodos ......................................
  if(Serial.available()){
  modo = Serial.read();
  if(modo=='1'){
    recorre(D);
    while(!Serial.available()){    
    }
    nivel=Serial.read();
    while(comprobarEntero(nivel)){
        while(!Serial.available()){    
        }
        ob1x=Serial.read();
        while(!Serial.available()){    
        }
        ob1y=Serial.read();
        while(!Serial.available()){    
        }
        ob2x=Serial.read();
        while(!Serial.available()){    
        }
        ob2y=Serial.read();
        while(!Serial.available()){    
        }
        ob3x=Serial.read();
        while(!Serial.available()){    
        }
        ob3y=Serial.read();
        while(!Serial.available()){    
        }
        ob4x=Serial.read();
        while(!Serial.available()){    
        }
        ob4y=Serial.read();
        
        if(comprobarEntero(ob4y)){ 
          Snake[PasarEntero(ob1x)][PasarEntero(ob1y)]=1;
          Snake[PasarEntero(ob2x)][PasarEntero(ob2y)]=1;
          Snake[PasarEntero(ob3x)][PasarEntero(ob3y)]=1;
          Snake[PasarEntero(ob4x)][PasarEntero(ob4y)]=1;
          recorre(Snake); 
        }
        while(comprobarEntero(ob4y)){
          recorre(Snake); 
          while(!Serial.available()){    
          }
          posx=Serial.read();
          
          while(!Serial.available()){    
          }
          posy=Serial.read();
          while(!Serial.available()){    
          }
          modoArchivo=Serial.read();
          
          if(modoArchivo=='A'){
            Snake[PasarEntero(posx)][PasarEntero(posy)]=1; 
          }else if(modoArchivo=='B'){
            Snake[PasarEntero(posx)][PasarEntero(posy)]=0; 
          }
          
          
          recorre(Snake); 
      }
    }
  }
  else if(modo=='2'){
    recorre(F);
 
    while(!Serial.available()){    
    }
    modoArchivo=Serial.read();
    String inputString="";
    while(comprobarEntero(modoArchivo))
    {
      
      if(modoArchivo=='1'){
        
      }else if(modoArchivo=='2'){
        
      }else if(modoArchivo=='3'){
        while(!Serial.available()){
        }
        while(Serial.available()){
          char inChar = (char)Serial.read();
          // add it to the inputString:
          inputString += inChar;
          recorre(K);
        }
        char palabra[inputString.length()];
        inputString.toCharArray(palabra,inputString.length());
        printPalabraIzDr(palabra);
        modoArchivo='6';
        inputString="";
      }else if(modoArchivo=='4'){
        while(!Serial.available()){
        }
        while(Serial.available()){
          char inChar = (char)Serial.read();
          // add it to the inputString:
          inputString += inChar;
          recorre(K);
        }
        char palabra[inputString.length()];
        inputString.toCharArray(palabra,inputString.length());
        printPalabraDrIz(palabra);
        modoArchivo='6';
        inputString="";
      }else if(modoArchivo=='5'){
        modoArchivo='A';
        modo='6';
      }else if(modoArchivo=='6'){
        recorre(P);
        if(Serial.available()){
          modoArchivo=Serial.read();}
      }
    }
  }
  else if(modo=='3'){
    recorre(H);
  }
  else if(modo=='4'){
    while(modo=='4'){
      recorre(I);
      wifi();
    }
      recorre(A);
  }
  recorre(B);
  
  //printPalabraIzDr("TEPO KUN");
  //printPalabraDrIz("TEPO KUN");
  //recorre(A);
  //cuboLleno();
  //EscucharMusica(10,3);

}
recorre(C);
}


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//________________________________________________________________________________________________________________________________
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||     Coordenadas    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void recorre(byte mat[8][8]){

  String concatenar = "";
  long decimal = 0;
for(int k = 0; k<10; k++){
  for (int i=0; i<8; i++){
   for (int j=0; j<8; j++){
      concatenar = concatenar + String(mat[i][j]); 
    }
    decimal = convBinario((concatenar).toInt());
    dibujar(decimal,i);
    concatenar = "";
  }
}    
}

int convBinario(long bin){
    int dec;
    long p,c;
    c=1;
    dec=0;
    while(bin>0){
        p=0;
        p=c*(bin%10);
        dec+=p;
        c*=2;
        bin/=10;
    }
    return dec;
}

void dibujar(int decimal, int piso){


      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 8. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 7. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 6. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 5. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 4. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 3. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 2. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 1. 74hc595
      digitalWrite(latchPin, 1);
  
    switch(piso){
      case 0:
   
          digitalWrite(piso1,1);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,0);
          digitalWrite(piso8,0);
          //delay(tiempoRapido);
        break;
  
       case 1:
          digitalWrite(piso1,0);
          digitalWrite(piso2,1);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,0);
          digitalWrite(piso8,0);
          //delay(tiempoRapido);
        break;
  
         case 2:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,1);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,0);
          digitalWrite(piso8,0);
          //delay(tiempoRapido);
        break;
  
        case 3:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,1);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,0);
          digitalWrite(piso8,0);
         // delay(tiempoRapido);
        break;
  
        case 4:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,1);
          digitalWrite(piso6,0);
          digitalWrite(piso7,0);
          digitalWrite(piso8,0);
          //delay(tiempoRapido);
        break;
  
       case 5:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,1);
          digitalWrite(piso7,0);
          digitalWrite(piso8,0);
         // delay(tiempoRapido);
        break;
  
        case 6: 
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,1);
          digitalWrite(piso8,0);
         // delay(tiempoRapido);
        break;

        case 7: 
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,0);
          digitalWrite(piso8,1);
          //delay(tiempoRapido);
        break;
    }
 
}

void dibujarSonido(int decimal, int piso){


      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 8. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 7. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 6. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 5. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 4. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 3. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 2. 74hc595
      shiftOut(dataPin, clockPin, MSBFIRST, decimal);  // 1. 74hc595
      digitalWrite(latchPin, 1);
  
    switch(piso){
      case 0:
   
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,0);
          digitalWrite(piso8,1);
          //delay(tiempoRapido);
        break;
  
       case 1:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,0);
          digitalWrite(piso7,1);
          digitalWrite(piso8,1);
          //delay(tiempoRapido);
        break;
  
         case 2:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,0);
          digitalWrite(piso6,1);
          digitalWrite(piso7,1);
          digitalWrite(piso8,1);
          //delay(tiempoRapido);
        break;
  
        case 3:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,0);
          digitalWrite(piso5,1);
          digitalWrite(piso6,1);
          digitalWrite(piso7,1);
          digitalWrite(piso8,1);
         // delay(tiempoRapido);
        break;
  
        case 4:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,0);
          digitalWrite(piso4,1);
          digitalWrite(piso5,1);
          digitalWrite(piso6,1);
          digitalWrite(piso7,1);
          digitalWrite(piso8,1);
          //delay(tiempoRapido);
        break;
  
       case 5:
          digitalWrite(piso1,0);
          digitalWrite(piso2,0);
          digitalWrite(piso3,1);
          digitalWrite(piso4,1);
          digitalWrite(piso5,1);
          digitalWrite(piso6,1);
          digitalWrite(piso7,1);
          digitalWrite(piso8,1);
         // delay(tiempoRapido);
        break;
  
        case 6: 
          digitalWrite(piso1,0);
          digitalWrite(piso2,1);
          digitalWrite(piso3,1);
          digitalWrite(piso4,1);
          digitalWrite(piso5,1);
          digitalWrite(piso6,1);
          digitalWrite(piso7,1);
          digitalWrite(piso8,1);
         // delay(tiempoRapido);
        break;

        case 7: 
          digitalWrite(piso1,1);
          digitalWrite(piso2,1);
          digitalWrite(piso3,1);
          digitalWrite(piso4,1);
          digitalWrite(piso5,1);
          digitalWrite(piso6,1);
          digitalWrite(piso7,1);
          digitalWrite(piso8,1);
          //delay(tiempoRapido);
        break;
    }
 
}

//________________________________________________________________________________________________________________________________
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||     Figuras de prueba    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void cuboLleno(){

  for(int i=0; i<=5; i++){
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 8. 74hc595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 7. 74hc595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 6. 74hc595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 5. 74hc595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 4. 74hc595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 3. 74hc595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 2. 74hc595
    shiftOut(dataPin, clockPin, MSBFIRST, 255);  // 1. 74hc595
    digitalWrite(latchPin, 1);

    digitalWrite(piso1,1);
    digitalWrite(piso2,1);
    digitalWrite(piso3,1);
    digitalWrite(piso4,1);
    digitalWrite(piso5,1);
    digitalWrite(piso6,1);
    digitalWrite(piso7,1);
    digitalWrite(piso8,1);
    //delay(tiempoRapido);

    digitalWrite(piso1,0);
    digitalWrite(piso2,0);
    digitalWrite(piso3,0);
    digitalWrite(piso4,0);
    digitalWrite(piso5,0);
    digitalWrite(piso6,0);
    digitalWrite(piso7,0);
    digitalWrite(piso8,0);
    //delay(tiempoRapido);
  }
  
}

//________________________________________________________________________________________________________________________________
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||     WiFi    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//WiFi, va dentro de loop
void wifi(){

   
  String TARGET_ID="0";
  String TARGET_TYPE="TCP";
  String TARGET_ADDR="nodejsp2.appspot.com";
  String TARGET_PORT="80";

  String cmd="AT+CIPSTART=" + TARGET_ID;
  cmd += ",\"" + TARGET_TYPE + "\",\"" + TARGET_ADDR + "\"";
  cmd += ","+ TARGET_PORT;

  Serial1.println(cmd);
  ESP8266.println(cmd);
  delay(100);
  //Assume OK
  //display and clear buffer
  clearESP8266SerialBuffer();
  
  /*
  GET / HTTP/1.1\r\n
  Host: www.example.com:80\r\n\r\n
  */
  String HTTP_RQS ="GET /5 HTTP/1.1\r\n";
  HTTP_RQS += "Host: " + TARGET_ADDR;
  HTTP_RQS += ":" + TARGET_PORT + "\r\n\r\n";
  
  String cmdSEND_length = "AT+CIPSEND=";
  cmdSEND_length += TARGET_ID + "," + HTTP_RQS.length() +"\r\n";
  
  ESP8266.print(cmdSEND_length);
  Serial1.println(cmdSEND_length);
  
  Serial1.println("waiting >");
  
//  if(!ESP8266.available());
  
  if(ESP8266.find(">")){
    Serial1.println("> received");
    ESP8266.println(HTTP_RQS);
    Serial1.println(HTTP_RQS);
    
    boolean OK_FOUND = false;
    
    //program blocked untill "SEND OK" return
    while(!OK_FOUND){
      if(ESP8266.readBytesUntil('\n', buffer, BUFFER_SIZE)>0){
        
        if(strncmp(buffer, "SEND OK", 7)==0){
          OK_FOUND = true;
        }else{
        }
      }
    }

    if(OK_FOUND){
//      Serial.println("Aqui recibo perro");
      //Dummy display received data
      //until connection CLOSED, "</HTML>" or "</html>" received
      //only compare beginning of lines
      int i;    
      
      while((i=ESP8266.readBytesUntil('\n', buffer, BUFFER_SIZE-1))>=0){
        buffer[i] = '\0';  //insert terminator
//        Serial.println("Inicio buffer");
        //Serial.println(buffer + 'p');
        String json = String(buffer);
        //tepo marik
        if(json!=""){
          if(json.indexOf('{')>=0){
            json = String(buffer);
            deserializar(json);
            break;
          }
        }
        else{
          break;
        }
        
        //Serial.println(buffer);
//        Serial.println("Fin buffer");
        //have to match with TARGET_ID
        if(strncmp(buffer, "0,CLOSED", 7)==0){
          Serial1.println("CLOSED");
          break;
        }
        if(strncmp(buffer, "</HTML>", 7)==0){
          Serial1.println("</HTML> found");
          break;
        }
        if(strncmp(buffer, "</html>", 7)==0){
          Serial1.println("</html> found");
          break;
        }
      }
    }
    
  }else{
    Serial1.println("> NOT received, something wrong!");
  }
  
  //Close connection
  String cmdCIPCLOSE = "AT+CIPCLOSE=" + TARGET_ID; 
  ESP8266.println(cmdCIPCLOSE);
  Serial1.println(cmdCIPCLOSE);
  
  delay(10000);
  
  
}

//WiFi, dentro del setup
void wifiSetup(){
  //WIFI
  pinMode(LED, OUTPUT);
  
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);

  do{
    //Serial.begin(9600);
    //ESP8266.begin(9600);
    Serial1.begin(115200);
    ESP8266.begin(115200);
  
    //Wait Serial Monitor to start
    while(!Serial);
    Serial1.println("--- Start ---");

    ESP8266.println("AT+RST\r\n");
  
    if(ESP8266.find("ready"))
    {
      Serial1.println("Module is ready");
      sendData("AT+CWMODE=3\r\n",1000,DEBUG); // configuración punto de acceso
      sendData("AT+CIPMUX=1\r\n",1000,DEBUG); // multiples conexiones
      sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // encender servidor en puerto 80
      delay(7000);
      //Quit existing AP, for demo
      Serial1.println("Quit AP");
      ESP8266.println("AT+CWQAP\r\n");
      delay(1000);    
      clearESP8266SerialBuffer();
      if(cwJoinAP())
      {
        Serial1.println("CWJAP Success");
        FAIL_8266 = false;
        
        delay(3000);
        clearESP8266SerialBuffer();
        //Get and display my IP
        sendData("AT+CIFSR\r\n",1000,DEBUG); // se obtienen direcciones IP 
        delay(5000); 
        Serial1.println("Setup finish");
      }else{
        Serial1.println("CWJAP Fail");
        delay(500);
        FAIL_8266 = true;
      }
    }else{
      Serial1.println("Module have no response.");
      delay(500);
      FAIL_8266 = true;
    }
  }while(FAIL_8266);
  
  digitalWrite(LED, HIGH);
  
  //set timeout duration ESP8266.readBytesUntil
  ESP8266.setTimeout(1000);
//_____________
}

boolean waitOKfromESP8266(int timeout){
  do{
    Serial1.println("wait OK...");
    delay(1000);
    if(ESP8266.find("OK"))
    {
      return true;
    }

  }while((timeout--)>0);
  return false;
}

boolean cwJoinAP(){
  String cmd="AT+CWJAP=\"" + SSID + "\",\"" + PASSWORD + "\"";
  ESP8266.println(cmd);
  return waitOKfromESP8266(10);
}

String sendData(String command, const int timeout, boolean debug){
    String response = "";
    ESP8266.print(command); // Se envía el carácter de lectura a la esp8266
    long int time = millis();
    while( (time+timeout) > millis())
    {while(ESP8266.available())
      { 
        char c = ESP8266.read(); // Lee el siguiente carácter.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial1.print(response);
    }    
    return response;
}

void clearESP8266SerialBuffer(){
  Serial.println("= clearESP8266SerialBuffer() =");
  while (ESP8266.available() > 0) {
    char a = ESP8266.read();
    Serial.write(a);
  }
  Serial.println("==============================");
}
//________________________________________________________________________________________________________________________________
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||     JSON    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void deserializar(String jsonString){
    // Use arduinojson.org/assistant to compute the capacity.
  //StaticJsonBuffer<200> jsonBuffer;

  // StaticJsonBuffer allocates memory on the stack, it can be
  // replaced by DynamicJsonBuffer which allocates in the heap.
  //
   DynamicJsonBuffer  jsonBuffer(200);

  // JSON input string.
  //
  // It's better to use a char[] as shown here.
  // If you use a const char* or a String, ArduinoJson will
  // have to make a copy of the input in the JsonBuffer.
  char json[jsonString.length() + 1];
  jsonString.toCharArray(json, jsonString.length());
//      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

  // Root of the object tree.
  //
  // It's a reference to the JsonObject, the actual bytes are inside the
  // JsonBuffer with all the other nodes of the object tree.
  // Memory is freed when jsonBuffer goes out of scope.
  //JsonObject& root = jsonBuffer.parseObject(json);
  
  
  JsonObject& objeto = jsonBuffer.parseObject(jsonString);

  
  
  JsonArray& objeto0 = objeto["objeto"];

  int tamObjeto = objeto.size();
  int memoriaUsada = jsonBuffer.size();
  // Test if parsing succeeds.
  String tipoFigura = "";
  
  if (objeto.success()) {
   // Serial.println("contenido: ");
   
//Serial.println(objeto0.size());
    for(int i=0; i<objeto0.size(); i++){
       if(objeto0[i]["Contenido"].is<int>()){
       // Serial.println("es numero");
        int numElegido = objeto0[i]["Contenido"].as<int>();
        //Serial.println(numElegido);
        int now   = millis(); 
        int  now2=millis();
        switch(numElegido){
          case 1:
            while((now2-now)<=5000){
              recorre(cilindro);
              now2 = millis();
            }
            break;
          case 2:
            while((now2-now)<=5000){
            recorre(corazon);
            now2 = millis();
            }
            break;
          case 3:
            while((now2-now)<=5000){
              recorre(piramide);
              now2 = millis();
            }
            break;
          case 4:
            while((now2-now)<=5000){
              recorre(cubo);
              now2 = millis();
            }
            break;
          case -1:
          //Devuelve control Assembler
            while(Serial.available()){
            }
            Serial.print(1); 
            while(!Serial.available()){
                  
            }
            modo=Serial.read();        
            return;
        }
       } else if(objeto0[i]["Contenido"].is<char*>()){
          //Serial.println("es texto");
          printPalabraDrIz(objeto0[i]["Contenido"].as<char*>());
       }
        //recorre(ESPACIO);
              
    }
    
    //return;
  }else{
  }

  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do root["time"].as<long>();

}


//________________________________________________________________________________________________________________________________
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||     corrimiento    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||


 void printPalabraDrIz(char * palabra){
        int cantidad_Letras=0;
        while (palabra[cantidad_Letras]!='\0') {
            cantidad_Letras++;
        }
        int coordenanaX0=0;
        int cantidadColumnas=cantidad_Letras*10;
        int matrizLetrasConsola[8][cantidadColumnas];
        int contador=0;
        for (int i =0;i<8;i++) {
            for (int j=0;j<cantidadColumnas;j++){
                matrizLetrasConsola[i][j]=0;
            }
        }
        for (int k=0;k<cantidad_Letras;k++) {
            EncontrarMatrizLetra(palabra[k]);
            for (int i =0;i<8;i++) {
                for (int j =0;j<8;j++){
                    matrizLetrasConsola[i][j+coordenanaX0]=GLOBAL[contador];
                    contador++;
                }
            }
            //printf("\n");
            contador=0;
            coordenanaX0=coordenanaX0+10;
        }
        byte matTemporal[8][8];
        for (int i=0;i<cantidadColumnas-8;i++) {
            for (int j=0;j<8;j++) {
                for (int k=i;k<(i+8);k++) {
                    matTemporal[j][k-i]=matrizLetrasConsola[j][k];
                }
            }
            recorre(matTemporal);
        }
    }



  void printPalabraIzDr(char * palabra){
    int cantidad_Letras=0;
    char * palabraV=(char*)malloc(sizeof (palabra));
    while (palabra[cantidad_Letras]!='\0') {
        cantidad_Letras++;
    }
    for (int i=0;i<cantidad_Letras;i++) {
        palabraV[i]=palabra[cantidad_Letras-i-1];
    }
    int coordenanaX0=0;
    int cantidadColumnas=cantidad_Letras*10;
    int matrizLetrasConsola[8][cantidadColumnas];
    int contador=0;
    for (int i =0;i<8;i++) {
        for (int j=0;j<cantidadColumnas;j++){
            matrizLetrasConsola[i][j]=0;
        }
    }
    for (int k=0;k<cantidad_Letras;k++) {
        EncontrarMatrizLetra(palabraV[k]);
        for (int i =0;i<8;i++) {
            for (int j =0;j<8;j++){
                matrizLetrasConsola[i][j+coordenanaX0]=GLOBAL[contador];
                contador++;
            }
        }
        contador=0;
        coordenanaX0=coordenanaX0+10;
    }
    byte matTemporal[8][8];
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            matTemporal[i][j]=0;
        }
    }
    int finalMatTemp=cantidadColumnas;
    while ((finalMatTemp-8)>0) {
        int inicioMatTem=finalMatTemp-8;
        for (int i=0;i<8;i++) {
            for (int j=inicioMatTem;j<finalMatTemp;j++) {
                matTemporal[i][j-inicioMatTem]=matrizLetrasConsola[i][j];
            }
        }

        finalMatTemp=finalMatTemp-1;
        recorre(matTemporal);
    }
}

//________________________________________________________________________________________________________________________________
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||     snake    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

 bool comprobarEntero(int ob){
    if(ob=='1')
      return true;
    else if(ob=='2')
      return true;
    else if(ob=='3')
      return true;
    else if(ob=='4')
      return true;
    else if(ob=='5')
      return true;
    else if(ob=='6')
      return true;
    else if(ob=='7')
      return true;
    else if(ob=='8')
      return true;
    else if(ob=='9')
      return true;
    else if(ob=='0')
      return true;
    else 
      return false;
    
  }

int PasarEntero(int ob){
    if(ob=='1')
      return 1;
    else if(ob=='2')
      return 2;
    else if(ob=='3')
      return 3;
    else if(ob=='4')
      return 4;
    else if(ob=='5')
      return 5;
    else if(ob=='6')
      return 6;
    else if(ob=='7')
      return 7;
    else if(ob=='8')
      return 8;
    else if(ob=='9')
      return 9;
    else if(ob=='0')
      return 0;
    else 
      return -1;
    
  }

//________________________________________________________________________________________________________________________________
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||     musica    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
void EscucharMusica(int factor, int animacion){
  /* 1 = Pisos
   * 2 = Cubos
   * 3 = Barras
  **/
  volumen=analogRead(A0);
  if(animacion == 1){
     if(volumen>minimo&&volumen<minimo+factor){
        nivelMuisica=0;
        dibujarSonido(255,0);
     }else if(volumen>(minimo+factor)&&volumen<(minimo+2*factor)){
        nivelMuisica=1;
        dibujarSonido(255,1);
     }else if(volumen>(minimo+2*factor)&&volumen<(minimo+3*factor)){
        nivelMuisica=2;
        dibujarSonido(255,2);
     }else if(volumen>(minimo+3*factor)&&volumen<(minimo+4*factor)){
        nivelMuisica=3;
        dibujarSonido(255,3);
     }else if(volumen>(minimo+4*factor)&&volumen<(minimo+5*factor)){
        nivelMuisica=4;
        dibujarSonido(255,4);
     }else if(volumen>(minimo+5*factor)&&volumen<(minimo+6*factor)){
        nivelMuisica=5;
        dibujarSonido(255,5);
     }else if(volumen>(minimo+6*factor)&&volumen<(minimo+7*factor)){
        nivelMuisica=6;
        dibujarSonido(255,6);
     }else if(volumen>(minimo+7*factor)&&volumen<(minimo+8*factor)){
        nivelMuisica=7;
        dibujarSonido(255,7);
     }
  } else if(animacion == 2){
        if(volumen>minimo&&volumen<minimo+factor){
            nivelMuisica=0;
            recorre(cubo3);
         }else if(volumen>(minimo+factor)&&volumen<(minimo+2*factor)){
            nivelMuisica=1;
            recorre(cubo4);
         }else if(volumen>(minimo+2*factor)&&volumen<(minimo+3*factor)){
            nivelMuisica=2;
            recorre(cubo5);
         }else if(volumen>(minimo+3*factor)&&volumen<(minimo+4*factor)){
            nivelMuisica=3;
            recorre(cubo5);
         }else if(volumen>(minimo+4*factor)&&volumen<(minimo+5*factor)){
            nivelMuisica=4;
            recorre(cubo6);
         }else if(volumen>(minimo+5*factor)&&volumen<(minimo+6*factor)){
            nivelMuisica=5;
            recorre(cubo6);
         }else if(volumen>(minimo+6*factor)&&volumen<(minimo+7*factor)){
            nivelMuisica=6;
            recorre(cubo7);
         }else if(volumen>(minimo+7*factor)&&volumen<(minimo+8*factor)){
            nivelMuisica=7;
            recorre(cubo7);
        }
     } else if (animacion == 3){
        if(volumen>minimo&&volumen<minimo+factor){
          nivelMuisica=0;
          recorre(m1);
       }else if(volumen>(minimo+factor)&&volumen<(minimo+2*factor)){
          nivelMuisica=1;
          recorre(m2);
       }else if(volumen>(minimo+2*factor)&&volumen<(minimo+3*factor)){
          nivelMuisica=2;
          recorre(m3);
       }else if(volumen>(minimo+3*factor)&&volumen<(minimo+4*factor)){
          nivelMuisica=3;
          recorre(m4);
       }else if(volumen>(minimo+4*factor)&&volumen<(minimo+5*factor)){
          nivelMuisica=4;
          recorre(m5);
       }else if(volumen>(minimo+5*factor)&&volumen<(minimo+6*factor)){
          nivelMuisica=5;
          recorre(m6);
       }else if(volumen>(minimo+6*factor)&&volumen<(minimo+7*factor)){
          nivelMuisica=6;
          recorre(m7);
       }else if(volumen>(minimo+7*factor)&&volumen<(minimo+8*factor)){
          nivelMuisica=7;
          recorre(m8);
     }
  }
//   
//   Serial.println(nivelMuisica);
//   Serial.println(volumen);
  }
//________________________________________________________________________________________________________________________________
