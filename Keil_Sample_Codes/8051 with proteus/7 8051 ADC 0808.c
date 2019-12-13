#include<reg51.h>
/* ADC DataBus is connected to P2 and Control lines are connected to P1*/
#define adc_DATABUS  P2
sbit adc_A = P1^0;
sbit adc_B = P1^1;
sbit adc_C = P1^2;
sbit adc_ALE = P1^3;
sbit adc_START = P1^4;
sbit adc_EOC = P1^5;
sbit adc_OE = P1^6;

void delay_us(int count)
{
    while(count--);
}

void ADC_Init(void)
{
    adc_START=0;        //Initialize all the control lines to zero.
    adc_ALE=0;
    adc_OE=0;
    adc_EOC=1;          //Configure the EOC pin as I/P
    adc_DATABUS=0xff;   //configure adc_databus as input
}

uint8_t ADC_Read(uint8_t v_adcChannel_u8)
{
    uint8_t adc_result;

    adc_A=((v_adcChannel_u8>>0) & 0x01);   //Select the channel
    adc_B=((v_adcChannel_u8>>1) & 0x01);   //for which the conversion needs to be done
    adc_C=((v_adcChannel_u8>>2) & 0x01);

    adc_ALE=1;         // Latch the address by making the ALE high.
    DELAY_us(50);
    adc_Start=1;       //Start the conversion after latching the channel address
    delay_us(25);

    adc_ALE=0;         //Pull ALE line to zero after starting the conversion.
    delay_us(50);
    adc_START=0;       //Pull Start line to zero after starting the conversion.

    while(adc_EOC==0); // Wait till the ADC conversion is completed,
                       // EOC will be pulled to HIGH by ADC0809 once conversion is completed.

    adc_OE=1;          //Make the Output Enable high to bring the ADC data to port pins
    delay_us(25);
    adc_result=adc_DATABUS;  //Read the ADC data from ADC bus
    adc_OE=0;                //After reading the data, disable the ADC output line.

    return(adc_result) ;
}

void main()
{
    ADC_Init();             //Initialize the ADC module

    while(1)
    {
        P0 = ADC_Read(0);       // Read the ADC value of channel zero and display on LED's Connected to PO
    }
}