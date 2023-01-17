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
  setSize(400, 300);

  silverKnob.setLookAndFeel(ImageCache::getFromMemory(
      BinaryData::silver_knob_png, BinaryData::silver_knob_pngSize));

  gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
  gainSlider.setLookAndFeel(&silverKnob);
  gainSlider.setRange(-60.0f, 0.0f, 0.01f);
  gainSlider.setValue(-20.0f);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 15);
  // add db suffix
  gainSlider.setTextValueSuffix(" dB");
  gainSlider.addListener(this);
  addAndMakeVisible(gainSlider);

  githubLink.setButtonText("Source Code");
  githubLink.setColour(juce::HyperlinkButton::ColourIds::textColourId,
                       juce::Colours::black);
  githubLink.setFont(juce::Font(15.0f), false, juce::Justification::centredRight - 10);                     
  githubLink.addListener(this);
  addAndMakeVisible(&githubLink);
}

GainpluginAudioProcessorEditor::~GainpluginAudioProcessorEditor() {}

//==============================================================================
void GainpluginAudioProcessorEditor::paint(juce::Graphics &g) {
  g.fillAll(juce::Colours::black);

  // set bg image
  juce::Image bg = juce::ImageCache::getFromMemory(BinaryData::bg_png,
                                                   BinaryData::bg_pngSize);
  g.drawImageAt(bg, 0, 0);
}

void GainpluginAudioProcessorEditor::resized() {
  gainSlider.setBounds(getWidth() / 2 - 70, getHeight() / 2 - 60, 150, 150);

  githubLink.setBounds(getWidth() - 100, getHeight() - 40, 100, 30);
}

void GainpluginAudioProcessorEditor::sliderValueChanged(Slider *slider) {
  if (slider == &gainSlider) {
    audioProcessor.gainParam = gainSlider.getValue();
  }
}

void GainpluginAudioProcessorEditor::buttonClicked(Button *button) {
  if (button == &githubLink) {
    URL("https://github.com/barisaksu/GainPlugin").launchInDefaultBrowser();
  }
}
