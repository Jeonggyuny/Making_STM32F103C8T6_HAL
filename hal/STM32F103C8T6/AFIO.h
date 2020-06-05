#ifndef HAL_STM32F103C8T6_AFIO_H_
#define HAL_STM32F103C8T6_AFIO_H_

/* Event control register */
typedef union AFIO_EVCR
{
	uint32_t all;
	struct {
		uint32_t PIN:4;		// 3:0
		uint32_t PORT:3;	// 6:4
		uint32_t EVOE:1;	// 7
		uint32_t Reserved:24;	// 31:8
	} bits;
} AFIO_EVCR_t;

/* AF remap and debug I/O configuration register */
typedef union AFIO_MAPR
{
	uint32_t all;
} AFIO_MAPR_t;

/* External interrupt configuration register 1 */
typedef union AFIO_EXTICR1
{
	uint32_t all;
	struct {
		uint32_t EXTIx:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} AFIO_EXTICR1_t;

/* External interrupt configuration register 2 */
typedef union AFIO_EXTICR2
{
	uint32_t all;
	struct {
		uint32_t EXTIx:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} AFIO_EXTICR2_t;

/* External interrupt configuration register 3 */
typedef union AFIO_EXTICR3
{
	uint32_t all;
	struct {
		uint32_t EXTIx:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} AFIO_EXTICR3_t;

/* External interrupt configuration register 4 */
typedef union AFIO_EXTICR4
{
	uint32_t all;
	struct {
		uint32_t EXTIx:16;	// 15:0
		uint32_t Reserved:16;	// 31:16
	} bits;
} AFIO_EXTICR4_t;

/* AF remap and debug I/O configuration register 2 */
typedef union AFIO_MAPR2
{
	uint32_t all;
} AFIO_MAPR2_t;

typedef struct AFIO
{
	AFIO_EVCR_t	afio_evcr;	// 0x00
	AFIO_MAPR_t	afio_mapr;	// 0x04
	AFIO_EXTICR1_t	afio_exticr1;	// 0x08
	AFIO_EXTICR2_t	afio_exticr2;	// 0x0C
	AFIO_EXTICR3_t	afio_exticr3;	// 0x10
	AFIO_EXTICR4_t	afio_exticr4;	// 0x14
	AFIO_MAPR2_t	afio_mapr2;	// 0x18
} AFIO_t;

#define AFIO_BASE_ADDRESS 0x40010000

#endif /* HAL_STM32F103C8T6_AFIO_H_ */
