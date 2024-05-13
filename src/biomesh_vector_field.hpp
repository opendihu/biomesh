
#ifndef BIOMESH_VECTOR_FIELD_HPP
#define BIOMESH_VECTOR_FIELD_HPP

#include <vtkStructuredGrid.h>
#include <vtkStructuredGridReader.h>
#include <memory>
#include <biomesh.hpp>

namespace biomesh
{
class vector_field
{
public:
  vector_field();
  vector_field(const vector_field& other);
  vector_field(const vector_field&& other);
  ~vector_field();
  void read_vtk_file(const std::string& file_name);
  void generate_field();

private:
  std::string m_file_name;
  std::unique_ptr<vtkStructuredGrid> m_sgrid;
};
} // namespace biomesh

#endif