#ifndef __STM32L4XX_H
#define __STM32L4XX_H

#include <stdint.h>

/* Base address definitions */
#define PERIPH_BASE           0x40000000UL
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)

#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x1000UL)

/* GPIO register structure */
typedef struct
{
    volatile uint32_t MODER;    /*!< GPIO mode register           */
    volatile uint32_t OTYPER;   /*!< GPIO output type register    */
    volatile uint32_t OSPEEDR;  /*!< GPIO output speed register   */
    volatile uint32_t PUPDR;    /*!< GPIO pull-up/down register   */
    volatile uint32_t IDR;      /*!< GPIO input data register     */
    volatile uint32_t ODR;      /*!< GPIO output data register    */
    volatile uint32_t BSRR;     /*!< GPIO bit set/reset register  */
    volatile uint32_t LCKR;     /*!< GPIO config lock register    */
    volatile uint32_t AFR[2];   /*!< GPIO alternate function regs */
    volatile uint32_t BRR;      /*!< GPIO bit reset register      */
} GPIO_TypeDef;

/* RCC register structure (simplified) */
typedef struct
{
    volatile uint32_t CR;         /*!< Clock control register            */
    volatile uint32_t ICSCR;      /*!< Internal clock sources calibration */
    volatile uint32_t CFGR;       /*!< Clock configuration register     */
    volatile uint32_t PLLCFGR;    /*!< PLL configuration register       */
    volatile uint32_t PLLSAI1CFGR;/*!< PLLSAI1 configuration register   */
    volatile uint32_t CIER;       /*!< Clock interrupt enable register  */
    volatile uint32_t CIFR;       /*!< Clock interrupt flag register    */
    volatile uint32_t CICR;       /*!< Clock interrupt clear register   */
    volatile uint32_t AHB1RSTR;   /*!< AHB1 peripheral reset register   */
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    volatile uint32_t APB1RSTR1;
    volatile uint32_t APB1RSTR2;
    volatile uint32_t APB2RSTR;
    volatile uint32_t AHB1ENR;    /*!< AHB1 peripheral clock enable reg */
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t RESERVED1;
    volatile uint32_t APB1ENR1;
    volatile uint32_t APB1ENR2;
    volatile uint32_t APB2ENR;
    // ... other registers if needed
} RCC_TypeDef;

/* Peripheral pointers */
#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define RCC     ((RCC_TypeDef *) RCC_BASE)

/* RCC AHB1ENR bit definitions for GPIO */
#define RCC_AHB1ENR_GPIOAEN   (1U << 0)
#define RCC_AHB1ENR_GPIOBEN   (1U << 1)
#define RCC_AHB1ENR_GPIOCEN   (1U << 2)

#endif /* __STM32L4XX_H */
