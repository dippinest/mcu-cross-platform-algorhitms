
#include "gamma.h"


// таблица значений степенной аппроксимации
//
// -------------------------------------------------------------------------------
// table of power approximation values
//
const uint8_t Gamma_Correction_Power_Approximation_Table[256] PROGMEM =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05,
	0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07,
	0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x0A,
	0x0A, 0x0A, 0x0B, 0x0B, 0x0C, 0x0C, 0x0C, 0x0D,
	0x0D, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x10, 0x10,
	0x11, 0x11, 0x12, 0x12, 0x13, 0x13, 0x14, 0x14,
	0x15, 0x16, 0x16, 0x17, 0x17, 0x18, 0x19, 0x19,
	0x1A, 0x1B, 0x1B, 0x1C, 0x1D, 0x1D, 0x1E, 0x1F,
	0x20, 0x20, 0x21, 0x22, 0x23, 0x23, 0x24, 0x25,
	0x26, 0x27, 0x28, 0x29, 0x29, 0x2A, 0x2B, 0x2C,
	0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34,
	0x35, 0x36, 0x37, 0x38, 0x39, 0x3B, 0x3C, 0x3D,
	0x3E, 0x3F, 0x40, 0x42, 0x43, 0x44, 0x45, 0x47,
	0x48, 0x49, 0x4B, 0x4C, 0x4D, 0x4F, 0x50, 0x51,
	0x53, 0x54, 0x56, 0x57, 0x59, 0x5A, 0x5C, 0x5D,
	0x5F, 0x60, 0x62, 0x64, 0x65, 0x67, 0x68, 0x6A,
	0x6C, 0x6E, 0x6F, 0x71, 0x73, 0x75, 0x76, 0x78,
	0x7A, 0x7C, 0x7E, 0x80, 0x82, 0x84, 0x85, 0x87,
	0x89, 0x8B, 0x8E, 0x90, 0x92, 0x94, 0x96, 0x98,
	0x9A, 0x9C, 0x9E, 0xA1, 0xA3, 0xA5, 0xA7, 0xAA,
	0xAC, 0xAE, 0xB1, 0xB3, 0xB6, 0xB8, 0xBA, 0xBD,
	0xBF, 0xC2, 0xC4, 0xC7, 0xCA, 0xCC, 0xCF, 0xD1,
	0xD4, 0xD7, 0xD9, 0xDC, 0xDF, 0xE2, 0xE5, 0xE7,
	0xEA, 0xED, 0xF0, 0xF3, 0xF6, 0xF9, 0xFC, 0xFF
};


// таблица значений логарифмической аппроксимации
//
// -------------------------------------------------------------------------------
// table of logarithmic approximation values
//
const uint8_t Gamma_Correction_Logarithmic_Approximation_Table[256] PROGMEM =
{
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06,
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08,
	0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09,
	0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0B, 0x0B, 0x0B,
	0x0B, 0x0C, 0x0C, 0x0C, 0x0C, 0x0D, 0x0D, 0x0D,
	0x0E, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x10,
	0x10, 0x10, 0x11, 0x11, 0x12, 0x12, 0x12, 0x13,
	0x13, 0x14, 0x14, 0x14, 0x15, 0x15, 0x16, 0x16,
	0x17, 0x17, 0x18, 0x18, 0x19, 0x19, 0x1A, 0x1B,
	0x1B, 0x1C, 0x1C, 0x1D, 0x1E, 0x1E, 0x1F, 0x20,
	0x20, 0x21, 0x22, 0x23, 0x23, 0x24, 0x25, 0x26,
	0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D,
	0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
	0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3D, 0x3E, 0x3F,
	0x41, 0x42, 0x44, 0x45, 0x47, 0x48, 0x4A, 0x4C,
	0x4D, 0x4F, 0x51, 0x52, 0x54, 0x56, 0x58, 0x5A,
	0x5C, 0x5E, 0x60, 0x62, 0x64, 0x66, 0x69, 0x6B,
	0x6D, 0x70, 0x72, 0x75, 0x77, 0x7A, 0x7C, 0x7F,
	0x82, 0x85, 0x88, 0x8B, 0x8E, 0x91, 0x94, 0x97,
	0x9B, 0x9E, 0xA2, 0xA5, 0xA9, 0xAC, 0xB0, 0xB4,
	0xB8, 0xBC, 0xC0, 0xC4, 0xC9, 0xCD, 0xD2, 0xD6,
	0xDB, 0xE0, 0xE5, 0xEA, 0xEF, 0xF4, 0xF9, 0xFF
};


// ===============================================================================


uint8_t Gamma_Correction_Get_Power_Approximation_Value(uint8_t value)
{
	return pgm_read_byte(&(Gamma_Correction_Power_Approximation_Table[value]));
}

uint8_t Gamma_Correction_Get_Logarithmic_Approximation_Value(uint8_t value)
{
	return pgm_read_byte(&(Gamma_Correction_Logarithmic_Approximation_Table[value]));
}



