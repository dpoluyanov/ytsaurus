#pragma once

#include <util/system/compiler.h>

#include <CXX/Extensions.hxx> // pycxx
#include <CXX/Objects.hxx> // pycxx

namespace NYT::NPython {

////////////////////////////////////////////////////////////////////////////////

Y_WEAK Py::Object DumpParquete(Py::Tuple& args, Py::Dict& kwargs);

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NPython

