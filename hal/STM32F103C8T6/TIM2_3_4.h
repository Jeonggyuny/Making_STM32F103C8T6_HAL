#ifndef HAL_STM32F103C8T6_TIM2_3_4_H_
#define HAL_STM32F103C8T6_TIM2_3_4_H_

/* TIMx control register 1 */
typedef union TIMx_CR1
{
	uint32_t all;
	struct {
		uint32_t CEN:1;		// 0
		uint32_t UDIS:1;	// 1
		uint32_t URS:1;		// 2
		uint32_t OPM:1;		// 3
		uint32_t DIR:1;		// 4
		uint32_t CMS:2;		// 6:5
		uint32_t ARPE:1;	// 7
		uint32_t CKD:2;		// 9:8
		uint32_t Reserved:22;	// 31:10
	} bits;
} TIMx_CR1_t;

/* TIMx control register 2 */
typedef union TIMx_CR2
{
	uint32_t all;
	struct {
		uint32_t Reserved_0:3;	// 2:0
		uint32_t CCDS:1;	// 3
		uint32_t MMS:3;		// 6:4
		uint32_t TI1S:1;	// 7
		uint32_t Reserved_1:24;	// 31:8
	} bits;
} TIMx_CR2_t;

/* TIMx slave mode control register */
typedef union TIMx_SMCR
{
	uint32_t all;
	struct {
		uint32_t SMS:3;		// 2:0
		uint32_t Reserved_0:1;	// 3
		uint32_t TS:3;		// 6:4
		uint32_t MSM:1;		// 7
		uint32_t ETF:4;		// 11:8
		uint32_t ETPS:2;	// 13:12
		uint32_t ECE:1;		// 14
		uint32_t ETP:1;		// 15
		uint32_t Reserved_1:16;	// 31:16
	} bits;
} TIMx_SMCR_t;

/* TIMx DMA/Interrupt enable register */
typedef union TIMx_DIER
{
	uint32_t all;
	struct {
		uint32_t UIE:1;		// 0
		uint32_t CC1IE:1;	// 1
		uint32_t CC2IE:1;	// 2
		uint32_t CC3IE:1;	// 3
		uint32_t CC4IE:1;	// 4
		uint32_t Reserved_0:1;	// 5
		uint32_t TIE:1;		// 6
		uint32_t Reserved_1:1;	// 7
		uint32_t UDE:1;		// 8
		uint32_t CC1DE:1;	// 9
		uint32_t CC2DE:1;	// 10
		uint32_t CC3DE:1;	// 11
		uint32_t CC4DE:1;	// 12
		uint32_t Reserved_2:1;	// 13
		uint32_t TDE:1;		// 14
		uint32_t Reserved:17;	// 31:15
	} bits;
} TIMx_DIER_t;

/* TIMx status register */
typedef union TIMx_SR
{
	uint32_t all;
	struct {
		uint32_t UIF:1;		// 0
		uint32_t CC1IF:1;	// 1
		uint32_t CC2IF:1;	// 2
		uint32_t CC3IF:1;	// 3
		uint32_t CC4IF:1;	// 4
		uint32_t Reserved_0:1;	// 5
		uint32_t TIF:1;		// 6
		uint32_t Reserved_1:2;	// 8:7
		uint32_t CC1OF:1;	// 9
		uint32_t CC2OF:1;	// 10
		uint32_t CC3OF:1;	// 11
		uint32_t CC4OF:1;	// 12
		uint32_t Reserved_2:19;	// 31:13
	} bits;
} TIMx_SR_t;

/* TIMx event generation register */
typedef union TIMx_EGR
{
	uint32_t all;
	struct {
		uint32_t UG:1;		// 0
		uint32_t CC1G:1;	// 1
		uint32_t CC2G:1;	// 2
		uint32_t CC3G:1;	// 3
		uint32_t CC4G:1;	// 4
		uint32_t Reserved_0:1;	// 5
		uint32_t TG:1;		// 6
		uint32_t Reserved_1:25;	// 31:7
	} bits;
} TIMx_EGR_t;

/* TIMx capture/compare mode register 1 */
typedef union TIMx_CCMR1
{
	uint32_t all;
} TIMx_CCMR1_t;

/* TIMx capture/compare mode register 2 */
typedef union TIMx_CCMR2
{
	uint32_t all;
} TIMx_CCMR2_t;

/* TIMx captuer/compare enable register */
typedef union TIMx_CCER
{
	uint32_t all;
	struct {
		uint32_t CC1E:1;	// 0
		uint32_t CC1P:1;	// 1
		uint32_t Reserved_0:2;	// 3:2
		uint32_t CC2E:1;	// 4
		uint32_t CC2P:1;	// 5
		uint32_t Reserved_1:2;	// 7:6
		uint32_t CC3E:1;	// 8
		uint32_t CC3P:1;	// 9
		uint32_t Reserved_2:2;	// 11:10
		uint32_t CC4E:1;	// 12
		uint32_t CC4P:1;	// 13
		uint32_t Reserved_3:18;	// 31:14
	} bits;
} TIMx_CCER_t;

/* TIMx counter */
typedef union TIMx_CNT
{
	uint32_t all;
	struct {
		uint32_t CNT:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} TIMx_CNT_t;

/* TIMx prescaler */
typedef union TIMx_PSC
{
	uint32_t all;
	struct {
		uint32_t PSC:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} TIMx_PSC_t;

/* TIMx auto-reload register */
typedef union TIMx_ARR
{
	uint32_t all;
	struct {
		uint32_t ARR:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} TIMx_ARR_t;

/* TIMx captuer/compare register 1 */
typedef union TIMx_CCR1
{
	uint32_t all;
	struct {
		uint32_t CCR1:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} TIMx_CCR1_t;

/* TIMx captuer/compare register 1 */
typedef union TIMx_CCR2
{
	uint32_t all;
	struct {
		uint32_t CCR2:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} TIMx_CCR2_t;

/* TIMx captuer/compare register 3 */
typedef union TIMx_CCR3
{
	uint32_t all;
	struct {
		uint32_t CCR3:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} TIMx_CCR3_t;

/* TIMx captuer/compare register 4 */
typedef union TIMx_CCR4
{
	uint32_t all;
	struct {
		uint32_t CCR4:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} TIMx_CCR4_t;

/* TIMx DMA control register */
typedef union TIMx_DCR
{
	uint32_t all;
	struct {
		uint32_t DBA:5;		// 4:0
		uint32_t Reserved_0:4;	// 7::5
		uint32_t DBL:5;		// 12:8
		uint32_t Reserved_1:19;	// 31:13
	} bits;
} TIMx_DCR_t;

/* TIMx DMA address for full transfer */
typedef union TIMx_DMAR
{
	uint32_t all;
	struct {
		uint32_t DMAB:16;	// 15:0
		uint32_t Reserved_0:16;	// 31:16
	} bits;
} TIMx_DMAR_t;

typedef struct TIM2_3_4
{
	TIMx_CR1_t	timx_cr1;	// 0x00
	TIMx_CR2_t	timx_cr2;	// 0x04
	TIMx_SMCR_t	timx_smcr;	// 0x08
	TIMx_DIER_t	timx_dier;	// 0x0C
	TIMx_SR_t	timx_sr;	// 0x10
	TIMx_EGR_t	timx_egr;	// 0x14
	TIMx_CCMR1_t	timx_ccmr1;	// 0x18
	TIMx_CCMR2_t	timx_ccmr2;	// 0x1C
	TIMx_CCER_t	timx_ccer;	// 0x20
	TIMx_CNT_t	timx_cnt;	// 0x24
	TIMx_PSC_t	timx_psc;	// 0x28
	TIMx_ARR_t	timx_arr;	// 0x2C
	uint32_t	Reserved_0;	// 0x30
	TIMx_CCR1_t	timx_ccr1;	// 0x34
	TIMx_CCR2_t	timx_ccr2;	// 0x38
	TIMx_CCR3_t	timx_ccr3;	// 0x3C
	TIMx_CCR4_t	timx_ccr4;	// 0x40
	uint32_t	Reserved_1;	// 0x44
	TIMx_DCR_t	timx_dcr;	// 0x48
	TIMx_DMAR_t	timx_dmar;	// 0x4C
} TIM2_3_4_t;

#define TIM2_BASE_ADDRESS 0x40000000
#define TIM3_BASE_ADDRESS 0x40000400
#define TIM4_BASE_ADDRESS 0x40000800

#endif /* HAL_STM32F103C8T6_TIM2_3_4_H_ */
