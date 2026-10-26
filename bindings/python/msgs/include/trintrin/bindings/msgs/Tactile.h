// SPDX-FileCopyrightText: Generative Bionics S.R.L.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef TRINTRIN_BINDINGS_MSGS_TACTILE_H
#define TRINTRIN_BINDINGS_MSGS_TACTILE_H

#include <pybind11/pybind11.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateTactile(pybind11::module& module);

        } // namespace msgs
    } // namespace bindings
} // namespace trintrin

#endif // TRINTRIN_BINDINGS_MSGS_TACTILE_H
