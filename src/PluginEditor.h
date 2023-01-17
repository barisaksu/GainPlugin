/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"
#include "myLookAndFeel.h"

//==============================================================================
class GainpluginAudioProcessorEditor : public juce::AudioProcessorEditor,
                                       public juce::Slider::Listener,
                                       public juce::Button::Listener {
 public:
  GainpluginAudioProcessorEditor(GainpluginAudioProcessor &);
  ~GainpluginAudioProcessorEditor() override;

  //==============================================================================
  void paint(juce::Graphics &) override;
  void resized() override;
  void sliderValueChanged(juce::Slider *slider) override;
  void buttonClicked(juce::Button *button) override;

 private:
  juce::Slider gainSlider;
  juce::HyperlinkButton githubLink;

  // LookandFeels
  // myLookAndFeel blackHexKnobLAF;
  myLookAndFeel silverKnob;

  GainpluginAudioProcessor &audioProcessor;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainpluginAudioProcessorEditor)
};
