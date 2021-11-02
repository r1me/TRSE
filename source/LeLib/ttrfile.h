#ifndef TTRFILE_H
#define TTRFILE_H

#include <QByteArray>
#include <QString>
#include "util/util.h"

class TTRFile
{
public:
    TTRFile();

    int m_noChannels = 4;

    QByteArray m_header;
    QVector<QByteArray> m_patterns;
    QVector<QByteArray> m_instruments;
    QVector<QByteArray> m_orders;
    QString m_text="";
    int m_currentOrder = 0;
    int m_currentInstrument = 0;
    int m_noBytesPerLine = 4;
    int m_patternLength = 0x20;
    int m_version = 0x1;


    const int HEADER_SIZE = 64;

    const int TRSE_INSTR_START = 48+7;


    int getTRSEInstrument(int i) {
        return m_header[TRSE_INSTR_START+i];
    }
    void setTRSEInstrument(int i,uchar j) {
        m_header[TRSE_INSTR_START+i] = j;
    }

    void AddInstrument();
    static const int HEADER_POS_CURRENTTYPE = 0;
    QStringList systemTypes = QStringList() << "Adlib" << "VIC20";


    /*
     *
     *
     * 1 = Carrier ADSR
2 = Carrier volume
3 = Carrier multiplier / KSR / ADR or ADSR / vibrato / tremolo
4 = Carrier waveform
5 = Modulator ADSR
6 = Modulator volume
7 = Modulator multiplier / KSR / ADR or ADSR / vibrato / tremolo
8 = Modulator waveform
9 = Define connection of operators
A = Fine tune
B = Hard restart timer
C = Hard restart sustain and release
D = Unused?
E = Unused?
    */
    const unsigned char INSTRUMENT_PIANO1[11]    = { 0x00, 0x33, 0x5A, 0xB2, 0x50, 0x00, 0x31, 0x00, 0xB1, 0xF5, 0x11 };
        const unsigned char INSTRUMENT_PIANO2[11]    = { 0x00, 0x31, 0x49, 0xF2, 0x53, 0x01, 0x11, 0x03, 0xF1, 0xF5, 0x07 };
        const unsigned char INSTRUMENT_PIANO3[11]    = { 0x00, 0x31, 0x95, 0xD1, 0x83, 0x01, 0x32, 0x03, 0xC1, 0xF5, 0x0D };
        const unsigned char INSTRUMENT_HONKTONK[11]  = { 0x00, 0x34, 0x9B, 0xF3, 0x63, 0x01, 0x11, 0x00, 0x92, 0xF5, 0x11 };
        const unsigned char INSTRUMENT_EP1[11]       = { 0x00, 0x27, 0x28, 0xF8, 0xB7, 0x02, 0x91, 0x00, 0xF1, 0xF9, 0x01 };
        const unsigned char INSTRUMENT_EP2[11]       = { 0x00, 0x1A, 0x2D, 0xF3, 0xEE, 0x01, 0x11, 0x00, 0xF1, 0xF5, 0x01 };
        const unsigned char INSTRUMENT_HARPSIC[11]   = { 0x00, 0x35, 0x95, 0xF2, 0x58, 0x01, 0x32, 0x02, 0x81, 0xF6, 0x1F };
        const unsigned char INSTRUMENT_CLAVIC[11]    = { 0x00, 0x31, 0x85, 0xC9, 0x40, 0x00, 0x35, 0x00, 0xC2, 0xB9, 0x11 };
        const unsigned char INSTRUMENT_CELESTA[11]   = { 0x00, 0x09, 0x15, 0xC7, 0x64, 0x00, 0x01, 0x05, 0xB2, 0x35, 0x08 };
        const unsigned char INSTRUMENT_GLOCK[11]     = { 0x00, 0x06, 0x03, 0xF4, 0x44, 0x01, 0x01, 0x1B, 0xF2, 0x34, 0x00 };
        const unsigned char INSTRUMENT_MUSICBOX[11]  = { 0x00, 0x04, 0x06, 0xA9, 0x24, 0x01, 0x01, 0x01, 0xF5, 0x74, 0x0A };
        const unsigned char INSTRUMENT_VIBES[11]     = { 0x00, 0xD4, 0x00, 0xF6, 0x33, 0x00, 0xF1, 0x00, 0x61, 0xE3, 0x00 };
        const unsigned char INSTRUMENT_MARIMBA[11]   = { 0x00, 0xD4, 0x00, 0xF7, 0xE8, 0x00, 0xD1, 0x00, 0xA4, 0x64, 0x04 };
        const unsigned char INSTRUMENT_XYLO[11]      = { 0x00, 0x36, 0x16, 0xF7, 0xF7, 0x00, 0x31, 0x07, 0xB5, 0xF5, 0x01 };
        const unsigned char INSTRUMENT_TUBEBELL[11]  = { 0x00, 0x03, 0x1B, 0xA2, 0x43, 0x00, 0x00, 0x00, 0xF3, 0x74, 0x0B };
        const unsigned char INSTRUMENT_SANTUR[11]    = { 0x00, 0xC3, 0x8E, 0xF8, 0x35, 0x01, 0x11, 0x00, 0xC3, 0x94, 0x11 };
        const unsigned char INSTRUMENT_ORGAN1[11]    = { 0x00, 0xE2, 0x07, 0xF4, 0x1B, 0x01, 0xE0, 0x00, 0xF4, 0x0D, 0x16 };
        const unsigned char INSTRUMENT_ORGAN2[11]    = { 0x00, 0xF2, 0x00, 0xF6, 0x2C, 0x00, 0xF0, 0x00, 0xF5, 0x0B, 0x14 };
        const unsigned char INSTRUMENT_ORGAN3[11]    = { 0x00, 0xF1, 0x06, 0xB6, 0x15, 0x00, 0xF0, 0x00, 0xBF, 0x07, 0x0A };
        const unsigned char INSTRUMENT_PIPEORG[11]   = { 0x00, 0x22, 0x03, 0x79, 0x16, 0x01, 0xE0, 0x00, 0x6D, 0x08, 0x18 };
        const unsigned char INSTRUMENT_REEDORG[11]   = { 0x00, 0x31, 0x27, 0x63, 0x06, 0x00, 0x72, 0x00, 0x51, 0x17, 0x11 };
        const unsigned char INSTRUMENT_ACORDIAN[11]  = { 0x00, 0xB4, 0x1D, 0x53, 0x16, 0x01, 0x71, 0x00, 0x51, 0x17, 0x1F };
        const unsigned char INSTRUMENT_HARMONIC[11]  = { 0x00, 0x25, 0x29, 0x97, 0x15, 0x00, 0x32, 0x00, 0x53, 0x08, 0x11 };
        const unsigned char INSTRUMENT_BANDNEON[11]  = { 0x00, 0x24, 0x9E, 0x67, 0x15, 0x00, 0x31, 0x00, 0x53, 0x06, 0x1F };
        const unsigned char INSTRUMENT_NYLONGT[11]   = { 0x00, 0x13, 0x27, 0xA3, 0xB4, 0x01, 0x31, 0x00, 0xD2, 0xF8, 0x05 };
        const unsigned char INSTRUMENT_STEELGT[11]   = { 0x00, 0x17, 0xA3, 0xF3, 0x32, 0x00, 0x11, 0x00, 0xE2, 0xC7, 0x11 };
        const unsigned char INSTRUMENT_JAZZGT[11]    = { 0x00, 0x33, 0x24, 0xD2, 0xC1, 0x01, 0x31, 0x00, 0xF1, 0x9C, 0x0F };
        const unsigned char INSTRUMENT_CLEANGT[11]   = { 0x00, 0x31, 0x05, 0xF8, 0x44, 0x00, 0x32, 0x02, 0xF2, 0xC9, 0x11 };
        const unsigned char INSTRUMENT_MUTEGT[11]    = { 0x00, 0x21, 0x09, 0x9C, 0x7B, 0x00, 0x02, 0x03, 0x95, 0xFB, 0x07 };
        const unsigned char INSTRUMENT_OVERDGT[11]   = { 0x00, 0x21, 0x84, 0x81, 0x98, 0x01, 0x21, 0x04, 0xA1, 0x59, 0x07 };
        const unsigned char INSTRUMENT_DISTGT[11]    = { 0x00, 0xB1, 0x0C, 0x78, 0x43, 0x00, 0x22, 0x03, 0x91, 0xFC, 0x31 };
        const unsigned char INSTRUMENT_GTHARMS[11]   = { 0x00, 0x00, 0x0A, 0x82, 0x8C, 0x00, 0x08, 0x02, 0xB4, 0xEC, 0x09 };
        const unsigned char INSTRUMENT_ACOUBASS[11]  = { 0x00, 0x21, 0x13, 0xAB, 0x46, 0x00, 0x21, 0x00, 0x93, 0xF7, 0x01 };
        const unsigned char INSTRUMENT_FINGBASS[11]  = { 0x00, 0x01, 0x0A, 0xF9, 0x32, 0x00, 0x22, 0x04, 0xC1, 0x58, 0x01 };
        const unsigned char INSTRUMENT_PICKBASS[11]  = { 0x00, 0x21, 0x07, 0xFA, 0x77, 0x00, 0x22, 0x02, 0xC3, 0x6A, 0x0B };
        const unsigned char INSTRUMENT_FRETLESS[11]  = { 0x00, 0x21, 0x17, 0x71, 0x57, 0x00, 0x21, 0x00, 0x62, 0x87, 0x0B };
        const unsigned char INSTRUMENT_SLAPBAS1[11]  = { 0x00, 0x25, 0x01, 0xFA, 0x78, 0x01, 0x12, 0x00, 0xF3, 0x97, 0x07 };
        const unsigned char INSTRUMENT_SLAPBAS2[11]  = { 0x00, 0x21, 0x03, 0xFA, 0x88, 0x00, 0x13, 0x00, 0xB3, 0x97, 0x0D };
        const unsigned char INSTRUMENT_SYNBASS1[11]  = { 0x00, 0x21, 0x09, 0xF5, 0x7F, 0x01, 0x23, 0x04, 0xF3, 0xCC, 0x09 };
        const unsigned char INSTRUMENT_SYNBASS2[11]  = { 0x00, 0x01, 0x10, 0xA3, 0x9B, 0x00, 0x01, 0x00, 0x93, 0xAA, 0x09 };
        const unsigned char INSTRUMENT_VIOLIN[11]    = { 0x00, 0xE2, 0x19, 0xF6, 0x29, 0x01, 0xE1, 0x00, 0x78, 0x08, 0x1D };
        const unsigned char INSTRUMENT_VIOLA[11]     = { 0x00, 0xE2, 0x1C, 0xF6, 0x29, 0x01, 0xE1, 0x00, 0x78, 0x08, 0x1D };
        const unsigned char INSTRUMENT_CELLO[11]     = { 0x00, 0x61, 0x19, 0x69, 0x16, 0x01, 0x61, 0x00, 0x54, 0x27, 0x1B };
        const unsigned char INSTRUMENT_CONTRAB[11]   = { 0x00, 0x71, 0x18, 0x82, 0x31, 0x01, 0x32, 0x00, 0x61, 0x56, 0x0D };
        const unsigned char INSTRUMENT_TREMSTR[11]   = { 0x00, 0xE2, 0x23, 0x70, 0x06, 0x01, 0xE1, 0x00, 0x75, 0x16, 0x1D };
        const unsigned char INSTRUMENT_PIZZ[11]      = { 0x00, 0x02, 0x00, 0x88, 0xE6, 0x00, 0x61, 0x00, 0xF5, 0xF6, 0x18 };
        const unsigned char INSTRUMENT_HARP[11]      = { 0x00, 0x12, 0x20, 0xF6, 0xD5, 0x01, 0x11, 0x80, 0xF3, 0xE3, 0x0F };
        const unsigned char INSTRUMENT_TIMPANI[11]   = { 0x00, 0x61, 0x0E, 0xF4, 0xF4, 0x01, 0x00, 0x00, 0xB5, 0xF5, 0x01 };
        const unsigned char INSTRUMENT_STRINGS[11]   = { 0x00, 0x61, 0x1E, 0x9C, 0x04, 0x01, 0x21, 0x80, 0x71, 0x16, 0x0F };
        const unsigned char INSTRUMENT_SLOWSTR[11]   = { 0x00, 0xA2, 0x2A, 0xC0, 0xD6, 0x02, 0x21, 0x00, 0x30, 0x55, 0x1F };
        const unsigned char INSTRUMENT_SYNSTR1[11]   = { 0x00, 0x61, 0x21, 0x72, 0x35, 0x01, 0x61, 0x00, 0x62, 0x36, 0x1F };
        const unsigned char INSTRUMENT_SYNSTR2[11]   = { 0x00, 0x21, 0x1A, 0x72, 0x23, 0x01, 0x21, 0x02, 0x51, 0x07, 0x0F };
        const unsigned char INSTRUMENT_CHOIR[11]     = { 0x00, 0xE1, 0x16, 0x97, 0x31, 0x00, 0x61, 0x00, 0x62, 0x39, 0x09 };
        const unsigned char INSTRUMENT_OOHS[11]      = { 0x00, 0x22, 0xC3, 0x79, 0x45, 0x00, 0x21, 0x00, 0x66, 0x27, 0x01 };
        const unsigned char INSTRUMENT_SYNVOX[11]    = { 0x00, 0x21, 0xDE, 0x63, 0x55, 0x01, 0x21, 0x00, 0x73, 0x46, 0x01 };
        const unsigned char INSTRUMENT_ORCHIT[11]    = { 0x00, 0x42, 0x05, 0x86, 0xF7, 0x00, 0x50, 0x00, 0x74, 0x76, 0x1A };
        const unsigned char INSTRUMENT_TRUMPET[11]   = { 0x00, 0x31, 0x1C, 0x61, 0x02, 0x00, 0x61, 0x81, 0x92, 0x38, 0x0F };
        const unsigned char INSTRUMENT_TROMBONE[11]  = { 0x00, 0x71, 0x1E, 0x52, 0x23, 0x00, 0x61, 0x02, 0x71, 0x19, 0x0F };
        const unsigned char INSTRUMENT_TUBA[11]      = { 0x00, 0x21, 0x1A, 0x76, 0x16, 0x00, 0x21, 0x01, 0x81, 0x09, 0x0F };
        const unsigned char INSTRUMENT_MUTETRP[11]   = { 0x00, 0x25, 0x28, 0x89, 0x2C, 0x02, 0x20, 0x00, 0x83, 0x4B, 0x27 };
        const unsigned char INSTRUMENT_FRHORN[11]    = { 0x00, 0x21, 0x1F, 0x79, 0x16, 0x00, 0xA2, 0x05, 0x71, 0x59, 0x09 };
        const unsigned char INSTRUMENT_BRASS1[11]    = { 0x00, 0x21, 0x19, 0x87, 0x16, 0x00, 0x21, 0x03, 0x82, 0x39, 0x0F };
        const unsigned char INSTRUMENT_SYNBRAS1[11]  = { 0x00, 0x21, 0x17, 0x75, 0x35, 0x00, 0x22, 0x82, 0x84, 0x17, 0x0F };
        const unsigned char INSTRUMENT_SYNBRAS2[11]  = { 0x00, 0x21, 0x22, 0x62, 0x58, 0x00, 0x21, 0x02, 0x72, 0x16, 0x0F };
        const unsigned char INSTRUMENT_SOPSAX[11]    = { 0x00, 0xB1, 0x1B, 0x59, 0x07, 0x01, 0xA1, 0x00, 0x7B, 0x0A, 0x01 };
        const unsigned char INSTRUMENT_ALTOSAX[11]   = { 0x00, 0x21, 0x16, 0x9F, 0x04, 0x00, 0x21, 0x00, 0x85, 0x0C, 0x1B };
        const unsigned char INSTRUMENT_TENSAX[11]    = { 0x00, 0x21, 0x0F, 0xA8, 0x20, 0x00, 0x23, 0x00, 0x7B, 0x0A, 0x1D };
        const unsigned char INSTRUMENT_BARISAX[11]   = { 0x00, 0x21, 0x0F, 0x88, 0x04, 0x00, 0x26, 0x00, 0x79, 0x18, 0x19 };
        const unsigned char INSTRUMENT_OBOE[11]      = { 0x00, 0x31, 0x18, 0x8F, 0x05, 0x00, 0x32, 0x01, 0x73, 0x08, 0x01 };
        const unsigned char INSTRUMENT_ENGLHORN[11]  = { 0x00, 0xA1, 0x0A, 0x8C, 0x37, 0x01, 0x24, 0x04, 0x77, 0x0A, 0x01 };
        const unsigned char INSTRUMENT_BASSOON[11]   = { 0x00, 0x31, 0x04, 0xA8, 0x67, 0x00, 0x75, 0x00, 0x51, 0x19, 0x0B };
        const unsigned char INSTRUMENT_CLARINET[11]  = { 0x00, 0xA2, 0x1F, 0x77, 0x26, 0x01, 0x21, 0x01, 0x74, 0x09, 0x01 };
        const unsigned char INSTRUMENT_PICCOLO[11]   = { 0x00, 0xE1, 0x07, 0xB8, 0x94, 0x01, 0x21, 0x01, 0x63, 0x28, 0x01 };
        const unsigned char INSTRUMENT_FLUTE1[11]    = { 0x00, 0xA1, 0x93, 0x87, 0x59, 0x00, 0xE1, 0x00, 0x65, 0x0A, 0x01 };
        const unsigned char INSTRUMENT_RECORDER[11]  = { 0x00, 0x22, 0x10, 0x9F, 0x38, 0x00, 0x61, 0x00, 0x67, 0x29, 0x01 };
        const unsigned char INSTRUMENT_PANFLUTE[11]  = { 0x00, 0xE2, 0x0D, 0x88, 0x9A, 0x01, 0x21, 0x00, 0x67, 0x09, 0x01 };
        const unsigned char INSTRUMENT_BOTTLEB[11]   = { 0x00, 0xA2, 0x10, 0x98, 0x94, 0x00, 0x21, 0x01, 0x6A, 0x28, 0x0F };
        const unsigned char INSTRUMENT_SHAKU[11]     = { 0x00, 0xF1, 0x1C, 0x86, 0x26, 0x00, 0xF1, 0x00, 0x55, 0x27, 0x0F };
        const unsigned char INSTRUMENT_WHISTLE[11]   = { 0x00, 0xE1, 0x3F, 0x9F, 0x09, 0x00, 0xE1, 0x00, 0x6F, 0x08, 0x00 };
        const unsigned char INSTRUMENT_OCARINA[11]   = { 0x00, 0xE2, 0x3B, 0xF7, 0x19, 0x00, 0x21, 0x00, 0x7A, 0x07, 0x01 };
        const unsigned char INSTRUMENT_SQUARWAV[11]  = { 0x00, 0x22, 0x1E, 0x92, 0x0C, 0x00, 0x61, 0x06, 0xA2, 0x0D, 0x0F };
        const unsigned char INSTRUMENT_SAWWAV[11]    = { 0x00, 0x21, 0x15, 0xF4, 0x22, 0x01, 0x21, 0x00, 0xA3, 0x5F, 0x0F };
        const unsigned char INSTRUMENT_SYNCALLI[11]  = { 0x00, 0xF2, 0x20, 0x47, 0x66, 0x01, 0xF1, 0x00, 0x42, 0x27, 0x03 };
        const unsigned char INSTRUMENT_CHIFLEAD[11]  = { 0x00, 0x61, 0x19, 0x88, 0x28, 0x00, 0x61, 0x05, 0xB2, 0x49, 0x0F };
        const unsigned char INSTRUMENT_CHARANG[11]   = { 0x00, 0x21, 0x16, 0x82, 0x1B, 0x00, 0x23, 0x00, 0xB2, 0x79, 0x11 };
        const unsigned char INSTRUMENT_SOLOVOX[11]   = { 0x00, 0x21, 0x00, 0xCA, 0x93, 0x00, 0x22, 0x00, 0x7A, 0x1A, 0x01 };
        const unsigned char INSTRUMENT_FIFTHSAW[11]  = { 0x00, 0x23, 0x00, 0x92, 0xC9, 0x01, 0x22, 0x00, 0x82, 0x28, 0x18 };
        const unsigned char INSTRUMENT_BASSLEAD[11]  = { 0x00, 0x21, 0x1D, 0xF3, 0x7B, 0x00, 0x22, 0x02, 0xC3, 0x5F, 0x0F };
        const unsigned char INSTRUMENT_FANTASIA[11]  = { 0x00, 0xE1, 0x00, 0x81, 0x25, 0x01, 0xA6, 0x86, 0xC4, 0x95, 0x10 };
        const unsigned char INSTRUMENT_WARMPAD[11]   = { 0x00, 0x21, 0x27, 0x31, 0x01, 0x00, 0x21, 0x00, 0x44, 0x15, 0x0F };
        const unsigned char INSTRUMENT_POLYSYN[11]   = { 0x00, 0x60, 0x14, 0x83, 0x35, 0x02, 0x61, 0x00, 0xD1, 0x06, 0x0D };
        const unsigned char INSTRUMENT_SPACEVOX[11]  = { 0x00, 0xE1, 0x5C, 0xD3, 0x01, 0x01, 0x62, 0x00, 0x82, 0x37, 0x01 };
        const unsigned char INSTRUMENT_BOWEDGLS[11]  = { 0x00, 0x28, 0x38, 0x34, 0x86, 0x02, 0x21, 0x00, 0x41, 0x35, 0x01 };
        const unsigned char INSTRUMENT_METALPAD[11]  = { 0x00, 0x24, 0x12, 0x52, 0xF3, 0x01, 0x23, 0x02, 0x32, 0xF5, 0x15 };
        const unsigned char INSTRUMENT_HALOPAD[11]   = { 0x00, 0x61, 0x1D, 0x62, 0xA6, 0x00, 0xA1, 0x00, 0x61, 0x26, 0x0B };
        const unsigned char INSTRUMENT_SWEEPPAD[11]  = { 0x00, 0x22, 0x0F, 0x22, 0xD5, 0x01, 0x21, 0x84, 0x3F, 0x05, 0x1B };
        const unsigned char INSTRUMENT_ICERAIN[11]   = { 0x00, 0xE3, 0x1F, 0xF9, 0x24, 0x00, 0x31, 0x01, 0xD1, 0xF6, 0x01 };
        const unsigned char INSTRUMENT_SOUNDTRK[11]  = { 0x00, 0x63, 0x00, 0x41, 0x55, 0x01, 0xA2, 0x00, 0x41, 0x05, 0x16 };
        const unsigned char INSTRUMENT_CRYSTAL[11]   = { 0x00, 0xC7, 0x25, 0xA7, 0x65, 0x01, 0xC1, 0x05, 0xF3, 0xE4, 0x01 };
        const unsigned char INSTRUMENT_ATMOSPH[11]   = { 0x00, 0xE3, 0x19, 0xF7, 0xB7, 0x01, 0x61, 0x00, 0x92, 0xF5, 0x11 };
        const unsigned char INSTRUMENT_BRIGHT[11]    = { 0x00, 0x66, 0x9B, 0xA8, 0x44, 0x00, 0x41, 0x04, 0xF2, 0xE4, 0x1F };
        const unsigned char INSTRUMENT_GOBLIN[11]    = { 0x00, 0x61, 0x20, 0x22, 0x75, 0x00, 0x61, 0x00, 0x45, 0x25, 0x0D };
        const unsigned char INSTRUMENT_ECHODROP[11]  = { 0x00, 0xE1, 0x21, 0xF6, 0x84, 0x00, 0xE1, 0x01, 0xA3, 0x36, 0x0F };
        const unsigned char INSTRUMENT_STARTHEM[11]  = { 0x00, 0xE2, 0x14, 0x73, 0x64, 0x01, 0xE1, 0x01, 0x98, 0x05, 0x1B };
        const unsigned char INSTRUMENT_SITAR[11]     = { 0x00, 0x21, 0x0B, 0x72, 0x34, 0x00, 0x24, 0x02, 0xA3, 0xF6, 0x19 };
        const unsigned char INSTRUMENT_BANJO[11]     = { 0x00, 0x21, 0x16, 0xF4, 0x53, 0x00, 0x04, 0x00, 0xF6, 0xF8, 0x0D };
        const unsigned char INSTRUMENT_SHAMISEN[11]  = { 0x00, 0x21, 0x18, 0xDA, 0x02, 0x00, 0x35, 0x00, 0xF3, 0xF5, 0x0D };
        const unsigned char INSTRUMENT_KOTO[11]      = { 0x00, 0x25, 0x0F, 0xFA, 0x63, 0x00, 0x02, 0x00, 0x94, 0xE5, 0x19 };
        const unsigned char INSTRUMENT_KALIMBA[11]   = { 0x00, 0x32, 0x07, 0xF9, 0x96, 0x00, 0x11, 0x00, 0x84, 0x44, 0x01 };
        const unsigned char INSTRUMENT_BAGPIPE[11]   = { 0x00, 0x20, 0x0E, 0x97, 0x18, 0x02, 0x25, 0x03, 0x83, 0x18, 0x19 };
        const unsigned char INSTRUMENT_FIDDLE[11]    = { 0x00, 0x61, 0x18, 0xF6, 0x29, 0x00, 0x62, 0x01, 0x78, 0x08, 0x11 };
        const unsigned char INSTRUMENT_SHANNAI[11]   = { 0x00, 0xE6, 0x21, 0x76, 0x19, 0x00, 0x61, 0x03, 0x8E, 0x08, 0x1B };
        const unsigned char INSTRUMENT_TINKLBEL[11]  = { 0x00, 0x27, 0x23, 0xF0, 0xD4, 0x00, 0x05, 0x09, 0xF2, 0x46, 0x01 };
        const unsigned char INSTRUMENT_AGOGO[11]     = { 0x00, 0x1C, 0x0C, 0xF9, 0x31, 0x01, 0x15, 0x00, 0x96, 0xE8, 0x1F };
        const unsigned char INSTRUMENT_STEELDRM[11]  = { 0x00, 0x02, 0x00, 0x75, 0x16, 0x02, 0x01, 0x00, 0xF6, 0xF6, 0x16 };
        const unsigned char INSTRUMENT_WOODBLOK[11]  = { 0x00, 0x25, 0x1B, 0xFA, 0xF2, 0x00, 0x12, 0x00, 0xF6, 0x9A, 0x01 };
        const unsigned char INSTRUMENT_TAIKO[11]     = { 0x00, 0x02, 0x1D, 0xF5, 0x93, 0x00, 0x00, 0x00, 0xC6, 0x45, 0x01 };
        const unsigned char INSTRUMENT_MELOTOM[11]   = { 0x00, 0x11, 0x15, 0xF5, 0x32, 0x00, 0x10, 0x00, 0xF4, 0xB4, 0x05 };
        const unsigned char INSTRUMENT_SYNDRUM[11]   = { 0x00, 0x22, 0x06, 0xFA, 0x99, 0x00, 0x01, 0x00, 0xD5, 0x25, 0x09 };
        const unsigned char INSTRUMENT_REVRSCYM[11]  = { 0x00, 0x2E, 0x00, 0xFF, 0x00, 0x02, 0x0E, 0x0E, 0x21, 0x2D, 0x0F };
        const unsigned char INSTRUMENT_FRETNOIS[11]  = { 0x00, 0x30, 0x0B, 0x56, 0xE4, 0x01, 0x17, 0x00, 0x55, 0x87, 0x21 };
        const unsigned char INSTRUMENT_BRTHNOIS[11]  = { 0x00, 0x24, 0x00, 0xFF, 0x03, 0x00, 0x05, 0x08, 0x98, 0x87, 0x1D };
        const unsigned char INSTRUMENT_SEASHORE[11]  = { 0x00, 0x0E, 0x00, 0xF0, 0x00, 0x02, 0x0A, 0x04, 0x17, 0x04, 0x3F };
        const unsigned char INSTRUMENT_BIRDS[11]     = { 0x00, 0x20, 0x08, 0xF6, 0xF7, 0x00, 0x0E, 0x05, 0x77, 0xF9, 0x21 };
        const unsigned char INSTRUMENT_TELEPHON[11]  = { 0x00, 0x20, 0x14, 0xF1, 0x08, 0x00, 0x2E, 0x02, 0xF4, 0x08, 0x01 };
        const unsigned char INSTRUMENT_HELICOPT[11]  = { 0x00, 0x20, 0x04, 0xF2, 0x00, 0x01, 0x23, 0x00, 0x36, 0x05, 0x13 };
        const unsigned char INSTRUMENT_APPLAUSE[11]  = { 0x00, 0x2E, 0x00, 0xFF, 0x02, 0x00, 0x2A, 0x05, 0x32, 0x55, 0x3F };
        const unsigned char INSTRUMENT_GUNSHOT[11]   = { 0x00, 0x20, 0x00, 0xA1, 0xEF, 0x00, 0x10, 0x00, 0xF3, 0xDF, 0x0F };

        const unsigned char *midiInstruments[128] = {
                INSTRUMENT_PIANO1,   INSTRUMENT_PIANO2,   INSTRUMENT_PIANO3,   INSTRUMENT_HONKTONK, INSTRUMENT_EP1,      INSTRUMENT_EP2,
                INSTRUMENT_HARPSIC,  INSTRUMENT_CLAVIC,   INSTRUMENT_CELESTA,  INSTRUMENT_GLOCK,    INSTRUMENT_MUSICBOX, INSTRUMENT_VIBES,
                INSTRUMENT_MARIMBA,  INSTRUMENT_XYLO,     INSTRUMENT_TUBEBELL, INSTRUMENT_SANTUR,   INSTRUMENT_ORGAN1,   INSTRUMENT_ORGAN2,
                INSTRUMENT_ORGAN3,   INSTRUMENT_PIPEORG,  INSTRUMENT_REEDORG,  INSTRUMENT_ACORDIAN, INSTRUMENT_HARMONIC, INSTRUMENT_BANDNEON,
                INSTRUMENT_NYLONGT,  INSTRUMENT_STEELGT,  INSTRUMENT_JAZZGT,   INSTRUMENT_CLEANGT,  INSTRUMENT_MUTEGT,   INSTRUMENT_OVERDGT,
                INSTRUMENT_DISTGT,   INSTRUMENT_GTHARMS,  INSTRUMENT_ACOUBASS, INSTRUMENT_FINGBASS, INSTRUMENT_PICKBASS, INSTRUMENT_FRETLESS,
                INSTRUMENT_SLAPBAS1, INSTRUMENT_SLAPBAS2, INSTRUMENT_SYNBASS1, INSTRUMENT_SYNBASS2, INSTRUMENT_VIOLIN,   INSTRUMENT_VIOLA,
                INSTRUMENT_CELLO,    INSTRUMENT_CONTRAB,  INSTRUMENT_TREMSTR,  INSTRUMENT_PIZZ,     INSTRUMENT_HARP,     INSTRUMENT_TIMPANI,
                INSTRUMENT_STRINGS,  INSTRUMENT_SLOWSTR,  INSTRUMENT_SYNSTR1,  INSTRUMENT_SYNSTR2,  INSTRUMENT_CHOIR,    INSTRUMENT_OOHS,
                INSTRUMENT_SYNVOX,   INSTRUMENT_ORCHIT,   INSTRUMENT_TRUMPET,  INSTRUMENT_TROMBONE, INSTRUMENT_TUBA,     INSTRUMENT_MUTETRP,
                INSTRUMENT_FRHORN,   INSTRUMENT_BRASS1,   INSTRUMENT_SYNBRAS1, INSTRUMENT_SYNBRAS2, INSTRUMENT_SOPSAX,   INSTRUMENT_ALTOSAX,
                INSTRUMENT_TENSAX,   INSTRUMENT_BARISAX,  INSTRUMENT_OBOE,     INSTRUMENT_ENGLHORN, INSTRUMENT_BASSOON,  INSTRUMENT_CLARINET,
                INSTRUMENT_PICCOLO,  INSTRUMENT_FLUTE1,   INSTRUMENT_RECORDER, INSTRUMENT_PANFLUTE, INSTRUMENT_BOTTLEB,  INSTRUMENT_SHAKU,
                INSTRUMENT_WHISTLE,  INSTRUMENT_OCARINA,  INSTRUMENT_SQUARWAV, INSTRUMENT_SAWWAV,   INSTRUMENT_SYNCALLI, INSTRUMENT_CHIFLEAD,
                INSTRUMENT_CHARANG,  INSTRUMENT_SOLOVOX,  INSTRUMENT_FIFTHSAW, INSTRUMENT_BASSLEAD, INSTRUMENT_FANTASIA, INSTRUMENT_WARMPAD,
                INSTRUMENT_POLYSYN,  INSTRUMENT_SPACEVOX, INSTRUMENT_BOWEDGLS, INSTRUMENT_METALPAD, INSTRUMENT_HALOPAD,  INSTRUMENT_SWEEPPAD,
                INSTRUMENT_ICERAIN,  INSTRUMENT_SOUNDTRK, INSTRUMENT_CRYSTAL,  INSTRUMENT_ATMOSPH,  INSTRUMENT_BRIGHT,   INSTRUMENT_GOBLIN,
                INSTRUMENT_ECHODROP, INSTRUMENT_STARTHEM, INSTRUMENT_SITAR,    INSTRUMENT_BANJO,    INSTRUMENT_SHAMISEN, INSTRUMENT_KOTO,
                INSTRUMENT_KALIMBA,  INSTRUMENT_BAGPIPE,  INSTRUMENT_FIDDLE,   INSTRUMENT_SHANNAI,  INSTRUMENT_TINKLBEL, INSTRUMENT_AGOGO,
                INSTRUMENT_STEELDRM, INSTRUMENT_WOODBLOK, INSTRUMENT_TAIKO,    INSTRUMENT_MELOTOM,  INSTRUMENT_SYNDRUM,  INSTRUMENT_REVRSCYM,
                INSTRUMENT_FRETNOIS, INSTRUMENT_BRTHNOIS, INSTRUMENT_SEASHORE, INSTRUMENT_BIRDS,    INSTRUMENT_TELEPHON, INSTRUMENT_HELICOPT,
                INSTRUMENT_APPLAUSE, INSTRUMENT_GUNSHOT
            };

    QStringList m_predefinedInstruments = QStringList() <<"Piano1" << "Piano2" << "Piano3"<<"HonkTonk";

    QByteArray getPredefinedInstrument(int no) {

        QByteArray ba;
//        for (int i=0;i<11;i++)
/*
        kioCarrier		=	0		# Extra offsets
            kioModulator		=	5
            kioMisc			=	0		# Per-operator...
            kioKSLVol		=	1		# ...
            kioAD			=	2		# ...
            kioSR			=	3		# ...
            kioWaveform		=	4		# .
            kioFeedback		=	10		# Per-instrument
            kioA			=	11		# ...
            kioB			=	12		# ...UNUSED
            kioC			=	13		# ...UNUSED
            kioD			=	14		# ...UNUSED
            kioE			=	15		# ...UNUSED.
  */
        /*
         *
         *

 0 - Transpose
 *		Tells the number of semi-tones a note that is played using this instrument should be pitched up or down. For
 *		drum instruments that are played in melodic mode this sets the absolute note to be played for the drum sound.
 *
 *  1 - Channel c, operator 1, register 0x20
 *		Tremolo(1) | Vibrato(1) | Sustain(1) | KSR(1) | Frequency multiplier (4)
 *
 *  2 - Channel c, operator 1, register 0x40
 *		Key scale level(2) | Output level(6)
 *
 *  3 - Channel c, operator 1, register 0x60
 *		Attack(4) | Decay(4)
 *
 *  4 - Channel c, operator 1, register 0x80
 *		Sustain(4) | Release(4)
 *
 *  5 - Channel c, register 0xC0
 *		Undefined(4) | Modulation feedback factor(3) | Synth type(1)
 *
 *  6 - Channel c, operator 2, register 0x20
 *  7 - Channel c, operator 2, register 0x40
 *  8 - Channel c, operator 2, register 0x60
 *  9 - Channel c, operator 2, register 0x80
 *
 * 10 - Channel c, operators 1 + 2, register 0xE0
 *		OP1 WaveForm(3) | OP2 Waveform(3)
 *
 **/


        ba.append(midiInstruments[no][2]);//
        ba.append(midiInstruments[no][2]);// KSL 2->1
        ba.append(midiInstruments[no][3]); // AD 3->2
        ba.append(midiInstruments[no][4]); // SR 4->3
        ba.append(midiInstruments[no][10]); // waveform 10 -> 4
        ba.append(midiInstruments[no][5]); // modulation 5 -> 5
        ba.append(midiInstruments[no][6]);
        ba.append(midiInstruments[no][7]);
        ba.append(midiInstruments[no][8]);
        ba.append(midiInstruments[no][9]);
        ba.append(midiInstruments[no][10]);
        ba.append(midiInstruments[no][11]);
        return ba;
    }



//    const int POS_START_OF_INSTRUMENTS = 0x23;
    int POS_START_OF_INSTRUMENTS = 0x7+HEADER_SIZE;
    const int SIZE_OF_METADATA = 0x2*5;
    const int POS_START_OF_SPFX = POS_START_OF_INSTRUMENTS+2;
    const int POS_START_OF_ORDERS = POS_START_OF_SPFX+2;
    const int POS_START_OF_PATTERNS = POS_START_OF_ORDERS+2;
    const int POS_START_OF_TEXT = POS_START_OF_PATTERNS+2;
    const int INSTRUMENT_SIZE = 16;

    void Initialize(int channels, int rows);

    void InsertPattern(int pos);
    void DeletePattern(int pos);


    QVector<QByteArray> getCurrentPattern();
    void Save(QString filename);
    void Export(QString filename, int type);
    void ExportVIC20(QString filename);
    void ExportBeep(QString filename);
    void ExportVIC20C(QString filename);
    void ExportVZ(QString filename);
    void Load(QString filename);
    void LoadPSF(QString filename);

    void InsertOrder(int pos);
    void DeleteOrder();
};

#endif // TTRFILE_H
