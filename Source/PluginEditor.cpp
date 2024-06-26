/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
using namespace juce;
//==============================================================================
DelaySEGAudioProcessorEditor::DelaySEGAudioProcessorEditor (DelaySEGAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    addAndMakeVisible(lengthState = new Slider("Length")); 
    lengthState->Slider::setSliderStyle(Slider::LinearBarVertical);
    lengthState->Slider::setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    addAndMakeVisible(sizeState = new Slider("Size"));
    sizeState->Slider::setSliderStyle(Slider::LinearBarVertical);
    sizeState->Slider::setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    addAndMakeVisible(tailState = new Slider("Tail"));
    tailState->Slider::setSliderStyle(Slider::LinearBarVertical);
    tailState->Slider::setTextBoxStyle(Slider::NoTextBox, false, 100, 100);



    addAndMakeVisible(lengthTxt = new Label("lenghtTxt"));
    lengthTxt->Label::setText("Mix", dontSendNotification);
    lengthTxt->Label::attachToComponent(lengthState, false);

    addAndMakeVisible(sizeTxt = new Label("sizeTxt"));
    sizeTxt->Label::setText("Size", dontSendNotification);
    sizeTxt->Label::attachToComponent(sizeState, false);

    addAndMakeVisible(tailTxt = new Label("tailTxt"));
    tailTxt->Label::setText("Time", dontSendNotification);
    tailTxt->Label::attachToComponent(tailState, false);

    lengthAtt = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "length", *lengthState);
    sizeAtt = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "size", *sizeState);
    tailAtt = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "tail", *tailState);

        //addAndMakeVisible(lengthState = new Slider(""));
        //lengthState->Slider::setSliderStyle(Slider::LinearBarVertical);
        //lengthState->Slider::setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    

     
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (700, 400);
}
void DelaySEGAudioProcessorEditor::makeStateVisible(ScopedPointer<Slider> State, String name){

   
    State->Slider::setSliderStyle(Slider::LinearBarVertical);
    State->Slider::setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    }


void DelaySEGAudioProcessorEditor::sliderStyle(ScopedPointer<Slider> sliderState,int order) {

}
DelaySEGAudioProcessorEditor::~DelaySEGAudioProcessorEditor()
{
}

//==============================================================================
void DelaySEGAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour(Colours::white);
    g.setFont(15.0f);

    
}

void DelaySEGAudioProcessorEditor::resized()
{
    int xunit = (getWidth() / 12);
    int yunit = (getHeight() / 12);
    int xcenter = xunit * 6;
    int ycenter = xunit * 6;
    int sliderWidth = xunit * 2;
    int sliderHeight = yunit * 10;

    lengthState->setBounds(2 * xunit, yunit, sliderWidth, sliderHeight);
    sizeState->setBounds(xcenter - (xunit), yunit, sliderWidth, sliderHeight);
    tailState->setBounds(xcenter + (2 * xunit), yunit, sliderWidth, sliderHeight);

}



