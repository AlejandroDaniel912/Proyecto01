/*
 * vivero_hc05.h
 *
 *  Created on: Feb 13, 2026
 *      Author: ale55
 */

#ifndef API_INC_VIVERO_HC05_H_
#define API_INC_VIVERO_HC05_H_

#include "main.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/* Configuración */
#define HC05_RX_BUFFER_SIZE   128

typedef struct
{
    UART_HandleTypeDef *huart;

    uint8_t rxByte;
    uint8_t rxBuffer[HC05_RX_BUFFER_SIZE];

    volatile uint16_t head;
    volatile uint16_t tail;

} HC05_HandleTypeDef;


/* API pública */
void HC05_Init(HC05_HandleTypeDef *hdev, UART_HandleTypeDef *huart);

void HC05_StartReception(HC05_HandleTypeDef *hdev);

void HC05_Tx(HC05_HandleTypeDef *hdev, uint8_t *data, uint16_t len);

void HC05_WriteString(HC05_HandleTypeDef *hdev, const char *str);

void HC05_WriteLine(HC05_HandleTypeDef *hdev, const char *str);

bool HC05_Available(HC05_HandleTypeDef *hdev);

uint8_t HC05_Read(HC05_HandleTypeDef *hdev);

void HC05_RxCpltCallback(HC05_HandleTypeDef *hdev);

#endif /* API_INC_VIVERO_HC05_H_ */
