#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <TBD>

#define RESPONSE_N (256)

int main()
{
    <TBD>_7816_rpdu_t rpdu = {};
    <TBD>_7816_cpdu_t cpdu = {};
    unsigned char response[RESPONSE_N] = {};

    if (0 != <TBD>_SPI_open()) {
        printf("Can't ini SPI Bus!\n");
        return -1;
    }
    set_transcieve_fd(get_ctrl_fd());

    rpdu.len       = sizeof(response);
    rpdu.pdata     = response;
    cpdu.cla       = 0x00;
    cpdu.ins       = 0x70;
    cpdu.p1        = 0x00;
    cpdu.p2        = 0x00;
    cpdu.lc        = 0;
    cpdu.pdata     = NULL;
    cpdu.cpdu_type = 0;
    cpdu.le_type   = 1;
    cpdu.le        = 1;
    if (0 != <TBD>_7816_transceive(&cpdu, &rpdu)) {
        printf("Can't transmit APDU cmd!\n");
    } else {
        printf("Status Words: %02X %02X\n", rpdu.sw1, rpdu.sw2);
    }

    set_transcieve_fd(-1);
    <TBD>_close();

    return 0;
}
