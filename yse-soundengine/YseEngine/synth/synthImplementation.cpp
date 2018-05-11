/*
  ==============================================================================

    synthImplementation.cpp
    Created: 6 Jul 2014 10:01:29pm
    Author:  yvan

  ==============================================================================
*/

/*
#include "synthImplementation.h"
#include "../internalHeaders.h"
#include "../sound/soundManager.h"
#include "samplerSound.h"
#include "dspSound.h"
#include "dspVoiceInternal.h"

YSE::SYNTH::implementationObject::implementationObject(interfaceObject * head) 
: head(head),
  synthBuffer(1, STANDARD_BUFFERSIZE), ID(0), voiceID(0), onNoteEvent(nullptr) {

  synthesizer.clearSounds();
  midiCollector.reset(SAMPLERATE);
  synthesizer.setCurrentPlaybackSampleRate(SAMPLERATE);
}

void YSE::SYNTH::implementationObject::addVoices(const YSE::SYNTH::samplerConfig & voice, int numVoices) {
  //for (int i = 0; i < numVoices; i++) {
  //  synthesizer.addVoice(new SamplerVoice());
  //}

  //ScopedPointer<AudioFormatReader> audioreader;
  //if (IO().getActive()) {
  //  INTERNAL::customFileReader * cfr = new INTERNAL::customFileReader;
  //  cfr->create(voice.file().c_str());
  //  audioreader = SOUND::Manager().getReader(cfr);
  //}
  //else {
  //  File ioFile = File::getCurrentWorkingDirectory().getChildFile(juce::String(voice.file()));
  //  audioreader = SOUND::Manager().getReader(ioFile);
  //}

  //BigInteger allNotes;
  //allNotes.setRange(voice.lowestNote(), voice.highestNote(), true);
  //synthesizer.addSound(new samplerSoundWithChannel(voice.name(), *audioreader, voice.channel(), allNotes, voice.root(), voice.attackTime(), voice.releaseTime(), voice.maxLength()));
}

void YSE::SYNTH::implementationObject::addVoices(YSE::SYNTH::dspVoice * voice, int numVoices, int channel, int lowestNote, int highestNote) {
  synthesizer.addSound(new dspSound(channel, lowestNote, highestNote, ++ID));
  for (int i = 0; i < numVoices; i++) {
    synthesizer.addVoice(new dspVoiceInternal(voice, ID, voiceID++));  
  }
}


void YSE::SYNTH::implementationObject::process(YSE::SOUND_STATUS & intent) {
  //// let juce take care of the midi parsing and buffer generation
  //synthBuffer.clear();
  //MidiBuffer incomingMidi;

  //// get messages from midi files
  //for (auto i = midiFiles.begin(); i != midiFiles.end(); i++) {
  //  (*i)->getMessages(incomingMidi);
  //}

  //// get messages from midi input
  //midiCollector.removeNextBlockOfMessages(incomingMidi, STANDARD_BUFFERSIZE);
  //
  //// sync message queue
  //keyboardState.processNextMidiBuffer(incomingMidi, 0, STANDARD_BUFFERSIZE, true);
  //synthesizer.renderNextBlock(synthBuffer, incomingMidi, 0, STANDARD_BUFFERSIZE);

  //// alter events if there's a callback function provided
  //if (onNoteEvent != nullptr && !incomingMidi.isEmpty()) {
  //  MidiBuffer::Iterator iter(incomingMidi);
  //  MidiMessage m(0xf0);
  //  int sample;
  //  while (iter.getNextEvent(m, sample)) {
  //    if (m.isNoteOnOrOff()) {
  //      float pitch = m.getNoteNumber();
  //      float velocity = m.getFloatVelocity();
  //      onNoteEvent(m.isNoteOn(), &pitch, &velocity);
  //      m.setNoteNumber(static_cast<int>(pitch));
  //      m.setVelocity(velocity);
  //    }
  //  }
  //}

  //// now copy over the buffer generated by juce to our own format
  //// TODO: is there a way to avoid this copy?
  //float * out = samples[0].getPtr();
  //const float * in = synthBuffer.getReadPointer(0);

  //int l = STANDARD_BUFFERSIZE;
  //for (; l > 7; l -= 8, out += 8, in += 8) {
  //  out[0] = in[0]; out[1] = in[1]; out[2] = in[2]; out[3] = in[3];
  //  out[4] = in[4]; out[5] = in[5]; out[6] = in[6]; out[7] = in[7];
  //}

  //while (l--) *out++ = *in++;
}

void YSE::SYNTH::implementationObject::frequency(Flt value) {

}

void YSE::SYNTH::implementationObject::sendMessage(const messageObject & message) {
  messages.push(message);
}

bool YSE::SYNTH::implementationObject::sync() {
  if (head == nullptr) {
    return false;
  }

  messageObject message;
  while (messages.try_pop(message)) {
    parseMessage(message);
  }

  return true;
}

void YSE::SYNTH::implementationObject::parseMessage(const messageObject & message) {
  switch (message.ID) {
    case MESSAGE::ALL_NOTES_OFF: {
      keyboardState.allNotesOff(message.uIntValue[0]);
      break;
    }
    case MESSAGE::NOTE_OFF: {
      keyboardState.noteOff((int)(message.vecValue[0]), (int)(message.vecValue[1]), 127); // newer juce version needs 127 as third argument
      break;
    }
    case MESSAGE::NOTE_ON: {
      keyboardState.noteOn((int)(message.vecValue[0]), (int)(message.vecValue[1]), message.vecValue[2]);
      break;
    }
    case MESSAGE::PITCH_WHEEL: {
      synthesizer.handlePitchWheel(message.intValue[0], message.intValue[1]);
      break;

    }
    case MESSAGE::CONTROLLER: {
      synthesizer.handleController(message.intValue[0], message.intValue[1], message.intValue[2]);
      break;
    }
    case MESSAGE::AFTERTOUCH: {
      synthesizer.handleAftertouch(message.intValue[0], message.intValue[1], message.intValue[2]);
      break;
    }
    case MESSAGE::SUSTAIN: {
      synthesizer.handleSustainPedal(message.cb.channel, message.cb.value);
      break;
    }
    case MESSAGE::SOSTENUTO: {
      synthesizer.handleSostenutoPedal(message.cb.channel, message.cb.value);
      break;
    }
    case MESSAGE::SOFTPEDAL: {
      synthesizer.handleSoftPedal(message.cb.channel, message.cb.value);
      break;
    }
    case MESSAGE::CALLBACK: {
      onNoteEvent = (void(*)(bool, float*, float*))message.ptr;
      break;
    }
  }
}


void YSE::SYNTH::implementationObject::registerMidiFile(MIDI::fileImpl * file) {
  for (auto i = midiFiles.begin(); i != midiFiles.end(); i++) {
    if (*i == file) {
      // don't try to register a file twice!
      assert(false);
      return;
    }
  }
  midiFiles.push_front(file);
}

void YSE::SYNTH::implementationObject::removeMidiFile(MIDI::fileImpl * file) {
  auto previous = midiFiles.before_begin();
  for (auto i = midiFiles.begin(); i != midiFiles.end(); i++) {
    if (*i == file) {
      midiFiles.erase_after(previous);
      return;
    }
    previous++;
  }
  // file not found
  assert(false);
}

YSE::SYNTH::implementationObject::~implementationObject() {
  //// if midifiles are still connected, let them know this object got deleted
  //for (auto i = midiFiles.begin(); i != midiFiles.end(); i++) {
  //  (*i)->removeDevice(this);
  //}
}

void YSE::SYNTH::implementationObject::removeInterface() {
  head = nullptr;
}

bool YSE::SYNTH::implementationObject::hasInterface() {
  return head != nullptr;
}

*/