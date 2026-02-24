/*
 * Driver_PWM.h
 *
 *  Created on: Feb 19, 2026
 *      Author: ale55
 */

#ifndef API_INC_DRIVER_PWM_H_
#define API_INC_DRIVER_PWM_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    MOTOR_DIR_FORWARD = 0,
    MOTOR_DIR_BACKWARD
} Motor_Direction_t;

typedef struct
{
    TIM_HandleTypeDef *htim;
    uint32_t channel;

    GPIO_TypeDef *IN1_Port;
    uint16_t IN1_Pin;

    GPIO_TypeDef *IN2_Port;
    uint16_t IN2_Pin;

    uint8_t currentSpeed;   // 0–100 %
    Motor_Direction_t direction;

} Motor_HandleTypeDef;

/* Inicializa estructura y arranca PWM */
void Motor_Init(Motor_HandleTypeDef *hmotor,
                TIM_HandleTypeDef *htim,
                uint32_t channel,
                GPIO_TypeDef *IN1_Port,
                uint16_t IN1_Pin,
                GPIO_TypeDef *IN2_Port,
                uint16_t IN2_Pin);

/* Control de velocidad 0–100% */
void Motor_SetSpeed(Motor_HandleTypeDef *hmotor, uint8_t speed);

/* Control de dirección */
void Motor_SetDirection(Motor_HandleTypeDef *hmotor, Motor_Direction_t dir);

/* Detiene motor (PWM=0 y pines LOW) */
void Motor_Stop(Motor_HandleTypeDef *hmotor);

/* Obtiene velocidad actual */
uint8_t Motor_GetSpeed(Motor_HandleTypeDef *hmotor);


#endif /* API_INC_DRIVER_PWM_H_ */
