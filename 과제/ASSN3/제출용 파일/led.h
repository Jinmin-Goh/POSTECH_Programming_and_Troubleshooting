#ifndef __LED_H
#define __LED_H

void moveLEDLeft(char led[][220], int inputLength, double speed); //LED전광판 내용을 좌로 이동
void moveLEDRight(char led[][220], int inputLength, double speed); //LED전광판 내용을 우로 이동
void moveLEDUp(char led[][220], int inputLength, double speed); //LED전광판 내용을 위로 이동
void moveLEDDown(char led[][220], int inputLength, double speed); //LED전광판 내용을 아래로 이동
void makeArray(char led[][220], int inputLength, char string[]);	// string을 입력받아서 대응되는 단어의 표현형을 led 배열에 저장


#endif
