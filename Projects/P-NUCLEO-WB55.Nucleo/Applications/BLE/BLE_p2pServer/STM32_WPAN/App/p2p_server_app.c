/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    p2p_server_app.c
  * @author  MCD Application Team
  * @brief   Peer to peer Server Application
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_common.h"
#include "dbg_trace.h"
#include "ble.h"
#include "p2p_server_app.h"
#include "stm32_seq.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "AD5697R.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
 typedef struct{
    uint8_t             Device_Led_Selection;
    uint8_t             Led1;
 }P2P_LedCharValue_t;

 typedef struct{
    uint8_t             Device_Button_Selection;
    uint8_t             ButtonStatus;
    uint8_t             ButtonStatus2;
    uint8_t             ButtonStatus3;
 }P2P_ButtonCharValue_t;

 typedef struct{
	 uint8_t			sDelimiter;
	 uint8_t			Code;
	 uint8_t			vDelimiter; // vVal is going to be DAC input voltage, which corresponds to set Ids current.
	 uint8_t			vVal1;
	 uint8_t			vVal2;
	 uint8_t			vVal3;
	 uint8_t			vVal4;

	 uint8_t			iDelimiter; // iVal is going to be ADC value, which corresponds to Vds. iValXY means a channel X and digit Y
	 uint8_t			iVal11;
	 uint8_t			iVal12;
	 uint8_t			iVal13;
	 uint8_t			iVal14;
	 uint8_t			iVale1;
	 uint8_t			iVal21;
	 uint8_t			iVal22;
	 uint8_t			iVal23;
	 uint8_t			iVal24;
	 uint8_t			iVale2;
	 uint8_t			eDelimiter;

 }P2P_FETValue_t;

typedef struct
{
  uint8_t               Notification_Status; /* used to check if P2P Server is enabled to Notify */
  P2P_LedCharValue_t    LedControl;
  P2P_ButtonCharValue_t ButtonControl;
  P2P_FETValue_t		FETVal;
  uint16_t              ConnectionHandle;
} P2P_Server_App_Context_t;
/* USER CODE END PTD */

/* Private defines ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macros -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/**
 * START of Section BLE_APP_CONTEXT
 */

PLACE_IN_SECTION("BLE_APP_CONTEXT") static P2P_Server_App_Context_t P2P_Server_App_Context;
double dacV0 = 0;
double dacV1 = 0;
int globalTick = 0;
int sweepFlag = 0;
int adcTick = 0;
int adcFlag = 0;
int adcCount = 0;
uint32_t adcSum0 = 0;
int adcChannel = 0;
uint32_t adcSum1 = 0;
int samplingTick = 0;
int samplingFlag = 0;
uint16_t adcBuffer[2] = {0};


double adcV_offset = 0.0;

extern hadc1;
/**
 * END of Section BLE_APP_CONTEXT
 */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
static void P2PS_Send_Notification(void);
static void P2PS_APP_LED_BUTTON_context_Init(void);
double ival_Calibration(double);
/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void P2PS_STM_App_Notification(P2PS_STM_App_Notification_evt_t *pNotification)
{
/* USER CODE BEGIN P2PS_STM_App_Notification_1 */

/* USER CODE END P2PS_STM_App_Notification_1 */
  switch(pNotification->P2P_Evt_Opcode)
  {
/* USER CODE BEGIN P2PS_STM_App_Notification_P2P_Evt_Opcode */
#if(BLE_CFG_OTA_REBOOT_CHAR != 0)
    case P2PS_STM_BOOT_REQUEST_EVT:
      APP_DBG_MSG("-- P2P APPLICATION SERVER : BOOT REQUESTED\n");
      APP_DBG_MSG(" \n\r");

      *(uint32_t*)SRAM1_BASE = *(uint32_t*)pNotification->DataTransfered.pPayload;
      NVIC_SystemReset();
      break;
#endif
/* USER CODE END P2PS_STM_App_Notification_P2P_Evt_Opcode */

    case P2PS_STM__NOTIFY_ENABLED_EVT:
/* USER CODE BEGIN P2PS_STM__NOTIFY_ENABLED_EVT */
      P2P_Server_App_Context.Notification_Status = 1;
      APP_DBG_MSG("-- P2P APPLICATION SERVER : NOTIFICATION ENABLED\n"); 
      APP_DBG_MSG(" \n\r");
/* USER CODE END P2PS_STM__NOTIFY_ENABLED_EVT */
      break;

    case P2PS_STM_NOTIFY_DISABLED_EVT:
/* USER CODE BEGIN P2PS_STM_NOTIFY_DISABLED_EVT */
      P2P_Server_App_Context.Notification_Status = 0;
      APP_DBG_MSG("-- P2P APPLICATION SERVER : NOTIFICATION DISABLED\n");
      APP_DBG_MSG(" \n\r");
/* USER CODE END P2PS_STM_NOTIFY_DISABLED_EVT */
      break;

    case P2PS_STM_WRITE_EVT:
/* USER CODE BEGIN P2PS_STM_WRITE_EVT */
      if(pNotification->DataTransfered.pPayload[0] == 0x00){ /* ALL Deviceselected - may be necessary as LB Routeur informs all connection */
        if(pNotification->DataTransfered.pPayload[1] == 0x01)
        {
          BSP_LED_On(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER  : LED1 ON\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x01; /* LED1 ON */
        }
        if(pNotification->DataTransfered.pPayload[1] == 0x00)
        {
          BSP_LED_Off(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER  : LED1 OFF\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x00; /* LED1 OFF */
        }
      }
#if(P2P_SERVER1 != 0)  
      if(pNotification->DataTransfered.pPayload[0] == 0x01){ /* end device 1 selected - may be necessary as LB Routeur informs all connection */
        if(pNotification->DataTransfered.pPayload[1] == 0x01)
        {
          BSP_LED_On(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 1 : LED1 ON\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x01; /* LED1 ON */
        }
        if(pNotification->DataTransfered.pPayload[1] == 0x00)
        {
          BSP_LED_Off(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 1 : LED1 OFF\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x00; /* LED1 OFF */
        }
      }
#endif
#if(P2P_SERVER2 != 0)
      if(pNotification->DataTransfered.pPayload[0] == 0x02){ /* end device 2 selected */ 
        if(pNotification->DataTransfered.pPayload[1] == 0x01)
        {
          BSP_LED_On(LED_BLUE);
           APP_DBG_MSG("-- P2P APPLICATION SERVER 2 : LED1 ON\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x01; /* LED1 ON */
        }
        if(pNotification->DataTransfered.pPayload[1] == 0x00)
        {
          BSP_LED_Off(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 2 : LED1 OFF\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x00; /* LED1 OFF */
        }   
      }
#endif      
#if(P2P_SERVER3 != 0)  
      if(pNotification->DataTransfered.pPayload[0] == 0x03){ /* end device 3 selected - may be necessary as LB Routeur informs all connection */
        if(pNotification->DataTransfered.pPayload[1] == 0x01)
        {
          BSP_LED_On(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 3 : LED1 ON\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x01; /* LED1 ON */
        }
        if(pNotification->DataTransfered.pPayload[1] == 0x00)
        {
          BSP_LED_Off(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 3 : LED1 OFF\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x00; /* LED1 OFF */
        }
      }
#endif
#if(P2P_SERVER4 != 0)
      if(pNotification->DataTransfered.pPayload[0] == 0x04){ /* end device 4 selected */ 
        if(pNotification->DataTransfered.pPayload[1] == 0x01)
        {
          BSP_LED_On(LED_BLUE);
           APP_DBG_MSG("-- P2P APPLICATION SERVER 2 : LED1 ON\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x01; /* LED1 ON */
        }
        if(pNotification->DataTransfered.pPayload[1] == 0x00)
        {
          BSP_LED_Off(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 2 : LED1 OFF\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x00; /* LED1 OFF */
        }   
      }
#endif     
#if(P2P_SERVER5 != 0)  
      if(pNotification->DataTransfered.pPayload[0] == 0x05){ /* end device 5 selected - may be necessary as LB Routeur informs all connection */
        if(pNotification->DataTransfered.pPayload[1] == 0x01)
        {
          BSP_LED_On(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 5 : LED1 ON\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x01; /* LED1 ON */
        }
        if(pNotification->DataTransfered.pPayload[1] == 0x00)
        {
          BSP_LED_Off(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 5 : LED1 OFF\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x00; /* LED1 OFF */
        }
      }
#endif
#if(P2P_SERVER6 != 0)
      if(pNotification->DataTransfered.pPayload[0] == 0x06){ /* end device 6 selected */ 
        if(pNotification->DataTransfered.pPayload[1] == 0x01)
        {
          BSP_LED_On(LED_BLUE);
           APP_DBG_MSG("-- P2P APPLICATION SERVER 6 : LED1 ON\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x01; /* LED1 ON */
        }
        if(pNotification->DataTransfered.pPayload[1] == 0x00)
        {
          BSP_LED_Off(LED_BLUE);
          APP_DBG_MSG("-- P2P APPLICATION SERVER 6 : LED1 OFF\n"); 
          APP_DBG_MSG(" \n\r");
          P2P_Server_App_Context.LedControl.Led1=0x00; /* LED1 OFF */
        }   
      }
#endif 
/* USER CODE END P2PS_STM_WRITE_EVT */
      break;

    default:
/* USER CODE BEGIN P2PS_STM_App_Notification_default */
      
/* USER CODE END P2PS_STM_App_Notification_default */
      break;
  }
/* USER CODE BEGIN P2PS_STM_App_Notification_2 */

/* USER CODE END P2PS_STM_App_Notification_2 */
  return;
}

void P2PS_APP_Notification(P2PS_APP_ConnHandle_Not_evt_t *pNotification)
{
/* USER CODE BEGIN P2PS_APP_Notification_1 */

/* USER CODE END P2PS_APP_Notification_1 */
  switch(pNotification->P2P_Evt_Opcode)
  {
/* USER CODE BEGIN P2PS_APP_Notification_P2P_Evt_Opcode */

/* USER CODE END P2PS_APP_Notification_P2P_Evt_Opcode */
  case PEER_CONN_HANDLE_EVT :
/* USER CODE BEGIN PEER_CONN_HANDLE_EVT */
          
/* USER CODE END PEER_CONN_HANDLE_EVT */
    break;

    case PEER_DISCON_HANDLE_EVT :
/* USER CODE BEGIN PEER_DISCON_HANDLE_EVT */
       P2PS_APP_LED_BUTTON_context_Init();       
/* USER CODE END PEER_DISCON_HANDLE_EVT */
    break;

    default:
/* USER CODE BEGIN P2PS_APP_Notification_default */

/* USER CODE END P2PS_APP_Notification_default */
      break;
  }
/* USER CODE BEGIN P2PS_APP_Notification_2 */

/* USER CODE END P2PS_APP_Notification_2 */
  return;
}

void P2PS_APP_Init(void)
{
/* USER CODE BEGIN P2PS_APP_Init */
  UTIL_SEQ_RegTask( 1<< CFG_TASK_SW1_BUTTON_PUSHED_ID, UTIL_SEQ_RFU, P2PS_Send_Notification );

  /**
   * Initialize LedButton Service
   */
  P2P_Server_App_Context.Notification_Status=0; 
  P2PS_APP_LED_BUTTON_context_Init();
/* USER CODE END P2PS_APP_Init */
  return;
}

/* USER CODE BEGIN FD */
void P2PS_APP_LED_BUTTON_context_Init(void){
  
  BSP_LED_Off(LED_BLUE);
  
  #if(P2P_SERVER1 != 0)
  P2P_Server_App_Context.LedControl.Device_Led_Selection=0x01; /* Device1 */
  P2P_Server_App_Context.LedControl.Led1=0x00; /* led OFF */
  P2P_Server_App_Context.ButtonControl.Device_Button_Selection=0x01;/* Device1 */
  P2P_Server_App_Context.ButtonControl.ButtonStatus=0x00;
#endif
#if(P2P_SERVER2 != 0)
  P2P_Server_App_Context.LedControl.Device_Led_Selection=0x02; /* Device2 */
  P2P_Server_App_Context.LedControl.Led1=0x00; /* led OFF */
  P2P_Server_App_Context.ButtonControl.Device_Button_Selection=0x02;/* Device2 */
  P2P_Server_App_Context.ButtonControl.ButtonStatus=0x00;
#endif  
#if(P2P_SERVER3 != 0)
  P2P_Server_App_Context.LedControl.Device_Led_Selection=0x03; /* Device3 */
  P2P_Server_App_Context.LedControl.Led1=0x00; /* led OFF */
  P2P_Server_App_Context.ButtonControl.Device_Button_Selection=0x03; /* Device3 */
  P2P_Server_App_Context.ButtonControl.ButtonStatus=0x00;
#endif
#if(P2P_SERVER4 != 0)
  P2P_Server_App_Context.LedControl.Device_Led_Selection=0x04; /* Device4 */
  P2P_Server_App_Context.LedControl.Led1=0x00; /* led OFF */
  P2P_Server_App_Context.ButtonControl.Device_Button_Selection=0x04; /* Device4 */
  P2P_Server_App_Context.ButtonControl.ButtonStatus=0x00;
#endif  
 #if(P2P_SERVER5 != 0)
  P2P_Server_App_Context.LedControl.Device_Led_Selection=0x05; /* Device5 */
  P2P_Server_App_Context.LedControl.Led1=0x00; /* led OFF */
  P2P_Server_App_Context.ButtonControl.Device_Button_Selection=0x05; /* Device5 */
  P2P_Server_App_Context.ButtonControl.ButtonStatus=0x00;
#endif
#if(P2P_SERVER6 != 0)
  P2P_Server_App_Context.LedControl.Device_Led_Selection=0x06; /* device6 */
  P2P_Server_App_Context.LedControl.Led1=0x00; /* led OFF */
  P2P_Server_App_Context.ButtonControl.Device_Button_Selection=0x06; /* Device6 */
  P2P_Server_App_Context.ButtonControl.ButtonStatus=0x00;
#endif  
}

void P2PS_APP_SW1_Button_Action(void)
{
  UTIL_SEQ_SetTask( 1<<CFG_TASK_SW1_BUTTON_PUSHED_ID, CFG_SCH_PRIO_0);

  return;
}

void P2PS_APP_FETdata_Transmit(double vValue, double iValue1, double iValue2)
{
	  /*
		 uint8_t			sDelimiter;
		 uint8_t			Code;
		 uint8_t			vDelimiter; // vVal is going to be DAC input voltage, which corresponds to set Ids current.
		 uint8_t			vVal1;
		 uint8_t			vVal2;
		 uint8_t			vVal3;
		 uint8_t			vVal4;

		 uint8_t			iDelimiter; // iVal is going to be ADC value, which corresponds to Vds. iValXY means a channel X and digit Y
		 uint8_t			iVal11;
		 uint8_t			iVal12;
		 uint8_t			iVal13;
		 uint8_t			iVal14;
		 uint8_t			iVale1;
		 uint8_t			iVal21;
		 uint8_t			iVal22;
		 uint8_t			iVal23;
		 uint8_t			iVal24;
		 uint8_t			iVale2;
		 uint8_t			eDelimiter;
	  */
  P2P_Server_App_Context.FETVal.sDelimiter=0x3C;
  P2P_Server_App_Context.FETVal.Code=0x52;
  P2P_Server_App_Context.FETVal.vDelimiter=0x56;
  P2P_Server_App_Context.FETVal.iDelimiter=0x49;
  P2P_Server_App_Context.FETVal.eDelimiter=0x3E;

  P2P_Server_App_Context.FETVal.vVal1=((int)(vValue)%10)+'0';
  P2P_Server_App_Context.FETVal.vVal2=((int)((vValue)*pow(10,1))%10)+'0';
  P2P_Server_App_Context.FETVal.vVal3=((int)((vValue)*pow(10,2))%10)+'0';
  P2P_Server_App_Context.FETVal.vVal4=((int)((vValue)*pow(10,3))%10)+'0';

  int indice = log10(iValue1);
  P2P_Server_App_Context.FETVal.iVal11=((int)((iValue1)*pow(10,abs(indice)))%10)+'0';
  P2P_Server_App_Context.FETVal.iVal12=((int)((iValue1)*pow(10,abs(indice)+1))%10)+'0';
  P2P_Server_App_Context.FETVal.iVal13=((int)((iValue1)*pow(10,abs(indice)+2))%10)+'0';
  P2P_Server_App_Context.FETVal.iVal14=((int)((iValue1)*pow(10,abs(indice)+3))%10)+'0';
  P2P_Server_App_Context.FETVal.iVale1=(abs(indice)+1)+'0';

  indice = log10(iValue2);
  P2P_Server_App_Context.FETVal.iVal21=((int)((iValue2)*pow(10,abs(indice)))%10)+'0';
  P2P_Server_App_Context.FETVal.iVal22=((int)((iValue2)*pow(10,abs(indice)+1))%10)+'0';
  P2P_Server_App_Context.FETVal.iVal23=((int)((iValue2)*pow(10,abs(indice)+2))%10)+'0';
  P2P_Server_App_Context.FETVal.iVal24=((int)((iValue2)*pow(10,abs(indice)+3))%10)+'0';
  P2P_Server_App_Context.FETVal.iVale2=(abs(indice)+1)+'0';


  UTIL_SEQ_SetTask( 1<<CFG_TASK_SW1_BUTTON_PUSHED_ID, CFG_SCH_PRIO_0);
  return;
}

void Response(void){
	P2PS_Send_Notification();
}

void HAL_SYSTICK_Callback(void){

	if(sweepFlag == 0 && P2P_Server_App_Context.Notification_Status == 1){
		sweepFlag = 1;
		dacV0 = 0.02;
		dacV1 = 0.02;
	}
	else if(sweepFlag == 1 && P2P_Server_App_Context.Notification_Status == 1 && dacV0 <= 2.0 && dacV0 >= 0){

		if(adcFlag == 0 && samplingFlag == 0){
			AD5697R_setDAC(0,dacV0);
			AD5697R_setDAC(1,dacV1);

			adcTick = 0;
			samplingTick = 0;

			adcCount = 0;
			adcSum0 = 0;
			adcSum1 = 0;

			samplingFlag = 1;
			adcFlag = 1;

			HAL_ADC_Start_DMA(&hadc1, &adcBuffer, 2);
		}
		else if(adcTick > 90 && adcFlag == 1 && samplingFlag == 1 && P2P_Server_App_Context.Notification_Status == 1 ){
			HAL_ADC_Stop_DMA(&hadc1);

			adcFlag = 0;



			int adcAve0 = adcSum0 / adcCount;
			int adcAve1 = adcSum1 / adcCount;

			double vval0 = ((double)adcAve0) / ((double)4096.0)*3.3;
			double vval1 = ((double)adcAve1) / ((double)4096.0)*3.3;

			double ival0 = ((double)adcAve0) / ((double)4096.0)*3.3 /1e5;
			double ival1 = ((double)adcAve1) / ((double)4096.0)*3.3 /1e5;

			printf("%.3f, %d, %d, %d, %.3f, %.6e, %d, %d, %d, %.3f, %.6e\r\n",dacV0, adcSum0, adcCount, adcAve0, vval0, ival0, adcSum1, adcCount, adcAve1, vval1, ival1);

			adcCount = 0;
			adcSum0 = 0;
			adcSum1 = 0;

			P2PS_APP_FETdata_Transmit(dacV0, vval0, vval1);

		}
		else if(adcFlag == 0 && samplingTick > 100 && samplingFlag == 1){
			samplingFlag = 0;
			dacV0 = dacV0 + 0.03;
			dacV1 = dacV1 + 0.03;
		}
	}
	else if (sweepFlag == 1 && P2P_Server_App_Context.Notification_Status == 1 && dacV0 >2.0 && dacV0 != -1 	){
		dacV0 = -1;
		P2PS_APP_FETdata_Transmit(dacV0, 0.0, 0.0);
		globalTick = 0;
		dacV0 = 0.001;
		dacV1 = 0.001;
		AD5697R_setDAC(0,dacV0);
		AD5697R_setDAC(1,dacV1);
		dacV0 = -1;
		dacV1 = -1;
	}
	else if (globalTick > 10000 && sweepFlag == 1 && P2P_Server_App_Context.Notification_Status == 1 && dacV0 <= -0.5){

		sweepFlag = 0;
	}




	globalTick = globalTick + 1;
	adcTick = adcTick + 1;
	samplingTick = samplingTick + 1;


}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	//printf("DMA val: %d, %d\r\n", (uint16_t)adcBuffer[0], (uint16_t)adcBuffer[1]);
	adcSum0 = adcSum0 + (uint16_t)adcBuffer[0];
	adcSum1 = adcSum1 + (uint16_t)adcBuffer[1];
	adcCount = adcCount + 1;

	/*int retVal = HAL_ADC_GetValue(&hadc1);

	if(adcChannel == 0){
		adcSum0 = adcSum0 + retVal;
		adcCount0 = adcCount0 + 1;
		adcChannel = 1;
		printf("ADC val 1: %d\r\n", retVal);
	}
	else if(adcChannel == 1){
		adcSum1 = adcSum1 + retVal;
		adcCount1 = adcCount1 + 1;
		adcChannel = 0;
		printf("ADC val 2: %d\r\n", retVal);
	}

*/
}

double ival_Calibration(double ival)
{
	double ival_cal = 0;
	double a = 0.0729;
	double b = -0.3029;
	double c = 0.41465;
	double d = 0.53718;
	double ratio = a*pow(ival, 3) + b*pow(ival,2) + c*ival + d;
	return ival/ratio;
}


/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/
/* USER CODE BEGIN FD_LOCAL_FUNCTIONS*/
void P2PS_Send_Notification(void)
{
 
  if(P2P_Server_App_Context.ButtonControl.ButtonStatus == 0x00){
    P2P_Server_App_Context.ButtonControl.ButtonStatus=0x01;
  } else {
    P2P_Server_App_Context.ButtonControl.ButtonStatus=0x00;
  }



  if(P2P_Server_App_Context.Notification_Status){
    //APP_DBG_MSG("-- P2P APPLICATION SERVER  : INFORM CLIENT BUTTON 1 PUSHED \n ");
    //APP_DBG_MSG(" \n\r");
    P2PS_STM_App_Update_Char(P2P_NOTIFY_CHAR_UUID, (uint8_t *)&P2P_Server_App_Context.FETVal);
   } else {
    APP_DBG_MSG("-- P2P APPLICATION SERVER : CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n "); 
   }

  return;
}

/* USER CODE END FD_LOCAL_FUNCTIONS*/
