# QuadEncoderX
Quad encoder interface with calibration channel for Arduino and Mbed  
Written by Dan Oates (WPI Class of 2020)

### Description
This class extends the QuadEncoder class (see dependencies) with a third X channel, which goes high once per rotation to allow for absolute angle calibration. Additional methods relating to absolute angle calibration are included.

### Dependencies
- [Platform](https://github.com/doates625/Platform.git)
- [QuadEncoder](https://github.com/doates625/QuadEncoder.git)
- [DigitalIn](https://github.com/doates625/DigitalIn.git)
- [CppUtil](https://github.com/doates625/CppUtil.git)
