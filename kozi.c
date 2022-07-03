#include <stdio.h>
#include "pico/stdio.h"
#include "hardware/adc.h"
#include <math.h>

int main(){
    adc_init();
    adc_gpi_init(27);
    adc_select_input(1);

    while(1){
        float resistencia = adc_read();
        resistencia = resistencia*3.3/4095;
        resistencia = 10000/(3.3/resistencia-1);
        float kozigian = (3950*298)/(298*log(resistencia/10000)+3950) - 273; 

        printf("la temperatura es: %.2f (Resistencia: %.2f )\n", kozigian, resistencia);

        sleep_ms(500);
    }
}