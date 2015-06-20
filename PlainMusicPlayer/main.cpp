#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

#include "SoundSystem.h"
#include "Library.h"

#include <fstream>

#include "bass.h"

int main(int argc, char *argv[])
{
    SoundSystem::Initialize();

    int device = -1; // Default Sounddevice
    int freq = 44100; // Sample rate (Hz)
    HSTREAM streamHandle; // Handle for sample
    HCHANNEL channel; // Handle for open channel of the sample
  
    int err = 0;
    
    /* Initialize output device */
    if(!BASS_Init(device, freq, 0, 0, NULL))
        err = BASS_ErrorGetCode();
        
    streamHandle = BASS_StreamCreateFile(FALSE, "D:/test.mp3", 0, 0, 0);
    err = BASS_ErrorGetCode();
    
    channel = BASS_ChannelPlay(streamHandle, TRUE);
    err = BASS_ErrorGetCode();
    
    QApplication a(argc, argv);
    
    a.setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.show();

    return a.exec();
}
