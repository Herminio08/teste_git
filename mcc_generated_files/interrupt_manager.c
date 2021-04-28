/**
  Generated Interrupt Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F25K80
        Driver Version    :  2.12
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB 	          :  MPLAB X 5.45
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Enable Interrupt Priority Vectors
    RCONbits.IPEN = 1;

    // Assign peripheral interrupt priority vectors

    // TXI - high priority
    IPR1bits.TX1IP = 1;

    // RCI - high priority
    IPR1bits.RC1IP = 1;


    // WAKI - low priority
    IPR5bits.WAKIP = 0;    

    // ERRI - low priority
    IPR5bits.ERRIP = 0;    

    // RXB1I - low priority
    IPR5bits.RXB1IP = 0;    

    // IRXI - low priority
    IPR5bits.IRXIP = 0;    

    // RXB0I - low priority
    IPR5bits.RXB0IP = 0;    

    // TXB2I - low priority
    IPR5bits.TXB2IP = 0;    

    // TXB1I - low priority
    IPR5bits.TXB1IP = 0;    

    // TXB0I - low priority
    IPR5bits.TXB0IP = 0;    

}

void __interrupt() INTERRUPT_InterruptManagerHigh (void)
{
   // interrupt handler
    if(PIE1bits.TX1IE == 1 && PIR1bits.TX1IF == 1)
    {
        EUSART1_TxDefaultInterruptHandler();
    }
    else if(PIE1bits.RC1IE == 1 && PIR1bits.RC1IF == 1)
    {
        EUSART1_RxDefaultInterruptHandler();
    }
    else
    {
        //Unhandled Interrupt
    }
}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow (void)
{
    // interrupt handler
    if(PIE5bits.WAKIE == 1 && PIR5bits.WAKIF == 1)
    {
        ECAN_WAKI_ISR();
    }
    else if(PIE5bits.ERRIE == 1 && PIR5bits.ERRIF == 1)
    {
        ECAN_ERRI_ISR();
    }
    else if(PIE5bits.RXB1IE == 1 && PIR5bits.RXB1IF == 1)
    {
        ECAN_RXB1I_ISR();
    }
    else if(PIE5bits.IRXIE == 1 && PIR5bits.IRXIF == 1)
    {
        ECAN_IRXI_ISR();
    }
    else if(PIE5bits.RXB0IE == 1 && PIR5bits.RXB0IF == 1)
    {
        ECAN_RXB0I_ISR();
    }
    else if(PIE5bits.TXB2IE == 1 && PIR5bits.TXB2IF == 1)
    {
        ECAN_TXB2I_ISR();
    }
    else if(PIE5bits.TXB1IE == 1 && PIR5bits.TXB1IF == 1)
    {
        ECAN_TXB1I_ISR();
    }
    else if(PIE5bits.TXB0IE == 1 && PIR5bits.TXB0IF == 1)
    {
        ECAN_TXB0I_ISR();
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
