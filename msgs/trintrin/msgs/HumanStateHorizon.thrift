// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

include "HumanState.thrift"

namespace yarp trintrin.msgs

/**
 * A HumanState tagged with the time at which it is meant to hold.
 *
 * `timeOffset` is expressed in seconds, relative to the timestamp of the message
 * carrying this sample. A zero offset denotes the current desired state, a
 * positive one a future desired state.
 */
struct TimedHumanState {
    1: double timeOffset;
    2: HumanState.HumanState state;
}

/**
 * A time-ordered sequence of TimedHumanState samples.
 *
 * It is meant to stream a *future* horizon of desired states (e.g. the reference
 * trajectory fed to a motion-tracking policy that needs look-ahead), instead of a
 * single instantaneous state.
 *
 * The samples must be sorted by non-decreasing `timeOffset`. `samples[0]` is
 * typically the current desired state, i.e. it carries a zero offset.
 */
struct HumanStateHorizon {
    1: list<TimedHumanState> samples;
}
