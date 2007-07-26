#ifndef XU1541_BIOS_H
#define XU1541_BIOS_H

#define BIOSTABLE __attribute__ ((section (".textbiostable")))

typedef unsigned char RJMP[2];

typedef
struct xu1541_bios_data_s {
        unsigned char version_major;
        unsigned char version_minor;
        RJMP start_flash_bootloader;
        RJMP spm;
} xu1541_bios_data_t;

extern xu1541_bios_data_t bios_data BIOSTABLE;

#define bios_start_flash_bootloader() \
        ((void(*)(void))&bios_data.start_flash_bootloader)()

#define bios_spm(_what, _address, _data) \
        ((void(*)(uint8_t what, uint16_t address, uint16_t data))&bios_data.spm)(_what, _address, _data)

#endif /* #ifndef XU1541_BIOS_H */
