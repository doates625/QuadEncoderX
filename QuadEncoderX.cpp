/**
 * @file QuadEncoderX.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "QuadEncoderX.h"
#include <CppUtil.h>

/**
 * @brief Constructs quad encoder interface
 * @param pin_channel_A ID of channel A input
 * @param pin_channel_B ID of channel B input
 * @param pin_channel_X ID of channel X input
 * @param cnt_per_rev Resolution [counts per revolution]
 * @param wrap_angle Wraps angle to range [-pi, +pi] if true
 */
QuadEncoderX::QuadEncoderX(
	Platform::pin_t pin_channel_A,
	Platform::pin_t pin_channel_B,
	Platform::pin_t pin_channel_X,
	float cnt_per_rev,
	bool wrap_angle) :
	QuadEncoder(pin_channel_A, pin_channel_B, cnt_per_rev, wrap_angle),
	channel_X(pin_channel_X)
{
	this->calibrated = false;
	this->home_angle = 0.0f;
}

/**
 * @brief Pin rise/fall ISR for channel X
 */
void QuadEncoderX::interrupt_X()
{
	counts = 0;
	calibrated = true;
}

/**
 * @brief Returns calibration status
 */
bool QuadEncoderX::is_calibrated()
{
	return calibrated;
}

/**
 * @brief Returns encoder angle [rad]
 * 
 * Note: Briefly globally disables interrupts
 */
float QuadEncoderX::get_angle()
{
	Platform::disable_interrupts();
	int32_t counts_copy = counts;
	Platform::enable_interrupts();
	float angle = counts_copy * rad_per_cnt - home_angle;
	if (wrap_angle)
	{
		angle = CppUtil::wrap(angle, -M_PI, +M_PI);
	}
	return angle;
}

/**
 * @brief Sets home angle to current angle
 */
void QuadEncoderX::set_home()
{
	set_home(0.0f);
	set_home(get_angle());
}

/**
 * @brief Sets home angle to given angle
 * @param home_angle Home angle [rad]
 */
void QuadEncoderX::set_home(float home_angle)
{
	this->home_angle = home_angle;
}
