/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************
 * 
 *                       MSP430 CODE EXAMPLE DISCLAIMER
 *
 * MSP430 code examples are self-contained low-level programs that typically
 * demonstrate a single peripheral function or device feature in a highly
 * concise manner. For this the code may rely on the device's power-on default
 * register values and settings such as the clock configuration and care must
 * be taken when combining code from several examples to avoid potential side
 * effects. Also see www.ti.com/grace for a GUI- and www.ti.com/msp430ware
 * for an API functional library-approach to peripheral configuration.
 *
 * --/COPYRIGHT--*/
//******************************************************************************
//  MSP430F54xA Demo - RTC_A in real time clock mode
//
//  Description: This program demonstrates the RTC mode by triggering an
//  interrupt every second and minute. This code toggles P1.0 every second.
//  This code recommends an external LFXT1 crystal for RTC accuracy.
//  ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
//
//                MSP430F54xA
//             -----------------
//        /|\ |              XIN|-
//         |  |                 | 32kHz
//         ---|RST          XOUT|-
//            |                 |
//            |            P1.0 |--> Toggles every second
//            |                 |
//
//  W. Goh
//  Texas Instruments Inc.
//  April 2010
//  Built with CCS version 4.2 and IAR Embedded Workbench Version: 4.21.8
//******************************************************************************

//Blinking LED CODE
// #include <msp430.h>
// #include <stdio.h>
// int main(void)
// {
//   WDTCTL = WDTPW | WDTHOLD;
//   P10DIR |= BIT0;                          
//   P10OUT |= BIT0; 
  
//   while (1)                                 
//   {
//       P10OUT ^= BIT0;                        
//       __delay_cycles(100000);
        
//   }
// }


//
// #include <msp430.h>

// int main(void)
// {
//     WDTCTL = WDTPW | WDTHOLD;

//     // LED on P10.0
//     P10DIR |= BIT0;   // Output
//     P10OUT &= ~BIT0;  // Start OFF

//     // Button on P10.1
//     P10DIR &= ~BIT1;  // Input
//     P10REN |= BIT1;   // Enable resistor
//     P10OUT &= ~BIT1;   // Pulldown resistor (so unpressed = 0, pressed = 1)

//     while (1)
//     {
//         if ((P10IN & BIT1) )   // Button pressed (reads 1)
//         {
//             P10OUT |= BIT0;        // Turn LED ON
//         }
//         else                       // Button not pressed
//         {
//             P10OUT &= ~BIT0;       // Turn LED OFF
//         }
//     }
// }

#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    P1DIR |= BIT0;              // Set P1.0 as output (LED pin)

    while (1)
    {
        P1OUT ^= BIT0;          // Toggle P1.0
        __delay_cycles(50000);  // Delay (same as assembly loop)
    }
}