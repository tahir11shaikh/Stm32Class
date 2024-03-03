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
#include <hal_gpio.hpp>
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
GPIO_CLASS::GPIO_CLASS()
{
    // Initialize class members by Constructor
    // Initialize all PinConfig in stDIn with HAL_PIN_LOW
    for (int i = 0; i < GPI_PIN_MaxCnt; i++) {
        this->stStatus.stDIn.enPinState[i] = HAL_PIN_LOW;
    }

    // Initialize all PinConfig in stDout with HAL_PIN_LOW
    for (int i = 0; i < GPO_PIN_MaxCnt; i++) {
        this->stStatus.stDout.enPinState[i] = HAL_PIN_LOW;
    }
}

GPIO_CLASS::~GPIO_CLASS()
{
	// TODO Auto-generated destructor stub
}
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */
/* USER CODE END EV */

/* functions --------------------------------------------------------*/

/**
  * @brief  This function is used to set PIN level high/low.
  * @param  GPIO_PinTypeDef
  * @retval HAL_PinState
  */
HAL_PinState GPIO_CLASS::GPO_PinSetLevel(GPO_PinTypeDef enPinTypeDef, HAL_PinState enPinState)
{
    switch(enPinTypeDef)
    {
        case GPO_PIN_PA5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (GPIO_PinState)enPinState);
            break;

        case GPO_PIN_MaxCnt:
            break;
    }
    return this->stStatus.stDout.enPinState[enPinTypeDef] = enPinState;
}

/**
  * @brief  This function is used to toggle the state of a PIN.
  * @param  GPIO_PinTypeDef: Pin to be toggled.
  * @retval HAL_PinState
  */
HAL_PinState GPIO_CLASS::GPO_PinToggle(GPO_PinTypeDef enPinTypeDef)
{
    switch(enPinTypeDef)
    {
        case GPO_PIN_PA5:
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
            break;

        case GPO_PIN_MaxCnt:
            break;
    }
    return this->stStatus.stDout.enPinState[enPinTypeDef] = (this->stStatus.stDout.enPinState[enPinTypeDef] == HAL_PIN_LOW) ? HAL_PIN_HIGH : HAL_PIN_LOW;
}

/**
  * @brief  This function is used to get PIN level high/low.
  * @param  GPI_PinTypeDef
  * @retval HAL_PinState
  */
HAL_PinState GPIO_CLASS::GPI_PinGetLevel(GPI_PinTypeDef enPinTypeDef)
{
    HAL_PinState enPinState = HAL_PIN_LOW;
    switch(enPinTypeDef)
    {
        case GPI_PIN_PC13:
            enPinState = (HAL_PinState)HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
            break;

        case GPI_PIN_MaxCnt:
            break;
    }
    return this->stStatus.stDIn.enPinState[enPinTypeDef] = enPinState;
}

