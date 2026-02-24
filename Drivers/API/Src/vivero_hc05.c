/*
 * vivero_hc05.c
 *
 *  Created on: Feb 13, 2026
 *      Author: ale55
 */


#include "vivero_hc05.h"

void HC05_Init(HC05_HandleTypeDef *hdev, UART_HandleTypeDef *huart)
{
    hdev->huart = huart;
    hdev->head = 0;
    hdev->tail = 0;
}

void HC05_StartReception(HC05_HandleTypeDef *hdev)
{
    HAL_UART_Receive_IT(hdev->huart, &hdev->rxByte, 1);
}

void HC05_Tx(HC05_HandleTypeDef *hdev, uint8_t *data, uint16_t len)
{
    HAL_UART_Transmit(hdev->huart, data, len, HAL_MAX_DELAY);
}

void HC05_WriteString(HC05_HandleTypeDef *hdev, const char *str)
{
    if (str == NULL) return;

    HC05_Tx(hdev, (uint8_t*)str, strlen(str));
}

void HC05_WriteLine(HC05_HandleTypeDef *hdev, const char *str)
{
    if (str == NULL) return;

    HC05_Tx(hdev, (uint8_t*)str, strlen(str));
    HC05_Tx(hdev, (uint8_t*)"\n", 1);
}

bool HC05_Available(HC05_HandleTypeDef *hdev)
{
    return (hdev->head != hdev->tail);
}

uint8_t HC05_Read(HC05_HandleTypeDef *hdev)
{
    uint8_t data = 0;

    if (hdev->head != hdev->tail)
    {
        data = hdev->rxBuffer[hdev->tail];
        hdev->tail = (hdev->tail + 1) % HC05_RX_BUFFER_SIZE;
    }

    return data;
}

void HC05_RxCpltCallback(HC05_HandleTypeDef *hdev)
{
    uint16_t next = (hdev->head + 1) % HC05_RX_BUFFER_SIZE;

    if (next != hdev->tail) // Evita overflow
    {
        hdev->rxBuffer[hdev->head] = hdev->rxByte;
        hdev->head = next;
    }

    HAL_UART_Receive_IT(hdev->huart, &hdev->rxByte, 1);
}
