// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_8_latin_ext_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_8_latin_ext'.
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

#define STB_FONT_arial_bold_8_latin_ext_BITMAP_WIDTH         256
#define STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT         64
#define STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT_POW2    64

#define STB_FONT_arial_bold_8_latin_ext_FIRST_CHAR            32
#define STB_FONT_arial_bold_8_latin_ext_NUM_CHARS            560

#define STB_FONT_arial_bold_8_latin_ext_LINE_SPACING           5

static unsigned int stb__arial_bold_8_latin_ext_pixels[]={
    0x53033310,0x88388110,0xa8180980,0x0a02a209,0x44155026,0x4c40980a,
    0x19881981,0x03102204,0x0440406a,0x44062044,0x44133310,0x220cc400,
    0x021105c0,0x088220e4,0x44221102,0x982b8110,0x05022222,0x47318981,
    0x4540efed,0x035065c0,0x22153019,0x432e0a8a,0x2e60a9a8,0x54151510,
    0x41515109,0x04e44448,0x320ec032,0x20570aa4,0x76c3981a,0x0aa1d43e,
    0x1eeeba7c,0x0d8150ba,0x2a82e154,0x641a8837,0x8f74caa4,0x5ceed73b,
    0x73511544,0x444aeaa1,0xa889608b,0x16a0ee88,0x6443bbb6,0x0360aa5b,
    0x4b9dc66e,0x4b9dc66e,0x4b9dc66e,0x4b9dc66e,0xb9dcdbd3,0x445ddd14,
    0xa9622eee,0xdb0fbb62,0xbade447d,0x15bc88a5,0x72fe8b79,0x32268339,
    0xa87bb60e,0x9547bb62,0xc8f76c58,0x3aa55498,0x27768ee1,0x2771644b,
    0x2e57554b,0x3b8ea973,0x45a87797,0x2ee1fb4a,0x4c1bb169,0xbac5542f,
    0x562aa973,0x22aa973b,0x5552e775,0x552e7758,0x2e770a9d,0x4b9a2974,
    0x2551e8d1,0x8a5b8a5b,0xd17969bb,0x5da6ee1d,0xd725469b,0xbb96a1dd,
    0xb866951c,0x0cc66953,0x7719a54d,0x75ecee57,0x73bb4772,0x5cee2c89,
    0x4ee59774,0xb9dc574b,0x322d43bc,0x1591e9cb,0xcc8f666d,0x3bb45dc5,
    0x5da2ee97,0x5a2ee973,0x22ee973b,0xeb92e776,0x652e770e,0x3d1e47a3,
    0x1792a96c,0x3a2f21dd,0x2ad1590e,0x22b21f35,0x2c8d1596,0xcc93212e,
    0x4ee07919,0xc9a0883c,0x770ee883,0xd1dd2b6e,0x8b21dd2a,0x32ee973b,
    0x1652e772,0x87ab2e77,0x3457545a,0x332ed9b1,0xbb83a3e3,0x5cee9568,
    0x4ee9568b,0x2e9568bb,0x52ad1773,0x54b6553b,0x3456a774,0x2689a2b5,
    0x43e6b52a,0x3621f35a,0x893fae6c,0x8d9d36cd,0x8bbbae1d,0xaccbbe66,
    0xaaccee3a,0x59962553,0x4772ec75,0x8b4771fa,0x5b170eee,0x9773ba54,
    0x3a9dd2a5,0x4439dd2a,0x51776dc2,0x5376eb57,0x3a63eeea,0x21fdd16c,
    0xfdd16ce9,0x745b3a61,0x2d9d30fe,0xdd10fee8,0x83fba21d,0x77642eec,
    0x322a96a2,0x277644ee,0x42a8b575,0xb5755aba,0x743883d4,0x43bb20e1,
    0x43bb22d8,0xeec8552a,0xa85c3d30,0x1aa172cc,0x220eea89,0x4b620fee,
    0x4b10fee8,0x8890fee8,0x02aa0043,0x000d11d8,0x00000000,0x50000000,
    0x40000cc1,0x202a20aa,0xa82aa0aa,0x21982a01,0x30051000,0x214c00a3,
    0x5288aa28,0x40001985,0x00050028,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x21a88110,
    0x33103108,0x06044098,0x26011044,0x11011009,0x2a091060,0x0102b809,
    0x2620a02a,0x214c4001,0x44088808,0x40884409,0x88818818,0x02601500,
    0x08110135,0x84181998,0x20540440,0x04c41880,0x099a8932,0xfd87d197,
    0x31dc1c6e,0x70aa885f,0x32a16607,0x1b7a64db,0x440aa853,0xd82a883b,
    0x175511ee,0x7f75c0b8,0x40b812e2,0x05cdc43b,0x956b8591,0x2e22164c,
    0x220ea608,0x845c443c,0xa87904a8,0x71045c43,0x9917e6d4,0x21d41288,
    0x155510db,0x52e77154,0xbfe83dcb,0x3b87bb64,0x93191732,0xde98b76e,
    0x2f326e66,0x32153b53,0x4dbd3498,0x76c2eee8,0xb8cd2a3e,0x3bba2973,
    0x9725d2e2,0x5c5ddd10,0x52e772bb,0x3ee2eee8,0x5ddd14ab,0xdd14b9dc,
    0x1777445d,0x6f5d2e77,0x5433262e,0x9a55aa92,0x56ab50cc,0x2ad50cc9,
    0x23b87324,0x71dc973b,0x1f7dd2e7,0x34aa5f54,0x1d1f1dc3,0x8cb95ddc,
    0x642a76a6,0x75c91d59,0x2a57770e,0x22970a9d,0x0f2296e6,0x14ba5cee,
    0x706ff5cd,0xb9a29709,0xba5cee5e,0x5f65cd14,0x3b9a2974,0x73452e97,
    0x973b9a29,0x59725cee,0x7d5a2ee1,0x215974ab,0x2b2eb33a,0x2e957f50,
    0x3b8ee68b,0x2771dc97,0x03f1974b,0x5c0f2979,0x447ddd53,0x71e770ee,
    0x22eb21dd,0x4b65529e,0x3bae0ee8,0xbc8f4790,0x2ab30ee8,0x1e52e773,
    0x83e32e3d,0x47a3c84b,0x2e770edb,0xbb8f4794,0x8f4794fa,0xe8f2973b,
    0x3b8f4791,0x837fae97,0xd1773eb8,0x5c52faea,0x4566753e,0x97d753eb,
    0x5c7734b2,0x951dc973,0x86ba5cee,0x8eab34bc,0xb1a23b3b,0x551f75cb,
    0x766d5cb6,0xd83bba22,0x5a96caa5,0x0f9ad4d1,0xba543bb2,0x4b9a2b53,
    0x8777dcd7,0x55dcd15a,0xad4ee954,0xaa6cee68,0x3ba54d15,0x15a9a2b5,
    0x773ba54d,0x8eed41f1,0xf5756ce9,0x5d4776a9,0x23bb52ea,0xbd14faba,
    0x2e951dc5,0x77445b13,0xbc80640f,0x3a83bb24,0x770f4c90,0x641ddd10,
    0x0dc2c99a,0x777443d3,0xd90bbb20,0x7445709d,0x0bbb20fe,0x32126032,
    0xd11cc2ee,0x177641fd,0x8bbb2064,0x3b20fee8,0x1177642e,0x54ee1fdd,
    0x9b3a8005,0x6cea0000,0xe8865c04,0x400510fe,0x00666029,0x298d402a,
    0x54c0004c,0x0a614c0a,0x2a200000,0x02980000,0x01a80035,0x00029800,
    0x00000000,0x00000000,0x00054c00,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x08020000,0x40000350,0x0a0a2088,0x22088804,0x22604881,0x10444880,
    0x04422210,0x06a0a031,0x866020aa,0x81a82208,0x28811020,0x260840c8,
    0x15408819,0x88088082,0x80a80280,0x28044099,0x71038944,0x5cc17510,
    0x1cc3322a,0x4c1986ae,0xab84cd81,0x15308e62,0x20a8b882,0x47709998,
    0x37bb7a27,0x82e62554,0x2ea20aa8,0xbdd10cc0,0x2a771dc1,0xed85316c,
    0x47ba65ae,0x33310ab8,0x0321cec1,0x65c550ee,0xb84b838a,0x5100a624,
    0x03262111,0x21288879,0x6447b71a,0x3fb21dcd,0x2a15db0d,0xcc83b692,
    0xd03a8ee1,0x2a92a879,0x23ea3a92,0x916cf24a,0x4f1dcb67,0x2e11993b,
    0x2e1fdb73,0xfdb70fed,0x2a511dc1,0xb53b8ee4,0x22951dc7,0x3b876e4f,
    0xdfb4a9dc,0x36217ccb,0xbab8ee0d,0x2a1cc80c,0x0bb7ae92,0x5cf77fa2,
    0x17911dde,0x5772d9e4,0x6e544d77,0x12e2cc69,0xb92ed177,0x3a8ee68b,
    0x2e19fe88,0x2d17768b,0x42cadcac,0x25be85be,0xd72c9e3b,0x07b0ee7b,
    0x3b87b07b,0x3b9bbbf2,0x8ee254ee,0xed887a3c,0x32e59971,0x419934b8,
    0x1e4c45cc,0x55cd4477,0xbb9a2ee1,0x212e7768,0x97089eac,0x2165dc11,
    0x372ee5be,0x2fb32e69,0x70ea2cc3,0x2c972d17,0x90751dcd,0x45dc5f55,
    0x32ad1776,0x7d40ec9e,0x2ee0fa80,0x43ca54f3,0x1321323b,0x498ee132,
    0x2b51dcb5,0x2b51dc3c,0xba5d4c68,0x9dbd768c,0x1d693fb6,0x0771e65c,
    0x6964b919,0x7f5da2ee,0x6f47c40d,0x21bbd72d,0x07d41bcc,0x545bd577,
    0x2cc3dedd,0x6ce983a6,0x8b7a21d3,0x3660ea3b,0x5b3a65de,0x2bf16ce9,
    0xd106886e,0x224edbb8,0x775efded,0x2e1ae1ae,0xeec87706,0xded88ee0,
    0x37b21dc0,0x3b8f74c2,0x8ca54eed,0xb8ffbea5,0x710ee4dd,0x22de8976,
    0xf1776ce9,0x40feeb81,0x41dd983b,0x0001dc68,0x00000166,0x0777d477,
    0x6cfa0000,0x0d106884,0xfe9dc000,0x3ddfd1ee,0x3b87bbfa,0x5c007700,
    0x77044003,0x204a9dda,0x7700d11d,0xb8000208,0xdd0e8b53,0x0bbbee9d,
    0x00771a20,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x08800000,0x44c08838,0x804cc0c1,0x40880440,
    0x2004409a,0x02201008,0x08804301,0x40880882,0x4c402030,0x10040100,
    0x40441110,0x44008040,0x80804000,0x00002000,0x54082041,0x05c44350,
    0x40b988ae,0x10aea21a,0x0b7a61f9,0x41d4433a,0x8550e64b,0x2642bac8,
    0x415c5316,0x37a6953b,0x03221dc5,0x3730bbb6,0x7447ddb0,0x0f6ec2ee,
    0x1065c337,0xb1582987,0x3204dc1b,0x22065c0c,0x6ecc2983,0xee983aa0,
    0x56a3db10,0x21456a28,0xd70bc899,0x42f223bb,0xbb11ddeb,0x44777ae1,
    0x422ee6bc,0x3ae2ebc8,0x21b910ed,0x41b910ed,0x3223bb9b,0x6e44320d,
    0x9dc3b970,0x4453b54a,0x50be60dd,0x85f31a29,0xd14b8a4a,0x25519a4c,
    0x49552554,0x57489255,0x320e6457,0x320e641c,0x390e641c,0x1126e457,
    0x4826ea3b,0xb838c987,0x1972cbbb,0xcb965dc1,0x5cf26208,0x9a6ee08c,
    0x1a6ee3ed,0x4ddd2a77,0x0cddc971,0x9bb8cc97,0x8cddcaa1,0x54ee68cb,
    0x4c43bae4,0x5917323c,0xc8b990f4,0xe8f21bb3,0xd1770770,0x45dda2ee,
    0x954d1776,0xd1773aac,0x177345dc,0x77345dcd,0xaa76d4d1,0xc8ecc79c,
    0x226662dd,0x43151531,0xd71bccbb,0x46f321bb,0x9970ddeb,0x64377ae7,
    0x5912a68a,0x2b33b8d1,0x647518ac,0x2ee6e18a,0x48862b23,0x34ee3159,
    0xd954ee95,0xeb479972,0x83ea7660,0xf8ad41d6,0x599a2b50,0x5da2ee75,
    0x2d17768b,0x5c3268bb,0xc9a592ba,0x326964d2,0x226964d2,0x99a572b9,
    0x893753a8,0x47938793,0x771dd9bb,0x0ee3bb30,0x41dd376e,0x3bb66de9,
    0x3b8d9d34,0x4cbb6297,0x445db10e,0x3b621bbc,0x72ed8ac2,0x777447db,
    0x2e1ddd10,0x7fdf54dd,0xf50efec8,0x4eec87fd,0x3b216f64,0x26d9d30e,
    0x2d9d36ce,0xd8966ce9,0x445bd10d,0x8b7a22de,0x37a22de8,0x6c437a62,
    0x4437a62d,0x3262a1dd,0xb9726665,0x05ddf703,0x701777dc,0x00005ddf,
    0x000defb8,0x00000000,0x11d80000,0x11d84c0d,0x0000000d,0x00000000,
    0x00000000,0x81040800,0x00000ee0,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x08811000,0x81440c18,
    0x02204408,0x04060220,0x0802a011,0x02022200,0x41021011,0x981c0cc0,
    0x44044408,0x38818808,0x8040a800,0x88860440,0x50888880,0x44372279,
    0x6404444c,0x0730441c,0x8965d411,0x531320aa,0xf88381a8,0xaa88aa3e,
    0x44c89910,0x3ba6d029,0x75910481,0x550774c5,0x7712c815,0xa8776ec1,
    0x4c3b8515,0x21d6441b,0x41ca82aa,0x2ee20c88,0x5c440c82,0x853032a0,
    0x0d98d44a,0xb9eeff44,0x2233770c,0x3b7ae0bc,0x88907320,0x232e4c83,
    0x32217916,0x2217910b,0x50be60bc,0x886ec43b,0x21bb10dd,0x1bb10dd8,
    0x6dddaf22,0x5e417cc1,0x4b2ee3bb,0x22c8956a,0x07e52a3b,0xf30ee0e9,
    0x21ddeb85,0x42f982f9,0xbd71ddeb,0x2e17cc3b,0x87d51dde,0xa8b2ea2a,
    0xeac87952,0x56477089,0x5c597718,0x9a2ee953,0x2a0f23ca,0xcbbb4ee2,
    0x2ee59772,0x6459772c,0x89e64c5c,0x279313c9,0x79313c98,0x4ddcf262,
    0xcc83d576,0x19acbb85,0x2fea1dd3,0x4771644a,0x261e9cac,0x90ee1a99,
    0x408cb8b9,0x45cc85cc,0x232e08cb,0x32e2e640,0x8ee17208,0x5cee68cb,
    0x37a3e20c,0x76c4572d,0x76c37992,0xb9a5959a,0x7702970c,0x379969dc,
    0x5e646f32,0xeb437991,0x65d26260,0x2e79973c,0x279973cc,0xd1593ccb,
    0x3ad1a2ae,0x91dc5e40,0x2faea755,0x1dc59174,0x270d15d5,0x3ad0ee49,
    0x68377ae0,0x5c1d681d,0xbbd70dde,0x3ae0eb41,0x770990dd,0x5cee69dc,
    0x207f75c3,0xbb324448,0xd14b9dc3,0x5951dc5b,0x36a83b8b,0x477663bb,
    0x3bb31dd9,0xe98ffbea,0x2e9bb71d,0x29bb74dd,0x9bb74ddb,0x6dddb7a6,
    0x10ffbea5,0x6f4c3779,0x2a9f5751,0xda8ee0ee,0x744542de,0xfefa8ee2,
    0x3bea0ee3,0x8ffbea3f,0xfa83b83b,0x2a0ee3fe,0x5c770eef,0x42b9dcd3,
    0x2a9ddd0e,0x7dc00d41,0x215c00de,0x541dc0a9,0x3b000001,0x000001a2,
    0x23b00000,0x9d400068,0x011dc04d,0x23b82208,0x77dcd11d,0xd9a23b2e,
    0x777dcd11,0x365ddf72,0x777dcd11,0x00000002,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00800000,0x00664c11,0x37044440,0x88932291,0x2001bb10,
    0xba8e6408,0x5502222c,0x5e440892,0x80404110,0x10208208,0x13882201,
    0x02022041,0x64104411,0x01111388,0x04101001,0x99104082,0x08876ea9,
    0x21139822,0xcc820880,0xb8ee0b10,0x910750ac,0xc86ff649,0x21bb158a,
    0x479314cb,0x2a3b8d3a,0xb9a32e92,0xd1770ede,0x59770eec,0x91176f76,
    0x55641707,0x80cb82e4,0xa9dca22c,0x47112e1d,0x33f70aa8,0x64aeee5f,
    0x4d6e0dfe,0x499b31ee,0xab547d3a,0x4ddc3e24,0x9dcd1976,0x2e114fec,
    0x953b8573,0xacb8b2ea,0x75c4770d,0x30aa0753,0x3159ac8b,0x65c6ee79,
    0x2a1cea3c,0x9dda2ee2,0xbba54ee6,0x64b32e68,0xb95b91bc,0xb72a9ba4,
    0x5c3ba63b,0x1dbd71dd,0xb9c4776e,0x2a2a8775,0xdb8aa2cb,0x8db12ebb,
    0x89ae5459,0x54d1133b,0x55fd43dc,0x455c3b64,0x43b9a776,0x7573b80d,
    0x5d2e32e5,0x9dcf468c,0x23bb56bb,0x31dc49ba,0xaef647db,0x5c773ccb,
    0x5c0ea4dd,0x9dda2ee3,0x4d66bb66,0x5a32e6ce,0xdbd71dd9,0x86df5649,
    0x53bf26a8,0x96cee6a8,0x9e5266a8,0x1971dc3b,0xbb771dcd,0x16626c59,
    0x740e8962,0x750fbea1,0x436ea97d,0x7dd76de8,0xa4c751dc,0x75cbb73b,
    0xd1a774ed,0x910ee751,0x543b81d4,0x376e1645,0x54530774,0x674c7703,
    0x2e770e26,0x334ee484,0x264a9dc3,0x83a66dcd,0x41d34eec,0x1d30eefb,
    0x8773cacc,0x7734ee3b,0x995f755c,0xac42cc1e,0x2a1c41e8,0x2aea0f8c,
    0x88bfdd4f,0x64770576,0xdb9dca20,0x5d2a770e,0x73a8e8d3,0x3bea1a87,
    0x8b30ee0e,0x503b8009,0xb83bbea1,0x7dc1a803,0x770a80de,0x54ee171a,
    0xfd26cfc4,0xdfd1dc5d,0x3bfa12e5,0x1dcee312,0x5cd3b8ee,0x4af32ae3,
    0x58859829,0x22cc9ff9,0xd9d4b73a,0x099406c4,0x3b81a3b8,0x54ee9557,
    0x00000004,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x64408844,0x2010224b,0x22001110,0x44044408,
    0x82222088,0x04444088,0x04204102,0x44220841,0x990410dc,0x2f220883,
    0x9936f720,0x127320cc,0xa4aa1111,0x32550dd8,0x88c0aa0c,0x018260cc,
    0x83b9b910,0x408aa3db,0x55570440,0x55462a04,0x2e55732b,0xe9b4ddc3,
    0x2b50be61,0x0750edeb,0x3ae1dbd7,0x977ae2ed,0xbd70fedb,0x8777ae3d,
    0xb8ec5b3c,0x951f51d3,0x9bb8f56a,0x2ee7dd91,0x9771d468,0x36be72e5,
    0x2ee15972,0x8bb804e8,0x2ee79316,0x5bb50be8,0x9855275c,0x6d42faa1,
    0xd3b9513c,0x27735dd4,0x641952bb,0x25a9ba25,0x4bd70dc9,0x59972a88,
    0x0f6da2b2,0x77498b99,0x9dc1d52a,0xb92e772d,0x65c7b00c,0x011972c8,
    0x1d4a8b7d,0x8b2b72b2,0x462b24dd,0x9a593aab,0x37995ffc,0x88e5fcae,
    0x07e593eb,0x65da2ee0,0x43d1773c,0x81d91cda,0x893ff63b,0xccb9f66d,
    0x9a7723be,0x9263953b,0x99ba1cd8,0x6dcb950c,0x8cb9dc0e,0x12ad9b16,
    0x774983ad,0x75c1d566,0x1bfd70ee,0x1321f75c,0x3ae3dbd7,0x207d40dd,
    0x3b2a68f8,0x83ea0ec9,0x7dd92ed8,0x4750b7a2,0xbdb11dd9,0x4776a1bb,
    0xd3002de8,0x4d376ed9,0x541a86be,0x4330ee4e,0x77950beb,0xa8f7b76a,
    0x540ee2de,0x3253330b,0xac8533cb,0x32695771,0x5cda773b,0x77d4955a,
    0xb9dca23f,0x70970754,0x41dc1f17,0x2b53b86b,0x6c1a203b,0x3757e23d,
    0x2080b9d1,0x00008800,0x08888000,0x3ff60000,0x110ee184,0x00000004,
    0x00000000,0x54d3b9dc,0x88ec950b,0x6f7dd266,0x2e1ddf50,0x5cb53b83,
    0x71eefe83,0x3bee5ddf,0xfa83442e,0x324d9f40,0x000005b3,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x08b6b6ea,
    0x2cba8626,0x08f2a082,0x9ba4e232,0x2e3bb72a,0x49bb74dd,0x04277040,
    0x42220891,0x11110a60,0x4ee19998,0x0000003b,0x00000000,0x00000000,
    0x00000000,0xb5770000,0x6c4732d1,0x2ad1970d,0x432e3b55,0x257771da,
    0x510dbeac,0x888d54cd,0x32bdb968,0xa9eb2332,0x319b8e21,0xccc832e5,
    0x00155544,0x00000000,0x00000000,0x00000000,0x00000000,0x96a4d5c0,
    0x3b966c57,0x772cda4d,0x26e886d4,0x3a66dcd9,0x121332e0,0x24d40541,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x49ab8000,
    0x23a9862d,0x0998cd3b,0x7c4c8057,0x0bbfa4d9,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__arial_bold_8_latin_ext_x[560]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
static signed short stb__arial_bold_8_latin_ext_y[560]={ 6,0,0,0,0,0,0,0,0,0,0,1,5,3,
5,0,0,0,0,0,0,0,0,0,0,0,2,2,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,2,0,2,0,2,0,2,0,0,
0,0,0,2,2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,0,2,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,2,0,0,1,0,
0,0,0,0,0,2,2,3,0,-1,0,1,0,0,0,2,0,3,6,0,0,2,0,0,0,2,-1,-1,-1,-1,
-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,1,0,-1,-1,-1,-1,-1,0,0,0,0,
0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,0,
-1,1,-1,0,0,2,-1,0,-1,0,-1,0,-1,0,-1,0,0,0,-1,1,-1,0,-1,0,0,2,-1,0,-1,0,
-1,0,-1,0,0,0,-1,-1,0,0,-1,0,-1,1,-1,0,0,0,-1,2,0,0,-1,0,0,0,2,-1,-1,0,
0,0,0,0,0,0,0,-1,0,0,2,-1,0,0,0,2,-1,1,-1,0,-1,0,0,2,-1,0,0,2,-1,0,
-1,0,-1,0,0,2,-1,0,0,0,-1,0,0,0,-1,0,-1,1,-1,0,-1,0,-1,0,0,2,-1,0,-1,0,
-1,-1,0,-1,0,-1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,
1,1,1,1,1,1,1,1,1,1,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0,2,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,0,-1,0,-1,
0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,-2,-1,-1,0,-1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1, };
static unsigned short stb__arial_bold_8_latin_ext_w[560]={ 0,2,4,4,4,7,6,2,3,3,3,4,2,3,
2,3,4,3,4,4,4,4,4,4,4,4,2,2,4,4,4,5,7,6,5,5,5,5,5,6,5,2,4,6,
5,6,5,6,5,6,6,5,5,5,6,7,5,6,5,3,3,2,4,6,2,4,5,4,4,4,3,4,4,2,
3,4,2,6,4,5,5,4,3,4,3,4,4,6,4,4,4,3,2,3,4,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,2,4,4,4,4,
2,4,3,7,3,4,4,3,7,6,3,4,3,3,3,4,5,2,3,2,3,4,6,6,6,5,6,6,6,6,
6,6,8,5,5,5,5,5,3,2,4,4,6,5,6,6,6,6,6,4,6,5,5,5,5,6,5,5,4,4,
4,4,4,4,7,4,4,4,4,4,3,3,4,4,5,4,5,5,5,5,5,4,5,4,4,4,4,4,5,4,
6,4,6,4,6,5,5,4,5,4,5,4,5,4,5,6,6,5,5,4,5,4,5,4,5,4,5,4,6,4,
6,4,6,4,6,4,5,4,6,4,4,4,4,4,4,4,2,2,2,2,6,4,5,4,6,4,4,5,3,5,
3,5,3,5,3,5,2,5,4,5,4,5,4,6,5,4,6,5,6,5,6,5,7,7,6,3,6,3,6,3,
5,4,5,4,5,4,5,4,5,3,5,4,5,3,5,4,5,4,5,4,5,4,5,4,5,5,7,6,6,4,
6,5,4,5,4,5,4,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,7,6,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,4,4,4,6,
5,5,4,5,4,5,4,5,4,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,6,4,8,7,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5, };
static unsigned short stb__arial_bold_8_latin_ext_h[560]={ 0,6,3,7,7,7,7,3,8,8,4,5,3,2,
1,7,7,6,6,7,6,7,7,6,7,7,4,6,5,3,5,6,8,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,7,6,7,6,7,6,6,6,6,6,8,7,8,4,2,2,5,7,5,7,5,6,6,6,6,
8,6,6,4,4,5,6,6,4,5,7,5,4,4,4,6,4,8,8,8,3,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,6,8,7,5,6,
8,8,2,7,4,4,3,2,7,2,4,5,4,4,2,6,8,1,2,4,4,4,7,7,7,6,7,7,7,7,
7,7,6,8,7,7,7,7,7,7,7,7,6,7,8,8,8,8,8,5,7,8,8,8,8,7,6,7,7,7,
7,7,7,7,5,6,7,7,7,7,6,6,6,6,7,6,7,7,7,7,7,5,5,7,7,7,7,8,8,8,
7,6,7,7,8,6,8,7,8,7,8,7,8,7,7,7,6,7,7,6,7,7,7,7,8,6,7,7,8,8,
8,8,8,8,8,8,7,7,6,6,7,6,7,5,7,6,8,8,7,4,7,8,8,8,8,8,4,7,7,8,
8,6,6,6,6,6,6,7,6,8,6,7,6,6,7,6,8,6,8,7,8,7,7,5,7,6,8,6,7,6,
8,7,8,7,8,6,8,7,9,9,7,7,6,7,8,7,8,6,8,7,8,7,8,7,8,6,7,6,7,8,
7,7,6,7,6,7,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,5,5,8,5,5,5,
5,5,5,5,5,5,5,5,5,5,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,7,7,7,6,8,
7,8,7,8,8,8,8,8,8,8,8,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,8,8,7,7,8,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5, };
static unsigned short stb__arial_bold_8_latin_ext_s[560]={ 255,25,75,178,162,200,51,69,246,188,33,
121,72,95,116,178,182,186,190,228,214,28,233,233,84,217,253,238,179,54,194,
195,69,18,65,152,28,71,53,138,249,230,95,201,34,168,208,145,40,124,46,
106,180,100,84,91,99,77,59,1,85,214,229,106,92,162,94,105,58,126,14,
9,4,1,175,244,241,1,17,115,224,219,29,139,63,157,37,42,234,175,49,
160,109,105,64,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,
151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,255,143,164,
40,110,122,185,206,88,72,25,243,59,95,76,99,221,174,225,239,84,39,29,
113,80,22,8,12,238,112,245,239,21,69,124,144,137,163,199,108,151,170,157,
131,252,253,119,100,222,89,120,91,191,171,184,199,105,178,198,114,152,246,132,
63,23,53,48,43,38,33,204,212,16,11,6,1,191,182,245,163,222,1,211,
205,199,193,187,189,212,173,168,163,158,83,57,52,131,44,117,112,45,53,35,
89,192,80,179,67,169,58,52,45,80,34,28,217,17,12,6,1,154,98,235,
241,101,18,112,138,119,126,131,143,172,167,103,93,149,28,137,184,126,65,211,
203,105,218,90,235,223,11,22,147,248,45,41,134,41,59,49,22,13,176,146,
243,158,165,75,221,186,6,232,250,158,229,140,249,94,35,97,131,219,235,127,
208,204,195,79,227,88,238,77,17,63,211,5,1,15,21,33,31,16,26,5,
70,250,216,240,63,229,58,217,87,68,110,83,198,76,114,117,108,127,120,138,
149,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,131,151,151,148,
151,151,151,151,151,151,151,151,151,151,151,151,151,154,144,151,151,151,151,151,
151,151,151,151,151,151,151,151,142,167,151,151,151,151,151,151,151,151,151,151,
151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,183,190,
195,153,98,208,85,214,73,68,62,57,51,46,40,35,151,151,151,151,151,151,
151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,
151,151,151,28,23,226,7,11,1,151,151,151,151,151,151,151,151,151,151,151,
151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,
151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,
151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,
151,151,151,151,151,151,151,151,151, };
static unsigned short stb__arial_bold_8_latin_ext_t[560]={ 10,51,58,20,20,20,20,58,1,1,58,
51,58,58,58,28,28,44,44,28,44,36,28,44,36,28,51,44,51,58,51,
44,10,51,51,28,51,51,51,28,44,44,36,44,51,44,44,28,51,28,51,
28,44,28,51,51,51,51,51,11,28,1,51,58,58,51,28,51,36,51,51,
51,51,51,1,44,44,58,58,51,44,44,58,51,28,51,58,58,51,44,58,
1,1,1,58,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,10,44,1,
28,51,44,1,1,58,28,58,51,58,58,36,58,51,51,51,51,58,44,10,
58,58,58,58,58,28,36,28,36,36,36,36,36,36,36,36,10,36,36,36,
36,28,20,36,36,36,36,10,1,10,10,10,51,36,10,10,10,10,20,44,
36,28,36,36,36,36,36,51,36,36,36,36,36,36,36,36,44,28,44,28,
28,28,28,28,51,51,28,28,28,28,10,10,10,28,44,28,28,10,44,10,
28,1,28,1,28,1,28,28,28,44,28,28,36,28,28,28,28,1,44,20,
20,10,1,1,1,1,1,1,1,20,20,44,44,20,44,20,51,20,44,1,
1,20,51,20,1,1,10,10,10,51,20,20,10,10,44,44,44,44,36,44,
10,44,10,44,10,36,44,10,36,10,36,10,10,10,20,20,51,20,36,10,
36,10,36,1,10,10,10,10,44,10,10,1,1,20,20,44,20,10,20,11,
44,1,10,1,20,1,20,1,44,20,44,20,1,20,20,44,20,44,20,44,
44,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,20,51,51,1,
51,51,51,51,51,51,51,51,51,51,51,51,51,20,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,20,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,20,20,
20,44,1,20,1,20,1,1,1,1,1,1,1,1,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,1,1,20,20,1,20,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51, };
static unsigned short stb__arial_bold_8_latin_ext_a[560]={ 32,38,54,64,64,102,83,27,
38,38,45,67,32,38,32,32,64,64,64,64,64,64,64,64,
64,64,38,38,67,67,67,70,112,83,83,83,83,76,70,89,
83,32,64,83,70,95,83,89,76,89,83,76,70,83,76,108,
76,76,70,38,32,38,67,64,38,64,70,64,70,64,38,70,
70,32,32,64,32,102,70,70,70,70,45,64,38,70,64,89,
64,64,57,45,32,45,67,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,32,38,64,64,64,64,32,64,
38,84,42,64,67,38,84,63,46,63,38,38,38,66,64,32,
38,38,42,64,96,96,96,70,83,83,83,83,83,83,115,83,
76,76,76,76,32,32,32,32,83,83,89,89,89,89,89,67,
89,83,83,83,83,76,76,70,64,64,64,64,64,64,102,64,
64,64,64,64,32,32,32,32,70,70,70,70,70,70,70,63,
70,70,70,70,70,64,70,64,83,64,83,64,83,64,83,64,
83,64,83,64,83,64,83,82,83,70,76,64,76,64,76,64,
76,64,76,64,89,70,89,70,89,70,89,70,83,70,83,70,
32,32,32,32,32,32,32,32,32,32,90,64,64,32,83,64,
64,70,32,70,32,70,44,70,55,70,32,83,70,83,70,83,
70,81,83,70,89,70,89,70,89,70,115,108,83,45,83,45,
83,45,76,64,76,64,76,64,76,64,70,38,70,55,70,38,
83,70,83,70,83,70,83,70,83,70,83,70,108,89,76,64,
76,70,57,70,57,70,57,32,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,83,86,86,64,86,86,86,86,86,
86,86,86,86,86,86,86,86,98,81,86,86,86,86,86,86,
86,86,86,86,86,86,86,95,83,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,83,64,32,32,89,70,83,70,83,70,83,
70,83,70,83,70,86,86,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,
86,86,83,64,115,102,89,70,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,
86,86,86,86,86,86,86,86, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT or STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_8_latin_ext(stb_fontchar font[STB_FONT_arial_bold_8_latin_ext_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT][STB_FONT_arial_bold_8_latin_ext_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_8_latin_ext_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_8_latin_ext_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_8_latin_ext_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_8_latin_ext_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_8_latin_ext_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_8_latin_ext_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_8_latin_ext_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_8_latin_ext_s[i] + stb__arial_bold_8_latin_ext_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_8_latin_ext_t[i] + stb__arial_bold_8_latin_ext_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_8_latin_ext_x[i];
            font[i].y0 = stb__arial_bold_8_latin_ext_y[i];
            font[i].x1 = stb__arial_bold_8_latin_ext_x[i] + stb__arial_bold_8_latin_ext_w[i];
            font[i].y1 = stb__arial_bold_8_latin_ext_y[i] + stb__arial_bold_8_latin_ext_h[i];
            font[i].advance_int = (stb__arial_bold_8_latin_ext_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_8_latin_ext_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_8_latin_ext_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_8_latin_ext_s[i] + stb__arial_bold_8_latin_ext_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_8_latin_ext_t[i] + stb__arial_bold_8_latin_ext_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_8_latin_ext_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_8_latin_ext_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_8_latin_ext_x[i] + stb__arial_bold_8_latin_ext_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_8_latin_ext_y[i] + stb__arial_bold_8_latin_ext_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_8_latin_ext_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_8_latin_ext
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_8_latin_ext_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_8_latin_ext_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_8_latin_ext_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_8_latin_ext_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_8_latin_ext_LINE_SPACING
#endif
