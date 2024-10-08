
#include <biomesh_vertex_base.hpp>

namespace biomesh
{

vertex::vertex () : m_position (0.0, 0.0, 0.0) {}

vertex::~vertex () {}

double
vertex::operator() (char dir) const
{
  BIOMESH_ASSERT (dir == 'x' || dir == 'y' || dir == 'z');
  if (dir == 'x')
    return m_position (0);
  if (dir == 'y')
    return m_position (1);
  if (dir == 'z')
    return m_position (2);

  return std::numeric_limits<double>::max ();
}

bool
vertex::operator== (const vertex &other) const
{
  return (this->m_position == other.m_position);
}

void
vertex::operator= (const vertex &other)
{
  m_position = other.m_position;
}

double
vertex::distance (const vertex &other) const
{
  double x_abs = std::fabs (other.m_position (0) - m_position (0));
  double y_abs = std::fabs (other.m_position (1) - m_position (1));
  double z_abs = std::fabs (other.m_position (2) - m_position (2));

  return std::sqrt (std::pow (x_abs, 2) + std::pow (y_abs, 2)
                    + std::pow (z_abs, 2));
}

void
vertex::print ()
{
  std::cout << "x: " << m_position (0) << " y: " << m_position (1)
            << " z: " << m_position (2) << std::endl;
}

} // namespace biomesh