/* Generated SBE (Simple Binary Encoding) message codec */

using System;
using Adaptive.SimpleBinaryEncoding;

namespace Adaptive.SimpleBinaryEncoding.Tests.Generated
{
    [Flags]
    public enum MatchEventIndicator : byte
    {
        LastTradeMsg = 1,
        LastVolumeMsg = 2,
        LastQuoteMsg = 4,
        LastStatsMsg = 8,
        LastImpliedMsg = 16,
        RecoveryMsg = 32,
        Reserved = 64,
        EndOfEvent = 128,
    }
}