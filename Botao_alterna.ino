#define led 4
#define btm 3
int btm_liberado = 0;
int btm_clicado = 0;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(btm , INPUT);

}
void troca_led(){
  if(digitalRead(led) == HIGH){
    digitalWrite(led , LOW);
  }
  else{
    digitalWrite(led , HIGH);
  }
}
void key_up(){
  if( (btm_clicado == 1) and (btm_liberado == 1)){
    btm_clicado =0;
    btm_liberado = 0;
    troca_led();
  }
}
void loop() {
  if(digitalRead(btm) == HIGH){
    btm_clicado =1;
    btm_liberado = 0;
  }
  else{
    btm_liberado =1 ;
  }
  key_up();
}
