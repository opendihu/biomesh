
#include <biomesh_fiber_grid2D.hpp>

namespace biomesh
{
fiber_grid2D::fiber_grid2D (const std::string &file_name)
    : m_jparser{ file_name }
{
  m_fiber_count = 0;
}

int
fiber_grid2D::generate_fiber_grid (const vector_field &vfield,
                                   size_t fpoint_count)
{
  m_jparser.read ();
  auto data = m_jparser.get_json_string ();
  m_fiber_count = data["seed_points"].size ();
  BIOMESH_ASSERT (m_fiber_count > 0);

  /* Loop over the fibers. */
  for (size_t fcount = 0; fcount < m_fiber_count; ++fcount)
    {
      /* Obtain the seed point. */
      double x = (data["seed_points"][(unsigned)fcount]["x"]).asDouble ();
      double y = (data["seed_points"][(unsigned)fcount]["y"]).asDouble ();
      vertex2D seed (x, y);

      /* Initialize the fiber. */
      fiber2D fiber (seed);

      /* Generate fiber. */
      fiber.generate_fiber (vfield, fpoint_count);

      /* Push fiber to fiber grid. */
      m_fiber_set.push_back (fiber);
    }

  return BIOMESH_SUCCESS;
}

}