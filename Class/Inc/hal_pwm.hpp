/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : hal_pwm.hpp
  * Created on      : 02-03-2024
  * Author          : Tahir.Shaikh
  * @brief          : Source/Header file
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CLASS_INC_HAL_PWM_H_
#define CLASS_INC_HAL_PWM_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "stm32g4xx_hal.h"
/* USER CODE END Includes */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define MIN_DUTY_CYCLE 0
#define MAX_DUTY_CYCLE 100
/* USER CODE END EM */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum
{
	PWM_PIN_1,

	PWM_PIN_MaxCnt,
} PWM_PinTypeDef;
/* USER CODE END ET */

/* Global variable -----------------------------------------------------------*/
/* USER CODE BEGIN GV */
class PWM_CLASS
{
	public:
		// Internal Declaration
		PWM_CLASS();
		virtual ~PWM_CLASS();

		// Variable Declaration
		struct
		{
			HAL_ApiState enPwmPinStart[PWM_PIN_MaxCnt];
			HAL_ApiState enPwmPinStop[PWM_PIN_MaxCnt];
		} stStatus;

		// Methods Declaration
		HAL_ApiState PWM_Start(PWM_PinTypeDef enPinTypeDef);
		HAL_ApiState PWM_Stop(PWM_PinTypeDef enPinTypeDef);
		HAL_ApiState PWM_SetDutyCycle(PWM_PinTypeDef enPinTypeDef, uint8_t ucDutyCycle);
};
/* USER CODE END GV */

/* Exported functions prototypes ---------------------------------------------*/
/* USER CODE BEGIN EFP */
/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* CLASS_INC_HAL_PWM_H_ */
