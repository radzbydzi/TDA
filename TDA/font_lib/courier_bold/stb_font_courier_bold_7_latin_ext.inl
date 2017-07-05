// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_7_latin_ext_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_7_latin_ext'.
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

#define STB_FONT_courier_bold_7_latin_ext_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT         46
#define STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT_POW2    64

#define STB_FONT_courier_bold_7_latin_ext_FIRST_CHAR            32
#define STB_FONT_courier_bold_7_latin_ext_NUM_CHARS            560

#define STB_FONT_courier_bold_7_latin_ext_LINE_SPACING           3

static unsigned int stb__courier_bold_7_latin_ext_pixels[]={
    0x80400000,0x00000000,0x00002200,0x00000000,0x00000000,0x00200000,
    0x03710000,0x00350660,0x00000857,0x215c1a80,0x0ae0cc19,0x88505015,
    0x55104c19,0x70a222b8,0x215c2985,0x0ea15c2b,0x15c09813,0x188150ae,
    0x2b8ae0cc,0x570ea0d4,0x280a1b88,0x05712e6e,0x15c19833,0x44570331,
    0x55066219,0x70661e44,0x20cc2b85,0x5caeae2b,0x259912ba,0x19910cc8,
    0x3105c054,0x9b95d5c3,0x2257572b,0x257571cc,0x57571cb8,0x65c4b726,
    0x3225b931,0x3c88f223,0x1e44aeae,0x33225757,0x32257571,0x5d5c7914,
    0x26e57572,0x64cb2a2b,0x9cf3261c,0x950f2619,0x5cb72239,0x419171b9,
    0x19173b9c,0x645c322e,0x22e33170,0x45c9910c,0x2e19930c,0x9c6670c8,
    0x2a5b1719,0x2135509a,0x70e4c3c9,0x98cce191,0x148cce4a,0x3138cce3,
    0x21948cce,0xb8652313,0x23317198,0x4667198b,0x4667198b,0x20cce314,
    0x4ce33174,0x254c6671,0xd8832924,0x4c35172b,0xca6edc6c,0x549912ca,
    0x4aab20a8,0x15150a8a,0x28a42a2a,0x94d21515,0x49330a8a,0x35170a8a,
    0x4e646a2e,0x2a219512,0x990d930c,0xa8b85454,0x1a8b8f61,0x32351709,
    0x235172c8,0x59190eca,0x28a43b2a,0x728a4a29,0xb9452351,0x517091a8,
    0x5ca29483,0x435171a8,0xd9524a3d,0x9932ed41,0x3761ecb8,0x5c1bd92d,
    0xdc87b261,0x263d931e,0x23d931ec,0x3d930cc9,0x764c372a,0x764c2321,
    0x264c9931,0x332e19b9,0x32e19970,0xc99b6a1e,0x6cc9931e,0xcc993260,
    0x66549931,0x24a89932,0x992a2cca,0x219930cc,0x49930cc9,0x49930cc9,
    0x49931cc9,0x219934a8,0x993264c9,0x95132e0d,0x0005dcd8,0x01362060,
    0x000076ae,0x36e00000,0x0180001d,0x4b9e8000,0x0000cc00,0x80098000,
    0x00000009,0x00620000,0x9800cc00,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x200ae15c,0x4280402b,0x15c01ccb,0x00cc8826,
    0x10660000,0x01e5c570,0x00002880,0x001a8000,0x400cc000,0x00002b8c,
    0x82000002,0x0032a0d8,0xbab83700,0x64457572,0x0cc39910,0x70ce9853,
    0x9115c535,0x5472e219,0x130ae09a,0x9104c188,0x8f220a87,0x30260b9a,
    0x3b8a64c3,0x570ae1d4,0x910542b8,0x104c0a87,0x2ae2b899,0x276e0a2b,
    0x88660ae1,0x32e0dc4c,0x26449930,0x30902a24,0x4c720a81,0x9c6670db,
    0x8a47b119,0x48489911,0xa93220a8,0x4462709a,0x5c9910ca,0x4c9910cc,
    0x4c662e3c,0x54662e3c,0xcb8f266d,0x44935483,0xc88f264c,0x4c893224,
    0x2644662e,0x8e54c991,0xb8cce4c8,0x476ae0c8,0x95c644c9,0x892e64b9,
    0x7152cc1c,0x902a1c41,0x19506c46,0x2e1f98e4,0x435171a8,0x14d2120b,
    0xb12cc835,0x95126449,0x65cb2321,0x5549910c,0x64c9910a,0x6c994526,
    0x3abc9452,0x05cd4d93,0x26925552,0x29a4d932,0x37323b99,0x6e64a291,
    0x0db8a691,0x8d45ca69,0x32b60a8a,0x33b702a1,0x15cc3726,0x86441793,
    0x98320b8a,0x479d50cd,0x5c2a240a,0x4c9931ea,0x99305c4c,0x890372a3,
    0x99704c18,0x654332e1,0xccb86a2c,0x32e15950,0x263d970c,0x23d970cc,
    0xb8660cc9,0x44db51ec,0x6543334a,0x2a3d970d,0x219950dc,0x19930cca,
    0x6e54332a,0x6e547910,0x764c9930,0x702a0cc1,0x717263b5,0xb730cc83,
    0x84893621,0x02a0cc0a,0x01504c69,0x80007500,0x0002020a,0x37720000,
    0x40000002,0x13abc800,0x00001a83,0x00000000,0x6cc08000,0x000e56c4,
    0x10130000,0x50cd9810,0x0002079d,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x5dc00000,0x5330001b,
    0x0b001100,0x00000331,0x32200000,0xb880001c,0x0000261c,0x00130008,
    0xb81a8000,0x0d41a802,0x59033164,0x41306e23,0x2a00264a,0x5002b801,
    0x09815077,0x815165e4,0x32e15c4c,0x4457370c,0x0cc15c2a,0xb837102a,
    0x0c520b82,0x04c2b857,0x16e4c627,0x2e0dc457,0x882a26c2,0x570ae1cc,
    0x9115c288,0x222b8c89,0xccb93221,0x26e3b910,0x5c3b911b,0x54332e2c,
    0x15c39910,0x262b8993,0x6542b84c,0x9170e4c4,0xcb9c5441,0x221dd30c,
    0x99445c4c,0x930e4c4a,0x3261c989,0x7930e4c4,0x32121c98,0xc98dd540,
    0xca4b2324,0x22e39910,0x2639910c,0xa46e6e1c,0x65c99118,0x2e39910c,
    0xb8a690cc,0x6479719d,0x215551dc,0x49322374,0x551b9c37,0x445c2a15,
    0x20a81910,0x902a0dc9,0x15de4553,0x20a8a932,0x155539dc,0x1dcc9766,
    0x83d8336e,0x2640544c,0xc993202a,0x33264c86,0x5cd49b51,0x2cca82a0,
    0x222e1d95,0x22e15150,0x22193108,0x3732124c,0x22e15551,0x2a155508,
    0x476ae0dc,0x19950a9a,0x76542b2a,0x3eca86e3,0x0aca94ce,0xa8732615,
    0x85710540,0x20eedc0a,0x9336d409,0x952b883d,0xca932215,0x1b30720c,
    0x20546da8,0x2a0546da,0xa87b2e6d,0x7350d46d,0x0a8372a1,0xc992a0cc,
    0x263d931c,0xb89b51cc,0x65473261,0x2615950c,0x015951cc,0x9591cad8,
    0x016ee403,0x99b009b1,0x1d4b7721,0x36619b30,0x6cc37a64,0x404364c4,
    0x18804b9e,0x0198b772,0x740cc198,0xe89b34b9,0xe89b34b9,0x5cf404b9,
    0x64b2b204,0x089b32db,0x20000098,0x00136209,0xdc80b772,0x0000002d,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x01541980,0xc8826154,0x70313222,0x200de445,0x89664452,
    0x5113660a,0x204c5705,0x226441c9,0x21a81a83,0x19972a8b,0x41988f2a,
    0x000f2e09,0xa83312ee,0x2b873262,0x642b8362,0x4c000004,0xb9b932a1,
    0x1cc886a1,0x479300ae,0x171543c9,0x54332619,0xe993224b,0x45c33264,
    0x26599139,0x4b62e0ce,0x70b662b8,0x98e4c555,0x0a84c84c,0x43c98322,
    0xa94d21c9,0x237150aa,0x49910c8b,0x88aa0a9a,0x253372dc,0xb13224c8,
    0xb8543cb8,0x98b911cc,0x50506e21,0x2aa64c88,0x645c6671,0x32e11170,
    0x6c98620c,0x1cc99b26,0x92661515,0x19970c9a,0x24998ba6,0x914d2714,
    0x2e253990,0x15505c43,0x502a4c85,0x0a8150db,0xc9321b26,0x21595298,
    0x15152cbd,0x65647732,0x65647971,0x29a4a672,0x51f54a69,0xab854173,
    0x26371929,0x441911cc,0xcc83220c,0x2e35771d,0x215151a8,0x15551cc9,
    0x765c3726,0x22c3d971,0x42321ec9,0x906e0ddc,0xc9846439,0x641b950c,
    0xa833722c,0x77513263,0x81536d41,0x93624b9e,0x3d970cd9,0x1b7b36d4,
    0x664cb772,0x32a3d930,0xa9a8660c,0x2721bd90,0x2a1b951c,0xda82a0dc,
    0x54150546,0x20542c4c,0x9950540a,0x4c986c41,0x21a87b26,0x05710aca,
    0xb807d500,0xb80001dd,0x300001dd,0x27a00000,0x0e04d9cb,0xe801a835,
    0x019804b9,0xcac81000,0x10000031,0x1b13abc8,0x7d501362,0xcd9866cc,
    0x88019b30,0x64000cc0,0x01bd32dd,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x02b80000,0x06644570,0x70765c33,0x21982a19,0x88e42bab,
    0xc896543c,0x2221e643,0x9910d441,0xa88b7267,0x000004c2,0x1e4490a6,
    0x98e5c471,0x219170dc,0x04150a29,0x92b9b800,0x2098e644,0x20c8b805,
    0x237371ca,0x32a2b810,0x44222200,0x71264c0d,0x552b8c83,0x92132613,
    0x65c2a1ca,0x6446670c,0x4833171d,0x89b8662e,0x39307262,0x83291aa4,
    0x750229bb,0x39038388,0x419111c4,0x3bb8c4e5,0x98542a2a,0x054150ce,
    0x3264c1b3,0x31485c95,0x2a899706,0x11621515,0x9876d499,0x0aa0ec0b,
    0x44150750,0x88cedc0c,0x7102a0ca,0x2a08ddcc,0x235170aa,0x29452374,
    0x36e38a49,0x2642640c,0x3b2a3b93,0x244aaea0,0xb8c82eea,0x3a237170,
    0x42a8530c,0x3b8b2324,0x906c7b2a,0x43bd50a8,0x8f62420a,0x5c37092a,
    0x6cc72288,0x98f6121e,0x5b836a5b,0x3d101d43,0x5c0a8150,0x419971da,
    0x3630d40a,0x42b2a150,0x4fb2a4c9,0x49970cc9,0x20720cc9,0x436d46da,
    0x77512a2b,0xbb892e61,0x644eae62,0x221f913b,0xca9604c3,0x41a8e62c,
    0x054b320a,0x0e40a815,0xc985c1b3,0x66ec391c,0x74c66020,0xaa993a22,
    0x3aa39d50,0x2111103c,0x93660cd9,0x32b60cd9,0x30136601,0xddc85437,
    0xb1000002,0x4f40cc39,0x312e7a4b,0x088004c3,0x5c3b83b8,0x0e202404,
    0x4c042ee0,0x66542a02,0x37219b31,0x08090664,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x6c400000,0x2033950a,0x32a4c883,0x3b9e64c0,0x9930645c,
    0x83513227,0x99104c2a,0xc8b85d54,0x40dc1b13,0x190e1ccb,0x1ca85970,
    0x22cb8991,0x93021cc8,0x1b11e4c7,0x3951cca8,0x1a88e65c,0x5cdc3326,
    0x4e437371,0x44ee723b,0x54732e18,0x54087970,0x459950bc,0x26322b8c,
    0x2902a513,0x90ccb870,0x321643b9,0x547b52ba,0x4af620a8,0x883224c8,
    0xa437260c,0x2a3db729,0xb982a1a8,0x4536ee0d,0x17136a0c,0x6433a635,
    0x46a2e1dc,0x9822088b,0x351b266c,0xd8a6edc1,0x2e53571c,0xc892663c,
    0x55913224,0xc885c5c5,0x2a0a6ae0,0xb882e0b9,0x5c537138,0x0b6f219d,
    0x0dc6902a,0x06654672,0x52ce4319,0x87b26173,0x8332e5da,0x5710540a,
    0xdca86e54,0x0543d930,0x2cdc83f3,0x20b9a82a,0x951229bd,0x994dec19,
    0x237751cc,0x3d971ecb,0x4b7760d4,0xa9362bc8,0xb82320a9,0x3b721ec1,
    0x81513221,0x36d42a0a,0x336239b5,0xdab87b10,0x454af321,0x79d50cd9,
    0x1a8aba20,0xddb8f3aa,0xd8059575,0x336605dc,0x3a619b30,0x0b2ae00d,
    0xd570cd98,0x90cd9803,0x86664595,0xccc804e9,0x51000c00,0xd5003366,
    0x32b23d85,0x3623bb71,0xab8b6f24,0x9b31641d,0x5e413621,0x1da82a3a,
    0x395b076a,0x001a5cf4,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x65400000,0x65c6eee0,0xbaa93262,
    0x49307261,0x40130ccb,0xcc879709,0x2a39931c,0x259591ca,0x07971ccb,
    0x32655390,0x401b550d,0x10191089,0x42a25c41,0x402a0189,0x40c02a0a,
    0x88d41008,0x2799913a,0x0663ccc8,0x00000000,0x2a240000,0x150dce3b,
    0x13205cd4,0x88555499,0x351e443c,0xb1cd6419,0x525c49d0,0x82a6a377,
    0x88eedc2c,0x790b662b,0xb81512aa,0x771362cb,0x2a570de4,0x417a6350,
    0x261b5509,0x426130bb,0x00001543,0x00000000,0x23480000,0x514ce4ca,
    0xb506e541,0x5952e54d,0x1970ecc1,0x77d0e654,0xecc8faa9,0x20888b22,
    0x19531cac,0x1bd3364c,0x23b872ee,0x019b30aa,0x13062251,0x00350a66,
    0x00000055,0x00000000,0x00000000,0xc9e75400,0x2199b2bb,0x8b6f24d9,
    0x4d514b9e,0x20752ddc,0x059b91c8,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_7_latin_ext_x[560]={ 0,1,0,0,0,0,0,1,1,0,0,0,1,0,
1,0,0,0,0,0,0,0,0,0,0,0,1,1,-1,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
0,-1,-1,0,0,0,0,0,0,0,-1,-1,0,0,0,1,0,0,0,-1,1,0,-1,0,0,0,0,0,0,0,
0,0,0,-1,0,0,-1,0,0,0,0,0,0,-1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
1,0,0,-1,0,0,-1,0,-1,-1,0,0,0,0,1,0,0,1,1,1,0,0,0,-1,0,0,-1,-1,-1,-1,
-1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,
-1,0,-1,0,-1,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,-1,0,-1,0,-1,0,-1,0,0,0,0,0,0,0,0,-1,-1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,-1,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0, };
static signed short stb__courier_bold_7_latin_ext_y[560]={ 5,0,1,0,0,1,1,1,1,1,1,1,4,2,
4,0,0,0,0,0,1,1,0,1,0,0,2,2,1,2,1,1,0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,6,0,2,1,2,1,2,1,2,1,1,
1,1,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,1,1,2,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,2,0,1,1,1,
1,1,1,1,0,2,2,2,1,0,0,0,0,0,0,2,1,2,4,0,0,2,0,0,0,2,-1,-1,-1,0,
0,-1,1,1,-1,-1,-1,0,-1,-1,-1,0,1,0,-1,-1,-1,0,0,2,1,-1,-1,-1,0,-1,1,1,0,0,
0,1,1,0,2,2,0,0,0,1,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,1,0,1,1,
0,1,-1,0,1,2,-1,0,-1,0,0,1,0,0,0,1,1,1,0,1,-1,0,0,1,1,2,0,0,-1,0,
-1,0,0,1,1,0,-1,-1,1,1,0,1,0,1,-1,0,1,1,0,2,1,1,-1,0,1,1,2,-1,-1,1,
1,1,1,1,1,1,1,-1,0,1,2,0,0,1,1,2,0,1,-1,0,-1,0,1,2,-1,0,1,2,0,0,
-1,0,-1,0,1,2,0,0,1,1,0,1,1,1,0,1,0,1,-1,0,-1,0,-1,0,1,2,-1,0,-1,0,
0,-1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,2,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
0,0,0,-1,0,-1,0,-1,0,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,-2,-1,-1,0,-1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1, };
static unsigned short stb__courier_bold_7_latin_ext_w[560]={ 0,2,3,4,4,4,4,2,3,3,4,4,2,4,
2,4,4,4,4,4,4,4,4,4,4,4,2,2,5,4,4,4,4,5,4,4,4,4,4,4,4,4,4,4,
4,5,5,4,4,4,4,4,4,4,5,5,4,4,4,2,4,3,4,5,2,4,5,4,4,4,4,4,4,4,
3,4,4,5,4,4,5,4,4,4,4,4,4,5,4,4,4,2,2,2,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,2,4,4,4,4,
2,4,3,5,3,4,5,4,5,5,3,4,3,3,2,4,4,2,2,2,3,4,4,5,4,4,5,5,5,5,
5,5,5,4,4,4,4,4,4,4,4,4,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,
5,4,5,4,6,4,4,4,4,4,4,4,4,4,4,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,3,4,4,4,4,4,4,
4,4,4,4,4,4,4,5,4,5,4,5,4,5,4,4,4,4,4,4,4,4,5,5,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,5,4,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4, };
static unsigned short stb__courier_bold_7_latin_ext_h[560]={ 0,6,2,6,6,5,5,3,5,5,3,4,2,2,
2,6,6,5,5,6,4,5,6,5,6,6,4,4,4,3,4,5,6,4,4,5,4,4,4,5,4,4,5,4,
4,4,4,5,4,5,4,5,4,5,4,4,4,4,4,5,6,5,3,1,2,4,5,4,5,4,4,5,4,4,
6,4,4,3,3,4,5,5,3,4,5,4,3,3,3,5,3,5,5,5,2,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,5,6,4,4,4,
5,5,1,5,3,3,3,2,5,1,3,5,4,4,2,5,5,2,3,4,3,3,5,5,5,5,6,6,6,5,
5,6,4,6,6,6,6,5,6,6,6,5,4,5,7,7,7,6,6,3,5,7,7,7,6,6,4,5,6,6,
6,5,5,6,4,5,6,6,6,5,5,5,5,4,5,4,6,6,6,5,5,4,5,6,6,6,5,7,6,6,
5,5,6,6,5,4,7,6,7,6,6,5,6,6,5,5,4,5,5,5,6,6,5,5,5,4,5,6,7,7,
7,7,6,6,6,7,6,6,4,4,5,4,5,4,6,5,5,5,5,3,5,6,7,7,6,6,3,6,6,6,
6,4,4,4,4,4,4,6,5,6,5,5,5,4,5,5,6,5,7,6,7,6,4,4,6,5,6,5,5,5,
7,6,7,6,6,5,6,6,6,6,5,5,4,5,6,5,6,5,7,6,7,6,7,6,5,4,6,5,6,7,
5,6,5,5,4,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,4,6,4,4,4,
4,4,4,4,4,4,4,4,4,4,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,6,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,6,5,5,6,
6,6,6,7,6,7,6,7,6,7,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,7,7,6,6,7,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4, };
static unsigned short stb__courier_bold_7_latin_ext_s[560]={ 255,247,184,28,133,234,125,148,130,139,154,
226,181,170,159,222,217,174,179,212,32,239,207,27,197,160,218,253,47,79,42,
134,115,26,53,192,11,37,236,143,21,16,60,6,1,247,241,55,231,65,221,
17,213,45,202,196,191,186,181,220,26,99,89,194,175,145,200,135,50,124,119,
93,108,103,111,92,87,58,84,72,70,88,64,52,161,41,74,94,69,184,100,
158,166,189,165,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,255,197,202,
230,225,220,37,32,200,244,110,114,124,170,98,188,135,169,206,240,162,153,148,
178,151,11,144,139,120,114,109,104,6,60,71,82,76,82,46,88,66,23,163,
40,103,66,186,22,129,11,92,97,107,91,81,130,229,112,122,1,170,138,166,
193,76,101,125,173,168,86,160,153,140,150,33,133,128,123,118,208,108,176,21,
155,165,84,79,140,69,175,12,123,49,42,38,44,28,23,49,77,6,150,117,
158,52,118,143,223,16,128,210,204,113,194,189,184,153,148,215,54,39,20,158,
135,62,72,77,82,51,113,108,156,98,93,77,36,243,62,233,57,55,228,13,
18,1,119,34,17,151,127,1,250,105,242,237,232,227,6,1,25,155,235,249,
191,179,180,59,173,64,14,74,138,145,168,131,130,87,120,30,97,106,113,96,
89,94,178,11,71,16,61,56,198,46,41,36,31,103,223,171,203,6,183,250,
148,102,235,136,225,141,215,143,210,199,248,189,146,199,240,163,188,67,208,238,
215,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,44,244,244,11,
244,244,244,244,244,244,244,244,244,244,244,244,244,213,218,244,244,244,244,244,
244,244,244,244,244,244,244,244,167,82,244,244,244,244,244,244,244,244,244,244,
244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,250,173,
1,6,220,230,1,245,67,210,57,205,47,194,37,32,244,244,244,244,244,244,
244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
244,244,244,26,21,161,178,6,184,244,244,244,244,244,244,244,244,244,244,244,
244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
244,244,244,244,244,244,244,244,244, };
static unsigned short stb__courier_bold_7_latin_ext_t[560]={ 1,9,40,16,16,22,29,40,29,29,40,
35,40,40,40,9,9,29,29,9,40,22,9,29,9,9,35,35,40,40,40,
29,9,40,40,29,40,40,35,29,40,40,29,40,40,35,35,29,35,29,35,
29,35,29,35,35,35,35,35,16,9,23,40,40,40,35,29,35,29,35,35,
29,35,35,9,35,35,40,40,35,29,29,40,35,29,35,40,40,40,29,40,
29,29,29,40,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,
29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,1,29,9,
29,29,29,29,29,40,22,40,40,40,40,29,40,40,29,29,29,40,29,29,
40,40,35,40,40,29,29,29,29,16,16,16,29,29,16,35,16,9,16,16,
29,16,16,9,29,35,29,1,1,1,9,9,40,22,1,1,1,9,16,35,
22,9,9,9,22,22,9,35,23,9,9,16,23,23,23,23,35,23,35,9,
9,9,23,23,35,23,9,16,16,23,1,16,16,23,23,16,16,23,35,1,
16,1,16,16,16,9,16,16,16,35,16,16,16,16,16,16,23,23,35,23,
9,1,1,1,1,9,16,16,1,16,16,35,35,16,35,16,35,16,16,23,
23,23,40,23,16,1,1,16,9,40,9,9,9,9,35,35,35,35,29,29,
9,16,9,23,16,23,35,23,23,9,16,1,9,1,9,35,35,9,23,9,
23,23,22,1,9,1,9,9,22,9,9,9,9,23,22,35,22,9,22,1,
23,1,1,1,1,1,1,23,29,1,16,1,1,16,1,23,22,35,22,16,
29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,23,29,29,9,
29,29,29,29,29,29,29,29,29,29,29,29,29,22,22,29,29,29,29,29,
29,29,29,29,29,29,29,29,1,35,29,29,29,29,29,29,29,29,29,29,
29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,22,1,
29,29,1,1,9,1,1,1,1,1,1,1,1,1,29,29,29,29,29,29,
29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,
29,29,29,1,1,1,1,1,1,29,29,29,29,29,29,29,29,29,29,29,
29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,
29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,
29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,
29,29,29,29,29,29,29,29,29, };
static unsigned short stb__courier_bold_7_latin_ext_a[560]={ 59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT or STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_7_latin_ext(stb_fontchar font[STB_FONT_courier_bold_7_latin_ext_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT][STB_FONT_courier_bold_7_latin_ext_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_7_latin_ext_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_7_latin_ext_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_7_latin_ext_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_7_latin_ext_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_7_latin_ext_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_7_latin_ext_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_7_latin_ext_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_7_latin_ext_s[i] + stb__courier_bold_7_latin_ext_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_7_latin_ext_t[i] + stb__courier_bold_7_latin_ext_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_7_latin_ext_x[i];
            font[i].y0 = stb__courier_bold_7_latin_ext_y[i];
            font[i].x1 = stb__courier_bold_7_latin_ext_x[i] + stb__courier_bold_7_latin_ext_w[i];
            font[i].y1 = stb__courier_bold_7_latin_ext_y[i] + stb__courier_bold_7_latin_ext_h[i];
            font[i].advance_int = (stb__courier_bold_7_latin_ext_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_7_latin_ext_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_7_latin_ext_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_7_latin_ext_s[i] + stb__courier_bold_7_latin_ext_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_7_latin_ext_t[i] + stb__courier_bold_7_latin_ext_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_7_latin_ext_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_7_latin_ext_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_7_latin_ext_x[i] + stb__courier_bold_7_latin_ext_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_7_latin_ext_y[i] + stb__courier_bold_7_latin_ext_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_7_latin_ext_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_7_latin_ext
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_7_latin_ext_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_7_latin_ext_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_7_latin_ext_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_7_latin_ext_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_7_latin_ext_LINE_SPACING
#endif

