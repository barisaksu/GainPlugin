/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"

#include "PluginProcessor.h"

//==============================================================================
GainpluginAudioProcessorEditor::GainpluginAudioProcessorEditor(
    GainpluginAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(400, 300);

  gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
  gainSlider.setRange(-96.0f, 24.0f, 0.01f);
  gainSlider.setValue(0.0f);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80,15);
  // add db suffix
  gainSlider.setTextValueSuffix(" dB");

  addAndMakeVisible(gainSlider);
}

GainpluginAudioProcessorEditor::~GainpluginAudioProcessorEditor() {}

//==============================================================================
void GainpluginAudioProcessorEditor::paint(juce::Graphics &g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(juce::Colours::black);

  // set bg image
  juce::Image bg = juce::ImageCache::getFromMemory(BinaryData::bg_png,
                                                   BinaryData::bg_pngSize);
  g.drawImageAt(bg, 0, 0);

  g.setColour(juce::Colours::white);
  g.setFont(30.0f);
  g.drawFittedText("Gain Plugin", getLocalBounds(),
                   juce::Justification::centredTop, 5);
}

void GainpluginAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..

  gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}
