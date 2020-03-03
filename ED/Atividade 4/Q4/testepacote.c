#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pacote.h"
#include <inttypes.h>

int main(void){
    Packet *p1, *p2;
    //P1 será tipo Data
    p1 = createDataPacket(8, 1, 2, 2);
    //p2 será tipo ACK
    p2 = createACKPacket(7, 3, 2);
    
    //Usando a writeData com nosso p1
    uint8_t data[] = {1,3,5,7,111};
    writeData(p1, data, 3);
    
    //Usando a função clonePacket nos pacotes
    Packet *pct_clonado1 = clonePacket(p1);
    Packet *pct_clonado2 = clonePacket(p2);

    //Usando a função printPacketInformation com os pacotes
    printPacketInformation(p1);
    printf("\n");
    printPacketInformation(p2);
    printf("\n");

    //Usando a função deletePacket nos pacotes e seus clones
    deletePacket(p1);
    deletePacket(p2);
    deletePacket(pct_clonado1);
    deletePacket(pct_clonado2);


}

