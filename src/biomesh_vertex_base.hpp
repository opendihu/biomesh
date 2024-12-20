
#ifndef BIOMESH_VERTEX_BASE_HPP
#define BIOMESH_VERTEX_BASE_HPP

#include <Eigen/Dense>
#include <cmath>
#include <limits>

#include <biomesh_base.hpp>

namespace biomesh
{

/**
 * Base class for vertices/points in the Euclidean space.
 * This class defines all basic functions and members.
 */
class vertex
{
public:
  /**
   * Default constructor.
   */
  vertex ();

  /**
   * Default destructor.
   */
  ~vertex ();

  /**
   * Function to retrieve the value of coordiante.
   * Set dir to 'x' to get the X coordiante.
   * Set dir to 'y' to get the Y coordiante.
   * Set dir to 'z' to get the Z coordinate.
   *
   * If this function is called via vertex2D then
   * the Z coordinate will always be 0.
   *
   * If dir does not match 'x' or 'y' or 'z' then
   * DOUBLE_MAX will be returned.
   *
   * @param[in] dir The required coordinates value.
   *
   * @return The magnitude of the desired coordinate.
   */
  double operator() (char dir) const;

  /**
   * Function to test the equality of two vertices.
   *
   * @param[in] other The reference vertex object for comparison.
   *
   * @return True if equal else false.
   */
  bool operator== (const vertex &other) const;

  /**
   * Copy assignment operator.
   */
  void operator= (const vertex &other);

  /**
   * Print coordinates.
   */
  void print () const;

protected:
  Eigen::Vector3d m_position; /* The X,Y,Z coordinates of the vertex. */
};

} // namespace biomesh

#endif