#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "main.h"
#include "stdbool.h"

struct key{

	bool Key_sta;
	bool Sigle_flag;
	uint Key_judge;
	bool Long_flag;							// 长按键
	bool Short_falg;						// 短按键
	uint Key_time;							// 按键时长

};

#endif
