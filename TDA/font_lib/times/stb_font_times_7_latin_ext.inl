// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_7_latin_ext_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_7_latin_ext'.
//
/* // Example usage:

static stb_fontchar fontdata[STB_SOMEFONT_NUM_CHARS];

static void init(void)
{
    // optionally replace both STB_SOMEFONT_BITMAP_HEIGHT with STB_SOMEFONT_BITMAP_HEIGHT_POW2
    static unsigned char fontpixels[STB_SOMEFONT_BITMAP_HEIGHT][STB_SOMEFONT_BITMAP_WIDTH];
    STB_SOMEFONT_CREATE(fontdata, fontpixels, STB_SOMEFONT_BITMAP_HEIGHT);
    ... create texture ...
    // for best results rendering 1:1 pixels texels, use nearest-neighbor sampling
    // if allowed to scale up, use bilerp
}

// This function positions characters on integer coordinates, and assumes 1:1 texels to pixels
// Appropriate if nearest-neighbor sampling is used
static void draw_string_integer(int x, int y, char *str) // draw with top-left point x,y
{
    ... use texture ...
    ... turn on alpha blending and gamma-correct alpha blending ...
    glBegin(GL_QUADS);
    while (*str) {
        int char_codepoint = *str++;
        stb_fontchar *cd = &fontdata[char_codepoint - STB_SOMEFONT_FIRST_CHAR];
        glTexCoord2f(cd->s0, cd->t0); glVertex2i(x + cd->x0, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t0); glVertex2i(x + cd->x1, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t1); glVertex2i(x + cd->x1, y + cd->y1);
        glTexCoord2f(cd->s0, cd->t1); glVertex2i(x + cd->x0, y + cd->y1);
        // if bilerping, in D3D9 you'll need a half-pixel offset here for 1:1 to behave correct
        x += cd->advance_int;
    }
    glEnd();
}

// This function positions characters on float coordinates, and doesn't require 1:1 texels to pixels
// Appropriate if bilinear filtering is used
static void draw_string_float(float x, float y, char *str) // draw with top-left point x,y
{
    ... use texture ...
    ... turn on alpha blending and gamma-correct alpha blending ...
    glBegin(GL_QUADS);
    while (*str) {
        int char_codepoint = *str++;
        stb_fontchar *cd = &fontdata[char_codepoint - STB_SOMEFONT_FIRST_CHAR];
        glTexCoord2f(cd->s0f, cd->t0f); glVertex2f(x + cd->x0f, y + cd->y0f);
        glTexCoord2f(cd->s1f, cd->t0f); glVertex2f(x + cd->x1f, y + cd->y0f);
        glTexCoord2f(cd->s1f, cd->t1f); glVertex2f(x + cd->x1f, y + cd->y1f);
        glTexCoord2f(cd->s0f, cd->t1f); glVertex2f(x + cd->x0f, y + cd->y1f);
        // if bilerping, in D3D9 you'll need a half-pixel offset here for 1:1 to behave correct
        x += cd->advance;
    }
    glEnd();
}
*/

#ifndef STB_FONTCHAR__TYPEDEF
#define STB_FONTCHAR__TYPEDEF
typedef struct
{
    // coordinates if using integer positioning
    float s0,t0,s1,t1;
    signed short x0,y0,x1,y1;
    int   advance_int;
    // coordinates if using floating positioning
    float s0f,t0f,s1f,t1f;
    float x0f,y0f,x1f,y1f;
    float advance;
} stb_fontchar;
#endif

#define STB_FONT_times_7_latin_ext_BITMAP_WIDTH         256
#define STB_FONT_times_7_latin_ext_BITMAP_HEIGHT         50
#define STB_FONT_times_7_latin_ext_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_7_latin_ext_FIRST_CHAR            32
#define STB_FONT_times_7_latin_ext_NUM_CHARS            560

#define STB_FONT_times_7_latin_ext_LINE_SPACING           5

static unsigned int stb__times_7_latin_ext_pixels[]={
    0x10281331,0x81828101,0x06200100,0x440c0402,0x30110302,0x22088110,
    0x81100100,0x08100009,0x00098804,0x85106041,0x260a0440,0x04422081,
    0x40209881,0x80440441,0x8a988100,0x4d44c0c0,0x06060600,0x05c11151,
    0x20c11151,0x826088a8,0x20c088a8,0x02608998,0x06445071,0x44506054,
    0x20542853,0x22860c18,0x22080ba9,0x220a830a,0x22982609,0x23311098,
    0x0c6a3310,0x0444c466,0x53089888,0x51089988,0x70aaa88e,0x2c4cc573,
    0x182a0ce6,0xa86620c4,0x350cc431,0x46a19886,0x863514a1,0x0c6a38a8,
    0x1c544733,0x4e229c4a,0x9228e662,0x43998a09,0x218e661c,0xa882ee62,
    0x298ce532,0x18b9ca67,0x4cd49066,0x85432232,0x431a8541,0x330c6a0a,
    0x172431a8,0x13310c6a,0x2a61a9a4,0x0aa84c1a,0x0a8e7122,0x0c2a39c3,
    0x4c30a8e7,0x490c2a0c,0x9a86150b,0x24a0b922,0x35099213,0x86249145,
    0x26a1c29a,0x12a60862,0x90902415,0x20cc3510,0x250e4e44,0x21306352,
    0x1504c30a,0x18d41986,0x31a85c32,0x13719ba8,0x4c3b8c15,0x05cc3530,
    0x9c31a8e7,0x8e70c6a3,0x2a58831a,0x50b85c31,0x2e1ba863,0x92494170,
    0x8a1ba924,0x75144898,0x30dd4383,0x4c735514,0x2123090c,0x243a8704,
    0x21906e72,0xa84c19b8,0x2350d431,0x8cc66ea1,0x198a6e21,0x45cc2a03,
    0x86248542,0xa8aaa2ab,0xa866e24a,0xa866e24a,0xa866e24a,0x8866e229,
    0x866e229a,0x0a6a228a,0x98922625,0x828a2a48,0x88a2a282,0x14314540,
    0x13510214,0xa884d446,0x21983109,0x10cccc2a,0x10c0a831,0x710cc337,
    0x2e218833,0x2e21c819,0x10000019,0x001b1c01,0x00000000,0x00620000,
    0x1880004c,0x310020c4,0x00418808,0x20004000,0x00800001,0x40000088,
    0x00008000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x84000000,0x80440620,0x88311108,0x26620c09,
    0x26022020,0x02a00220,0x0220a011,0x20011051,0x44060440,0x00880300,
    0x40203028,0x88606008,0x20089820,0x40008008,0x11044040,0x82204088,
    0x09988841,0x433a0886,0x40c409aa,0x030cd4c3,0x25394c37,0x10660cc2,
    0xb8813105,0x440c0620,0x38710544,0x88888330,0x26262110,0x26262110,
    0x4c111110,0x04544c0b,0x33982223,0x40e2e618,0x188a2199,0x86415054,
    0xa884c0a8,0x4188630a,0x4e2a66a1,0x8a98c31a,0x064c33a0,0x5570e2a2,
    0x94317054,0xb8326122,0x15114a18,0x4a629c47,0x54471513,0x1305cc38,
    0x18b8e2a2,0x31a8e2a2,0x22863538,0x218d431a,0x19cc38a8,0x554c19cc,
    0x09198a61,0x26298232,0x239ca662,0x25331ce3,0x5c1919a9,0x261508b8,
    0x0c2a7134,0x13027133,0x05c912e6,0x2a20a8e7,0x10483261,0x1930d44b,
    0x09921724,0x2485c909,0x098aaa0b,0x243b85c9,0x4e0c2a17,0x2151c30a,
    0x5c90c2a1,0x5306aa60,0x4c771835,0x54c1c663,0x2398e62a,0x2351ce93,
    0x82a49c73,0x130e54c3,0x1a9cd5d4,0x04dcccc3,0x86cd5422,0x145c170b,
    0x25883857,0x853509a8,0x5c2e5883,0x17092490,0x70b85c2e,0x2171a86c,
    0x85c7370b,0x2506350b,0x2351c31a,0x2170c6a1,0x461dc60b,0x2a48543b,
    0x5035550a,0xa8554119,0x2aa5350a,0x52554224,0x83505453,0x5542628b,
    0x066e2512,0x0a0440c3,0x88385351,0x05350620,0x2a0c4285,0x88a6a229,
    0x426a2489,0x26a229a8,0x44221502,0x2a21429a,0x8866e229,0x84433710,
    0x26e219b8,0x150a6a21,0x14121512,0x26ae7000,0x00000000,0x0d40015c,
    0x011000c1,0x01300040,0x20400018,0x00000001,0x10008000,0x00000000,
    0x40000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10220600,
    0x88288181,0x20984400,0x4c0c0220,0x00442219,0x02611301,0x85108811,
    0x00882882,0x44010044,0x4400441a,0x08088080,0x40088008,0x0cc08300,
    0x30010022,0x11040c18,0x26062022,0x88502621,0x15510989,0x494c2662,
    0x84c54466,0x53330998,0x832b94c1,0x731c5c3b,0x235144cc,0x226208c1,
    0x4710a209,0x714c2e2a,0x1310cc41,0x20554470,0x20c0d440,0x445109a8,
    0xbb8860aa,0x2b831260,0x418e06a2,0x07062381,0x462294c3,0x271d5429,
    0x8a731ce3,0x17130b89,0x26532466,0x485c4c53,0xaa94c571,0x23514c08,
    0x4ccc5329,0x0706150c,0xa8911253,0x4a66530a,0x4738e718,0x46620ba9,
    0x555508a9,0x73305d4c,0x1988454c,0x46621153,0x473308a9,0xa9891308,
    0x30c66649,0x99922633,0x0ccca6e1,0x50661069,0x1ce39c53,0x987302ae,
    0x43324663,0x291cc0ab,0x530660a8,0x26350cc7,0x21724331,0x229b831a,
    0x05cc49b9,0x49c66353,0x31ce39c2,0x984dc177,0x986aa22b,0x98e6e0bb,
    0x5cc26e2b,0x15cc26e2,0x21ce18e7,0x420e3719,0x4e0e39c3,0x44155073,
    0x54098331,0x0e12aa4a,0x55751212,0x1120e0cc,0x86615955,0x2a0cc571,
    0x9a886629,0x27066622,0x2aa24663,0xa8ccaae2,0x92aa1129,0x512a64aa,
    0x9b826617,0x3712a61c,0x17504cc5,0x30ba8266,0x43255c13,0x0b8cc4aa,
    0x0ba8c175,0x505d4955,0x8902ea33,0x00337529,0x35912200,0x500a6b25,
    0x26b22447,0xa803a802,0x0003a803,0x9655245c,0x01d40363,0x07355000,
    0x2a00cdd4,0x4dd4039a,0x20337501,0x400019ba,0x000029ba,0x00200000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x11000000,0x88088022,0x08088080,0x02060010,0x04088602,
    0x08106040,0x10208808,0x18026208,0x13020204,0x8106000c,0x0c0884c0,
    0x41066044,0x11102020,0x204c0821,0x30440981,0x1a988208,0x20a21443,
    0x25054c1a,0x442a2622,0x3066238a,0x39818181,0x8cc41b83,0x418260a8,
    0x44266a21,0x9454a50b,0x4c4ea652,0x20c18260,0x4c31ca62,0x06215109,
    0x54e2a183,0x22111112,0x215310aa,0x9861328a,0x4a66a589,0x31243531,
    0x5114e213,0x84c26621,0x50c2a661,0x0e624415,0x44193122,0x70b92112,
    0x239c738e,0x41aa9873,0x25330aac,0x26533299,0x2a253329,0x5293308a,
    0x2064c663,0x46623312,0x2e331198,0x21550919,0x2a1550aa,0x2aa1550a,
    0x4ca65370,0x98454c53,0x44ce708a,0x321a9a41,0x490541c9,0x84c908a9,
    0x211530c9,0x8d54c189,0x0b986a61,0x2205cc14,0x21708e25,0x4738e70b,
    0xb8c39c73,0x938722a3,0xa4e93a4e,0x422aa293,0x208e6293,0x09b86399,
    0x5c26e137,0x4c24e709,0x2a63531a,0x46a63531,0x0cce71a9,0x315cc157,
    0x22239c57,0x41513719,0x91c41b9c,0x424915cc,0x98885732,0x43371331,
    0xa8aaa2ab,0x3515542b,0x510ccc45,0x55255453,0x95525549,0x5d5c90a8,
    0x26a5351c,0x4a6a5352,0x4515129a,0x2285129a,0x0ba8a18a,0x542ea175,
    0x2a23330b,0x2ae55709,0x4aae5572,0x2e5572ab,0x4c383329,0x99826609,
    0x8b995462,0x130cccc2,0x20998aa1,0x42664898,0x30a8c099,0x01b1c003,
    0x00001b1c,0x00000000,0x00000000,0x00000000,0x00000000,0xa8911d40,
    0x0337519b,0x50000000,0xba800337,0x00ea0819,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x20800000,
    0x808018c0,0x08808828,0x98830088,0x00220440,0x11998a6e,0x2199814c,
    0x42040808,0x46133108,0x10600022,0x854c0988,0x4442221b,0x7386a200,
    0x15504608,0x84c22008,0x26019881,0x45c2a600,0x32880401,0x10a188cc,
    0x05101103,0x20402033,0x30a649a9,0x1c738705,0x8c81cc22,0xa8302ea0,
    0x9a98cc10,0x30547152,0x2190cc73,0x926a60a8,0x19a870aa,0x38d43153,
    0x150c39c7,0x8660d4c3,0x64366ee1,0x4c704dc1,0x22173308,0xb9c35119,
    0x30662051,0x24408a65,0x44244244,0x44884884,0x8731b8ba,0xc8a6e199,
    0x8542ea48,0x1554c0aa,0x8a6e1933,0x442a1519,0x219550ab,0x1b8e6e19,
    0x7514dc32,0x5c6a6371,0xa8198260,0x24aa8e70,0x5c1912a9,0x2a98542a,
    0x14dc9373,0x14aa6175,0x1c13724e,0x815711ce,0x26331988,0x40b98151,
    0x205cc0b9,0x205cc0b9,0x85c660b9,0x1ce0cc1a,0x0a098a0a,0xca98232a,
    0x130b8e70,0x20a0a826,0x438a6e09,0x7198e71a,0x30c4aae1,0xa84c0cc1,
    0xb51c284a,0x704c2885,0x21ce48cc,0x4d428e0a,0x20c42ea3,0x2145c4aa,
    0x8cc66551,0x2a155453,0x2a15542a,0x2a15542a,0xa8a6ea2a,0x2337519b,
    0x5040448c,0x09ab9c03,0x2a48c875,0x2b86a351,0x17006a02,0x9ba92320,
    0x54350202,0x0006a19b,0xa8024337,0x2caa3371,0x8cdc0919,0x000c001b,
    0x27500539,0x4363823a,0x21b1c363,0x21b1c363,0x00000363,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x2e000000,0x10d44109,0x0aae1ccc,0x41884c22,0x0c104060,0x44221ccc,
    0x13310031,0x10c44422,0x10220881,0x41310262,0x22133109,0x88662110,
    0x104cc409,0x98845c5c,0x55543331,0x501062e2,0x239c2aa5,0x22982199,
    0x5330ab99,0x0c620444,0x22044c08,0x1939c6a0,0x1ce08a66,0x253199ce,
    0x85432aa4,0x2a0e0903,0xa4426229,0x22a62442,0x826aa530,0xa8b1cc29,
    0x54c93532,0x30b89829,0x3089a8a7,0x8cd4c175,0x439533a9,0xa886309b,
    0x9882a21a,0x8d4c2a09,0x46e61c73,0x384e4e39,0x2629b809,0x22135109,
    0x0a81333a,0x2938e719,0x170eaa1b,0x24dcc2a5,0x5c261953,0x2e151c18,
    0x3986ea29,0x305cc24c,0x0c98cc57,0x262e60cc,0xb8cca624,0x82655731,
    0x73055c39,0x2a05dcc5,0xa8a2e280,0x4dc5150b,0x4c041c1c,0x92aa5570,
    0x2a3730ba,0x217b350a,0x14c4029a,0x8c4c1833,0x5104c198,0x0394d46a,
    0x1984c387,0x5c2614c9,0x39c26383,0x4c188a2a,0x3315540c,0x44b98cc1,
    0x24dc4c19,0x85c66977,0x24114899,0x5304cc38,0x00181509,0x00000988,
    0x000000d4,0x00444400,0x20800201,0x05c0061a,0x2a35060c,0x46a154b2,
    0x2352439b,0x5306248b,0x2386c4d4,0x2a33750d,0x2a1b3553,0x3671519b,
    0x14dd4a20,0x35907575,0x50aa2445,0x2e2b8735,0x0000002b,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x26040840,0x22357370,0x8a6e5530,
    0x02037040,0x08355081,0x2150a822,0x2618419b,0x99801199,0x0ccc0109,
    0x000ccc55,0x00000000,0x00000000,0x00000000,0xa8000000,0x4e026a21,
    0x4e38a253,0x384cca23,0xa8a21328,0x55ca6162,0x1dc22130,0x98210022,
    0x21333099,0x00003308,0x00000000,0x00000000,0x00000000,0x00000000,
    0x13060cc4,0x8d4e322e,0x4491919b,0x4105c311,0xa84c6309,0x2088cc38,
    0x0039c81a,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x02662000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_7_latin_ext_x[560]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,
0,0,0,0,0,0,0,-1,0,-1,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0, };
static signed short stb__times_7_latin_ext_y[560]={ 5,0,0,0,0,0,0,0,0,0,0,1,4,3,
4,0,0,0,0,0,0,0,0,0,0,0,2,2,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,2,0,2,0,2,0,2,0,0,
0,0,0,2,2,2,2,2,2,2,1,2,2,2,2,2,2,0,0,0,2,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,0,0,1,0,
0,0,0,0,0,2,2,3,0,0,0,1,0,0,0,2,0,2,4,0,0,2,0,0,0,1,-1,-1,-1,-1,
-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,1,0,-1,-1,-1,-1,-1,0,0,0,0,
0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,
-1,1,-1,0,0,2,-1,0,-1,0,-1,0,-1,0,-1,0,0,0,-1,1,-1,0,-1,0,0,2,-1,0,-1,0,
-1,0,-1,0,0,0,-1,-1,0,0,-1,0,-1,1,-1,0,0,0,-1,2,0,0,-1,0,0,0,2,-1,-1,0,
0,0,0,0,0,0,0,-1,0,0,2,-1,0,0,0,2,-1,1,-1,0,-1,0,0,2,-1,0,0,2,-1,0,
-1,0,-1,0,0,2,-1,0,0,1,-1,0,0,1,-1,0,-1,1,-1,0,-1,0,-1,0,0,2,-1,0,-1,0,
-1,-1,0,-1,0,-1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,
1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,0,-1,0,-1,
0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,-2,-1,-1,0,-1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1, };
static unsigned short stb__times_7_latin_ext_w[560]={ 0,2,3,4,3,6,5,1,2,2,3,4,2,2,
2,2,3,3,3,3,3,3,3,3,3,3,2,2,4,4,4,3,6,5,4,4,5,4,4,5,5,2,3,5,
4,6,6,5,4,5,5,4,4,5,5,6,5,5,4,2,2,2,3,5,2,3,4,3,4,3,3,4,4,2,
3,4,2,5,4,3,4,4,3,3,2,4,4,5,4,4,3,3,1,3,4,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,2,3,4,4,4,
1,3,2,5,3,3,4,2,5,5,3,4,2,2,2,4,4,2,2,2,2,3,5,5,5,3,5,5,5,5,
5,5,7,4,4,4,4,4,2,2,2,2,5,6,5,5,5,5,5,4,5,5,5,5,5,5,4,3,3,3,
3,3,3,3,5,3,3,3,3,3,2,2,2,2,3,4,3,3,3,3,3,4,4,4,4,4,4,4,4,4,
5,3,5,3,5,4,4,3,4,3,4,3,4,3,5,5,5,4,4,3,4,3,4,3,4,3,4,3,5,4,
5,4,5,4,5,4,5,4,5,4,3,3,3,3,2,3,3,3,2,2,5,3,3,3,5,4,4,4,2,4,
2,4,3,4,3,4,2,6,4,6,4,6,4,4,5,3,5,3,5,3,5,3,6,5,5,3,5,3,5,3,
4,3,4,3,4,3,4,3,4,2,4,3,4,2,5,4,5,4,5,4,5,4,5,4,5,4,6,5,5,4,
5,4,3,4,3,4,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,6,4,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,2,2,5,
3,5,4,5,4,5,4,5,4,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,3,7,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5, };
static unsigned short stb__times_7_latin_ext_h[560]={ 0,6,3,6,6,6,6,3,7,7,4,4,3,1,
2,6,6,5,5,6,5,6,6,6,6,6,4,5,4,2,4,6,7,5,5,6,5,5,5,6,5,5,6,5,
5,5,6,6,5,7,5,6,5,6,6,6,5,5,5,7,6,7,3,1,2,4,6,4,6,4,5,5,5,5,
7,5,5,3,3,4,5,5,3,4,5,4,4,4,3,5,3,7,7,7,2,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,6,7,6,4,5,
7,7,2,6,3,4,2,1,6,1,3,4,3,3,2,5,7,2,3,3,3,4,6,6,6,6,6,6,6,6,
6,6,5,7,6,6,6,6,6,6,6,6,5,7,7,7,7,7,7,4,6,7,7,7,7,6,5,6,6,6,
6,6,6,6,4,5,6,6,6,6,5,5,5,5,6,5,6,6,6,6,6,4,5,6,6,6,6,7,7,7,
6,5,6,6,7,5,7,6,7,6,7,6,7,6,6,6,5,6,6,5,6,6,6,6,7,5,6,6,7,7,
7,7,7,7,7,7,6,6,5,5,6,5,6,4,6,5,7,7,6,3,6,7,7,7,7,7,3,6,6,7,
7,5,5,5,5,5,5,7,5,7,5,7,5,5,6,5,7,5,7,6,7,6,6,4,6,5,7,5,6,5,
7,6,7,6,7,5,7,6,7,6,6,6,5,5,7,6,7,5,7,6,7,6,7,6,7,5,7,6,6,7,
6,6,5,6,5,6,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,4,4,7,4,4,4,
4,4,4,4,4,4,4,4,4,4,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,6,5,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,6,6,5,7,
6,7,6,7,6,7,7,7,7,7,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,7,7,6,6,7,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4, };
static unsigned short stb__times_7_latin_ext_s[560]={ 254,129,65,6,252,67,72,254,145,136,207,
240,72,116,83,202,196,51,155,219,110,238,140,120,116,108,11,125,249,99,235,
112,11,78,120,144,114,84,139,232,32,89,223,92,98,103,65,39,38,242,144,
28,150,1,246,212,72,133,128,120,221,100,49,110,104,194,237,203,228,165,68,
63,58,55,19,46,43,14,27,221,24,19,39,211,8,198,180,159,56,239,23,
129,148,150,94,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,
225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,254,252,160,
17,169,189,169,201,107,33,61,231,86,116,98,119,35,6,20,32,80,122,18,
91,43,46,53,245,200,247,1,13,41,47,23,29,35,17,90,55,242,227,191,
186,10,7,253,177,148,12,98,77,92,113,124,1,206,130,154,148,139,180,98,
173,169,165,161,157,153,149,174,79,136,132,128,124,83,111,114,29,104,143,94,
90,86,82,78,185,131,60,55,50,45,45,35,65,22,154,11,7,104,194,171,
242,176,233,164,224,87,217,211,205,53,197,192,235,183,179,174,188,1,218,152,
148,81,89,103,133,109,115,123,143,106,101,207,213,84,199,74,190,64,171,186,
221,43,69,37,1,190,211,23,119,75,1,249,231,110,166,162,64,127,59,108,
173,103,180,74,166,69,249,191,4,160,11,75,213,29,230,57,215,142,15,154,
158,163,136,66,187,70,209,60,86,50,205,40,222,234,239,117,140,5,225,248,
175,236,217,225,16,215,11,205,180,194,243,21,181,46,52,185,32,203,27,222,
226,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,88,225,225,138,
225,225,225,225,225,225,225,225,225,225,225,225,225,78,230,225,225,225,225,225,
225,225,225,225,225,225,225,225,94,244,225,225,225,225,225,225,225,225,225,225,
225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,112,118,
122,1,94,125,83,132,71,137,60,55,49,44,38,33,225,225,225,225,225,225,
225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,
225,225,225,27,23,197,157,6,169,225,225,225,225,225,225,225,225,225,225,225,
225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,
225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,
225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,
225,225,225,225,225,225,225,225,225, };
static unsigned short stb__times_7_latin_ext_t[560]={ 5,17,44,17,9,17,24,1,9,9,38,
38,44,44,44,17,24,38,38,24,38,24,24,24,24,24,44,38,38,44,38,
24,9,38,38,24,38,38,38,24,38,38,24,38,38,38,24,24,38,1,38,
24,38,24,17,24,38,38,38,1,17,1,44,44,44,38,17,38,17,38,38,
38,38,38,1,38,38,44,44,38,38,38,44,38,38,38,38,38,44,31,44,
1,1,1,44,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,
38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,5,17,1,
24,38,31,1,1,44,24,44,38,44,44,24,44,44,44,44,44,44,31,9,
44,44,44,44,38,24,24,31,31,31,31,31,31,31,31,31,9,24,24,24,
24,31,31,24,24,31,1,9,1,9,9,9,44,24,9,9,9,9,24,31,
24,24,24,24,24,24,24,38,31,24,24,24,24,31,31,31,38,24,31,24,
24,24,24,24,38,31,24,24,24,24,9,9,9,24,31,24,24,9,31,1,
17,1,17,1,17,9,17,17,17,31,17,17,31,17,17,17,17,1,31,17,
17,9,1,1,1,1,1,1,1,17,17,31,31,17,31,17,38,17,31,1,
1,17,44,17,9,1,1,9,9,44,17,9,1,9,31,31,31,31,31,31,
9,31,9,31,9,31,31,9,38,9,38,9,9,9,9,17,38,17,38,1,
31,17,31,1,9,9,9,9,31,9,9,9,9,9,9,31,31,9,9,1,
31,1,9,1,17,1,17,1,31,1,9,17,1,17,17,31,17,31,17,31,
31,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,17,38,38,1,
38,38,38,38,38,38,38,38,38,38,38,38,38,17,31,38,38,38,38,38,
38,38,38,38,38,38,38,38,17,31,38,38,38,38,38,38,38,38,38,38,
38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,17,17,
17,38,1,17,1,17,1,17,1,1,1,1,1,1,38,38,38,38,38,38,
38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,
38,38,38,1,1,9,17,1,17,38,38,38,38,38,38,38,38,38,38,38,
38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,
38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,
38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,
38,38,38,38,38,38,38,38,38, };
static unsigned short stb__times_7_latin_ext_a[560]={ 25,34,41,51,51,84,79,18,
34,34,51,57,25,34,25,28,51,51,51,51,51,51,51,51,
51,51,28,28,57,57,57,45,93,73,67,67,73,62,56,73,
73,34,39,73,62,90,73,73,56,73,67,56,62,73,73,95,
73,73,62,34,28,34,47,51,34,45,51,45,51,45,34,51,
51,28,28,51,28,79,51,51,51,51,34,39,28,51,51,73,
51,51,45,49,20,49,55,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,25,34,51,51,51,51,20,51,
34,77,28,51,57,34,77,51,40,56,30,30,34,58,46,25,
34,30,31,51,76,76,76,45,73,73,73,73,73,73,90,67,
62,62,62,62,34,34,34,34,73,73,73,73,73,73,73,57,
73,73,73,73,73,73,56,51,45,45,45,45,45,45,67,45,
45,45,45,45,28,28,28,28,51,51,51,51,51,51,51,56,
51,51,51,51,51,51,51,51,73,45,73,45,73,45,67,45,
67,45,67,45,67,45,73,65,73,51,62,45,62,45,62,45,
62,45,62,45,73,51,73,51,73,51,73,51,73,51,73,51,
34,28,34,28,34,28,34,28,34,28,72,56,39,28,73,51,
51,62,28,62,28,62,41,62,35,62,28,73,51,73,51,73,
51,61,71,50,73,51,73,51,73,51,90,73,67,34,67,34,
67,34,56,39,56,39,56,39,56,39,62,28,62,43,62,28,
73,51,73,51,73,51,73,51,73,51,73,51,95,73,73,51,
73,62,45,62,45,62,45,28,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,73,79,79,51,79,79,79,79,79,
79,79,79,79,79,79,79,79,73,53,79,79,79,79,79,79,
79,79,79,79,79,79,79,78,55,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,73,45,34,28,73,51,73,51,73,51,73,
51,73,51,73,51,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,73,45,90,67,73,51,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_7_latin_ext_BITMAP_HEIGHT or STB_FONT_times_7_latin_ext_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_7_latin_ext(stb_fontchar font[STB_FONT_times_7_latin_ext_NUM_CHARS],
                unsigned char data[STB_FONT_times_7_latin_ext_BITMAP_HEIGHT][STB_FONT_times_7_latin_ext_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_7_latin_ext_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_7_latin_ext_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_7_latin_ext_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_7_latin_ext_BITMAP_WIDTH-1; ++i) {
                unsigned int value;
                if (numbits==0) bitpack = *bits++, numbits=32;
                value = bitpack & 1;
                bitpack >>= 1, --numbits;
                if (value) {
                    if (numbits < 3) bitpack = *bits++, numbits = 32;
                    data[j][i] = (bitpack & 7) * 0x20 + 0x1f;
                    bitpack >>= 3, numbits -= 3;
                } else {
                    data[j][i] = 0;
                }
            }
        }
    }

    // build font description
    if (font != 0) {
        float recip_width = 1.0f / STB_FONT_times_7_latin_ext_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_7_latin_ext_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_7_latin_ext_s[i]) * recip_width;
            font[i].t0 = (stb__times_7_latin_ext_t[i]) * recip_height;
            font[i].s1 = (stb__times_7_latin_ext_s[i] + stb__times_7_latin_ext_w[i]) * recip_width;
            font[i].t1 = (stb__times_7_latin_ext_t[i] + stb__times_7_latin_ext_h[i]) * recip_height;
            font[i].x0 = stb__times_7_latin_ext_x[i];
            font[i].y0 = stb__times_7_latin_ext_y[i];
            font[i].x1 = stb__times_7_latin_ext_x[i] + stb__times_7_latin_ext_w[i];
            font[i].y1 = stb__times_7_latin_ext_y[i] + stb__times_7_latin_ext_h[i];
            font[i].advance_int = (stb__times_7_latin_ext_a[i]+8)>>4;
            font[i].s0f = (stb__times_7_latin_ext_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_7_latin_ext_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_7_latin_ext_s[i] + stb__times_7_latin_ext_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_7_latin_ext_t[i] + stb__times_7_latin_ext_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_7_latin_ext_x[i] - 0.5f;
            font[i].y0f = stb__times_7_latin_ext_y[i] - 0.5f;
            font[i].x1f = stb__times_7_latin_ext_x[i] + stb__times_7_latin_ext_w[i] + 0.5f;
            font[i].y1f = stb__times_7_latin_ext_y[i] + stb__times_7_latin_ext_h[i] + 0.5f;
            font[i].advance = stb__times_7_latin_ext_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_7_latin_ext
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_7_latin_ext_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_7_latin_ext_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_7_latin_ext_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_7_latin_ext_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_7_latin_ext_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_7_latin_ext_LINE_SPACING
#endif

