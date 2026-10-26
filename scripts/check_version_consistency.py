# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

from pathlib import Path
import tomllib

root = Path(__file__).resolve().parent.parent
pixi_version = tomllib.loads((root / "pixi.toml").read_text(encoding="utf-8"))["package"]["version"]
cmake_version = next(
    line.split("=", 1)[1]
    for line in (root / "build/CMakeCache.txt").read_text(encoding="utf-8").splitlines()
    if line.startswith("CMAKE_PROJECT_VERSION:STATIC=")
)
if cmake_version != pixi_version:
    raise SystemExit(f"Version mismatch: CMake={cmake_version}, Pixi={pixi_version}")

print(f"CMake and Pixi versions match: {pixi_version}")
