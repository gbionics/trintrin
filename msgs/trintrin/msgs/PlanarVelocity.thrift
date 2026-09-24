// SPDX-FileCopyrightText: Generative Bionics S.R.L.
// SPDX-License-Identifier: BSD-3-Clause

namespace yarp trintrin.msgs

/**
 * Velocity of a body moving on the XY plane
 */
struct PlanarVelocity {
    1: double linearVelocityX;
    2: double linearVelocityY;
    3: double angularVelocityZ;
}
