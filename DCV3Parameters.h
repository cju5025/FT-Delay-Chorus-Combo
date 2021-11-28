#pragma once

enum DCV3Parameter
{
    kDCV3Parameter_InputGain = 0,
    kDCV3Parameter_DelayTime,
    kDCV3Parameter_DelayFeedback,
    kDCV3Parameter_DelayWetDry,
    kDCV3Parameter_DelayType,
    kDCV3Parameter_OutputGain,
    kDCV3Parameter_ModulationRate,
    kDCV3Parameter_ModulationDepth,
    kDCV3Parameter_TotalNumParameters
};

static String DCV3ParameterID [ kDCV3Parameter_TotalNumParameters ] =
{
    "Input Gain",
    "Time",
    "Feedback",
    "Wet / Dry",
    "Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth"
};

static String DCV3ParameterLabel [ kDCV3Parameter_TotalNumParameters ] =
{
    "Input Gain",
    "Time",
    "Feedback",
    "Wet/Dry",
    "Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth"
};

static float DCV3ParameterDefaultValue [ kDCV3Parameter_TotalNumParameters ] =
{
    0.5f,
    0.25f,
    0.5f,
    0.5f,
    0.0f,
    0.5f,
    0.25f,
    0.5f
};
