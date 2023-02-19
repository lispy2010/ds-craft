#pragma once
#ifdef __cplusplus
#define loadImage(spr, w, h, bitmap) glLoadTileSet(spr, w, h, w, h, GL_RGB, TEXTURE_SIZE_##w, TEXTURE_SIZE_##h, GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF, 0, 0, const_cast<u8 *>(reinterpret_cast<const u8 *>(bitmap)))
#define loadImageAlpha(spr, w, h, pal, bitmap) glLoadTileSet(spr, w, h, w, h, GL_RGB16, TEXTURE_SIZE_##w, TEXTURE_SIZE_##h, GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF | GL_TEXTURE_COLOR0_TRANSPARENT, 16, pal, const_cast<u8 *>(reinterpret_cast<const u8 *>(bitmap)))
#else
#define loadImage(spr, w, h, bitmap) glLoadTileSet(spr, w, h, w, h, GL_RGB, TEXTURE_SIZE_##w, TEXTURE_SIZE_##h, GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF, 0, 0, (u8 *)bitmap)
#define loadImageAlpha(spr, w, h, pal, bitmap) glLoadTileSet(spr, w, h, w, h, GL_RGB16, TEXTURE_SIZE_##w, TEXTURE_SIZE_##h, GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF | GL_TEXTURE_COLOR0_TRANSPARENT, 16, pal, (u8 *)bitmap)
#endif
#define unloadImage(spr) glDeleteTextures(1, &spr->textureID)
#define randomRange(a, b) ((a) + rand() % (((b) + 1) - (a)))
#define soundEffect(id)                            \
    {                                              \
        {id}, (int)(1.0f * (1 << 10)), 0, 255, 128 \
    }

#define declsfx4(effectname)            \
    mm_sound_effect snd##effectname##1; \
    mm_sound_effect snd##effectname##2; \
    mm_sound_effect snd##effectname##3; \
    mm_sound_effect snd##effectname##4;
#define declsfx3(effectname)            \
    mm_sound_effect snd##effectname##1; \
    mm_sound_effect snd##effectname##2; \
    mm_sound_effect snd##effectname##3;
#define loadsfx4(effectname)           \
    mmLoadEffect(SFX_##effectname##1); \
    mmLoadEffect(SFX_##effectname##2); \
    mmLoadEffect(SFX_##effectname##3); \
    mmLoadEffect(SFX_##effectname##4);
#define loadsfx3(effectname)           \
    mmLoadEffect(SFX_##effectname##1); \
    mmLoadEffect(SFX_##effectname##2); \
    mmLoadEffect(SFX_##effectname##3);
#define unloadsfx4(effectname)           \
    mmUnloadEffect(SFX_##effectname##1); \
    mmUnloadEffect(SFX_##effectname##2); \
    mmUnloadEffect(SFX_##effectname##3); \
    mmUnloadEffect(SFX_##effectname##4);
#define unloadsfx3(effectname)           \
    mmUnloadEffect(SFX_##effectname##1); \
    mmUnloadEffect(SFX_##effectname##2); \
    mmUnloadEffect(SFX_##effectname##3);
#define setsfx4(effectname, effectid)                    \
    snd##effectname##1 = soundEffect(SFX_##effectid##1); \
    snd##effectname##2 = soundEffect(SFX_##effectid##2); \
    snd##effectname##3 = soundEffect(SFX_##effectid##3); \
    snd##effectname##4 = soundEffect(SFX_##effectid##4);
#define setsfx3(effectname, effectid)                    \
    snd##effectname##1 = soundEffect(SFX_##effectid##1); \
    snd##effectname##2 = soundEffect(SFX_##effectid##2); \
    snd##effectname##3 = soundEffect(SFX_##effectid##3);

// if 1, filesystem errors will be displayed (e.g. can't open a file)
// if 0, filesystem errors will not be displayed
#define FS_ERROR_MESSAGES 1

#define HALFSIZE ((1 << 12) / 2)

// i think these are reduntant
typedef signed short s16;
typedef signed char s8;
