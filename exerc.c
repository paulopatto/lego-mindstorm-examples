/*
1 – Considere que o robô de esteiras utilizado no Laboratório de Robótica foi montado com os motores esquerdo e direito conectados às saídas A e C, respectivamente.
	Desenvolva um programa que faça o robô descrever as seguintes trajetórias:
	 4s
	a - b
	|   | 2s
	c - d
	
	 4s 
	a - b 3s
	6s/
	c - d 
*/

#define TEMPO_DE_GIRO 170
#define TEMPO_DE_MOVIMENTO 400

void movToRight(int time){
	Off(OUT_A+OUT_C);
	OnRev(OUT_A);
	OnFwd(OUT_C);
	Wait(time);
}
void movToLeft(int time){
	Off(OUT_A+OUT_C);
	OnFwd(OUT_A);
	OnRev(OUT_C);
	Wait(time);
}
void walkingFront(int time){
	Off(OUT_A+OUT_C);
	OnFwd(OUT_A+OUT_C);
	Wait(time);
}
void walkingBack(int time){
	Off(OUT_A+OUT_C);
	OnRev(OUT_A+OUT_C);
	Wait(time);
}

void DrawMoveSquare(){
  /// A - B
	walkingFront(TEMPO_DE_MOVIMENTO);
  /// B - C
  movToRight(TEMPO_DE_GIRO);
 	walkingFront(200);
 	
 	/// C - D
	movToRight(TEMPO_DE_GIRO);
	walkingFront(TEMPO_DE_MOVIMENTO);
	
	/// D - A
	movToRight(TEMPO_DE_GIRO);
	walkingFront(200);
}

void DrawMoveZigZag(){}

void moveAndDigress(){
    while(true){
      OnFwd(OUT_A+OUT_C);
      if(SENSOR_2 == 1){
        walkingBack(TEMPO_DE_GIRO);
        movToRight(TEMPO_DE_GIRO);
      }
      if(SENSOR_3 == 1){
        walkingBack(TEMPO_DE_GIRO);
        movToLeft(TEMPO_DE_GIRO);
      }
    }
}


task main(){
	moveAndDigress();
}