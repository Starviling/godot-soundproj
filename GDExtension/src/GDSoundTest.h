#ifndef GDSOUNDTEST_H
#define GDSOUNDTEST_H

#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/audio_stream_generator.hpp>
#include <godot_cpp/classes/audio_stream_generator_playback.hpp>

namespace godot {
    class GDSoundTest : public AudioStreamPlayer {
        GDCLASS(GDSoundTest, AudioStreamPlayer)

    private:
        double time_passed;
        Ref<AudioStreamGenerator> stream;
        godot::Ref<AudioStreamGeneratorPlayback> playback;
        double sample_hz;

    protected:
        static void _bind_methods();

    public:
        GDSoundTest();
        ~GDSoundTest();

        void _process(double delta);
        void _ready();

    private:
        void fill_buffer();
    };
}
#endif