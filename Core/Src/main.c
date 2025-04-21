/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "OLED.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

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
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int keynum=0;
int password = 0;
int keyflag = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    // 仅当 TIM2 触发时才执行
    if (htim->Instance == TIM3)
    {
        // 定时器周期到期时的操�????????
        // 例如：切�???????? LED 状�?�，或�?�计�????????
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);  // 假设 GPIOA_PIN_5 控制 LED
    }
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
    OLED_Init();
    OLED_Clear();

    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);

    HAL_TIM_Base_Start_IT(&htim3);

    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);

    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET);



    OLED_ShowString(0,0,"password:",16,0);
    OLED_ShowString(0,2,"work:",16,0);
    OLED_ShowString(0,4,"output:",16,0);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */








        if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_SET)
        {
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);

            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET);
                keyflag = 8;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET);
                keynum = 66;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET);
                keyflag = 9;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET);
                keyflag = 4;
            }

            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);

        }

        if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_SET)
        {
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);

            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET);
                keynum = 7;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET);
                keynum = 8;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET);
                keynum = 9;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET);
                keyflag = 3;
            }

            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
        }
        if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14)==GPIO_PIN_SET)
        {
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);

            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET);
                keynum = 4;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET);
                keynum = 5;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET);
                keynum = 6;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET);
                keyflag = 2;
            }

            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
        }
        if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_15)==GPIO_PIN_SET)
        {
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);

            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8)==GPIO_PIN_SET);
                keynum = 1;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_SET);
                keynum = 2;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10)==GPIO_PIN_SET);
                keynum = 3;
            }
            if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET)
            {
                HAL_Delay(50);
                while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11)==GPIO_PIN_SET);
                keyflag = 1;
            }

            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
        }




// 操作�??????????
    if(keyflag==8)
    {
        password=password/10;
        keyflag=0;
    }
    if(keyflag==9)
    {
        if(password==2628)
        {
            OLED_ShowString(72,4,"correct",16,0);
            password = 0;
            OLED_ShowNum(80,0,password,5,16,0);

            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);

            __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,50);
            HAL_Delay(10000);
            __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,250);
            HAL_Delay(100);

            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);


        }
        else
        {
            OLED_ShowString(72,4,"wrong!!",16,0);
            password = 0;
            OLED_ShowNum(80,0,password,5,16,0);

            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
            HAL_Delay(100);
            HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
        }
        keyflag=0;
    }







    //密码�??????????
    if(password<1000)
    {
        if(keynum == 66)
        {
            password=password*10;
            keynum = 0;
        }
        if(keynum!=0)
        {
            password=password*10;
            password+=keynum%10;
            keynum = 0;
        }
    }
      keynum = 0;





      OLED_ShowNum(80,0,password,5,16,0);
      OLED_ShowNum(80,2,keyflag,5,16,0);





  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
