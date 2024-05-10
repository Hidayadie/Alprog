
;CodeVisionAVR C Compiler V3.14 Advanced
;(C) Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
;http://www.hpinfotech.com

;Build configuration    : Debug
;Chip type              : ATmega32
;Program type           : Application
;Clock frequency        : 12,000000 MHz
;Memory model           : Small
;Optimize for           : Size
;(s)printf features     : int, width
;(s)scanf features      : int, width
;External RAM size      : 0
;Data Stack size        : 512 byte(s)
;Heap size              : 0 byte(s)
;Promote 'char' to 'int': Yes
;'char' is unsigned     : Yes
;8 bit enums            : Yes
;Global 'const' stored in FLASH: Yes
;Enhanced function parameter passing: Yes
;Enhanced core instructions: On
;Automatic register allocation for global variables: On
;Smart register allocation: On

	#define _MODEL_SMALL_

	#pragma AVRPART ADMIN PART_NAME ATmega32
	#pragma AVRPART MEMORY PROG_FLASH 32768
	#pragma AVRPART MEMORY EEPROM 1024
	#pragma AVRPART MEMORY INT_SRAM SIZE 2048
	#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x60

	#define CALL_SUPPORTED 1

	.LISTMAC
	.EQU UDRE=0x5
	.EQU RXC=0x7
	.EQU USR=0xB
	.EQU UDR=0xC
	.EQU SPSR=0xE
	.EQU SPDR=0xF
	.EQU EERE=0x0
	.EQU EEWE=0x1
	.EQU EEMWE=0x2
	.EQU EECR=0x1C
	.EQU EEDR=0x1D
	.EQU EEARL=0x1E
	.EQU EEARH=0x1F
	.EQU WDTCR=0x21
	.EQU MCUCR=0x35
	.EQU GICR=0x3B
	.EQU SPL=0x3D
	.EQU SPH=0x3E
	.EQU SREG=0x3F

	.DEF R0X0=R0
	.DEF R0X1=R1
	.DEF R0X2=R2
	.DEF R0X3=R3
	.DEF R0X4=R4
	.DEF R0X5=R5
	.DEF R0X6=R6
	.DEF R0X7=R7
	.DEF R0X8=R8
	.DEF R0X9=R9
	.DEF R0XA=R10
	.DEF R0XB=R11
	.DEF R0XC=R12
	.DEF R0XD=R13
	.DEF R0XE=R14
	.DEF R0XF=R15
	.DEF R0X10=R16
	.DEF R0X11=R17
	.DEF R0X12=R18
	.DEF R0X13=R19
	.DEF R0X14=R20
	.DEF R0X15=R21
	.DEF R0X16=R22
	.DEF R0X17=R23
	.DEF R0X18=R24
	.DEF R0X19=R25
	.DEF R0X1A=R26
	.DEF R0X1B=R27
	.DEF R0X1C=R28
	.DEF R0X1D=R29
	.DEF R0X1E=R30
	.DEF R0X1F=R31

	.EQU __SRAM_START=0x0060
	.EQU __SRAM_END=0x085F
	.EQU __DSTACK_SIZE=0x0200
	.EQU __HEAP_SIZE=0x0000
	.EQU __CLEAR_SRAM_SIZE=__SRAM_END-__SRAM_START+1

	.MACRO __CPD1N
	CPI  R30,LOW(@0)
	LDI  R26,HIGH(@0)
	CPC  R31,R26
	LDI  R26,BYTE3(@0)
	CPC  R22,R26
	LDI  R26,BYTE4(@0)
	CPC  R23,R26
	.ENDM

	.MACRO __CPD2N
	CPI  R26,LOW(@0)
	LDI  R30,HIGH(@0)
	CPC  R27,R30
	LDI  R30,BYTE3(@0)
	CPC  R24,R30
	LDI  R30,BYTE4(@0)
	CPC  R25,R30
	.ENDM

	.MACRO __CPWRR
	CP   R@0,R@2
	CPC  R@1,R@3
	.ENDM

	.MACRO __CPWRN
	CPI  R@0,LOW(@2)
	LDI  R30,HIGH(@2)
	CPC  R@1,R30
	.ENDM

	.MACRO __ADDB1MN
	SUBI R30,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDB2MN
	SUBI R26,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDW1MN
	SUBI R30,LOW(-@0-(@1))
	SBCI R31,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW2MN
	SUBI R26,LOW(-@0-(@1))
	SBCI R27,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	SBCI R22,BYTE3(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1N
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	SBCI R22,BYTE3(-@0)
	SBCI R23,BYTE4(-@0)
	.ENDM

	.MACRO __ADDD2N
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	SBCI R24,BYTE3(-@0)
	SBCI R25,BYTE4(-@0)
	.ENDM

	.MACRO __SUBD1N
	SUBI R30,LOW(@0)
	SBCI R31,HIGH(@0)
	SBCI R22,BYTE3(@0)
	SBCI R23,BYTE4(@0)
	.ENDM

	.MACRO __SUBD2N
	SUBI R26,LOW(@0)
	SBCI R27,HIGH(@0)
	SBCI R24,BYTE3(@0)
	SBCI R25,BYTE4(@0)
	.ENDM

	.MACRO __ANDBMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ANDWMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ANDI R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ANDD1N
	ANDI R30,LOW(@0)
	ANDI R31,HIGH(@0)
	ANDI R22,BYTE3(@0)
	ANDI R23,BYTE4(@0)
	.ENDM

	.MACRO __ANDD2N
	ANDI R26,LOW(@0)
	ANDI R27,HIGH(@0)
	ANDI R24,BYTE3(@0)
	ANDI R25,BYTE4(@0)
	.ENDM

	.MACRO __ORBMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ORWMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ORI  R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ORD1N
	ORI  R30,LOW(@0)
	ORI  R31,HIGH(@0)
	ORI  R22,BYTE3(@0)
	ORI  R23,BYTE4(@0)
	.ENDM

	.MACRO __ORD2N
	ORI  R26,LOW(@0)
	ORI  R27,HIGH(@0)
	ORI  R24,BYTE3(@0)
	ORI  R25,BYTE4(@0)
	.ENDM

	.MACRO __DELAY_USB
	LDI  R24,LOW(@0)
__DELAY_USB_LOOP:
	DEC  R24
	BRNE __DELAY_USB_LOOP
	.ENDM

	.MACRO __DELAY_USW
	LDI  R24,LOW(@0)
	LDI  R25,HIGH(@0)
__DELAY_USW_LOOP:
	SBIW R24,1
	BRNE __DELAY_USW_LOOP
	.ENDM

	.MACRO __GETD1S
	LDD  R30,Y+@0
	LDD  R31,Y+@0+1
	LDD  R22,Y+@0+2
	LDD  R23,Y+@0+3
	.ENDM

	.MACRO __GETD2S
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	LDD  R24,Y+@0+2
	LDD  R25,Y+@0+3
	.ENDM

	.MACRO __PUTD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R31
	STD  Y+@0+2,R22
	STD  Y+@0+3,R23
	.ENDM

	.MACRO __PUTD2S
	STD  Y+@0,R26
	STD  Y+@0+1,R27
	STD  Y+@0+2,R24
	STD  Y+@0+3,R25
	.ENDM

	.MACRO __PUTDZ2
	STD  Z+@0,R26
	STD  Z+@0+1,R27
	STD  Z+@0+2,R24
	STD  Z+@0+3,R25
	.ENDM

	.MACRO __CLRD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R30
	STD  Y+@0+2,R30
	STD  Y+@0+3,R30
	.ENDM

	.MACRO __POINTB1MN
	LDI  R30,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW1MN
	LDI  R30,LOW(@0+(@1))
	LDI  R31,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD1M
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __POINTW1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	LDI  R22,BYTE3(2*@0+(@1))
	LDI  R23,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTB2MN
	LDI  R26,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW2MN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTW2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	LDI  R24,BYTE3(2*@0+(@1))
	LDI  R25,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTBRM
	LDI  R@0,LOW(@1)
	.ENDM

	.MACRO __POINTWRM
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __POINTBRMN
	LDI  R@0,LOW(@1+(@2))
	.ENDM

	.MACRO __POINTWRMN
	LDI  R@0,LOW(@2+(@3))
	LDI  R@1,HIGH(@2+(@3))
	.ENDM

	.MACRO __POINTWRFN
	LDI  R@0,LOW(@2*2+(@3))
	LDI  R@1,HIGH(@2*2+(@3))
	.ENDM

	.MACRO __GETD1N
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __GETD2N
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __GETB1MN
	LDS  R30,@0+(@1)
	.ENDM

	.MACRO __GETB1HMN
	LDS  R31,@0+(@1)
	.ENDM

	.MACRO __GETW1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	.ENDM

	.MACRO __GETD1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	LDS  R22,@0+(@1)+2
	LDS  R23,@0+(@1)+3
	.ENDM

	.MACRO __GETBRMN
	LDS  R@0,@1+(@2)
	.ENDM

	.MACRO __GETWRMN
	LDS  R@0,@2+(@3)
	LDS  R@1,@2+(@3)+1
	.ENDM

	.MACRO __GETWRZ
	LDD  R@0,Z+@2
	LDD  R@1,Z+@2+1
	.ENDM

	.MACRO __GETD2Z
	LDD  R26,Z+@0
	LDD  R27,Z+@0+1
	LDD  R24,Z+@0+2
	LDD  R25,Z+@0+3
	.ENDM

	.MACRO __GETB2MN
	LDS  R26,@0+(@1)
	.ENDM

	.MACRO __GETW2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	.ENDM

	.MACRO __GETD2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	LDS  R24,@0+(@1)+2
	LDS  R25,@0+(@1)+3
	.ENDM

	.MACRO __PUTB1MN
	STS  @0+(@1),R30
	.ENDM

	.MACRO __PUTW1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	.ENDM

	.MACRO __PUTD1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	STS  @0+(@1)+2,R22
	STS  @0+(@1)+3,R23
	.ENDM

	.MACRO __PUTB1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRB
	.ENDM

	.MACRO __PUTW1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRW
	.ENDM

	.MACRO __PUTD1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRD
	.ENDM

	.MACRO __PUTBR0MN
	STS  @0+(@1),R0
	.ENDM

	.MACRO __PUTBMRN
	STS  @0+(@1),R@2
	.ENDM

	.MACRO __PUTWMRN
	STS  @0+(@1),R@2
	STS  @0+(@1)+1,R@3
	.ENDM

	.MACRO __PUTBZR
	STD  Z+@1,R@0
	.ENDM

	.MACRO __PUTWZR
	STD  Z+@2,R@0
	STD  Z+@2+1,R@1
	.ENDM

	.MACRO __GETW1R
	MOV  R30,R@0
	MOV  R31,R@1
	.ENDM

	.MACRO __GETW2R
	MOV  R26,R@0
	MOV  R27,R@1
	.ENDM

	.MACRO __GETWRN
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __PUTW1R
	MOV  R@0,R30
	MOV  R@1,R31
	.ENDM

	.MACRO __PUTW2R
	MOV  R@0,R26
	MOV  R@1,R27
	.ENDM

	.MACRO __ADDWRN
	SUBI R@0,LOW(-@2)
	SBCI R@1,HIGH(-@2)
	.ENDM

	.MACRO __ADDWRR
	ADD  R@0,R@2
	ADC  R@1,R@3
	.ENDM

	.MACRO __SUBWRN
	SUBI R@0,LOW(@2)
	SBCI R@1,HIGH(@2)
	.ENDM

	.MACRO __SUBWRR
	SUB  R@0,R@2
	SBC  R@1,R@3
	.ENDM

	.MACRO __ANDWRN
	ANDI R@0,LOW(@2)
	ANDI R@1,HIGH(@2)
	.ENDM

	.MACRO __ANDWRR
	AND  R@0,R@2
	AND  R@1,R@3
	.ENDM

	.MACRO __ORWRN
	ORI  R@0,LOW(@2)
	ORI  R@1,HIGH(@2)
	.ENDM

	.MACRO __ORWRR
	OR   R@0,R@2
	OR   R@1,R@3
	.ENDM

	.MACRO __EORWRR
	EOR  R@0,R@2
	EOR  R@1,R@3
	.ENDM

	.MACRO __GETWRS
	LDD  R@0,Y+@2
	LDD  R@1,Y+@2+1
	.ENDM

	.MACRO __PUTBSR
	STD  Y+@1,R@0
	.ENDM

	.MACRO __PUTWSR
	STD  Y+@2,R@0
	STD  Y+@2+1,R@1
	.ENDM

	.MACRO __MOVEWRR
	MOV  R@0,R@2
	MOV  R@1,R@3
	.ENDM

	.MACRO __INWR
	IN   R@0,@2
	IN   R@1,@2+1
	.ENDM

	.MACRO __OUTWR
	OUT  @2+1,R@1
	OUT  @2,R@0
	.ENDM

	.MACRO __CALL1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	ICALL
	.ENDM

	.MACRO __CALL1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	CALL __GETW1PF
	ICALL
	.ENDM

	.MACRO __CALL2EN
	PUSH R26
	PUSH R27
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMRDW
	POP  R27
	POP  R26
	ICALL
	.ENDM

	.MACRO __CALL2EX
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	CALL __EEPROMRDD
	ICALL
	.ENDM

	.MACRO __GETW1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z
	MOVW R30,R0
	.ENDM

	.MACRO __NBST
	BST  R@0,@1
	IN   R30,SREG
	LDI  R31,0x40
	EOR  R30,R31
	OUT  SREG,R30
	.ENDM


	.MACRO __PUTB1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RNS
	MOVW R26,R@0
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	CALL __PUTDP1
	.ENDM


	.MACRO __GETB1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R30,Z
	.ENDM

	.MACRO __GETB1HSX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	.ENDM

	.MACRO __GETW1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z+
	LD   R23,Z
	MOVW R30,R0
	.ENDM

	.MACRO __GETB2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R26,X
	.ENDM

	.MACRO __GETW2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	.ENDM

	.MACRO __GETD2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R1,X+
	LD   R24,X+
	LD   R25,X
	MOVW R26,R0
	.ENDM

	.MACRO __GETBRSX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	LD   R@0,Z
	.ENDM

	.MACRO __GETWRSX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	LD   R@0,Z+
	LD   R@1,Z
	.ENDM

	.MACRO __GETBRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	LD   R@0,X
	.ENDM

	.MACRO __GETWRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	LD   R@0,X+
	LD   R@1,X
	.ENDM

	.MACRO __LSLW8SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	CLR  R30
	.ENDM

	.MACRO __PUTB1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __CLRW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __CLRD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R30
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __PUTB2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z,R26
	.ENDM

	.MACRO __PUTW2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z,R27
	.ENDM

	.MACRO __PUTD2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z+,R27
	ST   Z+,R24
	ST   Z,R25
	.ENDM

	.MACRO __PUTBSRX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	ST   Z,R@0
	.ENDM

	.MACRO __PUTWSRX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	ST   Z+,R@0
	ST   Z,R@1
	.ENDM

	.MACRO __PUTB1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __MULBRR
	MULS R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRRU
	MUL  R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRR0
	MULS R@0,R@1
	.ENDM

	.MACRO __MULBRRU0
	MUL  R@0,R@1
	.ENDM

	.MACRO __MULBNWRU
	LDI  R26,@2
	MUL  R26,R@0
	MOVW R30,R0
	MUL  R26,R@1
	ADD  R31,R0
	.ENDM

	.CSEG
	.ORG 0x00

;START OF CODE MARKER
__START_OF_CODE:

;INTERRUPT VECTORS
	JMP  __RESET
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00

__RESET:
	CLI
	CLR  R30
	OUT  EECR,R30

;INTERRUPT VECTORS ARE PLACED
;AT THE START OF FLASH
	LDI  R31,1
	OUT  GICR,R31
	OUT  GICR,R30
	OUT  MCUCR,R30

;CLEAR R2-R14
	LDI  R24,(14-2)+1
	LDI  R26,2
	CLR  R27
__CLEAR_REG:
	ST   X+,R30
	DEC  R24
	BRNE __CLEAR_REG

;CLEAR SRAM
	LDI  R24,LOW(__CLEAR_SRAM_SIZE)
	LDI  R25,HIGH(__CLEAR_SRAM_SIZE)
	LDI  R26,__SRAM_START
__CLEAR_SRAM:
	ST   X+,R30
	SBIW R24,1
	BRNE __CLEAR_SRAM

;HARDWARE STACK POINTER INITIALIZATION
	LDI  R30,LOW(__SRAM_END-__HEAP_SIZE)
	OUT  SPL,R30
	LDI  R30,HIGH(__SRAM_END-__HEAP_SIZE)
	OUT  SPH,R30

;DATA STACK POINTER INITIALIZATION
	LDI  R28,LOW(__SRAM_START+__DSTACK_SIZE)
	LDI  R29,HIGH(__SRAM_START+__DSTACK_SIZE)

	JMP  _main

	.ESEG
	.ORG 0

	.DSEG
	.ORG 0x260

	.CSEG
;#include <mega32.h>
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
;#include <delay.h>
;//#include <cstdio>
;const short JUMLAHLAMPU = 4;
;short lampuSebelumnya[JUMLAHLAMPU] = {0,0,0,0};
;
;// FUNGSI INISIALISASI
;void init(void) {
; 0000 0008 void init(void) {

	.CSEG
_init:
; .FSTART _init
; 0000 0009 // Declare your local variables here
; 0000 000A 
; 0000 000B // Input/Output Ports initialization
; 0000 000C // Port A initialization
; 0000 000D // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
; 0000 000E DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
	LDI  R30,LOW(0)
	OUT  0x1A,R30
; 0000 000F // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
; 0000 0010 PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
	OUT  0x1B,R30
; 0000 0011 
; 0000 0012 // Port B initialization
; 0000 0013 // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
; 0000 0014 DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
	OUT  0x17,R30
; 0000 0015 // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
; 0000 0016 PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
	OUT  0x18,R30
; 0000 0017 
; 0000 0018 // Port C initialization
; 0000 0019 // Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
; 0000 001A DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
	LDI  R30,LOW(255)
	OUT  0x14,R30
; 0000 001B // State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
; 0000 001C PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
	LDI  R30,LOW(0)
	OUT  0x15,R30
; 0000 001D 
; 0000 001E // Port D initialization
; 0000 001F // Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
; 0000 0020 DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
	LDI  R30,LOW(255)
	OUT  0x11,R30
; 0000 0021 // State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
; 0000 0022 PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
	LDI  R30,LOW(0)
	OUT  0x12,R30
; 0000 0023 
; 0000 0024 // Timer/Counter 0 initialization
; 0000 0025 // Clock source: System Clock
; 0000 0026 // Clock value: Timer 0 Stopped
; 0000 0027 // Mode: Normal top=0xFF
; 0000 0028 // OC0 output: Disconnected
; 0000 0029 TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
	OUT  0x33,R30
; 0000 002A TCNT0=0x00;
	OUT  0x32,R30
; 0000 002B OCR0=0x00;
	OUT  0x3C,R30
; 0000 002C 
; 0000 002D // Timer/Counter 1 initialization
; 0000 002E // Clock source: System Clock
; 0000 002F // Clock value: Timer1 Stopped
; 0000 0030 // Mode: Normal top=0xFFFF
; 0000 0031 // OC1A output: Disconnected
; 0000 0032 // OC1B output: Disconnected
; 0000 0033 // Noise Canceler: Off
; 0000 0034 // Input Capture on Falling Edge
; 0000 0035 // Timer1 Overflow Interrupt: Off
; 0000 0036 // Input Capture Interrupt: Off
; 0000 0037 // Compare A Match Interrupt: Off
; 0000 0038 // Compare B Match Interrupt: Off
; 0000 0039 TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
	OUT  0x2F,R30
; 0000 003A TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
	OUT  0x2E,R30
; 0000 003B TCNT1H=0x00;
	OUT  0x2D,R30
; 0000 003C TCNT1L=0x00;
	OUT  0x2C,R30
; 0000 003D ICR1H=0x00;
	OUT  0x27,R30
; 0000 003E ICR1L=0x00;
	OUT  0x26,R30
; 0000 003F OCR1AH=0x00;
	OUT  0x2B,R30
; 0000 0040 OCR1AL=0x00;
	OUT  0x2A,R30
; 0000 0041 OCR1BH=0x00;
	OUT  0x29,R30
; 0000 0042 OCR1BL=0x00;
	OUT  0x28,R30
; 0000 0043 
; 0000 0044 // Timer/Counter 2 initialization
; 0000 0045 // Clock source: System Clock
; 0000 0046 // Clock value: Timer2 Stopped
; 0000 0047 // Mode: Normal top=0xFF
; 0000 0048 // OC2 output: Disconnected
; 0000 0049 ASSR=0<<AS2;
	OUT  0x22,R30
; 0000 004A TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
	OUT  0x25,R30
; 0000 004B TCNT2=0x00;
	OUT  0x24,R30
; 0000 004C OCR2=0x00;
	OUT  0x23,R30
; 0000 004D 
; 0000 004E // Timer(s)/Counter(s) Interrupt(s) initialization
; 0000 004F TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
	OUT  0x39,R30
; 0000 0050 
; 0000 0051 // External Interrupt(s) initialization
; 0000 0052 // INT0: Off
; 0000 0053 // INT1: Off
; 0000 0054 // INT2: Off
; 0000 0055 MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
	OUT  0x35,R30
; 0000 0056 MCUCSR=(0<<ISC2);
	OUT  0x34,R30
; 0000 0057 
; 0000 0058 // USART initialization
; 0000 0059 // USART disabled
; 0000 005A UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
	OUT  0xA,R30
; 0000 005B 
; 0000 005C // Analog Comparator initialization
; 0000 005D // Analog Comparator: Off
; 0000 005E // The Analog Comparator's positive input is
; 0000 005F // connected to the AIN0 pin
; 0000 0060 // The Analog Comparator's negative input is
; 0000 0061 // connected to the AIN1 pin
; 0000 0062 ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
	LDI  R30,LOW(128)
	OUT  0x8,R30
; 0000 0063 SFIOR=(0<<ACME);
	LDI  R30,LOW(0)
	OUT  0x30,R30
; 0000 0064 
; 0000 0065 // ADC initialization
; 0000 0066 // ADC disabled
; 0000 0067 ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);
	OUT  0x6,R30
; 0000 0068 
; 0000 0069 // SPI initialization
; 0000 006A // SPI disabled
; 0000 006B SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	OUT  0xD,R30
; 0000 006C 
; 0000 006D // TWI initialization
; 0000 006E // TWI disabled
; 0000 006F TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
	OUT  0x36,R30
; 0000 0070 }
	RET
; .FEND
;
;// KONSTRUKTOR
;void otomatis(void);
;void manual(void);
;
;// FUNGSI" LAMPU
;void lampu1(int status) {
; 0000 0077 void lampu1(int status) {
_lampu1:
; .FSTART _lampu1
; 0000 0078      switch (status) {             // KODE STATUS
	RCALL SUBOPT_0x0
;	status -> Y+0
; 0000 0079         case 0:                    // MERAH
	BRNE _0x6
; 0000 007A             PORTC.0 = 1;
	SBI  0x15,0
; 0000 007B             PORTC.1 = 0;
	CBI  0x15,1
; 0000 007C             PORTC.2 = 0;
	CBI  0x15,2
; 0000 007D             lampuSebelumnya[0] = 0;
	LDI  R30,LOW(0)
	STS  _lampuSebelumnya,R30
	STS  _lampuSebelumnya+1,R30
; 0000 007E         break;
	RJMP _0x5
; 0000 007F 
; 0000 0080         case 1:                    // KUNING
_0x6:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0xD
; 0000 0081             PORTC.0 = 0;
	CBI  0x15,0
; 0000 0082             PORTC.1 = 1;
	SBI  0x15,1
; 0000 0083             PORTC.2 = 0;
	CBI  0x15,2
; 0000 0084         break;
	RJMP _0x5
; 0000 0085 
; 0000 0086         case 2:                    // HIJAU
_0xD:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x5
; 0000 0087             PORTC.0 = 0;
	CBI  0x15,0
; 0000 0088             PORTC.1 = 0;
	CBI  0x15,1
; 0000 0089             PORTC.2 = 1;
	SBI  0x15,2
; 0000 008A             lampuSebelumnya[0] = 1;
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	STS  _lampuSebelumnya,R30
	STS  _lampuSebelumnya+1,R31
; 0000 008B         break;
; 0000 008C     }
_0x5:
; 0000 008D }
	RJMP _0x2000001
; .FEND
;
;void lampu2(int status) {
; 0000 008F void lampu2(int status) {
_lampu2:
; .FSTART _lampu2
; 0000 0090     switch (status) {
	RCALL SUBOPT_0x0
;	status -> Y+0
; 0000 0091         case 0:
	BRNE _0x1E
; 0000 0092             PORTC.3 = 1;
	SBI  0x15,3
; 0000 0093             PORTC.4 = 0;
	CBI  0x15,4
; 0000 0094             PORTC.5 = 0;
	CBI  0x15,5
; 0000 0095             lampuSebelumnya[1] = 0;
	__POINTW1MN _lampuSebelumnya,2
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	RJMP _0x99
; 0000 0096         break;
; 0000 0097 
; 0000 0098         case 1:
_0x1E:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0x25
; 0000 0099             PORTC.3 = 0;
	CBI  0x15,3
; 0000 009A             PORTC.4 = 1;
	SBI  0x15,4
; 0000 009B             PORTC.5 = 0;
	CBI  0x15,5
; 0000 009C         break;
	RJMP _0x1D
; 0000 009D 
; 0000 009E         case 2:
_0x25:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x1D
; 0000 009F             PORTC.3 = 0;
	CBI  0x15,3
; 0000 00A0             PORTC.4 = 0;
	CBI  0x15,4
; 0000 00A1             PORTC.5 = 1;
	SBI  0x15,5
; 0000 00A2             lampuSebelumnya[1] = 1;
	__POINTW1MN _lampuSebelumnya,2
	LDI  R26,LOW(1)
	LDI  R27,HIGH(1)
_0x99:
	STD  Z+0,R26
	STD  Z+1,R27
; 0000 00A3         break;
; 0000 00A4     }
_0x1D:
; 0000 00A5 }
	RJMP _0x2000001
; .FEND
;
;void lampu3(int status) {
; 0000 00A7 void lampu3(int status) {
_lampu3:
; .FSTART _lampu3
; 0000 00A8     switch (status) {
	RCALL SUBOPT_0x0
;	status -> Y+0
; 0000 00A9         case 0:
	BRNE _0x36
; 0000 00AA             PORTD.0 = 1;
	SBI  0x12,0
; 0000 00AB             PORTD.1 = 0;
	CBI  0x12,1
; 0000 00AC             PORTD.2 = 0;
	CBI  0x12,2
; 0000 00AD             lampuSebelumnya[2] = 0;
	__POINTW1MN _lampuSebelumnya,4
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	RJMP _0x9A
; 0000 00AE         break;
; 0000 00AF 
; 0000 00B0         case 1:
_0x36:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0x3D
; 0000 00B1             PORTD.0 = 0;
	CBI  0x12,0
; 0000 00B2             PORTD.1 = 1;
	SBI  0x12,1
; 0000 00B3             PORTD.2 = 0;
	CBI  0x12,2
; 0000 00B4         break;
	RJMP _0x35
; 0000 00B5 
; 0000 00B6         case 2:
_0x3D:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x35
; 0000 00B7             PORTD.0 = 0;
	CBI  0x12,0
; 0000 00B8             PORTD.1 = 0;
	CBI  0x12,1
; 0000 00B9             PORTD.2 = 1;
	SBI  0x12,2
; 0000 00BA             lampuSebelumnya[2] = 1;
	__POINTW1MN _lampuSebelumnya,4
	LDI  R26,LOW(1)
	LDI  R27,HIGH(1)
_0x9A:
	STD  Z+0,R26
	STD  Z+1,R27
; 0000 00BB         break;
; 0000 00BC     }
_0x35:
; 0000 00BD }
	RJMP _0x2000001
; .FEND
;
;void lampu4(int status) {
; 0000 00BF void lampu4(int status) {
_lampu4:
; .FSTART _lampu4
; 0000 00C0     switch (status) {
	RCALL SUBOPT_0x0
;	status -> Y+0
; 0000 00C1         case 0:
	BRNE _0x4E
; 0000 00C2             PORTD.3 = 1;
	SBI  0x12,3
; 0000 00C3             PORTD.4 = 0;
	CBI  0x12,4
; 0000 00C4             PORTD.5 = 0;
	CBI  0x12,5
; 0000 00C5             lampuSebelumnya[3] = 0;
	__POINTW1MN _lampuSebelumnya,6
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	RJMP _0x9B
; 0000 00C6         break;
; 0000 00C7 
; 0000 00C8         case 1:
_0x4E:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0x55
; 0000 00C9             PORTD.3 = 0;
	CBI  0x12,3
; 0000 00CA             PORTD.4 = 1;
	SBI  0x12,4
; 0000 00CB             PORTD.5 = 0;
	CBI  0x12,5
; 0000 00CC         break;
	RJMP _0x4D
; 0000 00CD 
; 0000 00CE         case 2:
_0x55:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x4D
; 0000 00CF             PORTD.3 = 0;
	CBI  0x12,3
; 0000 00D0             PORTD.4 = 0;
	CBI  0x12,4
; 0000 00D1             PORTD.5 = 1;
	SBI  0x12,5
; 0000 00D2             lampuSebelumnya[3] = 1;
	__POINTW1MN _lampuSebelumnya,6
	LDI  R26,LOW(1)
	LDI  R27,HIGH(1)
_0x9B:
	STD  Z+0,R26
	STD  Z+1,R27
; 0000 00D3         break;
; 0000 00D4     }
_0x4D:
; 0000 00D5 }
_0x2000001:
	ADIW R28,2
	RET
; .FEND
;
;
;// FUNGSI GANTI WARNA BIAR JADI KUNING
;void ganti() {
; 0000 00D9 void ganti() {
_ganti:
; .FSTART _ganti
; 0000 00DA     int i, ketemu, ubah;
; 0000 00DB     for (i = 0; i < JUMLAHLAMPU; i++) { /* NGECEK 1 PER 1 */
	CALL __SAVELOCR6
;	i -> R16,R17
;	ketemu -> R18,R19
;	ubah -> R20,R21
	__GETWRN 16,17,0
_0x64:
	__CPWRN 16,17,4
	BRGE _0x65
; 0000 00DC         if (lampuSebelumnya[i] == 1) {  // KALO KETEMU...
	MOVW R30,R16
	LDI  R26,LOW(_lampuSebelumnya)
	LDI  R27,HIGH(_lampuSebelumnya)
	LSL  R30
	ROL  R31
	ADD  R26,R30
	ADC  R27,R31
	CALL __GETW1P
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0x66
; 0000 00DD             ketemu = 1;                 // kondisi ketemu menjadi 1 = true
	__GETWRN 18,19,1
; 0000 00DE             ubah = i;                   // dan nilai iterator disimpan
	MOVW R20,R16
; 0000 00DF             break;                      // keluar dari loop for, jadi kalo
	RJMP _0x65
; 0000 00E0         }                               // ketemu langsung berhenti loop for
; 0000 00E1     }
_0x66:
	__ADDWRN 16,17,1
	RJMP _0x64
_0x65:
; 0000 00E2     if (ketemu == 1) {                  // KALAU TADI ADA (TRUE)
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	CP   R30,R18
	CPC  R31,R19
	BRNE _0x67
; 0000 00E3         switch (ubah) {                 // cek lampu mana yang diubah
	MOVW R30,R20
; 0000 00E4             case 0:                     /* LAMPU 1 */
	SBIW R30,0
	BRNE _0x6B
; 0000 00E5                 lampu1(1);              // lampu 1 -> kuning
	LDI  R26,LOW(1)
	LDI  R27,0
	RCALL _lampu1
; 0000 00E6                 delay_ms(1000);         // delay 1 detik
	RCALL SUBOPT_0x1
; 0000 00E7                 lampu1(0);              // lampu 1 -> merah
	RCALL _lampu1
; 0000 00E8             break;
	RJMP _0x6A
; 0000 00E9             case 1:                     /* LAMPU 2 */
_0x6B:
	CPI  R30,LOW(0x1)
	LDI  R26,HIGH(0x1)
	CPC  R31,R26
	BRNE _0x6C
; 0000 00EA                 lampu2(1);              // lampu 2 -> kuning
	LDI  R26,LOW(1)
	LDI  R27,0
	RCALL _lampu2
; 0000 00EB                 delay_ms(1000);         // delay 1 detik
	RCALL SUBOPT_0x1
; 0000 00EC                 lampu2(0);              // lampu 2 -> merah
	RCALL _lampu2
; 0000 00ED             break;
	RJMP _0x6A
; 0000 00EE             case 2:                     /* LAMPU 3 */
_0x6C:
	CPI  R30,LOW(0x2)
	LDI  R26,HIGH(0x2)
	CPC  R31,R26
	BRNE _0x6D
; 0000 00EF                 lampu3(1);              // lampu 3 -> kuning
	LDI  R26,LOW(1)
	LDI  R27,0
	RCALL _lampu3
; 0000 00F0                 delay_ms(1000);         // delay 1 detik
	RCALL SUBOPT_0x1
; 0000 00F1                 lampu3(0);              // lampu 3 -> merah
	RCALL _lampu3
; 0000 00F2             break;
	RJMP _0x6A
; 0000 00F3             case 3:                     /* LAMPU 4 */
_0x6D:
	CPI  R30,LOW(0x3)
	LDI  R26,HIGH(0x3)
	CPC  R31,R26
	BRNE _0x6A
; 0000 00F4                 lampu4(1);              // lampu 4 -> kuning
	LDI  R26,LOW(1)
	LDI  R27,0
	RCALL _lampu4
; 0000 00F5                 delay_ms(1000);         // delay 1 detik
	RCALL SUBOPT_0x1
; 0000 00F6                 lampu4(0);              // lampu 4 -> merah
	RCALL _lampu4
; 0000 00F7             break;
; 0000 00F8         }
_0x6A:
; 0000 00F9     }
; 0000 00FA }
_0x67:
	CALL __LOADLOCR6
	ADIW R28,6
	RET
; .FEND
;
;
;
;        /****************/
;        /*  KODE UTAMA  */
;        /****************/
;
;
;void main(void) {
; 0000 0103 void main(void) {
_main:
; .FSTART _main
; 0000 0104     int mode = 0;                   /* START MODE: OTOMATIS */
; 0000 0105     init();                         // jalanin kode inisialisasi 1x
;	mode -> R16,R17
	__GETWRN 16,17,0
	RCALL _init
; 0000 0106 
; 0000 0107     while (1) {                     // looping utama
_0x6F:
; 0000 0108         if (mode == 0) {            // cek mode lampu, jika 0
	MOV  R0,R16
	OR   R0,R17
	BRNE _0x72
; 0000 0109             otomatis();             // jalanin mode otomatis
	RCALL _otomatis
; 0000 010A         }
; 0000 010B         else if (mode == 1) {       // cek mode lampu, jika 1
	RJMP _0x73
_0x72:
	RCALL SUBOPT_0x2
	BRNE _0x74
; 0000 010C             manual();               // kalanin mode manual
	RCALL _manual
; 0000 010D         }
; 0000 010E 
; 0000 010F         mode = (mode == 1) ? 0 : 1; // cek, apakah mode isi nilainya 1...
_0x74:
_0x73:
	RCALL SUBOPT_0x2
	BRNE _0x75
	LDI  R30,LOW(0)
	LDI  R31,HIGH(0)
	RJMP _0x76
_0x75:
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
_0x76:
	MOVW R16,R30
; 0000 0110                                     // jika iya isinya 1,   ganti 0
; 0000 0111     }                               // jika isinya bukan 1, ganti 1
	RJMP _0x6F
; 0000 0112 }
_0x78:
	RJMP _0x78
; .FEND
;
;void manual(void)
; 0000 0115 {
_manual:
; .FSTART _manual
; 0000 0116     PORTD.7 = 1;             // hidupin lampu mode manual
	SBI  0x12,7
; 0000 0117 
; 0000 0118     lampu1(0);               // semua lampu bewarna merah
	RCALL SUBOPT_0x3
; 0000 0119     lampu2(0);
; 0000 011A     lampu3(0);
; 0000 011B     lampu4(0);
; 0000 011C     while (1)                // looping utama
_0x7B:
; 0000 011D           {
; 0000 011E           // Place your code here
; 0000 011F           if ((PINA&0b00010000) == 0) {     /* TOMBOL MODE */
	SBIS 0x19,4
; 0000 0120             //tutt();
; 0000 0121             break;                          // keluar dari looping while
	RJMP _0x7D
; 0000 0122 
; 0000 0123           }
; 0000 0124 
; 0000 0125 
; 0000 0126            else if((PINA&0b00000001)== 0) { /* TOMBOL 1 */
	SBIC 0x19,0
	RJMP _0x80
; 0000 0127             ganti();                        // ganti warna lampu sebelumnya
	RCALL SUBOPT_0x4
; 0000 0128             delay_ms(1000);                 // delay 1 detik
; 0000 0129             lampu1(2);                      // lampu 1 -> hijau
	RCALL _lampu1
; 0000 012A 
; 0000 012B           }
; 0000 012C 
; 0000 012D           else if((PINA&0b00000010)== 0) {  /* TOMBOL 2 */
	RJMP _0x81
_0x80:
	SBIC 0x19,1
	RJMP _0x82
; 0000 012E             ganti();                        // ganti warna lampu sebelumnya
	RCALL SUBOPT_0x4
; 0000 012F             delay_ms(1000);                 // delay 1 detik
; 0000 0130             lampu2(2);                      // lampu 2 -> hijau
	RCALL _lampu2
; 0000 0131           }
; 0000 0132 
; 0000 0133           else if((PINA&0b00000100)== 0) {  /* TOMBOL 3 */
	RJMP _0x83
_0x82:
	SBIC 0x19,2
	RJMP _0x84
; 0000 0134             ganti();                        // ganti warna lampu sebelumnya
	RCALL SUBOPT_0x4
; 0000 0135             delay_ms(1000);                 // delay 1 detik
; 0000 0136             lampu3(2);                      // lampu 3 -> hijau
	RCALL _lampu3
; 0000 0137           }
; 0000 0138 
; 0000 0139           else if((PINA&0b00001000)== 0) {  /* TOMBOL 4 */
	RJMP _0x85
_0x84:
	SBIC 0x19,3
	RJMP _0x86
; 0000 013A             ganti();                        // ganti warna lampu sebelumnya
	RCALL SUBOPT_0x4
; 0000 013B             delay_ms(1000);                 // delay 1 detik
; 0000 013C             lampu4(2);                      // lampu 4 -> hijau
	RCALL _lampu4
; 0000 013D           }
; 0000 013E 
; 0000 013F     } //while
_0x86:
_0x85:
_0x83:
_0x81:
	RJMP _0x7B
_0x7D:
; 0000 0140 
; 0000 0141     PORTD.7 = 0;             // Matikan lampu mode Manual
	CBI  0x12,7
; 0000 0142     delay_ms(2000);          // delay 2 detik
	LDI  R26,LOW(2000)
	LDI  R27,HIGH(2000)
	CALL _delay_ms
; 0000 0143 }// main
	RET
; .FEND
;
;        /*********************/
;        /*  FUNGSI OTOMATIS  */
;        /*********************/
;
;void otomatis(void) {
; 0000 0149 void otomatis(void) {
_otomatis:
; .FSTART _otomatis
; 0000 014A     int bruh = 0;               // :v tanya sendiri
; 0000 014B     PORTD.6 = 1;                // hidupin lampu mode
	ST   -Y,R17
	ST   -Y,R16
;	bruh -> R16,R17
	__GETWRN 16,17,0
	SBI  0x12,6
; 0000 014C 
; 0000 014D     lampu1(0);                  // semua lampu merah
	RCALL SUBOPT_0x3
; 0000 014E     lampu2(0);
; 0000 014F     lampu3(0);
; 0000 0150     lampu4(0);
; 0000 0151     while (1) {                 // loop utama
_0x8B:
; 0000 0152         if ((PINA&0b00010000) == 0) { /* TOMBOL MODE */
	SBIC 0x19,4
	RJMP _0x8E
; 0000 0153             bruh = -1;                // rusak urutan nyala lampu, lalu
	__GETWRN 16,17,-1
; 0000 0154             //tutt();                 // keluar dari loop harus nunggu
; 0000 0155             break;                    // delay dibawahnya selesai
	RJMP _0x8D
; 0000 0156         }
; 0000 0157         else if (bruh == 0) {         /* URUTAN PERTAMA */
_0x8E:
	MOV  R0,R16
	OR   R0,R17
	BRNE _0x90
; 0000 0158             delay_ms(1000);           // delay 1 detik
	RCALL SUBOPT_0x5
; 0000 0159             lampu1(2);                // lampu 1 -> hijau
	RCALL _lampu1
; 0000 015A             delay_ms(3000);           // delay 3 detik
	RCALL SUBOPT_0x6
; 0000 015B             lampu1(0);                // lampu 1 -> merah
	RCALL _lampu1
; 0000 015C             bruh++;                   // urutan + 1
	__ADDWRN 16,17,1
; 0000 015D         }
; 0000 015E         else if (bruh == 1) {         /* URUTAN KEDUA */
	RJMP _0x91
_0x90:
	RCALL SUBOPT_0x2
	BRNE _0x92
; 0000 015F             delay_ms(1000);           // delay 1 deti
	RCALL SUBOPT_0x5
; 0000 0160             lampu2(2);                // lampu 2 -> hijau
	RCALL _lampu2
; 0000 0161             delay_ms(3000);           // delay 3 detik
	RCALL SUBOPT_0x6
; 0000 0162             lampu2(0);                // lampu 2 -> merah
	RCALL _lampu2
; 0000 0163             bruh++;                   // urutan + 1
	__ADDWRN 16,17,1
; 0000 0164         }
; 0000 0165         else if (bruh == 2) {         /* URUTAN KETIGA */
	RJMP _0x93
_0x92:
	LDI  R30,LOW(2)
	LDI  R31,HIGH(2)
	CP   R30,R16
	CPC  R31,R17
	BRNE _0x94
; 0000 0166             delay_ms(1000);           // delay 1 deti
	RCALL SUBOPT_0x5
; 0000 0167             lampu3(2);                // lampu 3 -> hijau
	RCALL _lampu3
; 0000 0168             delay_ms(3000);           // delay 3 detik
	RCALL SUBOPT_0x6
; 0000 0169             lampu3(0);                // lampu 3 -> merah
	RCALL _lampu3
; 0000 016A             bruh++;                   // urutan + 1
	__ADDWRN 16,17,1
; 0000 016B         }
; 0000 016C         else if (bruh == 3) {         /* URUTAN KEEMPAT */
	RJMP _0x95
_0x94:
	LDI  R30,LOW(3)
	LDI  R31,HIGH(3)
	CP   R30,R16
	CPC  R31,R17
	BRNE _0x96
; 0000 016D             delay_ms(1000);           // delay 1 deti
	RCALL SUBOPT_0x5
; 0000 016E             lampu4(2);                // lampu 4 -> hijau
	RCALL _lampu4
; 0000 016F             delay_ms(3000);           // delay 3 detik
	RCALL SUBOPT_0x6
; 0000 0170             lampu4(0);                // lampu 4 -> merah
	RCALL _lampu4
; 0000 0171             bruh = 0;                 // urutan reset mulai dari awal
	__GETWRN 16,17,0
; 0000 0172         }
; 0000 0173 
; 0000 0174     }
_0x96:
_0x95:
_0x93:
_0x91:
	RJMP _0x8B
_0x8D:
; 0000 0175 
; 0000 0176     PORTD.6 = 0;             // matikan lampu mode Otomatis
	CBI  0x12,6
; 0000 0177     delay_ms(2000);          // delay 2 detik
	LDI  R26,LOW(2000)
	LDI  R27,HIGH(2000)
	CALL _delay_ms
; 0000 0178 
; 0000 0179 }
	LD   R16,Y+
	LD   R17,Y+
	RET
; .FEND

	.DSEG
_lampuSebelumnya:
	.BYTE 0x8

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:6 WORDS
SUBOPT_0x0:
	ST   -Y,R27
	ST   -Y,R26
	LD   R30,Y
	LDD  R31,Y+1
	SBIW R30,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:9 WORDS
SUBOPT_0x1:
	LDI  R26,LOW(1000)
	LDI  R27,HIGH(1000)
	CALL _delay_ms
	LDI  R26,LOW(0)
	LDI  R27,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x2:
	LDI  R30,LOW(1)
	LDI  R31,HIGH(1)
	CP   R30,R16
	CPC  R31,R17
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:11 WORDS
SUBOPT_0x3:
	LDI  R26,LOW(0)
	LDI  R27,0
	RCALL _lampu1
	LDI  R26,LOW(0)
	LDI  R27,0
	RCALL _lampu2
	LDI  R26,LOW(0)
	LDI  R27,0
	RCALL _lampu3
	LDI  R26,LOW(0)
	LDI  R27,0
	RJMP _lampu4

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:15 WORDS
SUBOPT_0x4:
	RCALL _ganti
	LDI  R26,LOW(1000)
	LDI  R27,HIGH(1000)
	CALL _delay_ms
	LDI  R26,LOW(2)
	LDI  R27,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:9 WORDS
SUBOPT_0x5:
	LDI  R26,LOW(1000)
	LDI  R27,HIGH(1000)
	CALL _delay_ms
	LDI  R26,LOW(2)
	LDI  R27,0
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 4 TIMES, CODE SIZE REDUCTION:9 WORDS
SUBOPT_0x6:
	LDI  R26,LOW(3000)
	LDI  R27,HIGH(3000)
	CALL _delay_ms
	LDI  R26,LOW(0)
	LDI  R27,0
	RET


	.CSEG
_delay_ms:
	adiw r26,0
	breq __delay_ms1
__delay_ms0:
	wdr
	__DELAY_USW 0xBB8
	sbiw r26,1
	brne __delay_ms0
__delay_ms1:
	ret

__GETW1P:
	LD   R30,X+
	LD   R31,X
	SBIW R26,1
	RET

__SAVELOCR6:
	ST   -Y,R21
__SAVELOCR5:
	ST   -Y,R20
__SAVELOCR4:
	ST   -Y,R19
__SAVELOCR3:
	ST   -Y,R18
__SAVELOCR2:
	ST   -Y,R17
	ST   -Y,R16
	RET

__LOADLOCR6:
	LDD  R21,Y+5
__LOADLOCR5:
	LDD  R20,Y+4
__LOADLOCR4:
	LDD  R19,Y+3
__LOADLOCR3:
	LDD  R18,Y+2
__LOADLOCR2:
	LDD  R17,Y+1
	LD   R16,Y
	RET

;END OF CODE MARKER
__END_OF_CODE:
