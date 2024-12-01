#define LED 3
#define MAX 16
#define MIN 0
#define TMP 100
void setup() {
  pinMode(LED,OUTPUT);

}

void loop() {
  int i;
  for(i=0 ; i< MAX;i++){
    analogWrite(LED,i);
    delay(TMP);
  }
  
 for(i=MAX ; i>MIN;i--){
    analogWrite(LED,i);
    delay(TMP);
  }

}
