/* Copyright (C) Dimitris Mandalidis */
 
unsigned int crc16_ccitt(unsigned char *src, unsigned int len)
{                                                                                                                                                  
        unsigned int crc_reg = 0;                                                                                                                  
        unsigned int i,j,octet;                                                                                                                    
        #define CRC_POLY 0x11021                                                                                                                   
        #define SRC_MSB 0x80                                                                                                                       
        #define CRC_LFSR_MSB 0x10000                                                                                                               
                                                                                                                                                   
        for (i = 0; i < len; i++) {                                                                                                                
      		octet = src[i];                                                                                                                    
            for (j = 0; j < 8; j++) {                                                                                                          
            	crc_reg <<= 1;                                                                                                             
                if (octet & SRC_MSB)                                                                                                       
                	crc_reg |= 1;                                                                                                      
                octet <<= 1;                                                                                                               
                if (crc_reg & CRC_LFSR_MSB)                                                                                                
                	crc_reg ^= CRC_POLY;                                                                                               
            }                                                                                                                                  
        }                                                                                                                                          
        for (j = 0; j < 16; j++) {                                                                                                                 
        	crc_reg <<= 1;                                                                                                                             
            if (crc_reg & CRC_LFSR_MSB)                                                                                                            
            	crc_reg ^= CRC_POLY;                                                                                                                   
        }                                                                                                                                          
        return crc_reg;                                                                                                                            
}                       
