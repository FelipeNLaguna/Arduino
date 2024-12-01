#define led_red 2
#define led_green 3
#define led_blue 4
#define btn 5
#define maximo 7

int btn_clicado = 0;
int btn_liberado = 0;
int ciclo = 0; // qual cor o led acende

void vermelho(){
  digitalWrite(led_red,HIGH);
  digitalWrite(led_green,LOW);
  digitalWrite(led_blue,LOW);
}
void verde(){
  digitalWrite(led_red,LOW);
  digitalWrite(led_green,HIGH);
  digitalWrite(led_blue,LOW);
}
void azul(){
  digitalWrite(led_red,LOW);
  digitalWrite(led_green,LOW);
  digitalWrite(led_blue,HIGH);
}

void cor1(){
  digitalWrite(led_red,HIGH);
  digitalWrite(led_green,HIGH);
  digitalWrite(led_blue,HIGH);
}
void cor2(){
  digitalWrite(led_red,HIGH);
  digitalWrite(led_green,LOW);
  digitalWrite(led_blue,HIGH);
}
void cor3(){
  digitalWrite(led_red,LOW);
  digitalWrite(led_green,HIGH);
  digitalWrite(led_blue,HIGH);
}
void cor4(){
  digitalWrite(led_red,HIGH);
  digitalWrite(led_green,HIGH);
  digitalWrite(led_blue,LOW);
}
void troca_led(){
  if(ciclo == 0){
    vermelho();
  }
  else if(ciclo == 1){
    verde();
  }
  else if(ciclo == 2){
    azul();
  }
  else if(ciclo == 3){
    cor1();
  }
  else if(ciclo == 4){
    cor2();
  }
  else if(ciclo == 5){
    cor3();
  }
  else{
    cor4();
  }
  ciclo = (ciclo+1) % maximo;
}
void verifica_btn(){
  if(digitalRead(btn) == HIGH){
    btn_clicado = true;
    btn_liberado = false;
  }
  else{
    btn_liberado  = true;
  }
  if( (btn_clicado == true) and (btn_liberado == true) ){
    btn_clicado = false;
    btn_liberado = false;
    troca_led();
  }
}

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_green,OUTPUT);
  pinMode(led_blue,OUTPUT);
  pinMode(btn,INPUT);

}

void loop() {
  verifica_btn();

}
