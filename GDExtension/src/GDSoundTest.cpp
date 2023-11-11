#include "GDSoundTest.h"
#include <godot_cpp/core/class_db.hpp>
// #include <godot_cpp/classes/audio_stream_generator_playback.hpp>
// #include <godot_cpp/classes/audio_stream_generator.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/audio_stream.hpp>
#include <stk/include/Brass.h>

using namespace godot;
using namespace stk;

void GDSoundTest::_bind_methods() {
}

GDSoundTest::GDSoundTest() {
    time_passed = 0.0;

    stream->set_mix_rate(44100.0);

    Brass tmp = Brass(1);
    tmp.tick();
}

GDSoundTest::~GDSoundTest(){

}

void GDSoundTest::_process(double delta) {
    time_passed += delta;

    // Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

    // set_position(new_position);
}

void GDSoundTest::_ready() {
    play();
    playback = get_stream_playback();
    stream = Ref<AudioStreamGenerator>(memnew(AudioStreamGenerator));
    set_stream(stream);
}

void GDSoundTest::fill_buffer() {
    auto phase = 0.0;
    auto increment = 440.0 / stream->get_mix_rate();
    auto frames_available = playback->get_frames_available();

    for (int i = 0; i < frames_available; i++)
    {
        playback->push_frame(Vector2(1, 1) * sin(phase * Math_TAU)); // Vector2(1, 1) is Vector2::ONE
        phase - fmod(phase + increment, 1.0);
    }
}