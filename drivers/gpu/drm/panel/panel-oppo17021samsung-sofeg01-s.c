// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct oppo17021samsung_sofeg01_s {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data oppo17021samsung_sofeg01_s_supplies[] = {
	{ .supply = "vddio" },
	{ .supply = "vddneg" },
	{ .supply = "vddpos" },
	{ .supply = "oledb" },
};

static inline
struct oppo17021samsung_sofeg01_s *to_oppo17021samsung_sofeg01_s(struct drm_panel *panel)
{
	return container_of_const(panel, struct oppo17021samsung_sofeg01_s, panel);
}

static void oppo17021samsung_sofeg01_s_reset(struct oppo17021samsung_sofeg01_s *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(2000, 3000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(12000, 13000);
}

static int oppo17021samsung_sofeg01_s_on(struct oppo17021samsung_sofeg01_s *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfc, 0x5a, 0x5a);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe8, 0x64, 0x08, 0x0c);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfc, 0xa5, 0xa5);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x01);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xed, 0x04);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0x5a, 0x5a);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0x01);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x01);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0x12);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x2c);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc,
				     0xb4, 0x03, 0x05, 0x05, 0xff, 0x02, 0x00,
				     0x00, 0xff, 0x00, 0xff, 0xff, 0xf0, 0x00,
				     0xf0, 0xe0, 0xce, 0x0f, 0xff, 0xfa, 0xff);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x42);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0x03);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x4b);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0x49);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xa5, 0xa5);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x20);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x0000);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_POWER_SAVE, 0x00);
	mipi_dsi_usleep_range(&dsi_ctx, 1000, 2000);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int oppo17021samsung_sofeg01_s_off(struct oppo17021samsung_sofeg01_s *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 40);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int oppo17021samsung_sofeg01_s_prepare(struct drm_panel *panel)
{
	struct oppo17021samsung_sofeg01_s *ctx = to_oppo17021samsung_sofeg01_s(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(oppo17021samsung_sofeg01_s_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	oppo17021samsung_sofeg01_s_reset(ctx);

	ret = oppo17021samsung_sofeg01_s_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(oppo17021samsung_sofeg01_s_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int oppo17021samsung_sofeg01_s_unprepare(struct drm_panel *panel)
{
	struct oppo17021samsung_sofeg01_s *ctx = to_oppo17021samsung_sofeg01_s(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = oppo17021samsung_sofeg01_s_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(oppo17021samsung_sofeg01_s_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode oppo17021samsung_sofeg01_s_mode = {
	.clock = (1080 + 112 + 20 + 96) * (2160 + 20 + 2 + 4) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 112,
	.hsync_end = 1080 + 112 + 20,
	.htotal = 1080 + 112 + 20 + 96,
	.vdisplay = 2160,
	.vsync_start = 2160 + 20,
	.vsync_end = 2160 + 20 + 2,
	.vtotal = 2160 + 20 + 2 + 4,
	.width_mm = 73,
	.height_mm = 146,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int oppo17021samsung_sofeg01_s_get_modes(struct drm_panel *panel,
						struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &oppo17021samsung_sofeg01_s_mode);
}

static const struct drm_panel_funcs oppo17021samsung_sofeg01_s_panel_funcs = {
	.prepare = oppo17021samsung_sofeg01_s_prepare,
	.unprepare = oppo17021samsung_sofeg01_s_unprepare,
	.get_modes = oppo17021samsung_sofeg01_s_get_modes,
};

static int oppo17021samsung_sofeg01_s_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int oppo17021samsung_sofeg01_s_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops oppo17021samsung_sofeg01_s_bl_ops = {
	.update_status = oppo17021samsung_sofeg01_s_bl_update_status,
	.get_brightness = oppo17021samsung_sofeg01_s_bl_get_brightness,
};

static struct backlight_device *
oppo17021samsung_sofeg01_s_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 1023,
		.max_brightness = 1023,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &oppo17021samsung_sofeg01_s_bl_ops, &props);
}

static int oppo17021samsung_sofeg01_s_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct oppo17021samsung_sofeg01_s *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct oppo17021samsung_sofeg01_s, panel,
				   &oppo17021samsung_sofeg01_s_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(oppo17021samsung_sofeg01_s_supplies),
					    oppo17021samsung_sofeg01_s_supplies,
					    &ctx->supplies);
	if (ret < 0)
		return ret;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO_BURST | MIPI_DSI_MODE_VIDEO_HSE |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = oppo17021samsung_sofeg01_s_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void oppo17021samsung_sofeg01_s_remove(struct mipi_dsi_device *dsi)
{
	struct oppo17021samsung_sofeg01_s *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id oppo17021samsung_sofeg01_s_of_match[] = {
	{ .compatible = "mdss,oppo17021samsung-sofeg01-s" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, oppo17021samsung_sofeg01_s_of_match);

static struct mipi_dsi_driver oppo17021samsung_sofeg01_s_driver = {
	.probe = oppo17021samsung_sofeg01_s_probe,
	.remove = oppo17021samsung_sofeg01_s_remove,
	.driver = {
		.name = "panel-oppo17021samsung-sofeg01-s",
		.of_match_table = oppo17021samsung_sofeg01_s_of_match,
	},
};
module_mipi_dsi_driver(oppo17021samsung_sofeg01_s_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for oppo17021samsung sofeg01_s 1080p cmd mode dsi panel");
MODULE_LICENSE("GPL");
