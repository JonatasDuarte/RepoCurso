#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
//Datapacket = 0
//Ackpacket =  1
typedef struct {
    uint8_t id_pct, tam_pct, *bytes;
    int tipo_pct; //ack = 1 OU data = 0
    uint32_t end_ori, end_dest;

} Packet;

Packet * createDataPacket(uint8_t id, uint32_t origem, uint32_t destino, uint8_t tam){
    Packet *pct =(Packet*)malloc(sizeof(Packet));
    pct->id_pct = id;
    pct->end_dest = destino;
    pct->end_ori = origem;
    pct->tipo_pct =  0;
    pct->tam_pct = tam;
    uint8_t *pct_bytes;
    pct_bytes = (uint8_t*)malloc(tam*(sizeof(uint8_t)));
    pct->bytes = pct_bytes;
    return pct;
}

Packet * createACKPacket(uint8_t id, uint32_t origem, uint32_t destino){
    Packet *pct = (Packet*)malloc(sizeof(Packet));
    pct-> id_pct = id;
    pct -> end_dest = destino;
    pct -> end_ori = origem;
    pct -> tam_pct = 0;
    pct -> bytes = NULL;
    return pct;
}

void writeData(Packet *pct, uint8_t *bts, uint8_t tam){
    uint8_t bytes_limite = pct->tam_pct;
    uint8_t i;
    for (i=0; i< bytes_limite; i++){
        if(i < tam){
            pct -> bytes[i] = bts[i];
        } else{
             pct -> bytes[i] = 0;
        }
    }
}

Packet * clonePacket(Packet *pct){
    Packet *pct_clone;
    if(pct -> tipo_pct == 0){
        pct_clone = createDataPacket(pct->id_pct, pct-> end_ori, pct->end_dest, pct-> tam_pct);
    } else if(pct -> tipo_pct == 1){
        pct_clone = createACKPacket(pct->id_pct, pct-> end_ori, pct->end_dest);
        writeData(pct, pct->bytes, pct->tam_pct);
    }

    return pct_clone;
}

void printPacketInformation(Packet *pct){
    uint8_t len = pct -> tam_pct;
    uint8_t i, *array = pct->bytes;

    if (pct -> tipo_pct == 1){
        printf("Packet type: ACK\n");
        printf("ID: %d\n", pct-> id_pct);
        printf("Sorce Address: %d\n", pct-> end_ori);
        printf("Destination Address: %d\n", pct-> end_dest);

    } else if(pct -> tipo_pct == 0){
        printf("Packet type: DATA\n");
        printf("ID: %d\n", pct-> id_pct);
        printf("Sorce Address: %d\n", pct-> end_ori);
        printf("Destination Address: %d\n", pct-> end_dest);
        printf("Payload Size: %d\n", pct->tam_pct);    }
        for(i=0; i< len; i++){
            if(i == len-1) printf("%d\n", array[i]);
            else printf("%d ", array[i]);
            
        }
}

void deletePacket(Packet *pct){
    if(pct ->tipo_pct == 0) free(pct ->bytes);
    free(pct);
}