/********************************************************************************/
/*Author      : Omar Elwy														*/
/*File Name   : WDT_interface.h													*/
/*Layer       : MCAL															*/
/*Description : This file contains interfacing paremeters of WDT module			*/
/*Date        : 22 March 2023													*/
/********************************************************************************/


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_


#define SLEEP_TIME_1SEC			6


/*This Function is to Enable Watch Dog Timer*/
void WDT_voidEnable(void);

/*This Function can Set Run The WDT with specific sleep time*/
void WDT_voidSetSleepTimer(u8 Copy_u8SleepTime);

/*This Function is to Disable Watch Dog Timer*/
void WDT_voidDisable(void);


#endif /* WDT_INTERFACE_H_ */
