#ifndef AB_UART_H
#define AB_UART_H

#define UART_TX_BUF_SIZE                256                                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE                256                                         /**< UART RX buffer size. */

#include "app_uart.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "ble_nus.h"

BLE_NUS_DEF(m_nus);
void uart_init(void);
void uart_event_handle(app_uart_evt_t * p_event);

#endif