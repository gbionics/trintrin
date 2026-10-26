// SPDX-FileCopyrightText: Generative Bionics S.R.L.
// SPDX-License-Identifier: BSD-3-Clause

include "Common.thrift"

namespace yarp trintrin.msgs

struct TactileFrameMetadata
{
  1: i32 schema_version;
  2: i64 sequence;
  3: double timestamp_s;
  4: bool all_sensors_valid;
}

struct TactileContactPoint
{
  1: i32 contact_index;
  2: Common.VectorXYZ position_mm;
  5: double force_n;
}

struct CompleteTactileSensor
{
  1: i32 sensor_index;
  2: string sensor_name;
  3: bool valid;
  4: Common.VectorXYZ resultant_force_n;
  5: list<TactileContactPoint> contacts;
  6: double temperature_c;
}

struct CompleteTactileFrame
{
  1: TactileFrameMetadata metadata;
  2: list<CompleteTactileSensor> sensors;
}
