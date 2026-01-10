
#include <iostream>
#include <biomesh_vector_field.hpp>
#include <biomesh_json_parser.hpp>
#include <biomesh_fiber_grid.hpp>
#include <biomesh_visualization.hpp>

using namespace biomesh;
using fiber_grid3d = fiber_grid<fiber3D, vertex3D>;

int main(int argc, char **argv)
{
  /* Set name of output file. */
  std::string filename(argv[1]);
  /* Load vector field from VTK file. */
  vector_field field(argv[2]);
  field.load_vtk_grid();
  //field.preprocess();


#if 1
  /* Classify cell in the vector field. */
  cell_table ct;
  ct.classify_cells(field.get_grid());
  //ct.find_seed_cells(field.get_grid());
  visualization::write_cell_type_vtk(ct, field, filename);
  //visualization::write_seed_type_vtk(ct, field, "ellipsoid");

  /* Generate fibers. */
  fiber_grid3d f(argv[3]);
  f.generate_fiber_grid(field, 200, 0.14);

  /* Write fibers to JSON format. */
  json_parser jp1;
  jp1.export_fiber_grid_json<fiber_grid3d>(f, filename + ".json");

  /* Write fibers to VTK format. */
  visualization::export_fiber_grid_vtk<fiber_grid3d>(f, filename);
#endif

#if 0
  f.transformation(affine_transform::translation<fiber3D>, 0.0, 0.0, 16);
  f.transformation(affine_transform::reflection<fiber3D>, 2);

  /* Write fibers to JSON format. */
  json_parser jp2;
  jp2.export_fiber_grid_json<fiber_grid3d>(f, filename + "_transformed.json");

  /* Write fibers to VTK format. */
  visualization::export_fiber_grid_vtk<fiber_grid3d>(f, filename + "_transformed");
#endif

  return EXIT_SUCCESS;
}