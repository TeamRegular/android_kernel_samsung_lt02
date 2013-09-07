#ifndef OV2659_H_
#define OV2659_H_

#include <linux/types.h>
#include <media/v4l2-chip-ident.h>
#include <media/v4l2-common.h>
#include <media/soc_camera.h>

#define	OV2659_END_ADDR	0xFFFF
#define	OV2659_END_VAL	0xFF

struct ov2659 {
	struct v4l2_subdev subdev;
	int model;	/* V4L2_IDENT_OV5642* codes from v4l2-chip-ident.h */
	struct v4l2_rect rect;
	u32 pixfmt;
	int res_idx;
	int fmt_is_jpeg;
	struct i2c_client *client;
	struct soc_camera_device icd;
};

struct ov2659_datafmt {
	enum v4l2_mbus_pixelcode	code;
	enum v4l2_colorspace		colorspace;
};

struct regval_list {
	u16 reg_num;
	unsigned char value;
};

struct regval_list init_global_tab[] = {
	{0x3000, 0x0f},
	{0x3001, 0xff},
	{0x3002, 0xff},
	{0x0100, 0x01},
	{0x3633, 0x3d},
	{0x3620, 0x02},
	{0x3631, 0x11},
	{0x3612, 0x04},
	{0x3630, 0x20},
	{0x4702, 0x02},
	{0x370c, 0x34},

	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x00},
	{0x3804, 0x06},
	{0x3805, 0x5f},
	{0x3806, 0x04},
	{0x3807, 0xb7},
	{0x3808, 0x03},
	{0x3809, 0x20},
	{0x380a, 0x02},
	{0x380b, 0x58},
	{0x380c, 0x05},
	{0x380d, 0x14},
	{0x380e, 0x02},
	{0x380f, 0x68},
	{0x3811, 0x08},
	{0x3813, 0x02},
	{0x3814, 0x31},
	{0x3815, 0x31},

	{0x3a00, 0x38},
	{0x3a02, 0x02},
	{0x3a03, 0x68},
	{0x3a08, 0x00},
	{0x3a09, 0x5c},
	{0x3a0a, 0x00},
	{0x3a0b, 0x4d},
	{0x3a0d, 0x08},
	{0x3a0e, 0x06},
	{0x3a14, 0x02},
	{0x3a15, 0x28},
	{0x3a05, 0x30},

	{0x3a02, 0x07},
	{0x3a03, 0x30},
	{0x3a14, 0x07},
	{0x3a15, 0x30},

	{0x3623, 0x00},
	{0x3634, 0x76},
	{0x3701, 0x44},
	{0x3702, 0x18},
	{0x3703, 0x24},
	{0x3704, 0x24},
	{0x3705, 0x0c},

	{0x3208, 0x01},
	{0x3702, 0x18},
	{0x3703, 0x24},
	{0x3704, 0x24},
	{0x3208, 0x11},

	{0x3208, 0x02},
	{0x3702, 0x30},
	{0x3703, 0x48},
	{0x3704, 0x48},
	{0x3208, 0x12},

	{0x3820, 0x81},
	{0x3821, 0x01},

	{0x370a, 0x52},
	{0x4608, 0x00},
	{0x4609, 0x80},
	{0x4300, 0x32},
	{0x5086, 0x02},

	{0x5000, 0xff},

	{0x5001, 0x1f},

	{0x5002, 0x00},

	{0x3a0f, 0x38},
	{0x3a10, 0x30},
	{0x3a1b, 0x38},
	{0x3a1e, 0x30},
	{0x3a11, 0x70},
	{0x3a1f, 0x18},
	{0x5060, 0x69},
	{0x5061, 0x7d},
	{0x5062, 0x7d},
	{0x5063, 0x69},
	{0x3a18, 0x00},
	{0x3a19, 0x3e},

	{0x500c, 0x03},
	{0x500d, 0x20},
	{0x500e, 0x02},
	{0x500f, 0x5c},
	{0x5010, 0x48},
	{0x5011, 0x00},
	{0x5012, 0x66},
	{0x5013, 0x03},
	{0x5014, 0x30},
	{0x5015, 0x02},
	{0x5016, 0x7c},
	{0x5017, 0x40},
	{0x5018, 0x00},
	{0x5019, 0x66},
	{0x501a, 0x03},
	{0x501b, 0x10},
	{0x501c, 0x02},
	{0x501d, 0x7c},
	{0x501e, 0x3a},
	{0x501f, 0x00},
	{0x5020, 0x66},

	{0x5035, 0x6a},
	{0x5036, 0x11},
	{0x5037, 0x92},
	{0x5038, 0x21},
	{0x5039, 0xe1},
	{0x503a, 0x01},
	{0x503c, 0x05},
	{0x503d, 0x08},
	{0x503e, 0x08},
	{0x503f, 0x64},
	{0x5040, 0x58},
	{0x5041, 0x2a},
	{0x5042, 0xc5},
	{0x5043, 0x2e},
	{0x5044, 0x3a},
	{0x5045, 0x3c},
	{0x5046, 0x44},
	{0x5047, 0xf8},
	{0x5048, 0x08},
	{0x5049, 0x70},
	{0x504a, 0xf0},
	{0x504b, 0xf0},

	{0x5025, 0x09},
	{0x5026, 0x19},
	{0x5027, 0x2f},
	{0x5028, 0x45},
	{0x5029, 0x5a},
	{0x502a, 0x69},
	{0x502b, 0x75},
	{0x502c, 0x7e},
	{0x502d, 0x88},
	{0x502e, 0x96},
	{0x502f, 0xa3},
	{0x5030, 0xaf},
	{0x5031, 0xc4},
	{0x5032, 0xd7},
	{0x5033, 0xe8},
	{0x5034, 0x20},

	{0x5070, 0x1d},
	{0x5071, 0x5e},
	{0x5072, 0x05},
	{0x5073, 0x20},
	{0x5074, 0x94},
	{0x5075, 0xb4},
	{0x5076, 0xb4},
	{0x5077, 0xaf},
	{0x5078, 0x05},
	{0x5079, 0x98},
	{0x507a, 0x21},

	{0x506e, 0x44},
	{0x5064, 0x08},
	{0x5065, 0x10},
	{0x5066, 0x12},
	{0x5067, 0x02},
	{0x506c, 0x08},
	{0x506d, 0x10},
	{0x506f, 0xa6},
	{0x5068, 0x08},
	{0x5069, 0x10},
	{0x506a, 0x04},
	{0x506b, 0x12},

	{0x3406, 0x00},

	{0x507e, 0x40},
	{0x507f, 0x20},
	{0x507b, 0x06},
	{0x507a, 0x01},
	{0x5084, 0x0c},
	{0x5085, 0x3e},
	{0x5005, 0x80},

	{0x3003, 0x80},
	{0x3004, 0x10},
	{0x3005, 0x18},
	{0x3006, 0x0d},

	{0x5051, 0x40},
	{0x5052, 0x40},
	{0x5053, 0x40},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_SVGA_tab[] = {
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x00},
	{0x3804, 0x06},
	{0x3805, 0x5f},
	{0x3806, 0x04},
	{0x3807, 0xb7},
	{0x3808, 0x03},
	{0x3809, 0x20},
	{0x380a, 0x02},
	{0x380b, 0x58},
	{0x380c, 0x05},
	{0x380d, 0x14},
	{0x380e, 0x02},
	{0x380f, 0x68},
	{0x3811, 0x08},
	{0x3813, 0x02},
	{0x3814, 0x31},
	{0x3815, 0x31},


	{0x3623, 0x00},
	{0x3634, 0x76},
	{0x3701, 0x44},
	{0x3208, 0xa1},
	{0x3705, 0x0c},

	{0x3820, 0x81},
	{0x3821, 0x01},

	{0x370a, 0x52},
	{0x4608, 0x00},
	{0x4609, 0x80},
	{0x5002, 0x10},
	{0x3503, 0x00},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_UXGA_tab[] = {
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x00},
	{0x3804, 0x06},
	{0x3805, 0x5f},
	{0x3806, 0x04},
	{0x3807, 0xbb},
	{0x3808, 0x06},
	{0x3809, 0x40},
	{0x380a, 0x04},
	{0x380b, 0xb0},
	{0x380c, 0x07},
	{0x380d, 0x9f},
	{0x380e, 0x04},
	{0x380f, 0xd0},
	{0x3811, 0x10},
	{0x3813, 0x06},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3623, 0x00},
	{0x3634, 0x44},
	{0x3701, 0x44},
	{0x3208, 0xa2},
	{0x3705, 0x18},
	{0x3820, 0x80},
	{0x3821, 0x00},
	{0x370a, 0x12},
	{0x4608, 0x00},
	{0x4609, 0x80},
	{0x5002, 0x00},
	{0x3005, 0x24},
	{0x3004, 0x20},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_480P_tab[] = {
	{0x3808, 0x02},
	{0x3809, 0xD0},
	{0x380a, 0x01},
	{0x380b, 0xe0},
	{0x4609, 0xa0},
	{0x5002, 0x10},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_VGA_tab[] = {
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x00},
	{0x3804, 0x06},
	{0x3805, 0x5f},
	{0x3806, 0x04},
	{0x3807, 0xb7},
	{0x3808, 0x02},
	{0x3809, 0x80},
	{0x380a, 0x01},
	{0x380b, 0xe0},
	{0x380c, 0x05},
	{0x380d, 0x14},
	{0x380e, 0x02},
	{0x380f, 0x68},
	{0x3811, 0x08},
	{0x3813, 0x02},
	{0x3814, 0x31},
	{0x3815, 0x31},
	{0x3623, 0x00},
	{0x3634, 0x76},
	{0x3701, 0x44},
	{0x3208, 0xa1},
	{0x3705, 0x0c},
	{0x3820, 0x81},
	{0x3821, 0x01},
	{0x370a, 0x52},
	{0x4608, 0x00},
	{0x4609, 0xa0},
	{0x5002, 0x10},
	{0x3005, 0x18},
	{0x3004, 0x10},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_QVGA_tab[] = {
	{0x3808, 0x01},
	{0x3809, 0x40},
	{0x380a, 0x00},
	{0x380b, 0xf0},
	{0x4609, 0xa0},
	{0x5002, 0x10},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_CIF_tab[] = {
	{0x3808, 0x01},
	{0x3809, 0x60},
	{0x380a, 0x01},
	{0x380b, 0x20},
	{0x4609, 0xa0},
	{0x5002, 0x10},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_QCIF_tab[] = {
	{0x3808, 0x00},
	{0x3809, 0xb0},
	{0x380a, 0x00},
	{0x380b, 0x90},
	{0x4609, 0xa0},
	{0x5002, 0x10},

	{OV2659_END_ADDR, OV2659_END_VAL}
};

struct regval_list yuv_240_160_tab[] = {
	{0x3808, 0x00},
	{0x3809, 0xf0},
	{0x380a, 0x00},
	{0x380b, 0xa0},
	{0x3811, 0x2d},
	{0x3813, 0x28},
	{0x3814, 0x71},
	{0x3815, 0x71},
	{0x4609, 0xa0},
	{0x5002, 0x10},

	{OV2659_END_ADDR, OV2659_END_VAL}
};
#endif