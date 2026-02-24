/*
 * Driver_PWM.c
 *
 *  Created on: Feb 19, 2026
 *      Author: ale55
 */


#include "Driver_PWM.h"

static void Motor_UpdatePWM(Motor_HandleTypeDef *hmotor)
{
    uint32_t arr = __HAL_TIM_GET_AUTORELOAD(hmotor->htim);

    uint32_t pulse = (arr * hmotor->currentSpeed) / 100;

    __HAL_TIM_SET_COMPARE(hmotor->htim, hmotor->channel, pulse);
}

void Motor_Init(Motor_HandleTypeDef *hmotor,
                TIM_HandleTypeDef *htim,
                uint32_t channel,
                GPIO_TypeDef *IN1_Port,
                uint16_t IN1_Pin,
                GPIO_TypeDef *IN2_Port,
                uint16_t IN2_Pin)
{
    hmotor->htim = htim;
    hmotor->channel = channel;

    hmotor->IN1_Port = IN1_Port;
    hmotor->IN1_Pin  = IN1_Pin;

    hmotor->IN2_Port = IN2_Port;
    hmotor->IN2_Pin  = IN2_Pin;

    hmotor->currentSpeed = 0;
    hmotor->direction = MOTOR_DIR_FORWARD;

    HAL_TIM_PWM_Start(htim, channel);

    Motor_Stop(hmotor);
}

void Motor_SetSpeed(Motor_HandleTypeDef *hmotor, uint8_t speed)
{
    if (speed > 100)
        speed = 100;

    hmotor->currentSpeed = speed;

    Motor_UpdatePWM(hmotor);
}

void Motor_SetDirection(Motor_HandleTypeDef *hmotor, Motor_Direction_t dir)
{
    hmotor->direction = dir;

    if (dir == MOTOR_DIR_FORWARD)
    {
        HAL_GPIO_WritePin(hmotor->IN1_Port, hmotor->IN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(hmotor->IN2_Port, hmotor->IN2_Pin, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(hmotor->IN1_Port, hmotor->IN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(hmotor->IN2_Port, hmotor->IN2_Pin, GPIO_PIN_SET);
    }
}

void Motor_Stop(Motor_HandleTypeDef *hmotor)
{
    hmotor->currentSpeed = 0;

    HAL_GPIO_WritePin(hmotor->IN1_Port, hmotor->IN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(hmotor->IN2_Port, hmotor->IN2_Pin, GPIO_PIN_RESET);

    __HAL_TIM_SET_COMPARE(hmotor->htim, hmotor->channel, 0);
}

uint8_t Motor_GetSpeed(Motor_HandleTypeDef *hmotor)
{
    return hmotor->currentSpeed;
}
