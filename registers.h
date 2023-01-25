#include <inttypes.h>

struct rcc {
  volatile uint32_t CR, CFGR, CIR, APB2RSTR, APB1RSTR, AHBENR, APB2ENR, APB1ENR,
      BDCR, CSR, AHBRSTR, CFGR2, CFGR3, CR2;
};
#define RCC ((struct rcc *)0x40021000)
struct crs {
  volatile uint32_t CR, CFGR, ISR, ICR;
};
#define CRS ((struct crs *)0x40006c00)
struct gpio {
  volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFR[2],
      BRR;
};
#define GPIO(bank) ((struct gpio *)0x48000000 + 0x400 * (bank))
struct syscfg {
  volatile uint32_t CFGR1, EXTICR[4], ITLINE[30];
};
#define SYSCFG ((struct syscfg *)0x40010000)
/*migth do a sub struct for dma redudant registers*/
struct dma {
  volatile uint32_t ISR, IFCR, CCR1, CNDTR1, CPAR1, CMAR1, RESERVED1, CCR2,
      CNDTR2, CPAR2, CMAR2, RESERVED2, CCR3, CNDTR3, CPAR3, CMAR3, RESERVED3,
      CCR4, CNDTR4, CPAR4, CMAR4, RESERVED4, CCR5, CNDTR5, CPAR5, CMAR5,
      RESERVED5, CCR6, CNDTR6, CPAR6, CMAR6, RESERVED6, CCR7, CNDTR7, CPAR7,
      CMAR7, RESERVED7, CSELR;
};
#define DMA(chan) ((struct dma *)0x40020000 + 0x400 * (chan - 1))
struct exti {
  volatile uint32_t IMR, EMR, RTSR, FTSR, SWIER, PR;
};
#define EXTI ((struct exti *)0x40010400)
struct crc {
  volatile uint32_t DR, IDR, CR, INIT, POL;
};
#define CRC ((struct crc *)0x40023000)
struct adc {
  volatile uint32_t ISR, IER, CR, CFGR[2], SMPR, TR, CHSELR, DR, CCR;
};
#define ADC ((struct adc *)0x40012400)
struct dac {
  volatile uint32_t CR, SWTRIGR, DHR12R1, DHR12L1, DHR8R1, DHR12R2, DHR12L2,
      DHR8R2, DHR12RD, DHR12LD, DHR8RD, DOR[2], SR;
};
#define DAC ((struct dac *)0x40007400);
#define COMP ((volatile uint32_t *)0x400106f2);
struct tsc {
  volatile uint32_t CR, IER, ICR, ISR, IOHCR, IOASCR, IOSCR, IOCCR, IOGCSR,
      IOGxCR[8];
};
#define TSC ((struct tsc *)0x40024000)
struct tim1 {
  volatile uint32_t CR[2], SMCR, DIER, SR, EGR, CCMR[2], CCER, CNT, PSC, ARR,
      RCR, CCR[4], BDTR, DCR, DMAR;
};
#define TIM1 ((struct tim1 *)0x40012c00)
struct tim2_3 {
  volatile uint32_t CR[2], SMCR, DIER, SR, EGR, CCMR1[2], CCMR2[2], CCER, CNT,
      PSC, ARR, RESERVED, CCR[4], RESERVED2, DCR, DMAR;
};
#define TIM2_3(no) ((struct tim2_3 *)0x40000000 + 0x400 * (no - 2))
struct tim14 {
  volatile uint32_t CR1, RESERVED1, DIER, SR, EGR, CCMR1[2], RESERVED2, CCER,
      CNT, PSC, ARR, RESERVED3, CCR1, RESERVED4, OR;
};
#define TIM14 ((struct tim14 *)0x40002000)
struct tim15 {
  volatile uint32_t CR[2], SMCR, DIER, SR, EGR, CCMR1[2], CCER, CNT, PSC, ARR,
      RCR, CCR[2], BDTR, DCR, DMAR;
};
#define TIM15 ((struct tim15 *)0x40014000)
struct tim16_17 {
  volatile uint32_t CR[2], DIER, SR, EGR, CCMR1[2], CCER, CNT, PSC, ARR, RCR,
      CCR1, DCR, DMAR;
};
#define TIM16_17(no) ((struct tim16_17 *)0x40014400 + 0x400 * (no - 6))
struct tim6_7 {
  volatile uint32_t CR[2], DIER, SR, EGR, CNT, PSC, ARR;
};
#define TIM6_7(no) ((struct tim6_7 *)0x40001000 + 0x400 * (no - 6))
struct iwdg {
  volatile uint32_t KR, PR, RLR, SR, WINR;
};
#define IWDG ((struct iwdg *)0x40003000)
struct wwdg {
  volatile uint32_t CR, CFR, SR;
};
#define WWDG ((struct wwdg *)0x40002c00)
struct rtc {
  volatile uint32_t TR, DR, CR, ISR, PRER, WUTR, ALRMAR, WPR, SSR, SHIFTR, TSTR,
      TSDR, TSSSR, CALR, TAFCR, ALRMASSR, OR, BKP0R, BKP4R;
};
#define RTC ((struct rtc *)0x40002800)
struct i2c {
  volatile uint32_t CR[2], OAR[2], TIMINGR, TIMEOUTR, ISR, ICR, PECR, RXDR,
      TXDR;
};
#define I2C(no) ((struct i2c *)0x40005400 + 0x400 * (no - 1))
struct usart {
  volatile uint32_t CR[3], BRR, GTPR, RTOR, RQR, ISR, ICR, RDR, TDR;
};
#define USART2_5(no) ((struct usart *)0x40004400 + 0x400(no - 2))
#define USART6_8(no) ((struct usart *)0x40011400 + 0x400(no - 6))
#define USART1 ((struct usart *)0x40013800)
struct spi {
  volatile uint32_t CR[2], SR, DR, CRCPR, RXCRCR, TXCRCR, I2SCFGR, I2SPR;
};
#define SPI1 ((struct spi *)0x40013000)
#define SPI2 ((struct spi *)0x40003800)
struct can {
  volatile uint32_t MCR, MSR, TSR, RFnR[2], IER, ESR, BTR, VOID[88], TI0R,
      TDT0R, TDL0R, TDH0R, TI1R, TDT1R, TDL1R, TDH1R, TI2R, TDT2R, TDL2R, TDH2R,
      RI0R, RDT0R, RDL0R, RDH0R, RI1R, RDT1R, RDL1R, RDH1R, VOID2[12], FMR[2],
      VOID3, FS1R, VOID4, FFA1R, VOID5, FA1R, VOID6[8], F0R[2], F1R[2], F2R[2],
      F3R[2], F4R[2], F5R[2], F6R[2], F7R[2], F8R[2], F9R[2], F10R[2], F11R[2],
      F12R[2], F13R[2];
};
#define CAN ((struct can *)0x40006400)
struct usb {
  volatile uint32_t EPnR[8], VOID[8], CNTR, ISTR, FNR, DADDR, BTABLE, LPMCSR,
      BCDR;
};
#define USB ((struct usb *)0x40005c00)
struct cec {
  volatile uint32_t CR, CFGR, TXDR, RXDR, ISR, IER;
};
#define CEC ((struct cec *)0x40007800)
#define UID ((volatile uint32_t *)0x1ffff7ac)
#define UID_BCD ((volatile uint32_t *)0x1ffff7ac + 0x4)
#define FLASH_SIZE ((volatile uint16_t *)0x1ffff7cc)
struct systick {
  volatile uint32_t CSR, RVR, CVR, CALIB;
};
#define SYSTICK ((struct systick *)0xe000e010)
#define CPUID ((volatile uint32_t *)0xe000ed00)
#define ICSR ((volatile uint32_t *)0xe000ed04)
#define AIRCR ((volatile uint32_t *)0xe000ed0c)
#define SCR ((volatile uint32_t *)0xe000ed10)
#define CCR ((volatile uint32_t *)0xe000ed14)
#define SHPR2 ((volatile uint32_t *)0xe000ed1c)
#define SHPR3 ((volatile uint32_t *)0xe000ed20)
