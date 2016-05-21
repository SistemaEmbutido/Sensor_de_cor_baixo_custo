// Define colour sensor LED pins
int leds[] = {2,3,4};

//vetor que sera salvo os valores das cores da leitura
float cores[] = {0,0,0};

//variavel para salvar o valor obtido da leitura do LDR
int valor_cor;


void setup(){
 
  //Configura os pinos utilizados pelos leds como saida
  pinMode(leds[0],OUTPUT);//Vermelho
  pinMode(leds[1],OUTPUT);//Verde
  pinMode(leds[2],OUTPUT);//Azul
 
  //Configura a serial para trabalhar com um baud rate de 9600
  Serial.begin(9600);
 
}

void loop(){

    leituraRGB();
    imprimeRGB();
}

void leituraRGB(){
  for(int i = 0;i<=2;i++){
     digitalWrite(leds[i],HIGH);//Acende a cor que sera realizada a leitura
     delay(100);                    
     
     getCores(5);                  //realiza n leituras simultaneas e pega a media do valor
     cores[i] = valor_cor;         //salva o valor obtido no vetor
     
     digitalWrite(leds[i],LOW);//Apaga a cor que sera realizada a leitura
     delay(100);
  }
}
void getCores(int count){
  int reading;
  int total=0;
  
  for(int i = 0;i < count;i++){
     reading = analogRead(0);
     total = reading + total;
     delay(10);
  }
  
  //calcula o valor medio das leituras realizadas
  valor_cor = (total)/count;
}

//imprime no terminal qual o valor detectado de cada cor
void imprimeRGB(){
  Serial.print("R = ");
  Serial.println(int(cores[0]));
  Serial.print("G = ");
  Serial.println(int(cores[1]));
  Serial.print("B = ");
  Serial.println(int(cores[2]));
}


