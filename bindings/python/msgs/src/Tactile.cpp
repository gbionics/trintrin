// SPDX-FileCopyrightText: Generative Bionics S.R.L.
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <trintrin/msgs/CompleteTactileFrame.h>
#include <trintrin/msgs/CompleteTactileSensor.h>
#include <trintrin/msgs/TactileContactPoint.h>
#include <trintrin/msgs/TactileFrameMetadata.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/Tactile.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateTactile(pybind11::module& module)
            {
                namespace py = ::pybind11;
                using namespace ::trintrin::msgs;

                py::class_<TactileFrameMetadata>(module, "TactileFrameMetadata")
                    .def(py::init())
                    .def_readwrite("schema_version", &TactileFrameMetadata::schema_version)
                    .def_readwrite("sequence", &TactileFrameMetadata::sequence)
                    .def_readwrite("timestamp_s", &TactileFrameMetadata::timestamp_s)
                    .def_readwrite("all_sensors_valid", &TactileFrameMetadata::all_sensors_valid)
                    .def("__str__", &TactileFrameMetadata::toString)
                    .def("toString", &TactileFrameMetadata::toString);

                py::class_<TactileContactPoint>(module, "TactileContactPoint")
                    .def(py::init())
                    .def_readwrite("contact_index", &TactileContactPoint::contact_index)
                    .def_readwrite("position_mm", &TactileContactPoint::position_mm)
                    .def_readwrite("force_n", &TactileContactPoint::force_n)
                    .def("__str__", &TactileContactPoint::toString)
                    .def("toString", &TactileContactPoint::toString);

                py::class_<CompleteTactileSensor>(module, "CompleteTactileSensor")
                    .def(py::init())
                    .def_readwrite("sensor_index", &CompleteTactileSensor::sensor_index)
                    .def_readwrite("sensor_name", &CompleteTactileSensor::sensor_name)
                    .def_readwrite("valid", &CompleteTactileSensor::valid)
                    .def_readwrite("resultant_force_n", &CompleteTactileSensor::resultant_force_n)
                    .def_readwrite("contacts", &CompleteTactileSensor::contacts)
                    .def_readwrite("temperature_c", &CompleteTactileSensor::temperature_c)
                    .def("__str__", &CompleteTactileSensor::toString)
                    .def("toString", &CompleteTactileSensor::toString);

                py::class_<CompleteTactileFrame>(module, "CompleteTactileFrame")
                    .def(py::init())
                    .def_readwrite("metadata", &CompleteTactileFrame::metadata)
                    .def_readwrite("sensors", &CompleteTactileFrame::sensors)
                    .def("__str__", &CompleteTactileFrame::toString)
                    .def("toString", &CompleteTactileFrame::toString);

                CreateBufferedPort<CompleteTactileFrame>(module, "BufferedPortCompleteTactileFrame");
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
