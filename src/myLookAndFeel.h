#pragma once
#include <JuceHeader.h>


//==============================================================================
class myLookAndFeel : public LookAndFeel_V4
{

public:
    myLookAndFeel();
    void setLookAndFeel(Image inputImage);
    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;

private:
    Image img;

};