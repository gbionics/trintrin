// SPDX-FileCopyrightText: Generative Bionics S.R.L.
// SPDX-License-Identifier: LicenseRef-GenerativeBionics-AllRightsReserved

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <trintrin/msgs/HumanStateHorizon.h>
#include <trintrin/msgs/TimedHumanState.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/HumanStateHorizon.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateHumanStateHorizon(pybind11::module& module)
            {
                namespace py = ::pybind11;
                using namespace ::trintrin::msgs;

                py::class_<TimedHumanState>(module, "TimedHumanState")
                    .def(py::init())
                    .def_readwrite("timeInMs", &TimedHumanState::timeInMs)
                    .def_readwrite("state", &TimedHumanState::state)
                    .def("__str__", &TimedHumanState::toString)
                    .def("toString", &TimedHumanState::toString);

                py::class_<HumanStateHorizon>(module, "HumanStateHorizon")
                    .def(py::init())
                    .def_readwrite("samples", &HumanStateHorizon::samples)
                    .def("__str__", &HumanStateHorizon::toString)
                    .def("toString", &HumanStateHorizon::toString);

                CreateBufferedPort<HumanStateHorizon>(module, "BufferedPortHumanStateHorizon");
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
