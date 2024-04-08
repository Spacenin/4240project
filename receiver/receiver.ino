#include <cc1101.h>
#include <macros.h>
#include <pins.h>
#include <registers.h>

#define packetSize 10
#define dataRate 4
#define logChannel 5

#define ARRSIZE 100

byte RX_buffer[10] = {0};
byte sizeRX;

int Xbuffer[ARRSIZE] = {0};
int Ybuffer[ARRSIZE] = {0};
int Zbuffer[ARRSIZE] = {0};
int counter = 0;

double calcAverage(int arr[]){
  int total = 0;
  for (int i = 0; i < ARRSIZE; i ++){
     total += arr[i];
  }
  return (double)total/ARRSIZE;
}

//the variance is the square of the standard deviation.
int variance (int arr[]){
  double avg = calcAverage(arr);
  double diff =0;
  for (int i = 0; i < n; i++) 
        diff += (arr[i] - avg) * 
                  (arr[i] - avg);
    return diff / n;
}

long getRand(){
  int axis = random(0,3);
  int index = random(0,ARRSIZE);
  int seed = 0;
  int buffer[100];
  if(axis == 0){
    //x axis
    buffer = Xbuffer;
  }else if(axis == 1){
    //y axis
    buffer = Ybuffer;
  }else{ // use the z axis
    buffer = Zbuffer;
  }
  //check to see if the accelerometer data is sufficiently random, we dont want our seed to be consistent.
    // too-consistent data is likely to happen if the cat is laying down/sleeping
  if (variance(buffer) < 144{
    //do something to the array? here
  }
  //we don't do anything if data is sufficiently spread
  seed = buffer[index];
  randomSeed(seed);
  return random();
}

void setup() {
  Serial.begin(9600);
  
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  
  Radio.Init();
  Radio.SetDataRate(dataRate);
  Radio.SetLogicalChannel(logChannel);
  Radio.SetTxPower(1);

  Radio.RxOn();
}

void loop() {
  if (Radio.CheckReceiveFlag()) {
    digitalWrite(RED_LED, HIGH);
    
    sizeRX = Radio.ReceiveData(RX_buffer);

    int xVal = RX_buffer[1] | (RX_buffer[2] << 8);
    int yVal = RX_buffer[3] | (RX_buffer[4] << 8);
    int zVal = RX_buffer[5] | (RX_buffer[6] << 8);

    Serial.print("packet num: ");
    Serial.println(RX_buffer[0]);
   
    Serial.println(xVal);
    Xbuffer[counter] = xVal;
    Serial.print("y: ");
    Serial.println(yVal);
    Ybuffer[counter] = yVal;
    Serial.print("z: ");
    Serial.println(zVal); 
    Zbuffer[counter] = zVal;
    counter = (counter+1)%100;

    delay(500);
    digitalWrite(RED_LED, LOW);

    Radio.RxOn();
  }
  Serial.println(getRand());
  
}
