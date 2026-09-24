// SPDX-FileCopyrightText: Generative Bionics S.R.L.
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>

#include <trintrin/msgs/PlanarVelocity.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/PlanarVelocity.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreatePlanarVelocity(pybind11::module& module)
            {
                namespace py = ::pybind11;
                using namespace ::trintrin::msgs;

                py::class_<PlanarVelocity>(module, "PlanarVelocity")
                    .def(py::init())
                    .def_readwrite("linearVelocityX", &PlanarVelocity::linearVelocityX)
                    .def_readwrite("linearVelocityY", &PlanarVelocity::linearVelocityY)
                    .def_readwrite("angularVelocityZ", &PlanarVelocity::angularVelocityZ)
                    .def("__str__", &PlanarVelocity::toString)
                    .def("toString", &PlanarVelocity::toString);

                CreateBufferedPort<PlanarVelocity>(module, "BufferedPortPlanarVelocity");
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
