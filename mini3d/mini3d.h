//
//  mini3d.h
//  Extension
//
//  Created by Dave Hayden on 10/20/15.
//  Copyright © 2015 Panic, Inc. All rights reserved.
//

#ifndef mini3d_h
#define mini3d_h

// Generally, you'd only need one of these, as they're two ways of solving the same problem:

// The Z buffer is slower but more accurate, and can handle intersecting geometry.
#define ENABLE_Z_BUFFER 1

// The ordering table is faster but can produce glitches if the table is too small or there's
// intersecting geometry in the scene.
#define ENABLE_ORDERING_TABLE 0

#define ENABLE_TEXTURES 1

// allow textures to have non-opaque pixels
#define ENABLE_TEXTURES_MASK 1

// ignored if textures are disabled
// if 1, textures are mapped with homogenous coordinates.
// if 0, textures will be significantly warped as they approach
// the camera.
#define ENABLE_TEXTURES_PROJECTIVE 1

#define FACE_CLIPPING 1

#define CLIP_EPSILON 1.3f

#include <stddef.h>

extern void* (*m3d_realloc)(void* ptr, size_t size);

#define m3d_malloc(s) m3d_realloc(NULL, (s))
#define m3d_free(ptr) m3d_realloc((ptr), 0)

void mini3d_setRealloc(void* (*realloc)(void* ptr, size_t size));

#include <pd_api.h>
PlaydateAPI* pd;

#endif /* mini3d_h */
