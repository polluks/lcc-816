/****************************************************************
*
*  speech.h - Speech toolkit interface file
*
*  August 1990
*  Barbara Allred
*
*  Copyright 1987-1991
*  First Byte, Inc.
*  All Rights Reserved
*
*  Copyright 1991
*  Byte Works, Inc.
*  All Rights Reserved
*
****************************************************************/

#pragma once

#include <types.h>

#ifndef __speech__
#define __speech__

#define maleToolNum   50
#define femaleToolNum 51
#define parserToolNum 52
#define speechToolNum 53

typedef enum Gender { Male, Female } Gender;
typedef enum Tone   { Treble, Bass } Tone;


/* Routines called in the GS/OS interface to the speech tool set. */

extern pascal void SpeechStartUp   (void)             inline(0x0235,dispatcher);
extern pascal void SpeechShutDown  (void)             inline(0x0335,dispatcher);
extern pascal int  SpeechVersion   (void)             inline(0x0435,dispatcher);
extern pascal void SpeechReset     (void)             inline(0x0535,dispatcher);
extern pascal int  SpeechStatus    (void)             inline(0x0635,dispatcher);


/* Routines called in the English text to phonetics parser tool set. */

extern pascal void ParseStartUp    (int myUserID)     inline(0x0234,dispatcher);
extern pascal void ParseShutDown   (void)             inline(0x0334,dispatcher);
extern pascal int  ParseVersion    (void)             inline(0x0434,dispatcher);
extern pascal void ParseReset      (void)             inline(0x0534,dispatcher);
extern pascal int  ParseStatus     (void)             inline(0x0634,dispatcher);
extern pascal void DictActivate    (int activeFlg)    inline(0x1034,dispatcher);
extern pascal void DictDelete      (String32Ptr theText)
                                                      inline(0x0B34,dispatcher);
extern pascal String32Ptr DictDump (String32Ptr theText,
                                     String32Ptr phoneticStr)
                                                      inline(0x0C34,dispatcher);
extern pascal void DictInit   (int initFlag)          inline(0x0E34,dispatcher);
extern pascal void DictInsert (String32Ptr theText, String32Ptr phoneticStr)
                                                      inline(0x0A34,dispatcher);
extern pascal int  Parse (StringPtr theText, StringPtr phoneticStr,
                          int firstChar)              inline(0x0934,dispatcher);
extern pascal void Say   (StringPtr theText)      inline(0x0F34,dispatcher);
extern pascal void SetSayGlobals (Gender theGender, Tone theTone,
                                  int pitch, int speed, int volume)
                                                      inline(0x0D34,dispatcher);


/* Routines called in the phonetics to adult male speech tool set. */

extern pascal void MaleStartUp  (void) inline(0x0232,dispatcher);
extern pascal void MaleShutDown (void) inline(0x0332,dispatcher);
extern pascal int  MaleVersion  (void) inline(0x0432,dispatcher);
extern pascal void MaleReset    (void) inline(0x0532,dispatcher);
extern pascal int  MaleStatus   (void) inline(0x0632,dispatcher);
extern pascal void MaleSpeak    (int volume, int speed, int pitch,
                                 StringPtr phoneticStr)
                                 inline(0x0932,dispatcher);


/* Routines called in the phonetics to adult female speech tool set. */

extern pascal void FemaleStartUp  (void) inline(0x0233,dispatcher);
extern pascal void FemaleShutDown (void) inline(0x0333,dispatcher);
extern pascal int  FemaleVersion  (void) inline(0x0433,dispatcher);
extern pascal void FemaleReset    (void) inline(0x0533,dispatcher);
extern pascal int  FemaleStatus   (void) inline(0x0633,dispatcher);
extern pascal void FemaleSpeak    (int volume, int speed, int pitch,
                                   StringPtr phoneticStr)
                                   inline(0x0933,dispatcher);
#endif
