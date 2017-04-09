/*
 * Copyright (C) 2017 Noralf Trønnes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __LINUX_TINYDRM_HELPERS_ADD_H
#define __LINUX_TINYDRM_HELPERS_ADD_H

/*

In file included from /home/pi/tinydrm/tinydrm/include/drm/tinydrm/tinydrm-helpers2.h:13:0,
                 from /home/pi/tinydrm/tinydrm/include/drm/tinydrm/tinydrm-ili9325.h:13,
                 from /home/pi/tinydrm/tinydrm/fb_ili9325.c:28:
./include/drm/tinydrm/tinydrm-helpers.h:40:14: warning: ‘struct drm_framebuffer’ declared inside parameter list [enabled by default]
       struct drm_clip_rect *clip);
              ^
./include/drm/tinydrm/tinydrm-helpers.h:40:14: warning: its scope is only this definition or declaration, which is probably not what you want [enabled by default]


*/
struct drm_framebuffer;

#include <drm/tinydrm/tinydrm-helpers.h>

struct gpio_desc;

int tinydrm_rgb565_buf_copy(void *dst, struct drm_framebuffer *fb,
			    struct drm_clip_rect *clip, bool swap);
void tinydrm_rgb565_to_mono8(u8 *mono8, u16 *vmem16, u32 width, u32 height);
void tinydrm_mono8_to_mono(u8 *mono, u8 *mono8, u32 width, u32 height);

void tinydrm_hw_reset(struct gpio_desc *reset, unsigned int assert_ms,
		      unsigned int settle_ms);

#endif /* __LINUX_TINYDRM_HELPERS_ADD_H */
