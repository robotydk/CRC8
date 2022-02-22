#include <stdio.h>
#include <stdint.h>
#include<math.h>
unsigned long int CRC8(unsigned long int data_buff);
short int hex(short int hex_val);

unsigned long int CRC8(unsigned long int data_buff)
{
    unsigned long int mask_1 = 0x800000;
    unsigned long int mask = 0, crc_res = 0;
    unsigned long int generator = 0x838000;
    int j = 0;

    while ((data_buff >> 8) != 0x00000000)
    {
        for (int i=0; i<sizeof(data_buff); i++)
        {
            mask = mask_1 >> j;
            crc_res = data_buff & mask;
            if (crc_res == mask)
            {
                data_buff = data_buff ^ generator;
                generator = generator >> 1;
                j++;
            }
            else
            {
                j++;
                generator = generator >> 1;
            }
        }
    }
    printf("%x",data_buff);
}

short int hex(short int hex_val)
{
    short int hex_digit=0, foo = 0;
    int ans=0, j=3;
    for (int i=12; i>=0; i = i-4)
    {
        hex_digit = (hex_val >> i) & 0x000f;
        if (hex_digit >= 0 && hex_digit <= 9)
        {
            ans += hex_digit * ((int)pow(16,j));
            j--;
        }
        else if (hex_digit >= 10 && hex_digit <= 15)
        {
            ans += hex_digit * ((int)pow(16,j));
            j--;
        }
    }
    printf("%d",ans);
}

void main()
{
    //long int is of 4 bytes
    unsigned long int msg_buff = 0x364f00;
    //CRC8(msg_buff);
    short int hex1 = 0xFFFF;
    hex(hex1);
}