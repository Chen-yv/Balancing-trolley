/***********************************************
公司：轮趣科技（东莞）有限公司
品牌：WHEELTEC
官网：wheeltec.net
淘宝店铺：shop114407458.taobao.com
速卖通: https://minibalance.aliexpress.com/store/4455017
版本：5.7
修改时间：2021-04-29

All rights reserved
***********************************************/

#include "stm32f10x.h"
#include "sys.h"
u8 Flag_Stop = 1;				   // 电机停止标志位，默认关闭
int Encoder_Left, Encoder_Right;   // 左右编码器的脉冲计数
float Angle_Balance, Gyro_Balance; // 平衡倾角 平衡陀螺仪
int main(void)
{
	int OLED_show = 1; // OLED显示标志位
	delay_init();				// 延时函数初始化
	JTAG_Set(JTAG_SWD_DISABLE); // 关闭JTAG接口
	JTAG_Set(SWD_ENABLE);		// 打开SWD接口 可以利用主板的SWD接口调试
	OLED_Init();				// OLED初始化

	KEY_Init(); // 按键初始化

	while (1)
	{
		// oled_show(); // 显示屏打开
		if (click())
		{
			OLED_show = !OLED_show; // 切换oled显示
		}
		if (OLED_show)
		{
			OLED_Display_On();
			OLED_ShowString(0, 0, "hello cjz");
			OLED_Refresh_Gram();
		}
		else{
			OLED_Clear();
			OLED_Refresh_Gram();
		}
	}
}
