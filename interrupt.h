#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "main.h"
#include "stdbool.h"

struct key{

	bool Key_sta;
	bool Sigle_flag;
	uint Key_judge;
	bool Long_flag;							// ������
	bool Short_falg;						// �̰���
	uint Key_time;							// ����ʱ��

};

#endif
