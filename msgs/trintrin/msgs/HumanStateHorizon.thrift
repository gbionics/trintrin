// SPDX-FileCopyrightText: Generative Bionics S.R.L.
// SPDX-License-Identifier: LicenseRef-GenerativeBionics-AllRightsReserved

include "HumanState.thrift"

namespace yarp trintrin.msgs

/**
 * A HumanState tagged with the time at which it is meant to hold.
 *
 * `time` is expressed in milliseconds, relative to the timestamp of the message
 * carrying this sample. A zero offset denotes the current desired state, a
 * positive one a future desired state.
 */
struct TimedHumanState {
    1: i32 time;
    2: HumanState.HumanState state;
}

/**
 * A time-ordered sequence of TimedHumanState samples.
 *
 * It is meant to stream a *future* horizon of desired states (e.g. the reference
 * trajectory fed to a motion-tracking policy that needs look-ahead), instead of a
 * single instantaneous state.
 *
 * The samples must be sorted by non-decreasing `time`. `samples[0]` is
 * typically the current desired state, i.e. it carries a zero offset.
 */
struct HumanStateHorizon {
    1: list<TimedHumanState> samples;
}
