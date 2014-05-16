#ifndef _DECOMPRESS_H_
#define _DECOMPRESS_H_

#include "gl.h"

void DecompressBlockDXT1(uint32_t x, uint32_t y, uint32_t width,
	const uint8_t* blockStorage,
	uint32_t* image);

void DecompressBlockDXT3(uint32_t x, uint32_t y, uint32_t width,
	const uint8_t* blockStorage,
	uint32_t* image);

void DecompressBlockDXT5(uint32_t x, uint32_t y, uint32_t width,
	const uint8_t* blockStorage, uint32_t* image);



#endif