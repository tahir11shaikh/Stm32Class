/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : hal_gpio.cpp
  * Created on      : 03-03-2024
  * Author          : Tahir.Shaikh
  * @brief          : Source/Header file
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <hal_pwm.hpp>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// Instance Declaration
PWM_CLASS::PWM_CLASS(TIM_HandleTypeDef *htim)
    :htim(htim)
{
    // Initialize class members by Constructor
    for (int i = 0; i < PWM_PIN_MaxCnt; ++i) {
        this->stVar.u32PwmPinDutyCycle[i] = 0;
        this->stStatus.enPwmPinStart[i] = HAL_ApiState::HAL_FAIL;
        this->stStatus.enPwmPinStop[i] = HAL_ApiState::HAL_FAIL;
    }
}

PWM_CLASS::~PWM_CLASS()
{
    // TODO Auto-generated destructor stub
}
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */
/* USER CODE END EV */

/* functions --------------------------------------------------------*/

/**
  * @brief  This function is used to start PWM
  * @param  PWM_PinTypeDef
  * @retval HAL_ApiState
  */
HAL_ApiState PWM_CLASS::PWM_Start(PWM_PinTypeDef enPinTypeDef)
{
    HAL_StatusTypeDef enStatus = HAL_ERROR;

    switch(enPinTypeDef)
    {
        case PWM_PIN_1:
            enStatus = HAL_TIM_PWM_Start(this->htim, TIM_CHANNEL_1);
            break;
        default:
        case PWM_PIN_MaxCnt:
            break;
    }
    if (enStatus != HAL_OK)
    {
        this->stStatus.enPwmPinStart[enPinTypeDef] = HAL_FAIL;
    } else {
        this->stStatus.enPwmPinStart[enPinTypeDef] = HAL_SUCCESS;
    }

    return this->stStatus.enPwmPinStart[enPinTypeDef];
}

/**
  * @brief  This function is used to stop PWM
  * @param  PWM_PinTypeDef
  * @retval HAL_ApiState
  */
HAL_ApiState PWM_CLASS::PWM_Stop(PWM_PinTypeDef enPinTypeDef)
{
    HAL_StatusTypeDef enStatus = HAL_ERROR;

    switch(enPinTypeDef)
    {
        case PWM_PIN_1:
            enStatus = HAL_TIM_PWM_Stop(this->htim, TIM_CHANNEL_1);
            break;
        default:
        case PWM_PIN_MaxCnt:
            break;
    }
    if (enStatus != HAL_OK)
    {
        this->stStatus.enPwmPinStop[enPinTypeDef] = HAL_FAIL;
    } else {
        this->stStatus.enPwmPinStop[enPinTypeDef] = HAL_SUCCESS;
    }

    return this->stStatus.enPwmPinStop[enPinTypeDef];
}

/**
  * @brief  This function is used to set duty cycle.
  * @param  PWM_PinTypeDef
  * @param  u8DutyCycle:0-100%
  * @retval HAL_ApiState
  */
HAL_ApiState PWM_CLASS::PWM_SetDutyCycle(PWM_PinTypeDef enPinTypeDef, uint8_t u8DutyCycle)
{
    uint8_t _u8DutyCycle;
    _u8DutyCycle = (uint8_t)(u8DutyCycle < MIN_DUTY_CYCLE) ? MIN_DUTY_CYCLE : ((u8DutyCycle > MAX_DUTY_CYCLE) ? MAX_DUTY_CYCLE : u8DutyCycle);

    switch(enPinTypeDef)
    {
        case PWM_PIN_1:
            __HAL_TIM_SET_COMPARE(this->htim, TIM_CHANNEL_1, _u8DutyCycle);
            break;
        default:
        case PWM_PIN_MaxCnt:
            break;
    }

    return HAL_SUCCESS;
}
