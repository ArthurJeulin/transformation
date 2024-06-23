
// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude Vector 3 Class
//


#include "aml_euler.h"


namespace aml
{
  double radToDeg(const double& rad)
  {
    return rad * (180.0/M_PI);
  }

  double degToRad(const double& deg)
  {
    return deg * (M_PI/180.0);
  }
  // Constructors
  Euler::Euler() : Vector3() {}
  // Copy constructor from Vector3
  Euler::Euler(const Vector3& vector) : Vector3(vector.x, vector.y, vector.z) {}
  Euler::Euler(double phi, double theta, double psi) : Vector3(phi, theta, psi) {}


  // Static conversion method from Vector3 to Euler
  Euler Euler::fromVector3(const Vector3& v)
  {
    return Euler(v.x, v.y, v.z);
  }

  // Accessors and Modifiers for Euler angles
  const double& Euler::phi() const { return x; }
  const double& Euler::theta() const { return y; }
  const double& Euler::psi() const { return z; }

  void Euler::phi(double phi) { x = phi; }
  void Euler::theta(double theta) { y = theta; }
  void Euler::psi(double psi) { z = psi; }
  // Display function for Euler angles
  void Euler::display() const
  {
    std::cout << "Phi (Roll): " << radToDeg(phi()) << " degrees\n"
              << "Theta (Pitch): " << radToDeg(theta()) << " degrees\n"
              << "Psi (Yaw): " << radToDeg(psi()) << " degrees\n";
  }
 
  // Stream Functions
  std::ostream& operator<<(std::ostream& os, const Euler& angle)
  {
    os << "[" << angle.phi() << ","<< angle.theta() << ","<<angle.psi() << "]";
    return os;
  }

  void Euler::toDeg()
  {
    x = radToDeg(x);
    y = radToDeg(y);
    z = radToDeg(z);
  }

  void Euler::toRad()
  {
    x = degToRad(x);
    y = degToRad(y);
    z = degToRad(z);
  }

} // namespace aml