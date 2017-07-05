// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_7_latin_ext_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_7_latin_ext'.
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

#define STB_FONT_arial_bold_7_latin_ext_BITMAP_WIDTH         256
#define STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT         52
#define STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT_POW2    64

#define STB_FONT_arial_bold_7_latin_ext_FIRST_CHAR            32
#define STB_FONT_arial_bold_7_latin_ext_NUM_CHARS            560

#define STB_FONT_arial_bold_7_latin_ext_LINE_SPACING           5

static unsigned int stb__arial_bold_7_latin_ext_pixels[]={
    0x40b98380,0x8181a849,0x42b81883,0x82828829,0x5d414c3c,0x0dcc1d40,
    0x221a82e6,0x2a054c2a,0x41988e61,0x5c03620a,0x0b84c261,0x7010aee6,
    0x12066098,0x5c41302e,0x0dcc1441,0x42988a13,0x220261a9,0x41cc1982,
    0x98cdc40b,0x20dcc59d,0x2a21c40a,0xb88a2a63,0xb88a2a63,0xa88a2a62,
    0x930a2a62,0x2a14ccc1,0x9506d41c,0x02ea0e5c,0xd98ae155,0x05751621,
    0x0a8541b7,0x10cddc75,0x82a0c985,0x9872609a,0x5c22a0a8,0xb307642b,
    0x334ae1b3,0x8a2a6131,0x8a6660ab,0x0a130899,0x3eb66117,0xb3b30392,
    0x2224c1b8,0x89a57098,0x89a57098,0x89a57098,0x99a57098,0x534ae59d,
    0x2b6a1b5b,0x2b6a910d,0x21b5b50d,0x26372dcb,0x4c930d9d,0x21ec0d9d,
    0xb922151b,0x4cbb53de,0x65c2a59d,0x21b3b32d,0x5b970d8c,0x475d136e,
    0x2571a89c,0x95c36326,0x95c772e6,0x95c36326,0x4e4b72e6,0xc8e573bc,
    0x7646ba81,0x95cae6e0,0x95cae6e6,0x95cae6e6,0x95cae6e6,0x34ae0726,
    0xa8e4ea39,0x9d472913,0x2e72751c,0x2a272372,0x544e45b1,0x546e06c1,
    0x3215c3a0,0x3900720b,0x46a27257,0x4ae725c9,0xddf50cbc,0x2b9e45dc,
    0x2572e4cd,0x95ceaae6,0xd2b97266,0x9db95cec,0x5c9bb12b,0x3a365472,
    0x5cae6e3a,0xb95cdcd2,0xb95cdcd2,0xb95cdcd2,0x2e395cd2,0x72b95cd2,
    0x2ba44ae5,0x995cae57,0x2ee372dd,0x5dc913c8,0x8dc343c8,0x6f5c910a,
    0x395cbd34,0xb96ecc2a,0x98ba3c8b,0x0d9b22dd,0x47b72239,0x71744de8,
    0x70ddb9a5,0x95c5d1a5,0x6dcb76a6,0x3622444d,0x543b2e4d,0x4b76a6ef,
    0x376a4de9,0x6d49bd32,0x549bd32d,0x49bd32dd,0x37a64dd8,0xd8937624,
    0x6ec52e4d,0xba937624,0x76ec771d,0x76ec1d11,0x23b116a1,0x4350770a,
    0x1526ec42,0xedd876ea,0x1dba8d31,0x882e0d75,0x234c4885,0x306e4de9,
    0x2634c9bd,0x076ea4de,0xd8000220,0x00000390,0x00000000,0x00260000,
    0x00621980,0x10260026,0x00c03043,0x20066040,0x04c19809,0x0c022188,
    0x00440026,0x02600098,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x9a800000,
    0x41305d40,0xa88260ba,0x91144c1b,0x23775041,0x21d41709,0x04c2ae1a,
    0x1c0e61d4,0x20986ee6,0x21437732,0x19848189,0x82440a98,0x804c2883,
    0x15428cc3,0x8884c5cc,0x43110ea0,0x1d413509,0x4cc28838,0x0ee0c41a,
    0x4cc130aa,0x226638a9,0x228cc6e2,0x5933910a,0x642e1c54,0x55c2f263,
    0x3506643c,0x0cdcaaee,0x1c54c2ee,0x0dfe82ee,0x9bb9cc6e,0x41cb86a6,
    0x0a2260c9,0x41cb8197,0x706540ca,0x2e289985,0x3356ccb6,0x32e39b5b,
    0x65c51331,0x82fa571d,0x3144cc39,0x356dc379,0x41cc982a,0x8a8ef21a,
    0x2695cd2b,0x1b9a571b,0x5c979937,0xb8993469,0x5771bae2,0x1de98dc5,
    0x955dc997,0x155dcd2b,0x371b89f9,0x5489736e,0x27661b5b,0x5b534ae5,
    0x436b6a1b,0x5b50dada,0x2570ae1b,0xca96f6e6,0x96a390ec,0x372dae1b,
    0x20f4ae55,0x72dae0ec,0x0d95cd37,0x34ddc779,0x97263b95,0x95cd2b9b,
    0x2695c6e6,0x7571771b,0x2b9a34dc,0x4779715c,0x546e1de9,0x4c7d7598,
    0x99a571de,0x2e26c1de,0x0f2ee191,0x1c9d472b,0xa8e4d2b8,0x8e4ea393,
    0x5cea393a,0x26e695c2,0xb962ea6d,0xb70dc572,0xb954dcb7,0x5c75d0d2,
    0x9736e5bd,0x97261b2b,0x2a725cdb,0x5cdcb973,0x2e695cd2,0x71b9a571,
    0x4dc17b95,0x5c5a9a56,0x8a874ae2,0x76cc6e59,0x22a1b373,0x8a9a5759,
    0x46e26c59,0x443a571b,0x95cae573,0x25734ae3,0x5cae572b,0x95cae572,
    0x9a573deb,0x16ec799b,0x22989bb1,0x11546d9b,0x6efa87db,0xcbb9b66e,
    0xcb9b2ae3,0xd98f2ee5,0x99b8aa0d,0x937a64de,0x5c9bd30b,0x87735910,
    0x1449b769,0xd9891066,0x24c3b13e,0x33ed986a,0x1f6cc9bd,0x8e235136,
    0xdd885448,0xe9937624,0x8937624d,0x937624dd,0x31544dd8,0x004889bd,
    0x266e0980,0x21b000c7,0x5cf3371c,0x570001d2,0x1b83003a,0x44008800,
    0x00880c40,0x08813062,0x204c1880,0x11000001,0x18110c18,0x00000000,
    0x44003000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x33030ea0,0x2e14c0a8,0x41a88aa2,
    0x350d443a,0x415c3330,0x1506222a,0x20d44150,0x5704d419,0x020d4288,
    0x11984c35,0x0ea04c39,0x2a833066,0x112b82aa,0x0ee15c11,0x4985506a,
    0x981a8188,0x50ae0cc1,0x0cc0e205,0x259930d4,0x2a0d45bb,0x1a8aee60,
    0x30545773,0x52654599,0x932bb983,0x32e1a817,0x57102a1d,0xb50a60b8,
    0x64732a1b,0x6426623b,0x8dc26623,0x0d47972a,0x4cc47115,0x84c13310,
    0x5c6a0a98,0xa94262b9,0x1330dc52,0x04cc28cc,0x5e4c7135,0x32639931,
    0x8813311c,0x26a62bbb,0x337705c0,0x6e543336,0x4ddcb771,0x8cddc6e1,
    0x466ee5bb,0x3b952dcb,0xabb8f72e,0xb9b932a6,0x3bc89952,0x5c2b8ef2,
    0x217930dc,0xc95cdc4c,0x8dcae6e4,0x0dc5d32a,0x5cdc7595,0x8dc57372,
    0x5c6e2b9b,0x46c6e2b9,0x4d7549dd,0x534ae1ab,0x1d6545d9,0x3a625d31,
    0x26e5d312,0x8cee642b,0x2ee5beb9,0x654f7ae5,0x66cea725,0x5c7bd70c,
    0x3367bd71,0x327bd70c,0x275392b8,0x6cae2b8c,0x54dc1190,0x5c981192,
    0x6c2b9726,0x1b8ae1ed,0x24d95cdc,0x73772b9b,0x0dc36e65,0x257371b6,
    0x5c6e2b9b,0x6d46e2b9,0x6d5c6e2d,0x5cd952bd,0x4fbd71dc,0x436c3bbc,
    0x92e25c4b,0x27622b9b,0x99d953de,0x15c33361,0x21bb305c,0x2e0ae5ca,
    0x25ca8571,0x996ecc2b,0x45bb30dd,0x17661d2b,0x2e2ecc76,0x2b972e5c,
    0xa8ae14e4,0x5a96ed45,0x755cb76a,0x0dc9d50e,0x25bb50ea,0x546e2dda,
    0x3506e2dd,0xebbe98dc,0x26e1d970,0x5cd1572a,0x2a1d40dd,0x516a2d45,
    0x2775c5bb,0xca97772e,0x18937ae5,0x24deb800,0x409bd71b,0x00004deb,
    0x06007bd7,0x3deb8000,0x000015c0,0x506e0c00,0x00dc0007,0x21b8606e,
    0x4dc0799f,0x401a572a,0xe9ef743a,0x07bdd3de,0x00bbd368,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x15c00000,0x7755502e,0x260cc198,
    0x30661540,0x5d41a885,0x88661c40,0x350aa208,0x44c14188,0x55106510,
    0x220d41a8,0x19808141,0x19838154,0x70a62088,0x44141981,0x104c1cc0,
    0x0541a853,0x83705066,0x22144089,0x20d45031,0x27eb2a2a,0xa82a0541,
    0xb8b3266b,0x06e21cc1,0x32bb9873,0x4772e597,0x15310988,0x4c442662,
    0x2f25b970,0x0d41a848,0x1a8150aa,0x3a2dc24c,0x1c41cc1c,0x350260d4,
    0x26542828,0xa886e0ea,0x2b886a21,0xbb82a05c,0x1a8b72a6,0x54839cc7,
    0xc932a3b9,0x26549bd1,0x73654b77,0x91aea337,0x3235d41d,0x5c66ee0e,
    0x2755719b,0x57372b9b,0x5cdcae6e,0x2e657392,0x4772a09a,0x3b951dca,
    0x6e54772a,0xdda83b21,0x1d90bd12,0x70e40ec8,0x772ddcb7,0x1192ddcb,
    0x9aea0ec8,0xa9aea6ba,0xba9aea6b,0xb9c96ae6,0x550eb2a2,0xa9c8b811,
    0x78dc1193,0x333608c8,0x3ae1d970,0xae8d953d,0x75d1b2a3,0xdeb9ef5c,
    0x26e1bb73,0x2e57372b,0x257372b9,0x65e42dd9,0x27275390,0x3275393a,
    0x475393a9,0x4ea723ae,0x1d746d9c,0x6c3b8eba,0x2199b0cc,0x199b0ccd,
    0x475d1766,0xa9b2a6ca,0xca9b2a6c,0xc9b9b2a6,0x6d85db32,0x9a98b350,
    0x44bb30dd,0x3665dedd,0x42e172a5,0xa8765c2b,0x43b2e6ef,0x70ae6efa,
    0x6ed41b85,0x36a5bb52,0x2a5bb52d,0x32e6a1db,0x3661bb30,0x261bb30d,
    0x21bb30dd,0x37666efa,0x2a1dbb50,0x9bbea6ef,0x4b951dca,0xa972a5ca,
    0xdf51545c,0xcb8765cd,0x2e1d970e,0x21d970ec,0x5b570ecb,0x941d42a8,
    0x0000385b,0x75c22000,0x0e43604d,0x75c721b0,0x229bd74d,0x98000000,
    0x00001041,0x0390d800,0x6c721b00,0x00044390,0x21b06000,0x0000001c,
    0x75022000,0x00000410,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x0c660000,0x14260c62,0x0ab866e2,
    0x4417106e,0x15302ea0,0x22981750,0x2a1c332a,0x50223281,0x443502a2,
    0x155026a0,0x0cc0404c,0x105c4373,0x26088455,0x5cc0ba81,0x26260540,
    0x44350a60,0x15ddc408,0x88081773,0xb986eea1,0x5098d40b,0x30e91028,
    0x99a570e7,0x55772fad,0xead98eae,0x36b6a330,0x9a851530,0x2a8aa1aa,
    0xcc98d415,0x20d8cb42,0x55cb5938,0x983a8665,0x87904dc3,0x1b3b32b9,
    0x22ca96aa,0x87751b8c,0x3b31aaba,0xd732dd4b,0x3505ccb7,0xb990bb2a,
    0x2355dc33,0xc986620d,0x31aaee0b,0xc87ef763,0x22aea089,0x57045540,
    0x33bc9c9a,0xc83763bd,0x8e4a6751,0x7516d73a,0x370dc511,0x3771b86e,
    0xa8b93683,0x3a61d591,0xd903b205,0x4c8ee5c1,0x44e4b72e,0x5db92e1a,
    0x26647272,0x0e4a2f2a,0xeca86c64,0x5c3970cc,0x6c477791,0x23763de9,
    0x2e1bd90d,0x417911dc,0x46e0d8dd,0x57447deb,0xaa859b86,0x3b734ae4,
    0x5d662a57,0x99dcd5c3,0x6dcae572,0x145d5c5b,0x21b8dc37,0x4a7bd71b,
    0x54490ba6,0x15436726,0x23ae875d,0x64573a9b,0x791772b8,0x219086c2,
    0x19371edc,0x2b945ddc,0xb972ce47,0x46e0dcbb,0x3bae0ddb,0x241d2c84,
    0x66c4aa6e,0x37074b20,0x35a1a2ae,0x254a2dca,0x6edc9bd3,0x6ecfb664,
    0x25fd910d,0x5c9bb13a,0x1d5cc6d9,0x4371b86e,0x4db8571b,0x1ed490d3,
    0xfa8c4bb5,0xb9bbea6e,0x6ccb50dd,0x547b762d,0x1c936a4d,0x2ae62ecc,
    0xd9937623,0x1b837004,0x25de9b40,0x3bb23deb,0x15c55371,0x2370f7ae,
    0x11ad0d2b,0x00044204,0x088c0000,0x003ccdc0,0x21b8dc37,0x209bd71b,
    0xd8000009,0x0e436390,0x20000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x88262a80,0x30994283,0x4c380981,0x4c4c2660,
    0x21c43511,0x11110889,0xa8098cc1,0x208888a2,0x86a04c1a,0x2a098622,
    0x26188981,0x32a88130,0x57730261,0x04c182e2,0x82e13044,0x5dcc6609,
    0x21553140,0x2994c519,0x38543773,0x3328a22a,0xbba8a28a,0x4cae2989,
    0x437318a8,0xb86ee6ab,0x4370dcc2,0x253571bb,0xca8ae1c9,0x777372bd,
    0x21cdb854,0x26e1511a,0x5e45312b,0x26130d43,0x3363b950,0x4b3772a1,
    0x1983371b,0xbb86ae15,0x2ddc9719,0x2e4ca857,0xa9aea3ca,0x2e4b5773,
    0x25b5cd53,0x3a62bb6b,0xd98eb2a2,0x2776362c,0xc99a2724,0x791dcb8b,
    0x6d527e76,0x2dc3bee5,0x2ed42aae,0xab8ae577,0x21b976a0,0x7370da9c,
    0x9bb8dc19,0xb8e5c6e5,0x23b972b9,0x370dc5c9,0xb9d4e46e,0x9b5391dc,
    0x2265c6e5,0x372e371b,0x9327bd71,0xc8570ccd,0x951bae08,0x5ccb954d,
    0x2e2a8b73,0x36b2e5bd,0x21b612e5,0x5eed5c6c,0x570eb262,0xa8ecaa6e,
    0xc8b11dcd,0xab85b1de,0x21571620,0x8b10ae1b,0x9837661b,0xdb8dc2dd,
    0x50dc6e4d,0x4aa6e5bb,0x370dc5cb,0xb86ecc6e,0xbbbb32aa,0x21f5c6e3,
    0x2a6e371b,0x2a2a8572,0xbb30ae5c,0xd971de5c,0xd0e5c661,0x26e2c3fb,
    0x56faae6d,0xe887505a,0x3aefa60e,0x4ae06f40,0x22372a9b,0x897ba78f,
    0x5cf7ae1d,0x5cbdd3de,0x3deb86e1,0x000dcbdd,0x205dc6e0,0x9b80371b,
    0x370dc02a,0x2a9b806e,0x1b371b80,0x5371b8dc,0x15537ae5,0xb80f7ae0,
    0xb95401d2,0x2e2c5882,0x27e6e799,0x3a87bdd5,0x27e2cd64,0x2b85c879,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x80000000,0x730d4428,0x205dcc37,0x4c6ee62a,0x19837730,
    0x21888a13,0x03330cbb,0x31108888,0x18884431,0x2318c222,0xb8630a89,
    0x8dc40c82,0x11054111,0x13331440,0x41514c66,0x44266639,0xb8ccc531,
    0x0a80a861,0xaaa8e651,0xdb8aa130,0x5c2aaa1b,0x32000001,0xbb96ae0e,
    0xa9aaee69,0x213772ba,0x4cd3771b,0xcb9a572e,0x5da96b24,0xd9901322,
    0x65c6e1d7,0x2763971d,0x549d149f,0xcb8f545d,0x4643b70c,0x263bd50d,
    0x85dc7751,0x26911bba,0x2a5a9364,0x2f2732db,0x5c269590,0x4572190d,
    0x99826110,0x11044209,0x004ccc15,0x3ae80000,0x4b9b7344,0x70d81b2b,
    0x75c6e19b,0x75caa24d,0xdc8fae7d,0x3cb8b10f,0x864e4e40,0x2e55371b,
    0x547736a1,0xda8be0ec,0x64c3710b,0x644b930d,0x0c4bb00a,0x64ea3dd9,
    0x0ee19553,0x847528aa,0x00021980,0x00000000,0x77d40000,0xcbb83626,
    0x55074ae3,0x2e37055c,0x5caa0e8a,0x4366e68a,0x717ba088,0x9c844447,
    0x2e370c8c,0x7c4372a9,0x3ab20878,0x0440a030,0xa954083d,0x0000002a,
    0x00000000,0x00000000,0x86c00000,0x2e1dd91c,0x0f7ae1d2,0x46e15c55,
    0xb9545deb,0x000000d2,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_bold_7_latin_ext_x[560]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,-1,0,0,0,0,-1,-1,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,-1,0,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,-1,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0, };
static signed short stb__arial_bold_7_latin_ext_y[560]={ 5,0,0,0,0,0,0,0,0,0,0,1,4,2,
4,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,1,0,1,0,1,0,1,0,0,
0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,2,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,0,0,1,0,
0,0,0,0,0,1,1,2,0,-1,0,0,0,0,0,1,0,2,5,0,0,1,0,0,0,1,-1,-1,-1,-1,
-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,1,0,-1,-1,-1,-1,-1,0,0,0,0,
0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,
-1,0,-1,0,0,1,-1,0,-1,0,-1,0,-1,0,-1,0,0,0,-1,0,-1,0,-1,0,0,1,-1,0,-1,0,
-1,0,-1,0,0,-1,-1,-1,0,0,-1,0,-1,0,-1,0,0,0,-1,1,0,0,-1,0,0,0,1,-1,-1,0,
0,0,0,0,0,0,0,-1,0,0,1,-1,0,0,0,1,-1,0,-1,0,-1,0,0,1,-1,0,0,1,-1,0,
-1,0,-1,0,0,1,-1,0,0,0,-1,0,0,0,-1,0,-1,0,-1,0,-1,0,-1,0,0,1,-1,0,-1,0,
-1,-1,0,-1,0,-1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,
1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,0,-1,0,-1,
0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,-2,-1,-1,0,-1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1, };
static unsigned short stb__arial_bold_7_latin_ext_w[560]={ 0,2,3,4,4,6,5,2,2,2,3,4,2,2,
2,3,4,3,4,4,4,4,4,4,4,4,2,2,4,4,4,4,7,5,5,5,5,4,4,5,5,2,3,5,
4,5,5,5,4,5,5,4,4,5,6,6,5,6,4,2,3,2,4,5,2,4,4,4,4,4,3,4,4,2,
3,4,2,6,4,4,4,4,3,4,3,4,4,5,4,4,4,3,2,3,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,2,4,4,4,4,
2,4,3,6,3,4,4,2,6,5,3,4,2,2,2,4,5,2,2,2,3,4,6,6,6,4,5,5,5,5,
5,5,7,5,4,4,4,4,3,2,3,3,6,5,5,5,5,5,5,4,5,5,5,5,5,6,4,4,4,4,
4,4,4,4,6,4,4,4,4,4,3,2,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
5,4,5,4,5,4,5,4,5,4,5,4,5,4,5,5,6,4,4,4,4,4,4,4,4,4,4,4,5,4,
5,4,5,4,5,4,5,4,5,4,3,3,3,3,3,3,2,2,2,2,5,3,4,3,5,4,4,4,2,4,
3,4,3,4,3,4,2,5,4,5,4,5,4,5,5,4,5,4,5,4,5,4,7,6,5,3,5,3,5,3,
4,4,4,4,4,4,4,4,4,3,4,4,4,3,5,4,5,4,5,4,5,4,5,4,5,4,6,5,6,4,
6,4,4,4,4,4,4,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,4,5,4,4,4,
4,4,4,4,4,4,4,4,4,4,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,6,5,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,3,3,5,
4,5,4,5,4,5,4,5,4,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,5,4,7,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4, };
static unsigned short stb__arial_bold_7_latin_ext_h[560]={ 0,5,3,6,6,6,6,3,7,7,3,4,3,2,
1,6,6,5,5,6,5,6,6,5,6,6,4,6,4,3,4,5,7,5,5,6,5,5,5,6,5,5,6,5,
5,5,5,6,5,6,5,6,5,6,5,5,5,5,5,7,6,7,3,2,2,5,6,5,6,5,5,6,5,5,
7,5,5,4,4,5,6,6,4,5,6,5,4,4,4,6,4,7,7,7,2,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,6,7,6,4,5,
7,7,2,6,3,4,3,2,6,2,3,5,3,3,2,6,7,2,2,3,3,4,6,6,6,6,6,6,6,6,
6,6,5,7,6,6,6,6,6,6,6,6,5,6,7,7,7,7,7,4,6,7,7,7,7,6,5,6,6,6,
6,6,6,6,5,6,6,6,6,6,5,5,5,5,6,5,6,6,6,6,6,4,5,6,6,6,6,7,7,7,
6,6,6,6,7,6,7,6,7,6,7,6,7,6,6,6,5,6,6,6,6,6,6,6,7,6,6,6,7,7,
7,7,7,7,7,8,6,6,5,5,6,5,6,5,6,5,7,7,6,4,6,7,7,7,7,7,4,6,6,7,
7,5,5,5,5,5,5,6,5,7,6,6,5,5,6,6,7,6,7,6,7,6,6,5,6,5,7,6,6,5,
7,6,7,6,7,6,7,6,7,7,6,6,5,6,7,6,7,6,7,6,7,6,7,6,7,6,6,5,6,7,
6,6,5,6,5,6,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,4,4,7,4,4,4,
4,4,4,4,4,4,4,4,4,4,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,6,5,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,6,6,5,7,
6,7,6,7,7,7,7,7,7,7,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,7,7,6,6,7,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4, };
static unsigned short stb__arial_bold_7_latin_ext_s[560]={ 255,189,182,16,51,101,144,193,102,111,189,
133,186,196,232,94,176,43,7,143,197,148,158,202,103,98,138,108,123,150,113,
24,25,1,37,170,18,154,29,137,47,34,85,178,168,213,207,46,192,37,12,
27,251,15,244,237,231,224,219,123,252,103,161,226,214,184,123,173,132,163,159,
96,149,146,148,137,134,78,88,117,71,233,93,101,128,91,128,97,108,89,63,
132,152,155,221,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,255,43,164,
32,58,20,175,199,217,58,166,68,170,196,163,208,146,216,158,155,202,153,92,
199,205,175,178,141,245,8,1,162,156,150,192,117,111,133,201,12,66,61,34,
80,76,73,69,65,209,52,150,144,138,132,114,103,21,126,161,81,1,238,78,
228,223,218,213,208,203,198,181,187,182,177,172,167,110,114,106,142,139,96,128,
123,118,113,108,118,196,91,86,81,76,244,233,222,55,50,44,39,204,29,169,
19,18,6,120,249,79,239,233,227,231,217,212,207,202,24,193,188,159,178,173,
168,136,118,126,178,183,194,210,1,115,110,242,122,94,238,85,192,76,74,13,
22,56,85,45,33,37,62,51,71,53,11,253,156,98,48,44,30,40,25,6,
214,221,167,196,190,1,248,226,244,91,222,112,183,106,1,11,127,220,87,105,
186,237,188,87,232,76,1,66,248,57,6,46,42,21,26,226,36,16,31,7,
40,249,66,238,71,227,80,216,89,98,9,59,189,126,133,15,138,35,143,53,
58,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,173,73,73,142,
73,73,73,73,73,73,73,73,73,73,73,73,73,179,62,73,73,73,73,73,
73,73,73,73,73,73,73,73,201,68,73,73,73,73,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,208,105,
198,83,97,243,85,148,73,68,62,57,51,46,40,35,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,
73,73,73,29,24,153,161,6,121,73,73,73,73,73,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73, };
static unsigned short stb__arial_bold_7_latin_ext_t[560]={ 1,39,45,18,18,25,25,45,10,10,45,
45,45,45,45,32,32,45,45,32,39,32,32,39,32,32,45,32,45,45,45,
45,10,45,45,32,45,39,45,32,45,45,32,39,39,39,39,32,39,32,45,
32,39,32,39,39,39,39,39,1,25,1,45,45,45,39,32,39,32,39,39,
25,39,39,1,39,39,45,45,39,25,25,45,39,32,39,45,45,45,32,45,
1,1,1,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,
45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,1,32,1,
32,45,39,1,1,45,32,45,45,45,45,32,45,45,32,45,45,45,32,10,
45,45,45,45,45,25,32,32,25,25,25,25,32,32,25,32,1,25,25,25,
32,32,32,32,32,32,32,10,10,10,10,10,45,32,10,10,10,10,25,39,
25,25,25,25,25,25,25,32,25,25,25,25,25,39,39,39,39,25,39,25,
25,25,25,25,45,32,25,25,25,25,1,1,1,25,25,25,25,1,25,1,
25,1,25,10,17,1,17,17,17,32,17,17,17,17,25,17,17,1,17,17,
18,1,1,1,1,1,1,1,1,18,18,32,39,18,32,18,32,18,39,10,
10,18,45,18,10,10,10,10,10,45,18,10,10,10,39,39,39,39,39,39,
10,32,10,10,10,39,32,10,17,1,17,1,17,1,25,25,39,10,39,10,
10,10,32,10,10,10,18,10,10,10,18,10,10,18,18,32,18,10,18,10,
18,1,18,1,18,1,18,1,18,18,39,18,1,18,18,39,18,39,18,39,
39,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,10,45,45,1,
45,45,45,45,45,45,45,45,45,45,45,45,45,10,39,45,45,45,45,45,
45,45,45,45,45,45,45,45,10,39,45,45,45,45,45,45,45,45,45,45,
45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,10,18,
17,39,1,10,1,18,1,1,1,1,1,1,1,1,45,45,45,45,45,45,
45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,
45,45,45,1,1,18,18,1,18,45,45,45,45,45,45,45,45,45,45,45,
45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,
45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,
45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,
45,45,45,45,45,45,45,45,45, };
static unsigned short stb__arial_bold_7_latin_ext_a[560]={ 28,33,48,56,56,89,72,24,
33,33,39,59,28,33,28,28,56,56,56,56,56,56,56,56,
56,56,33,33,59,59,59,61,98,72,72,72,72,67,61,78,
72,28,56,72,61,84,72,78,67,78,72,67,61,72,67,95,
67,67,61,33,28,33,59,56,33,56,61,56,61,56,33,61,
61,28,28,56,28,89,61,61,61,61,39,56,33,61,56,78,
56,56,50,39,28,39,59,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,28,33,56,56,56,56,28,56,
33,74,37,56,59,33,74,55,40,55,33,33,33,58,56,28,
33,33,37,56,84,84,84,61,72,72,72,72,72,72,100,72,
67,67,67,67,28,28,28,28,72,72,78,78,78,78,78,59,
78,72,72,72,72,67,67,61,56,56,56,56,56,56,89,56,
56,56,56,56,28,28,28,28,61,61,61,61,61,61,61,55,
61,61,61,61,61,56,61,56,72,56,72,56,72,56,72,56,
72,56,72,56,72,56,72,72,72,61,67,56,67,56,67,56,
67,56,67,56,78,61,78,61,78,61,78,61,72,61,72,61,
28,28,28,28,28,28,28,28,28,28,79,56,56,28,72,56,
56,61,28,61,28,61,39,61,48,61,28,72,61,72,61,72,
61,71,72,61,78,61,78,61,78,61,100,95,72,39,72,39,
72,39,67,56,67,56,67,56,67,56,61,33,61,48,61,33,
72,61,72,61,72,61,72,61,72,61,72,61,95,78,67,56,
67,61,50,61,50,61,50,28,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,73,75,75,56,75,75,75,75,75,
75,75,75,75,75,75,75,75,86,71,75,75,75,75,75,75,
75,75,75,75,75,75,75,83,73,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,72,56,28,28,78,61,72,61,72,61,72,
61,72,61,72,61,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,72,56,100,89,78,61,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT or STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_7_latin_ext(stb_fontchar font[STB_FONT_arial_bold_7_latin_ext_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT][STB_FONT_arial_bold_7_latin_ext_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_7_latin_ext_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_7_latin_ext_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_7_latin_ext_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_7_latin_ext_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_7_latin_ext_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_7_latin_ext_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_7_latin_ext_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_7_latin_ext_s[i] + stb__arial_bold_7_latin_ext_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_7_latin_ext_t[i] + stb__arial_bold_7_latin_ext_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_7_latin_ext_x[i];
            font[i].y0 = stb__arial_bold_7_latin_ext_y[i];
            font[i].x1 = stb__arial_bold_7_latin_ext_x[i] + stb__arial_bold_7_latin_ext_w[i];
            font[i].y1 = stb__arial_bold_7_latin_ext_y[i] + stb__arial_bold_7_latin_ext_h[i];
            font[i].advance_int = (stb__arial_bold_7_latin_ext_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_7_latin_ext_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_7_latin_ext_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_7_latin_ext_s[i] + stb__arial_bold_7_latin_ext_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_7_latin_ext_t[i] + stb__arial_bold_7_latin_ext_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_7_latin_ext_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_7_latin_ext_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_7_latin_ext_x[i] + stb__arial_bold_7_latin_ext_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_7_latin_ext_y[i] + stb__arial_bold_7_latin_ext_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_7_latin_ext_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_7_latin_ext
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_7_latin_ext_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_7_latin_ext_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_7_latin_ext_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_7_latin_ext_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_7_latin_ext_LINE_SPACING
#endif

