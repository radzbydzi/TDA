// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_10_latin_ext_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_10_latin_ext'.
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

#define STB_FONT_consolas_bold_10_latin_ext_BITMAP_WIDTH         256
#define STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT         82
#define STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_bold_10_latin_ext_FIRST_CHAR            32
#define STB_FONT_consolas_bold_10_latin_ext_NUM_CHARS            560

#define STB_FONT_consolas_bold_10_latin_ext_LINE_SPACING           7

static unsigned int stb__consolas_bold_10_latin_ext_pixels[]={
    0x0200ec08,0x00020110,0x18800760,0x55102a20,0x3312e983,0x10220720,
    0x3104407b,0x01080881,0x220409b1,0x0a251088,0x2155406a,0x01500810,
    0x08802204,0x202cc04c,0x54c28808,0x201102aa,0x3e20ec3b,0x2baa0792,
    0x57a87441,0x363ee98d,0x6dc41741,0xcf985900,0xdf716c2c,0x1bb50790,
    0x7540544c,0xdda9bb20,0x2616cf40,0x517dc098,0x75aa1b7b,0x3a22e4c4,
    0x22f545ce,0x1a00f85d,0xdda85dbb,0x0d303ae0,0x546a85c8,0x0ea84dfc,
    0xa81d8110,0xb5103f10,0x44a24d83,0xd8743a22,0x3be604c1,0xfa87603e,
    0x12e5ba80,0x2aa2172a,0x4c7e29b1,0x866d30a1,0x3e628662,0x3307c1ff,
    0x98d7d514,0x41ae29a9,0xf85b0a19,0x331fc980,0x882aaa14,0x85db4c0a,
    0x3fff62ba,0x05441745,0x3b0ffed8,0x5a87ffe6,0xd327e7c4,0x5dcd56a8,
    0x6c3b2dcb,0x39d70ffe,0xe88bff60,0xb8b220cf,0x7cc3d884,0x9aaf32cc,
    0x9698f14c,0xf14c9e29,0x641f07a0,0x0ffd4f14,0x17b3c532,0x478a6499,
    0x3e207c3c,0x1e2991ec,0x37e25f99,0x116fa64f,0x06a8b9dd,0x4fdf885d,
    0x0764bb4c,0x6647887a,0xa8b70fda,0x7ee6cd56,0x4976982c,0x6dc0dfe8,
    0x16ea87da,0x212e5fdd,0x407d46fa,0x45323dae,0xf14cb4c7,0x3d078a64,
    0x3c5323d4,0x14c89bd5,0x327aa6cf,0x21da8f14,0x924f540f,0xc96c1e29,
    0x17fccf34,0xd06a81ae,0x88f34c85,0x20762ebf,0x97b07c1e,0xd51323f5,
    0xcface9aa,0x175fc412,0x36f236f4,0x435c10f9,0xf990975b,0x7067f441,
    0x78a641fd,0x4f14cb4c,0x47a0f14c,0x78a644e8,0x4c87e3aa,0x3c475cf1,
    0x7d31e299,0x8efe607c,0x4b60f14c,0x574c7e3d,0x1322f60f,0x7b0ba0d5,
    0x815b30fc,0x1e61e81d,0x2d47ed7b,0x99f355aa,0x6cc763bf,0x3df4440a,
    0xfb9e7b6e,0xdddb12ff,0x0fa7e12e,0x44f89baa,0x9698f14c,0xf14c9e29,
    0x4c8f07a0,0x0ebb54f1,0xff91e299,0x6478a64d,0xfb37ffc3,0x83c5327d,
    0x98fc992d,0x7aa6cd96,0x0ba2f744,0xff10fc99,0x0f40ec9f,0x79deb8b7,
    0xd56a83e2,0x3b1ded74,0xfb93ffe2,0x2ffe81ef,0xb5daa0a8,0x2e4fcc4b,
    0x81f335c1,0x7698f35b,0xf35b9e6b,0x07c1f884,0x02a1e6b7,0x02a1e6b7,
    0x0791e6b7,0xadc59013,0xd52e8479,0xb8150f51,0x80a8788e,0x3d47540a,
    0x1d87c56e,0x0fcc7e21,0x17217ff4,0x360792dc,0x983e2b71,0x47807603,
    0x8976def8,0x3ee7eeeb,0x105fb2ff,0x16985ffd,0x7f445ffd,0x213fea2f,
    0x0bffa21d,0x0bffa21e,0x0bffa21e,0x1b03b05b,0xf117ff44,0x17fe44bf,
    0x86ffc83c,0xff910f07,0x23eee985,0x649ff51d,0x06c01d02,0x76c43ff1,
    0x774c760e,0x0000443e,0x5d3fdc00,0x800000fc,0x000006fd,0x00001ecc,
    0x02f40000,0x00000020,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x50110221,0x000110b7,0x98088021,0x3d880841,0x04c0d544,
    0x04417744,0x45304444,0x44088882,0x9e83101d,0x0880882d,0x444428a6,
    0x110808c0,0x1dd70000,0x35510220,0x775c0884,0x84110000,0x316c0408,
    0x80dda8bd,0x82edd81a,0x82d9e83e,0x076a20ea,0x15130bd5,0x2e1fe7d4,
    0xd987b00e,0x70f7441d,0xb7b51e3f,0x3d301981,0x3bb30318,0x3cbee5c8,
    0x7d503b62,0xdf88bd30,0x4bfbaa4f,0x83aa0a19,0x3a62ccf9,0x7540a885,
    0x0e9442fe,0xd0ba17a6,0x510d5445,0x41ffdb01,0x101300a8,0x23551015,
    0x5444fcf8,0x50ffed80,0x0a1996ed,0x20aaa0f6,0x3dbae2aa,0x229b02a2,
    0x9b15541f,0x855507e2,0x1ebd72ba,0x1aa88aaa,0xf115554c,0x64fd4f35,
    0x299e2996,0x14c0fa8a,0x527efc45,0x56a8d93f,0xa8955544,0x7ccba2ab,
    0x9fbf12cc,0x3e24bb4c,0x0ffe24fd,0x7cc9fbf1,0xfb5992cc,0x993f7e21,
    0x767d4976,0x6c3c5322,0x8973ba23,0x3b2e5cee,0x93f7e27a,0xced8d579,
    0x36355e65,0x573b65ce,0x76c79fcb,0x8ff3ea5c,0x3e24dfca,0x32d56a80,
    0x797dcf14,0x7dc33fa2,0x279a64f2,0x7fecd56a,0x5bfbaa5f,0x4ba6feea,
    0x79a640fa,0x4c8bafe2,0x4c87b0f3,0x3607d4f3,0x2991facb,0x8bafe279,
    0x5320ecea,0x1ae3d878,0xeacb835c,0x3a3cd327,0x403ea3da,0x03ea3dae,
    0xdbcb81f5,0x5aa03ea7,0x7c42e85b,0x32d56a80,0x7af5cf14,0x2bd76ea8,
    0xd51f8f67,0x440d51aa,0x3b17c42f,0x1ec33fa2,0xb02b663f,0xb0f60fc7,
    0xcfe88fc7,0x6c7ed7b0,0x056cc7e3,0x2991f5aa,0x2f63d878,0x322f64c8,
    0x7b3f52e4,0x41fd70fc,0x83fae05b,0xcb85b85b,0x5416e7f8,0x42e82ecf,
    0xd56a80f8,0xf973c532,0x2ed704f3,0xf93279fc,0xd51aad51,0x226c26c0,
    0x4cb75409,0x27ffc47e,0x0f60fc99,0x3aa0fc99,0x64f3bd76,0x7ffc47e4,
    0x993d5aa4,0x7fff99e2,0x54d9ea9b,0x327aa5cf,0x44f887e4,0x713e206b,
    0x2970d70d,0x7541ae7c,0x502e80ec,0x35b82a01,0x73ede5cf,0x2f2e5fff,
    0x1ea3aa7d,0x541aa2e4,0x3a07540e,0x8eab5c12,0x87c56e7a,0x3e67a8ea,
    0x2a3aa7ff,0x3fa6b827,0x9ea3aa2f,0x0a81f15b,0x09879adc,0xeb9e23ae,
    0x54f50788,0x07cc7a8e,0x3e604be6,0xf3097cc0,0xf9815025,0x83eb5412,
    0x23c0f02e,0x32e2ffe8,0x2e0f87f8,0x3f227f8c,0x441eb82f,0x107e25ee,
    0xfffb803f,0x4c5ff912,0x3f223eee,0x6449702f,0x3ffee2ff,0x3f2203a2,
    0x0fbba62f,0x0bffa21e,0x8dff9076,0x3f986ffc,0xfd8bff22,0x6cdff702,
    0x4dff702f,0xb83c6ffb,0x3d5aa6ff,0x00000174,0x2143e52e,0x0000f94b,
    0x77fffb80,0x0000ffff,0x0eb80000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x4c000000,
    0x4415c0a1,0x0dc3f4c0,0x08130088,0x08818801,0x40880400,0x0dc2aaa8,
    0x54026042,0x1011002a,0x09fd5015,0x21011037,0xdd702cc0,0x2201a81d,
    0x00264a80,0x10809811,0x55540881,0x06a01001,0x0ea1e299,0x509b03aa,
    0x901d50b7,0x02d9e81b,0x0dda83d3,0x0ba1776c,0x7e441bb5,0xd516ea3d,
    0x76c0eb8b,0x83ffb65c,0xfbf12edd,0x75503e89,0x2a06ed41,0xfa83545e,
    0x1bea0faf,0x71740754,0x703aa01d,0x545e981d,0x799f10dd,0x4c2e82e8,
    0x278a645c,0x80542ee8,0x222c881e,0x2aa22aaa,0x50150d41,0x0a86a155,
    0xaba883f1,0x3a04c152,0x55116442,0xa8d55455,0x24bb4c0f,0x2992aaa8,
    0x313fa279,0x20a2330b,0x1ff7541a,0x641f5ff9,0x2aaa20fc,0x80d434c2,
    0x1555441a,0x2aa23555,0x2601f12a,0xb10d5d40,0xb0f14c87,0x7fd40f87,
    0xab55aa6f,0x33ea6fee,0x43cd6e3f,0x2b70cff8,0x88f7e479,0x6c3b3dfc,
    0xfdd11741,0x44f7f225,0x10b73ccf,0x7e445d7f,0xb8fc7b3d,0x21aa6e9d,
    0x6fa8f14b,0xf33ccfd4,0x74fc1f5f,0xb0f7f223,0xfa86fa87,0x89efe446,
    0xbf913ccf,0xc8fbbe27,0x799f12ef,0x453237d4,0x407c3d87,0x6ab540f8,
    0x2ed517c4,0x5c1ecfc5,0x03d9f87c,0x2762e8bb,0x81741d89,0x1f11745b,
    0x0ad986b8,0x3f26c5d0,0x543e6fea,0x22972fee,0xd507e647,0xf9a883e2,
    0xd0b93f30,0x6640f885,0x407e640f,0x7403e22e,0x4c267e22,0x203e2d56,
    0x4d6e0fcc,0x407c3d86,0x8d56a879,0x1767d44d,0x7cf41fae,0xf31fae0e,
    0x362e85fd,0x1740dbea,0x2e8dddb1,0x7ccfbbe2,0x13ffe212,0x7a8eb8ba,
    0x3f527f54,0x1fbbeed9,0xab547d3f,0x775c3e07,0x25c2e87e,0x27e1f4fc,
    0x3e22e83e,0xf11743ee,0x15eefb81,0x74fc7ddf,0x207ffa23,0x2d407c3d,
    0x3aa6cbcc,0x20767540,0xf9e983f8,0x0a81fc41,0x37af22e8,0x2bfff30e,
    0x22e8d76a,0x3ee099f8,0x03e2b76f,0x01ffc85d,0x76ab545f,0x4fccf53b,
    0x07fbea5c,0x3e2e9e61,0x307e1741,0x4fccb93f,0x3e22e85c,0xf1174099,
    0x221aabff,0x93f3099f,0x0f601d0b,0x881fd81f,0x03f16dfe,0x0ba0fad5,
    0x1741fbb2,0x7645d078,0x12c80eea,0x22e8dbdf,0x4c5900f8,0x82e83eee,
    0xddd709cd,0x976ab541,0x7eeeb9e2,0x3fec81aa,0x545d0b30,0x27eeeb85,
    0x2e87eeeb,0x817403e2,0x457bf62c,0x3f775c0f,0x3ffe6274,0x005bffe7,
    0x53fffdc0,0x20ba1ead,0x741ff88f,0xbfff3002,0x6c83e5ee,0x8afffcc0,
    0x00145fff,0xd98bfff3,0x5aa0221d,0xe9e2976a,0x203547e2,0xf98fcc00,
    0xf17405ff,0xf31f8ba3,0x3ffe2bff,0xb0bfff35,0x5fff880b,0x0000fc5d,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x40840000,0x42044010,0x80800880,0x22058811,0x44084000,
    0x20110000,0xa8332608,0x9307905b,0x70775c1b,0x264d81dd,0x85ba8511,
    0x0f622d9e,0x00790762,0x3a2aa811,0x1676c2d9,0x0ec40f62,0x9d5000f2,
    0x4b64ca87,0x16cf45ea,0x367a0754,0x5c0376a2,0xe83ea87b,0xb05dbb02,
    0x362d9e89,0xa83b02ed,0x207540dd,0x2881a819,0x5541d930,0x3306621a,
    0x43c52e13,0x8983181a,0x8280cc0a,0x361eaee8,0x440c65ce,0x80a89828,
    0xdd105019,0x407ee45f,0x5554ba0a,0xa86a0d41,0xa8555510,0x53073201,
    0x540b5015,0xaaa83301,0x3f614531,0x50d5542f,0x27f54355,0x7f545df9,
    0xf12ffe44,0x177e4799,0x452e9fd5,0xd517fe47,0x56ab55aa,0xd56a9aad,
    0x07d457b0,0x3f217fe4,0x217fe42f,0x7fe42ffc,0x7fe4b702,0x8a977e43,
    0x3ea3ccf8,0x2279adc6,0x1bea3dfc,0xd909ffb1,0x501f07f9,0x29fd50df,
    0x5f73ccf8,0x27dadb9e,0x9f13ccf8,0x984be279,0x04be2d56,0x0f896ad5,
    0x5f16ab4c,0x2e78a5c2,0x6ab54f76,0xab55aad5,0x6c355aa6,0xbb5c2dc3,
    0xd73ddae7,0x4f76b9ee,0x76c4f76b,0x99aad56e,0x80f88d56,0x6cfc0fcc,
    0x7e642e83,0x64265320,0x90970f34,0x097c41f9,0xf5eb81f1,0x887cede4,
    0x2607c40f,0x35eefb87,0x12d5320f,0x3bee7ddf,0x2970f35e,0x87c53278,
    0x55aad56a,0x6a9aad56,0x6b87b0d5,0x321f14c8,0x45321f14,0x43e2990f,
    0x5aa1f14c,0xb9e6996b,0xf13b5eef,0x1f4fc7dd,0x21741fae,0x64ba3e9f,
    0x83f14c84,0x1f4fc0f8,0x7ddf10f3,0xdb9e7f2e,0x3bbe279e,0x227ddf13,
    0x221aa11f,0x5db5c11f,0x354267e2,0x29708fc4,0x9ea3ae79,0x65e6d979,
    0x799b2f36,0xf987b0d9,0x9ea3ae12,0x3ae7a8eb,0x2a3ae7a8,0x89ea3ae7,
    0x2ed76def,0x7c4a1aa6,0xb93f3099,0x45d03f88,0x2f65c9f9,0xf34c84e8,
    0x4fcc7b01,0x8847e25c,0xb797099f,0x222ffe8f,0x33f1099f,0xfb27fdc1,
    0x127fdcbd,0x07c4bbfd,0xff72f7ec,0x893f32e9,0x3fa22ffe,0x2dbfd16d,
    0x3a26dfe8,0xb83d86df,0x5ffd16ff,0xd117ff44,0x7ff445ff,0x40bffa22,
    0x83ffd13c,0x07c45efd,0x3a1fbbae,0x775c5d02,0x137fe67e,0x4c1b6332,
    0x71fbbae6,0x703e29ff,0x81d8ff19,0x007c40f8,0xf8800000,0x000005ff,
    0x00000000,0x000ffff3,0x00000000,0x44000364,0x7c5d5fff,0x3fe61741,
    0x00fc5d5f,0x001bff90,0x4401f8ba,0x32975fff,0xbfff1007,0x0017ffe2,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x42000000,0x45b3d01a,0x41d883d8,0x16ea003c,0x676c5b3d,0x3620f622,
    0x77e41e41,0x2e0775c1,0x6cec40ee,0x002aaa60,0xd7003bae,0x83b10325,
    0x055543d8,0x02a88995,0x55107620,0x01663eb8,0x43510555,0xa8800a19,
    0x406aaa1a,0xa8a82efc,0x20c60975,0x80cc0a89,0x544fea82,0x144418c1,
    0x03302a26,0x0b71f30a,0x30331035,0x7e7cc131,0x41ffb11c,0x9776c198,
    0x1984ad9d,0x3320a898,0x7f10542f,0x1982e8bb,0x5125d6cc,0x7441aa7d,
    0x167645ce,0xeea9e299,0x4b33e63f,0x2fa3eef8,0x31f0d569,0x77e40321,
    0xfc8bbf22,0x8977e42e,0x3fba212f,0x225fdd12,0xfdd12fee,0x88bfba25,
    0xd1d52fee,0xfc86fa83,0xb17fe42f,0x885b8f17,0x83f12fee,0xeed86bea,
    0x6c1776c2,0x74cbbb62,0xd704c5b8,0x66cecddd,0xeeaa640d,0x7cc1ae3f,
    0x54f14c80,0x03ea799f,0x3ee720f1,0x4c0f85ee,0x2ad33fde,0xb4daad36,
    0x9b55a66a,0x2dc2dc07,0x5c2dc2dc,0x2faab705,0x2e0fcc86,0x7bb5cf76,
    0x6c7be2ba,0xdf92dc03,0x0fc41d83,0x25b00fc4,0x0ffd81f8,0x9d8bfff3,
    0x4ae95d2c,0x33f51fe8,0x72645ecf,0x8a647fff,0x887c5aa7,0xbff10cfe,
    0x0f80d503,0xfbb5d7cc,0xbddf75ee,0xfb97bbee,0x423f15ee,0xdb16eed8,
    0x5bbb62dd,0xdb16eed8,0xb776c4dd,0x4fc5e8ea,0x87c5323e,0x2ba1f14c,
    0x220f61f8,0x25d86eed,0x77e45dca,0x6c0f7e41,0x7c47bf22,0xa8fcc5da,
    0xd5d1eefe,0xd51a2573,0x7aa6c3e2,0x2993d5ae,0x43d5aa78,0xb36446ea,
    0x3e17bf65,0xd579bcc0,0x20d50d50,0x29ff706a,0x5daad76a,0xb55aed56,
    0xa9aed56b,0x7c5aad76,0x5cb93f30,0x23ae7a8e,0xb1e3727a,0x4daed507,
    0xb5d12fef,0x360bb039,0xaec17425,0x1f44f36b,0xaac85b1d,0x2d50a0da,
    0x9e23ae7a,0x9adcf378,0x087fbea7,0x5e9721ae,0x2607c16a,0x2f7ecf37,
    0x77ecbdfb,0x362f7ec5,0x45b7be21,0xbdf16def,0x45b7be2d,0x3be26def,
    0x4bd7d56d,0x3a27eeeb,0x3ffa22ff,0x4bfffa22,0x6def883d,0x3ba390f4,
    0x4c5fdf30,0xbff12fef,0xe897f7cc,0xd91763fe,0x37621df9,0xf983ea2e,
    0x37fe41fe,0xfe88bff2,0x7dc1aa2f,0x3dff32ff,0x81ea8f62,0x26f36fff,
    0x80000007,0x00000002,0xf1740000,0x6c000003,0x80028003,0x01000200,
    0x017ffe60,0x00000000,0x0001aa00,0x00000164,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10775c00,
    0xb1015105,0xb2dd41b3,0x20007e29,0x6c1442aa,0x4ec802ce,0x2e002a88,
    0x264980ee,0x06e54188,0xb8144b95,0x5566191d,0x2a0bba24,0x32a15c41,
    0x641935c5,0x2e0554c3,0x150cc326,0x41750104,0x53000aa9,0x22b88555,
    0x2a200eea,0xf11aa2aa,0x098989fb,0x355e61a8,0x644ba364,0x221aa3fc,
    0x3a63e828,0x3b3e21f8,0x3137fe44,0xbab9aa03,0x20a81a83,0x953d3078,
    0x3d85ab4c,0xce893fa2,0xab40543f,0x33ae0a84,0x264ab43f,0x54edcd57,
    0xb92fae0f,0x21d83fce,0xf30dacbc,0x200f87d9,0xffb3dfc8,0x53cd32bf,
    0xd56a9aad,0x0cc1ed74,0x7ecf202a,0x1aad55ff,0x0757cc13,0xb543ea97,
    0xc9aad56a,0xffff76ff,0xf88ffe23,0x2e0f14ff,0x5ab4c6ad,0x99515ed8,
    0x7ef45320,0x3e2346c4,0x23cd6e3f,0x1ebd868d,0x0ba1fefc,0xd313cd6e,
    0x336a3237,0x1f1aa990,0x46a85d00,0xab547e3d,0xd7355aa6,0x1d89501f,
    0x46a83fae,0x3fe2d56a,0xd8a3fa23,0x2991fecb,0x55aad56a,0x164ecd56,
    0x47e621ec,0x1c83f378,0x7e45db4c,0x25d04c84,0x1c878af8,0xfa7f47b0,
    0x27c40e40,0xbf525de2,0x0fa7f419,0x2329bf95,0x97d50cdb,0x00fa8f8f,
    0x2646a85d,0x5355aa3f,0x84f89aad,0x310f44fc,0x4bbfaad9,0x23d8d56a,
    0x3f27cdcc,0xb656e1f4,0x5532d56a,0xb09d9d56,0x5e23e887,0x92f261e8,
    0x2e1fbff9,0x4d84c83d,0x5cc981e2,0x263723d8,0x892f260f,0x64fc3efd,
    0xc826fa23,0x0ec0f98d,0xca832719,0x07547c6c,0x2a3542e8,0x65e67a8e,
    0xf3365e66,0x2e80f881,0xf31aa6b8,0x5ec7b1b2,0x355ae5f8,0x5e6dbfd1,
    0x4db2b76c,0x43d82eaf,0xe81e20dd,0xb01666d9,0x360cc887,0x740f108d,
    0x71ec0e88,0xd9e8b91b,0x8873aa26,0x40f44eef,0x0a85c8db,0x22065272,
    0x74007c3d,0xc8af7442,0x37fa22ff,0x6db7fa26,0xe839f02f,0x443dff52,
    0xdbfd15ee,0x37bea3d8,0x407ff61f,0x2dbfd16a,0x3da6dfe8,0x7cdbffe6,
    0x9fff15ff,0x9875cd64,0x2dfff305,0xff57fff9,0x9641e2ff,0xdfff31ee,
    0xac837fee,0x7d510eb9,0x321b1543,0x3fee7fff,0x57ffe60d,0xf30ecddc,
    0x27ffdc9d,0x005fff98,0x4c000000,0x000ba0ed,0x0ffff300,0x00354000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x5aacc166,0x2ccaaaa6,0x7dc2cec8,0x8800000f,
    0x2a600002,0x42d882aa,0x289443d8,0x2aa22d88,0x9854152a,0x13054511,
    0x0a80a82a,0xb1001510,0x8105ca85,0x6c1bb500,0x175c02ca,0x2bed81a8,
    0x3607b100,0x698bba22,0xea96ad30,0x220d36ee,0x6407c0a8,0xdddd72ee,
    0x7f34fea8,0x265fdd05,0x3f2a6ede,0x8981984d,0x3f2fb20a,0x37660cc0,
    0xa9e6b76e,0x3b0ecb97,0x1f81f936,0x43e83fd0,0xf5015019,0x04442ec3,
    0xeec82226,0xfa817f92,0x7e428886,0x20544c2f,0xb4c7b019,0x82d5a64d,
    0x25fdd33d,0x3ea23ff8,0x2355a619,0x25f11c9d,0x20bd7d30,0x395b1b5b,
    0x7ef442e8,0xd92c87a4,0x3fe23f97,0x3e2f884f,0x0fe6c3d9,0x2a3b133b,
    0x1b3e0f36,0x31c83db5,0x76cc5fdb,0x3207ae2f,0x447ff10e,0x307e23ff,
    0x7e643b9d,0x54bfb660,0x1ffc4f76,0x8f607ff1,0xcb4c5be9,0x3f30f985,
    0x36a3d8b9,0x3bbee4cf,0x23ddfd55,0x8f369879,0xdb1d5eed,0x10efe43d,
    0x5d6cf15f,0xfb9f51d8,0x4d81f988,0x2fcc3f5c,0x4436ba76,0xcfa84c8f,
    0x807a3a20,0x3e65c9f9,0x407f15c9,0x1ec1ec4e,0x57cc7bf2,0x98ba7a5c,
    0x22995c9f,0x1ec1ec0f,0x0bfe63d8,0x9b0bbfd1,0x1ec6ab4c,0x3a1aa1e2,
    0x08fc41d8,0xb54d93d3,0x505b1b5b,0xc83c439d,0x5d50ecfb,0xa83e88f7,
    0xfb83f80e,0x06ef5e46,0x3f705d5d,0x20beadc8,0x99aad31b,0x21f4cd56,
    0xd83d84e8,0x55a6bb03,0x4cbb3f35,0x2a3aed56,0x03d83d87,0x07d74c7b,
    0x307cc2c8,0x887b1aad,0x329df907,0x3ee0eece,0x419df34f,0xbd55def8,
    0x442e81bd,0x4fd9d707,0x0dd8f35a,0x3a0457c4,0x91f4fc41,0x7641dd5d,
    0xbb907e07,0x699fc1df,0x46ab4cd5,0x6c0b61e8,0x3be63d83,0x5d6ad32f,
    0x55a67dde,0xb05ffb16,0x8f607b07,0x1b20d969,0x2d56989b,0x1e26fff9,
    0x69800010,0x42e80000,0xdb3f5078,0x3e679ad4,0x3ffee5ff,0x55720f47,
    0x31f2f90f,0x3fffc0bf,0x2ad300f4,0x00355a66,0xf36fff98,0xb4c08dff,
    0x98fc5b5a,0xff300d56,0x9bffe6df,0x0006fff9,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x98555400,0x44a22aaa,
    0x2a06aa22,0x260d5440,0x4514c0aa,0xaaa85129,0x55035511,0x22286635,
    0x40002aaa,0x0c00b559,0xb8837300,0x47ff1002,0x90f43a4c,0x89aa3aa5,
    0x36d34fff,0x28846444,0x71289987,0x222000e2,0x44054088,0x405d5088,
    0xf950cff8,0x24db549b,0x07c3fcfa,0xeb93b3e6,0x3cbee3fc,0xdf8f91f7,
    0x87d9d53c,0x22973cdf,0x44f7f227,0x66644fde,0xdcad5a61,0x4c2f86de,
    0x1d332fed,0x076175ec,0x9aaf31ec,0x361d8bad,0x8fcc41fd,0x77445be9,
    0xe8b67a3d,0x47b762d9,0x8775c5ec,0x3a66eeea,0x9af774c5,0x41b2e02d,
    0x2357542e,0x40f8b76a,0x9a5cf369,0xd73d7ae7,0x540f8dd7,0x5c0f8b55,
    0x445d0f14,0x36aa78af,0xdad5a65c,0x3110eadb,0xae4fcc11,0x9dde0ecc,
    0x3d80ae88,0xf791ed74,0x42fc41d9,0x0bfe63e8,0x65c3df91,0x98f1d35a,
    0x2f16e25f,0x2366883b,0x904ccc1d,0x06fcf405,0x83fd50ba,0x07c2ecfa,
    0x4b9ae3a6,0x3cf65c3e,0xef8d7f79,0x85fbf53e,0xddf72ccf,0x83c45d0f,
    0xd30bbe8c,0x6ceced72,0x21dddd70,0x3b76d569,0x75c37ae0,0x21ec0eef,
    0x33ae0fdb,0x20feec7e,0x3eba60dd,0xe894e540,0x4f2f60e8,0xf514dae8,
    0x08176741,0xee992273,0x303ff94e,0x85d03d3d,0x5f544dea,0x3e607c0e,
    0x7cd2e1df,0x64f97770,0x27e0e9e9,0x8f93d509,0x33b71abf,0x83c45d0f,
    0x3a25baba,0xb3b3b5df,0xab4c0a81,0x5d437756,0x3e60ec1b,0x517e26ff,
    0xbb54db3f,0x2bfff30e,0x8130d969,0x0c108810,0x35117763,0x20000000,
    0x85d06dec,0x5aa1f8ea,0x1a607c3d,0x772e465c,0xe84e4ff1,0x2ab503e0,
    0x452e07c6,0x81e22e87,0x9d800cca,0x21740d9d,0x2aa6d569,0x3902aa60,
    0x00000000,0x00000000,0x00000000,0x3fe23e00,0x5daa1741,0x3e3d5aa6,
    0x2e0d36ff,0x64ee0dff,0x3e1d8767,0x5bff55ff,0x78a5c0f8,0x0017ffe6,
    0x00000000,0x8bf70000,0x5b10b61d,0x6cec5db8,0x442a7b31,0xd9d8e43d,
    0x7ffc3311,0x000003ff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0xe83e2200,0x81987f14,0x3218c088,0x1140fddb,0x6476769f,
    0x000001ee,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x45d30000,0x000002d8,0x50400d40,0x00000151,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x7ec00000,0x0000591f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_bold_10_latin_ext_x[560]={ 0,1,1,0,0,0,0,2,1,1,0,0,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
2,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,-2,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,-1,0,
0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0, };
static signed short stb__consolas_bold_10_latin_ext_y[560]={ 7,0,0,0,-1,0,0,0,-1,-1,0,1,5,3,
5,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,1,0,-1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,8,0,1,0,1,0,1,0,1,0,-1,
-1,0,0,1,1,1,1,1,1,1,0,2,2,2,2,2,2,-1,-1,-1,3,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1,-1,0,0,0,
-1,0,0,0,0,2,3,3,-1,0,-1,0,0,-1,0,2,0,3,7,0,0,2,0,0,0,1,-2,-2,-2,-2,
-2,-2,0,0,-2,-2,-2,-2,-2,-2,-2,-2,0,-2,-2,-2,-2,-2,-2,2,-1,-2,-2,-2,-2,-2,0,0,0,0,
0,0,0,-1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
-1,0,-2,0,0,1,-2,0,-2,0,-2,-1,-2,0,-2,-1,0,0,-1,0,-2,0,-2,-1,0,1,-2,0,-2,0,
-2,0,-2,-1,0,-1,-2,-2,0,0,-2,0,-1,0,-2,0,0,-1,-2,2,0,-1,-2,0,0,0,2,-2,-2,0,
0,-1,-1,0,0,0,0,-2,0,0,1,-2,0,-1,0,1,-1,0,-2,0,-2,0,0,1,-2,0,0,1,-2,0,
-2,0,-2,0,0,1,-2,0,0,0,-2,-1,0,0,-2,0,-1,0,-2,0,-2,-1,-2,0,0,2,-2,0,-2,0,
-2,-2,0,-2,-1,-2,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,-3,-2,-2,0,-2,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0, };
static unsigned short stb__consolas_bold_10_latin_ext_w[560]={ 0,3,4,6,6,6,6,2,4,4,5,6,3,4,
3,5,6,5,5,5,6,5,6,5,5,5,3,3,5,5,5,4,6,6,6,5,6,5,5,6,6,5,5,6,
5,6,6,6,6,6,6,5,6,6,6,6,6,6,5,4,6,3,6,6,4,5,6,5,5,5,6,6,5,5,
5,6,5,6,5,6,6,5,6,5,5,5,6,6,6,6,5,5,2,4,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,3,5,6,6,6,
2,6,5,6,4,5,5,4,6,5,5,5,4,4,6,6,6,3,2,4,5,5,6,6,6,5,6,6,6,6,
6,6,7,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,5,6,6,6,6,6,6,6,6,5,6,
5,5,5,5,6,5,5,6,5,5,5,6,5,5,6,5,6,6,6,6,6,6,6,5,6,5,5,6,6,6,
6,5,6,5,6,5,6,6,5,5,5,5,5,5,7,7,6,6,5,5,5,5,5,5,5,5,5,5,6,6,
6,6,6,6,6,6,6,5,6,5,5,5,5,5,5,5,5,6,5,5,6,6,5,5,6,6,6,5,5,5,
5,7,7,6,7,5,5,6,6,6,5,6,5,5,6,5,6,6,6,6,6,6,6,6,7,6,6,6,7,6,
5,6,5,5,5,5,5,5,6,5,6,7,6,5,6,5,6,5,6,5,6,5,6,6,6,6,6,6,6,6,
6,5,6,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,5,7,6,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,5,5,6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6, };
static unsigned short stb__consolas_bold_10_latin_ext_h[560]={ 0,8,3,7,10,8,8,3,11,11,5,6,4,2,
3,9,8,7,7,8,7,8,8,7,8,7,7,8,7,4,7,8,11,7,7,8,7,7,7,8,7,7,8,7,
7,7,7,8,7,9,7,8,7,8,7,7,7,7,7,10,9,10,4,2,3,7,8,7,8,7,7,9,7,8,
11,7,7,6,6,7,8,8,6,7,8,6,5,5,5,8,5,10,11,10,3,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,8,10,7,7,7,
11,9,3,8,6,5,4,2,6,3,5,7,4,5,3,7,9,3,2,4,6,5,7,7,7,8,9,9,9,9,
9,9,7,9,9,9,9,9,9,9,9,9,7,9,10,10,10,10,10,5,10,10,10,10,10,9,7,8,8,8,
8,8,8,9,7,8,8,8,8,8,7,7,7,7,8,7,8,8,8,8,8,6,9,8,8,8,8,10,9,10,
8,8,9,8,9,8,10,8,10,8,10,9,10,8,9,9,7,8,8,8,9,8,9,9,9,8,9,8,10,10,
10,10,10,11,10,11,9,9,7,7,9,7,8,7,9,7,9,10,9,5,8,11,10,10,10,10,5,9,9,10,
10,8,8,7,7,7,7,9,7,10,9,9,7,8,10,9,9,8,10,8,10,8,8,7,9,7,10,9,9,7,
10,8,10,8,9,8,10,8,10,10,9,9,7,8,10,8,9,8,10,8,10,9,10,8,9,7,9,7,9,10,
9,9,7,9,8,9,7,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,10,10,9,8,11,10,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,10,9,10,10,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7, };
static unsigned short stb__consolas_bold_10_latin_ext_s[560]={ 254,251,202,106,59,142,74,253,30,17,194,
147,159,207,163,192,81,152,158,50,7,246,219,120,174,239,14,252,31,242,37,
200,42,67,70,193,43,64,77,212,83,90,162,16,30,57,50,13,36,131,23,
240,9,226,246,239,232,225,219,86,50,118,235,212,193,171,205,158,100,145,138,
118,126,68,11,106,100,116,130,80,233,88,96,55,7,110,160,167,174,33,181,
142,8,183,186,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,254,46,194,
212,205,198,49,138,180,193,136,206,229,207,103,174,223,226,154,218,167,139,172,
198,253,248,141,200,191,171,132,40,198,205,27,57,7,248,1,112,106,96,90,
70,212,186,224,21,184,76,213,247,7,21,35,212,48,76,111,122,129,14,164,
89,83,76,70,64,58,94,151,46,40,33,27,21,178,93,87,49,240,74,227,
220,213,206,199,123,83,179,172,166,160,117,165,131,96,130,158,52,179,234,124,
114,138,140,144,64,157,102,42,34,219,121,128,134,1,108,242,236,230,1,218,
247,89,62,96,14,227,52,169,1,151,145,205,61,125,132,1,43,100,113,88,
28,75,154,146,35,207,136,155,220,187,14,8,188,83,7,185,125,245,1,146,
198,18,150,185,211,25,15,103,225,218,103,55,153,110,110,117,177,39,191,69,
178,163,164,42,149,98,156,205,136,1,168,240,234,171,231,184,56,200,62,191,
94,176,27,162,27,148,20,1,113,81,198,62,104,47,33,212,245,180,239,119,
124,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,20,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,91,80,54,186,22,66,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,74,69,240,234,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,232,
232,232,232,232,232,232,232,232,232, };
static unsigned short stb__consolas_bold_10_latin_ext_t[560]={ 1,13,76,53,1,44,53,34,1,1,70,
70,76,76,76,24,53,53,53,53,62,44,44,61,44,53,62,44,62,70,62,
44,1,62,70,34,70,70,70,44,70,70,44,70,70,70,70,53,70,24,70,
44,70,44,61,61,61,61,61,1,34,1,70,76,76,61,44,61,53,61,61,
24,61,53,1,61,62,70,70,62,44,53,70,62,53,70,70,70,70,53,70,
1,1,1,76,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,1,53,1,
53,53,53,1,24,76,44,70,70,70,76,70,76,70,53,76,70,76,53,24,
76,38,70,70,70,53,53,53,53,24,24,34,34,34,24,70,24,24,34,34,
34,24,24,24,34,53,34,1,1,13,13,13,70,13,13,1,1,1,34,61,
44,44,44,44,44,44,24,61,44,44,44,44,44,53,62,62,62,34,62,34,
34,34,34,34,70,34,34,34,34,34,13,24,13,44,44,24,44,24,34,13,
34,13,34,13,34,13,34,34,34,53,34,34,34,34,34,24,24,24,44,24,
34,13,13,13,13,1,1,1,1,24,24,61,62,24,61,53,62,24,53,24,
13,24,70,34,1,1,1,1,1,70,24,24,1,13,44,34,53,53,62,53,
13,62,13,13,13,62,44,13,13,13,44,13,34,13,44,44,61,24,61,13,
13,13,53,13,44,1,44,13,44,13,44,1,1,13,13,61,53,1,53,13,
53,1,53,1,24,1,53,24,61,24,61,24,1,24,24,61,13,44,13,53,
44,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,24,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,1,1,24,44,1,1,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,1,24,1,1,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53, };
static unsigned short stb__consolas_bold_10_latin_ext_a[560]={ 88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
88,88,88,88,88,88,88,88, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT or STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_10_latin_ext(stb_fontchar font[STB_FONT_consolas_bold_10_latin_ext_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT][STB_FONT_consolas_bold_10_latin_ext_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_10_latin_ext_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_10_latin_ext_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_10_latin_ext_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_10_latin_ext_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_10_latin_ext_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_10_latin_ext_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_10_latin_ext_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_10_latin_ext_s[i] + stb__consolas_bold_10_latin_ext_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_10_latin_ext_t[i] + stb__consolas_bold_10_latin_ext_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_10_latin_ext_x[i];
            font[i].y0 = stb__consolas_bold_10_latin_ext_y[i];
            font[i].x1 = stb__consolas_bold_10_latin_ext_x[i] + stb__consolas_bold_10_latin_ext_w[i];
            font[i].y1 = stb__consolas_bold_10_latin_ext_y[i] + stb__consolas_bold_10_latin_ext_h[i];
            font[i].advance_int = (stb__consolas_bold_10_latin_ext_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_10_latin_ext_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_10_latin_ext_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_10_latin_ext_s[i] + stb__consolas_bold_10_latin_ext_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_10_latin_ext_t[i] + stb__consolas_bold_10_latin_ext_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_10_latin_ext_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_10_latin_ext_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_10_latin_ext_x[i] + stb__consolas_bold_10_latin_ext_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_10_latin_ext_y[i] + stb__consolas_bold_10_latin_ext_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_10_latin_ext_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_10_latin_ext
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_10_latin_ext_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_10_latin_ext_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_10_latin_ext_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_10_latin_ext_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_10_latin_ext_LINE_SPACING
#endif
