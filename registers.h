#include <inttypes.h>

struct flash{
  volatile uint32_t ACR, KEYR, OPTKEYR, SR, CR, AR, OBR, WRPR;
};
struct rcc {
  volatile uint32_t CR, CFGR, CIR, APB2RSTR, APB1RSTR, AHBENR, APB2ENR, APB1ENR,
      BDCR, CSR, AHBRSTR, CFGR2, CFGR3, CR2;
};
struct crs {
  volatile uint32_t CR, CFGR, ISR, ICR;
};
struct gpio {
  volatile uint32_t MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR, AFR[2],
      BRR;
};
struct syscfg {
  volatile uint32_t CFGR1, EXTICR[4], ITLINE[30];
};
/*migth do a sub struct for dma redudant registers*/
struct dma {
  volatile uint32_t ISR, IFCR, CCR1, CNDTR1, CPAR1, CMAR1, RESERVED1, CCR2,
      CNDTR2, CPAR2, CMAR2, RESERVED2, CCR3, CNDTR3, CPAR3, CMAR3, RESERVED3,
      CCR4, CNDTR4, CPAR4, CMAR4, RESERVED4, CCR5, CNDTR5, CPAR5, CMAR5,
      RESERVED5, CCR6, CNDTR6, CPAR6, CMAR6, RESERVED6, CCR7, CNDTR7, CPAR7,
      CMAR7, RESERVED7, CSELR;
};
struct exti {
  volatile uint32_t IMR, EMR, RTSR, FTSR, SWIER, PR;
};
struct crc {
  volatile uint32_t DR, IDR, CR, INIT, POL;
};
struct adc {
  volatile uint32_t ISR, IER, CR, CFGR[2], SMPR, TR, CHSELR, DR, CCR;
};
struct dac {
  volatile uint32_t CR, SWTRIGR, DHR12R1, DHR12L1, DHR8R1, DHR12R2, DHR12L2,
      DHR8R2, DHR12RD, DHR12LD, DHR8RD, DOR[2], SR;
};
struct tsc {
  volatile uint32_t CR, IER, ICR, ISR, IOHCR, IOASCR, IOSCR, IOCCR, IOGCSR,
      IOGxCR[8];
};
struct tim1 {
  volatile uint32_t CR[2], SMCR, DIER, SR, EGR, CCMR[2], CCER, CNT, PSC, ARR,
      RCR, CCR[4], BDTR, DCR, DMAR;
};
struct tim2_3 {
  volatile uint32_t CR[2], SMCR, DIER, SR, EGR, CCMR1[2], CCMR2[2], CCER, CNT,
      PSC, ARR, RESERVED, CCR[4], RESERVED2, DCR, DMAR;
};
struct tim14 {
  volatile uint32_t CR1, RESERVED1, DIER, SR, EGR, CCMR1[2], RESERVED2, CCER,
      CNT, PSC, ARR, RESERVED3, CCR1, RESERVED4, OR;
};
struct tim15 {
  volatile uint32_t CR[2], SMCR, DIER, SR, EGR, CCMR1[2], CCER, CNT, PSC, ARR,
      RCR, CCR[2], BDTR, DCR, DMAR;
};
struct tim16_17 {
  volatile uint32_t CR[2], DIER, SR, EGR, CCMR1[2], CCER, CNT, PSC, ARR, RCR,
      CCR1, DCR, DMAR;
};
struct tim6_7 {
  volatile uint32_t CR[2], DIER, SR, EGR, CNT, PSC, ARR;
};
struct iwdg {
  volatile uint32_t KR, PR, RLR, SR, WINR;
};
struct wwdg {
  volatile uint32_t CR, CFR, SR;
};
struct rtc {
  volatile uint32_t TR, DR, CR, ISR, PRER, WUTR, ALRMAR, WPR, SSR, SHIFTR, TSTR,
      TSDR, TSSSR, CALR, TAFCR, ALRMASSR, OR, BKP0R, BKP4R;
};
struct i2c {
  volatile uint32_t CR[2], OAR[2], TIMINGR, TIMEOUTR, ISR, ICR, PECR, RXDR,
      TXDR;
};
struct usart {
  volatile uint32_t CR[3], BRR, GTPR, RTOR, RQR, ISR, ICR, RDR, TDR;
};
struct spi {
  volatile uint32_t CR[2], SR, DR, CRCPR, RXCRCR, TXCRCR, I2SCFGR, I2SPR;
};
struct can {
  volatile uint32_t MCR, MSR, TSR, RFnR[2], IER, ESR, BTR, VOID[88], TI0R,
      TDT0R, TDL0R, TDH0R, TI1R, TDT1R, TDL1R, TDH1R, TI2R, TDT2R, TDL2R, TDH2R,
      RI0R, RDT0R, RDL0R, RDH0R, RI1R, RDT1R, RDL1R, RDH1R, VOID2[12], FMR[2],
      VOID3, FS1R, VOID4, FFA1R, VOID5, FA1R, VOID6[8], F0R[2], F1R[2], F2R[2],
      F3R[2], F4R[2], F5R[2], F6R[2], F7R[2], F8R[2], F9R[2], F10R[2], F11R[2],
      F12R[2], F13R[2];
};
struct usb {
  volatile uint32_t EPnR[8], VOID[8], CNTR, ISTR, FNR, DADDR, BTABLE, LPMCSR,
      BCDR;
};
struct cec {
  volatile uint32_t CR, CFGR, TXDR, RXDR, ISR, IER;
};
struct systick {
  volatile uint32_t CSR, RVR, CVR, CALIB;
};
#define  FLASH ((struct flash *)0x40022000)
#define RCC ((struct rcc *)0x40021000)
#define CRS ((struct crs *)0x40006c00)
#define GPIO(bank) ((struct gpio *)0x48000000 + 0x400 * (bank))
#define SYSCFG ((struct syscfg *)0x40010000)
#define DMA(chan) ((struct dma *)0x40020000 + 0x400 * (chan - 1))
#define EXTI ((struct exti *)0x40010400)
#define CRC ((struct crc *)0x40023000)
#define ADC ((struct adc *)0x40012400)
#define DAC ((struct dac *)0x40007400)
#define COMP ((volatile uint32_t *)0x400106f2)
#define TSC ((struct tsc *)0x40024000)
#define TIM1 ((struct tim1 *)0x40012c00)
#define TIM2_3(no) ((struct tim2_3 *)0x40000000 + 0x400 * (no - 2))
#define TIM14 ((struct tim14 *)0x40002000)
#define TIM15 ((struct tim15 *)0x40014000)
#define TIM16_17(no) ((struct tim16_17 *)0x40014400 + 0x400 * (no - 6))
#define TIM6_7(no) ((struct tim6_7 *)0x40001000 + 0x400 * (no - 6))
#define IWDG ((struct iwdg *)0x40003000)
#define WWDG ((struct wwdg *)0x40002c00)
#define RTC ((struct rtc *)0x40002800)
#define I2C(no) ((struct i2c *)0x40005400 + 0x400 * (no - 1))
#define USART2_5(no) ((struct usart *)0x40004400 + 0x400(no - 2))
#define USART6_8(no) ((struct usart *)0x40011400 + 0x400(no - 6))
#define USART1 ((struct usart *)0x40013800)
#define SPI1 ((struct spi *)0x40013000)
#define SPI2 ((struct spi *)0x40003800)
#define CAN ((struct can *)0x40006400)
#define USB ((struct usb *)0x40005c00)
#define CEC ((struct cec *)0x40007800)
#define UID ((volatile uint32_t *)0x1ffff7ac)
#define UID_BCD ((volatile uint32_t *)0x1ffff7ac + 0x4)
#define FLASH_SIZE ((volatile uint16_t *)0x1ffff7cc)
#define SYSTICK ((struct systick *)0xe000e010)
#define CPUID ((volatile uint32_t *)0xe000ed00)
#define ICSR ((volatile uint32_t *)0xe000ed04)
#define AIRCR ((volatile uint32_t *)0xe000ed0c)
#define SCR ((volatile uint32_t *)0xe000ed10)
#define CCR ((volatile uint32_t *)0xe000ed14)
#define SHPR2 ((volatile uint32_t *)0xe000ed1c)
#define SHPR3 ((volatile uint32_t *)0xe000ed20)
