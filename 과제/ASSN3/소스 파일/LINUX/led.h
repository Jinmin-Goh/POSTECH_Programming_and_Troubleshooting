#ifndef __LED_H
#define __LED_H

void moveLEDLeft(char led[][220], int inputLength, double speed); //LED������ ������ �·� �̵�
void moveLEDRight(char led[][220], int inputLength, double speed); //LED������ ������ ��� �̵�
void moveLEDUp(char led[][220], int inputLength, double speed); //LED������ ������ ���� �̵�
void moveLEDDown(char led[][220], int inputLength, double speed); //LED������ ������ �Ʒ��� �̵�
void makeArray(char led[][220], int inputLength, char string[]);	// string�� �Է¹޾Ƽ� �����Ǵ� �ܾ��� ǥ������ led �迭�� ����


#endif
