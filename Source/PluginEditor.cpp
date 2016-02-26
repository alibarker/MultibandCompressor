/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Multiband_compressorAudioProcessorEditor::Multiband_compressorAudioProcessorEditor (Multiband_compressorAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderLowThreshold = new Slider ("Low Gain Slider"));
    sliderLowThreshold->setRange (-80, 0, 0);
    sliderLowThreshold->setSliderStyle (Slider::LinearVertical);
    sliderLowThreshold->setTextBoxStyle (Slider::TextBoxAbove, false, 40, 20);
    sliderLowThreshold->addListener (this);

    addAndMakeVisible (sliderLowRatio = new Slider ("new slider"));
    sliderLowRatio->setRange (1, 10, 0);
    sliderLowRatio->setSliderStyle (Slider::Rotary);
    sliderLowRatio->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderLowRatio->addListener (this);

    addAndMakeVisible (sliderLowAttack = new Slider ("new slider"));
    sliderLowAttack->setRange (0.01, 100, 0);
    sliderLowAttack->setSliderStyle (Slider::Rotary);
    sliderLowAttack->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderLowAttack->addListener (this);

    addAndMakeVisible (sliderLowRelease = new Slider ("new slider"));
    sliderLowRelease->setRange (0.01, 100, 0);
    sliderLowRelease->setSliderStyle (Slider::Rotary);
    sliderLowRelease->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderLowRelease->addListener (this);

    addAndMakeVisible (sliderLowGain = new Slider ("new slider"));
    sliderLowGain->setRange (-20, 20, 0);
    sliderLowGain->setSliderStyle (Slider::Rotary);
    sliderLowGain->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderLowGain->addListener (this);

    addAndMakeVisible (sliderMidThreshold = new Slider ("Mid Gain Slider"));
    sliderMidThreshold->setRange (-80, 0, 0);
    sliderMidThreshold->setSliderStyle (Slider::LinearVertical);
    sliderMidThreshold->setTextBoxStyle (Slider::TextBoxAbove, false, 40, 20);
    sliderMidThreshold->addListener (this);

    addAndMakeVisible (sliderMidRatio = new Slider ("new slider"));
    sliderMidRatio->setRange (1, 10, 0);
    sliderMidRatio->setSliderStyle (Slider::Rotary);
    sliderMidRatio->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderMidRatio->addListener (this);

    addAndMakeVisible (sliderMidAttack = new Slider ("new slider"));
    sliderMidAttack->setRange (0.01, 100, 0);
    sliderMidAttack->setSliderStyle (Slider::Rotary);
    sliderMidAttack->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderMidAttack->addListener (this);

    addAndMakeVisible (sliderMidRelease = new Slider ("new slider"));
    sliderMidRelease->setRange (0.01, 100, 0);
    sliderMidRelease->setSliderStyle (Slider::Rotary);
    sliderMidRelease->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderMidRelease->addListener (this);

    addAndMakeVisible (sliderMidGain = new Slider ("new slider"));
    sliderMidGain->setRange (-20, 20, 0);
    sliderMidGain->setSliderStyle (Slider::Rotary);
    sliderMidGain->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderMidGain->addListener (this);

    addAndMakeVisible (sliderHighThreshold = new Slider ("High Gain Slider"));
    sliderHighThreshold->setRange (-80, 0, 0);
    sliderHighThreshold->setSliderStyle (Slider::LinearVertical);
    sliderHighThreshold->setTextBoxStyle (Slider::TextBoxAbove, false, 40, 20);
    sliderHighThreshold->addListener (this);

    addAndMakeVisible (sliderHighRatio = new Slider ("new slider"));
    sliderHighRatio->setRange (1, 10, 0);
    sliderHighRatio->setSliderStyle (Slider::Rotary);
    sliderHighRatio->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderHighRatio->addListener (this);

    addAndMakeVisible (sliderHighAttack = new Slider ("new slider"));
    sliderHighAttack->setRange (0.01, 100, 0);
    sliderHighAttack->setSliderStyle (Slider::Rotary);
    sliderHighAttack->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderHighAttack->addListener (this);

    addAndMakeVisible (sliderHighRelease = new Slider ("new slider"));
    sliderHighRelease->setRange (0.01, 100, 0);
    sliderHighRelease->setSliderStyle (Slider::Rotary);
    sliderHighRelease->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderHighRelease->addListener (this);

    addAndMakeVisible (sliderHighGain = new Slider ("new slider"));
    sliderHighGain->setRange (-20, 20, 0);
    sliderHighGain->setSliderStyle (Slider::Rotary);
    sliderHighGain->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    sliderHighGain->addListener (this);

    addAndMakeVisible (ratioLabel = new Label ("new label",
                                               TRANS("Ratio:")));
    ratioLabel->setFont (Font (15.00f, Font::plain));
    ratioLabel->setJustificationType (Justification::centredLeft);
    ratioLabel->setEditable (false, false, false);
    ratioLabel->setColour (TextEditor::textColourId, Colours::black);
    ratioLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (attackLabel = new Label ("new label",
                                                TRANS("Attack:")));
    attackLabel->setFont (Font (15.00f, Font::plain));
    attackLabel->setJustificationType (Justification::centredLeft);
    attackLabel->setEditable (false, false, false);
    attackLabel->setColour (TextEditor::textColourId, Colours::black);
    attackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (releaseLabel = new Label ("new label",
                                                 TRANS("Release:")));
    releaseLabel->setFont (Font (15.00f, Font::plain));
    releaseLabel->setJustificationType (Justification::centredLeft);
    releaseLabel->setEditable (false, false, false);
    releaseLabel->setColour (TextEditor::textColourId, Colours::black);
    releaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (gainLabel = new Label ("new label",
                                              TRANS("Gain:")));
    gainLabel->setFont (Font (15.00f, Font::plain));
    gainLabel->setJustificationType (Justification::centredLeft);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (TextEditor::textColourId, Colours::black);
    gainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sliderKneeWidth = new Slider ("new slider"));
    sliderKneeWidth->setRange (0, 10, 0);
    sliderKneeWidth->setSliderStyle (Slider::Rotary);
    sliderKneeWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    sliderKneeWidth->addListener (this);

    addAndMakeVisible (sliderOverallGain = new Slider ("new slider"));
    sliderOverallGain->setRange (-40, 10, 0);
    sliderOverallGain->setSliderStyle (Slider::Rotary);
    sliderOverallGain->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    sliderOverallGain->addListener (this);

    addAndMakeVisible (kneeWidthLabel = new Label ("new label",
                                                   TRANS("Knee Width:")));
    kneeWidthLabel->setFont (Font (15.00f, Font::plain));
    kneeWidthLabel->setJustificationType (Justification::centredLeft);
    kneeWidthLabel->setEditable (false, false, false);
    kneeWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    kneeWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (overallGainLabel = new Label ("new label",
                                                     TRANS("Overall Gain:")));
    overallGainLabel->setFont (Font (15.00f, Font::plain));
    overallGainLabel->setJustificationType (Justification::centredLeft);
    overallGainLabel->setEditable (false, false, false);
    overallGainLabel->setColour (TextEditor::textColourId, Colours::black);
    overallGainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (buttonLowONOFF = new TextButton ("new button"));
    buttonLowONOFF->setButtonText (TRANS("Low"));
    buttonLowONOFF->addListener (this);
    buttonLowONOFF->setClickingTogglesState(true);

    addAndMakeVisible (buttonMidONOFF = new TextButton ("new button"));
    buttonMidONOFF->setButtonText (TRANS("Mid"));
    buttonMidONOFF->addListener (this);
    buttonMidONOFF->setClickingTogglesState(true);

    addAndMakeVisible (buttonHighONOFF = new TextButton ("new button"));
    buttonHighONOFF->setButtonText (TRANS("High"));
    buttonHighONOFF->addListener (this);
    buttonHighONOFF->setClickingTogglesState(true);
    

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    startTimer(100);
    //[/Constructor]
}

Multiband_compressorAudioProcessorEditor::~Multiband_compressorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderLowThreshold = nullptr;
    sliderLowRatio = nullptr;
    sliderLowAttack = nullptr;
    sliderLowRelease = nullptr;
    sliderLowGain = nullptr;
    sliderMidThreshold = nullptr;
    sliderMidRatio = nullptr;
    sliderMidAttack = nullptr;
    sliderMidRelease = nullptr;
    sliderMidGain = nullptr;
    sliderHighThreshold = nullptr;
    sliderHighRatio = nullptr;
    sliderHighAttack = nullptr;
    sliderHighRelease = nullptr;
    sliderHighGain = nullptr;
    ratioLabel = nullptr;
    attackLabel = nullptr;
    releaseLabel = nullptr;
    gainLabel = nullptr;
    sliderKneeWidth = nullptr;
    sliderOverallGain = nullptr;
    kneeWidthLabel = nullptr;
    overallGainLabel = nullptr;
    buttonLowONOFF = nullptr;
    buttonMidONOFF = nullptr;
    buttonHighONOFF = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Multiband_compressorAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::antiquewhite);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Multiband_compressorAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderLowThreshold->setBounds (104, 96, 40, 144);
    sliderLowRatio->setBounds (88, 258, 80, 32);
    sliderLowAttack->setBounds (88, 292, 80, 32);
    sliderLowRelease->setBounds (88, 326, 80, 32);
    sliderLowGain->setBounds (88, 360, 80, 32);
    sliderMidThreshold->setBounds (216, 96, 40, 144);
    sliderMidRatio->setBounds (200, 258, 80, 32);
    sliderMidAttack->setBounds (200, 292, 80, 32);
    sliderMidRelease->setBounds (200, 326, 80, 32);
    sliderMidGain->setBounds (200, 360, 80, 32);
    sliderHighThreshold->setBounds (328, 96, 40, 144);
    sliderHighRatio->setBounds (312, 258, 80, 32);
    sliderHighAttack->setBounds (312, 292, 80, 32);
    sliderHighRelease->setBounds (312, 326, 80, 32);
    sliderHighGain->setBounds (312, 360, 80, 32);
    ratioLabel->setBounds (16, 258, 48, 24);
    attackLabel->setBounds (16, 292, 64, 24);
    releaseLabel->setBounds (16, 326, 72, 24);
    gainLabel->setBounds (16, 360, 48, 24);
    sliderKneeWidth->setBounds (496, 272, 56, 56);
    sliderOverallGain->setBounds (496, 336, 56, 56);
    kneeWidthLabel->setBounds (400, 280, 88, 24);
    overallGainLabel->setBounds (400, 352, 88, 24);
    buttonLowONOFF->setBounds (98, 65, 50, 24);
    buttonMidONOFF->setBounds (211, 65, 50, 24);
    buttonHighONOFF->setBounds (322, 65, 50, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Multiband_compressorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderLowThreshold)
    {
        //[UserSliderCode_sliderLowThreshold] -- add your slider handling code here..
        getProcessor()->setLowThreshold(sliderLowThreshold->getValue());
        //[/UserSliderCode_sliderLowThreshold]
    }
    else if (sliderThatWasMoved == sliderLowRatio)
    {
        //[UserSliderCode_sliderLowRatio] -- add your slider handling code here..
        getProcessor()->setLowRatio(sliderLowRatio->getValue());
        //[/UserSliderCode_sliderLowRatio]
    }
    else if (sliderThatWasMoved == sliderLowAttack)
    {
        //[UserSliderCode_sliderLowAttack] -- add your slider handling code here..
        getProcessor()->setLowAttack(sliderLowAttack->getValue());
        //[/UserSliderCode_sliderLowAttack]
    }
    else if (sliderThatWasMoved == sliderLowRelease)
    {
        //[UserSliderCode_sliderLowRelease] -- add your slider handling code here..
        getProcessor()->setLowRelease(sliderLowRelease->getValue());
        //[/UserSliderCode_sliderLowRelease]
    }
    else if (sliderThatWasMoved == sliderLowGain)
    {
        //[UserSliderCode_sliderLowGain] -- add your slider handling code here..
        getProcessor()->setLowGain(sliderLowGain->getValue());
        //[/UserSliderCode_sliderLowGain]
    }
    else if (sliderThatWasMoved == sliderMidThreshold)
    {
        //[UserSliderCode_sliderMidThreshold] -- add your slider handling code here..
        getProcessor()->setMidThreshold(sliderMidThreshold->getValue());
        //[/UserSliderCode_sliderMidThreshold]
    }
    else if (sliderThatWasMoved == sliderMidRatio)
    {
        //[UserSliderCode_sliderMidRatio] -- add your slider handling code here..
        getProcessor()->setMidRatio(sliderMidRatio->getValue());
        //[/UserSliderCode_sliderMidRatio]
    }
    else if (sliderThatWasMoved == sliderMidAttack)
    {
        //[UserSliderCode_sliderMidAttack] -- add your slider handling code here..
        getProcessor()->setMidAttack(sliderMidAttack->getValue());
        //[/UserSliderCode_sliderMidAttack]
    }
    else if (sliderThatWasMoved == sliderMidRelease)
    {
        //[UserSliderCode_sliderMidRelease] -- add your slider handling code here..
        getProcessor()->setMidRelease(sliderMidRelease->getValue());
        //[/UserSliderCode_sliderMidRelease]
    }
    else if (sliderThatWasMoved == sliderMidGain)
    {
        //[UserSliderCode_sliderMidGain] -- add your slider handling code here..
        getProcessor()->setMidGain(sliderMidGain->getValue());
        //[/UserSliderCode_sliderMidGain]
    }
    else if (sliderThatWasMoved == sliderHighThreshold)
    {
        //[UserSliderCode_sliderHighThreshold] -- add your slider handling code here..
        getProcessor()->setHighThreshold(sliderHighThreshold->getValue());
        //[/UserSliderCode_sliderHighThreshold]
    }
    else if (sliderThatWasMoved == sliderHighRatio)
    {
        //[UserSliderCode_sliderHighRatio] -- add your slider handling code here..
        getProcessor()->setHighRatio(sliderHighRatio->getValue());
        //[/UserSliderCode_sliderHighRatio]
    }
    else if (sliderThatWasMoved == sliderHighAttack)
    {
        //[UserSliderCode_sliderHighAttack] -- add your slider handling code here..
        getProcessor()->setHighAttack(sliderHighAttack->getValue());
        //[/UserSliderCode_sliderHighAttack]
    }
    else if (sliderThatWasMoved == sliderHighRelease)
    {
        //[UserSliderCode_sliderHighRelease] -- add your slider handling code here..
        getProcessor()->setHighRelease(sliderHighRelease->getValue());
        //[/UserSliderCode_sliderHighRelease]
    }
    else if (sliderThatWasMoved == sliderHighGain)
    {
        //[UserSliderCode_sliderHighGain] -- add your slider handling code here..
        getProcessor()->setHighGain(sliderHighGain->getValue());
        //[/UserSliderCode_sliderHighGain]
    }
    else if (sliderThatWasMoved == sliderKneeWidth)
    {
        //[UserSliderCode_sliderKneeWidth] -- add your slider handling code here..
        getProcessor()->setKneeWidth(sliderHighGain->getValue());
        //[/UserSliderCode_sliderKneeWidth]
    }
    else if (sliderThatWasMoved == sliderOverallGain)
    {
        //[UserSliderCode_sliderOverallGain] -- add your slider handling code here..
        getProcessor()->setOverallGain(sliderOverallGain->getValue());
        //[/UserSliderCode_sliderOverallGain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Multiband_compressorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == buttonLowONOFF)
    {
        //[UserButtonCode_buttonLowONOFF] -- add your button handler code here..
        getProcessor()->setLowONOFF(buttonLowONOFF->getToggleState());
        //[/UserButtonCode_buttonLowONOFF]
    }
    else if (buttonThatWasClicked == buttonMidONOFF)
    {
        //[UserButtonCode_buttonMidONOFF] -- add your button handler code here..
        getProcessor()->setMidONOFF(buttonMidONOFF->getToggleState());

        //[/UserButtonCode_buttonMidONOFF]
    }
    else if (buttonThatWasClicked == buttonHighONOFF)
    {
        //[UserButtonCode_buttonHighONOFF] -- add your button handler code here..
        getProcessor()->setHighONOFF(buttonHighONOFF->getToggleState());

        //[/UserButtonCode_buttonHighONOFF]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void Multiband_compressorAudioProcessorEditor::timerCallback() {

    sliderOverallGain->setValue( getProcessor()->getOverallGain());
    sliderKneeWidth->setValue( getProcessor()->getKneeWidth());

    sliderLowGain->setValue(getProcessor()->getLowGain());
    sliderLowThreshold->setValue(getProcessor()->getLowThreshold());
    sliderLowRatio->setValue(getProcessor()->getLowRatio());
    sliderLowAttack->setValue(getProcessor()->getLowAttack());
    sliderLowRelease->setValue(getProcessor()->getLowRelease());

    sliderMidGain->setValue(getProcessor()->getMidGain());
    sliderMidThreshold->setValue(getProcessor()->getMidThreshold());
    sliderMidRatio->setValue(getProcessor()->getMidRatio());
    sliderMidAttack->setValue(getProcessor()->getMidAttack());
    sliderMidRelease->setValue(getProcessor()->getMidRelease());

    sliderHighGain->setValue(getProcessor()->getHighGain());
    sliderHighThreshold->setValue(getProcessor()->getHighThreshold());
    sliderHighRatio->setValue(getProcessor()->getHighRatio());
    sliderHighAttack->setValue(getProcessor()->getHighAttack());
    sliderHighRelease->setValue(getProcessor()->getHighRelease());

    buttonLowONOFF->setToggleState(getProcessor()->getLowONOFF(), dontSendNotification);
    buttonMidONOFF->setToggleState(getProcessor()->getMidONOFF(), dontSendNotification);
    buttonHighONOFF->setToggleState(getProcessor()->getHighONOFF(), dontSendNotification);




}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Multiband_compressorAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="Multiband_compressorAudioProcessor* ownerFilter"
                 variableInitialisers="AudioProcessorEditor (ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="fffaebd7"/>
  <SLIDER name="Low Gain Slider" id="8b7c5322a4bbeb1d" memberName="sliderLowThreshold"
          virtualName="" explicitFocusOrder="0" pos="104 96 40 144" min="-80"
          max="0" int="0" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="41f3423a8399955" memberName="sliderLowRatio"
          virtualName="" explicitFocusOrder="0" pos="88 258 80 32" min="1"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="b4388857e0ed579a" memberName="sliderLowAttack"
          virtualName="" explicitFocusOrder="0" pos="88 292 80 32" min="0.010000000000000000208"
          max="100" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="e14011b0d7519da3" memberName="sliderLowRelease"
          virtualName="" explicitFocusOrder="0" pos="88 326 80 32" min="0.010000000000000000208"
          max="100" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="f966b2bcf80fa070" memberName="sliderLowGain"
          virtualName="" explicitFocusOrder="0" pos="88 360 80 32" min="-20"
          max="20" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Mid Gain Slider" id="9af554c661b648de" memberName="sliderMidThreshold"
          virtualName="" explicitFocusOrder="0" pos="216 96 40 144" min="-80"
          max="0" int="0" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="b7f5e6c16be1b2b0" memberName="sliderMidRatio"
          virtualName="" explicitFocusOrder="0" pos="200 258 80 32" min="1"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="de1f191e35c77811" memberName="sliderMidAttack"
          virtualName="" explicitFocusOrder="0" pos="200 292 80 32" min="0.010000000000000000208"
          max="100" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="b2ae8695c1ffab01" memberName="sliderMidRelease"
          virtualName="" explicitFocusOrder="0" pos="200 326 80 32" min="0.010000000000000000208"
          max="100" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="7b200698e28e19dd" memberName="sliderMidGain"
          virtualName="" explicitFocusOrder="0" pos="200 360 80 32" min="-20"
          max="20" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="High Gain Slider" id="70949a3a20587967" memberName="sliderHighThreshold"
          virtualName="" explicitFocusOrder="0" pos="328 96 40 144" min="-80"
          max="0" int="0" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="e9aa8181da8c56ba" memberName="sliderHighRatio"
          virtualName="" explicitFocusOrder="0" pos="312 258 80 32" min="1"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="18ed2f302ff0bc0c" memberName="sliderHighAttack"
          virtualName="" explicitFocusOrder="0" pos="312 292 80 32" min="0.010000000000000000208"
          max="100" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="ddc383ef00993e92" memberName="sliderHighRelease"
          virtualName="" explicitFocusOrder="0" pos="312 326 80 32" min="0.010000000000000000208"
          max="100" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="b49b7203d167a680" memberName="sliderHighGain"
          virtualName="" explicitFocusOrder="0" pos="312 360 80 32" min="-20"
          max="20" int="0" style="Rotary" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="bc5e79ca9a3aeace" memberName="ratioLabel"
         virtualName="" explicitFocusOrder="0" pos="16 258 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Ratio:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="553c2c20256ba90f" memberName="attackLabel"
         virtualName="" explicitFocusOrder="0" pos="16 292 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="56160d96e5bff51d" memberName="releaseLabel"
         virtualName="" explicitFocusOrder="0" pos="16 326 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="59c2666b63b4a2ea" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="16 360 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="e93146ed83e200ff" memberName="sliderKneeWidth"
          virtualName="" explicitFocusOrder="0" pos="496 272 56 56" min="0"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="655c9c9d4b92cde2" memberName="sliderOverallGain"
          virtualName="" explicitFocusOrder="0" pos="496 336 56 56" min="-40"
          max="10" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="76c3569cea3488c4" memberName="kneeWidthLabel"
         virtualName="" explicitFocusOrder="0" pos="400 280 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Knee Width:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8e872eeadbe367ee" memberName="overallGainLabel"
         virtualName="" explicitFocusOrder="0" pos="400 352 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Overall Gain:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="a4c1893239c3c319" memberName="buttonLowONOFF"
              virtualName="" explicitFocusOrder="0" pos="98 65 50 24" buttonText="Low"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="2d61f6b8246a85fa" memberName="buttonMidONOFF"
              virtualName="" explicitFocusOrder="0" pos="211 65 50 24" buttonText="Mid"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="6dcfd02ef78ca574" memberName="buttonHighONOFF"
              virtualName="" explicitFocusOrder="0" pos="322 65 50 24" buttonText="High"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
