/**
 * @file QuadEncoderX.h
 * @brief Quad encoder interface with calibration channel for Arduino and Mbed
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include <QuadEncoder.h>

class QuadEncoderX : public QuadEncoder
{
public:

	// Constructors and Destructors
	QuadEncoderX(
		DigitalIn* channel_A,
		DigitalIn* channel_B,
		DigitalIn* channel_X,
		float cnt_per_rev,
		bool wrap_angle = false);
	QuadEncoderX(
		Platform::pin_t pin_channel_A,
		Platform::pin_t pin_channel_B,
		Platform::pin_t pin_channel_X,
		float cnt_per_rev,
		bool wrap_angle = false);
	~QuadEncoderX();

	// Methods
	void interrupt_X();
	bool is_calibrated();
	float get_angle();
	void set_home();
	void set_home(float home_angle);

protected:

	// Fields
	DigitalIn* channel_X;
	bool calibrated;
	float home_angle;

	// Methods
	void zero();
};