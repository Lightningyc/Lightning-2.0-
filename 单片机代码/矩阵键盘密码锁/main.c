#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MrixKey.h"

unsigned char KeyNum;
unsigned int PassWord,Count;//�����������
void main()
{
    LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
   while(1)
   {
	   KeyNum=MrixKey();
	   if(KeyNum!=0)//�����ɿ���ִ��
	   {
		 if(KeyNum<=10)//���S1~S10���� 
		 {			 
	         if(Count<4)
			 {
			 PassWord*=10;//��ǰ�����ʮ��������һλ			
			 PassWord+=KeyNum%10;//��ʾ�����ʮȡ��
			 }
			 Count++;
		 }

		 LCD_ShowNum(1,10,PassWord,4);//��1��10�������λ����
	   }
	   if(KeyNum==15)//�������S15������ȷ�ϼ���
	   {
	     if(PassWord==1209)//���������ȷ
	     {
	     LCD_ShowString(2,1,"True ");//��ֹ�ַ��ص�
		 Delay(1500);	 
		 LCD_Init();
		 PassWord=0;//��������
	     Count=0;//�ƴ�����
		 LCD_ShowNum(1,10,PassWord,4);//������ʾ
		 LCD_ShowString(1,1,"PassWord:");			 
		 }
		 else//����
		 {
		 Delay(1500);	 
		 LCD_Init();
		 PassWord=0;//��������
	     Count=0;//�ƴ�����
		 LCD_ShowNum(1,10,PassWord,4);//������ʾ
		 LCD_ShowString(1,1,"PassWord:");	
		 }
       }
	   if(KeyNum==16)//�������S16������ȡ������
	   {
		 Delay(1500);	 
		 LCD_Init();
		 PassWord=0;//��������
	     Count=0;//�ƴ�����
		 LCD_ShowNum(1,10,PassWord,4);//������ʾ
		 LCD_ShowString(1,1,"PassWord:");	
	   }
   }

}