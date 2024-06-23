// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude Rotation
//

#include <aml_matrix_33.h>


namespace aml
{
  double radToDeg(const double& rad);
  double degToRad(const double& deg);
  

  /**
   * A FAIRE : 
   * - Vérifier pour chaque angle si l'on ajoute bien en radian ou degree
   * - Vérifier si chaque angle est compris entre 0 et 360° ou 0 et 180°
   * - Faire de même pour les valeurs en radian
   * - Peutêtre vérifier les valeurs
   * - ajouter Commentaire DOxygen
   *  * @brief Set the Phi angle and ensure it is within the range of -360 to 360 degrees.
   *  * @param phi The phi angle in degrees.
   * - Changer la classe en tempalate pour changer les données (float, doubles,etc)
   */
  class Euler : public Vector3 {
  public:

      // Constructors
      Euler() : Vector3() {}
      // Copy constructor from Vector3
      Euler(const Vector3& vector) : Vector3(vector.x, vector.y, vector.z) {}
      Euler(double phi, double theta, double psi) : Vector3(phi, theta, psi) {}


      // Static conversion method from Vector3 to Euler
      static Euler fromVector3(const Vector3& v)
      {
        return Euler(v.x, v.y, v.z);
      }

      // Accessors and Modifiers for Euler angles
      const double& phi() const { return x; }
      const double& theta() const { return y; }
      const double& psi() const { return z; }

      void phi(double phi) { x = phi; }
      void theta(double theta) { y = theta; }
      void psi(double psi) { z = psi; }

      void toDeg();
      void toRad();
      
      // Display function for Euler angles
      void display() const {
          std::cout << "Phi (Roll): " << phi() << " degrees\n"
                    << "Theta (Pitch): " << theta() << " degrees\n"
                    << "Psi (Yaw): " << psi() << " degrees\n";
      }
  };

  // Stream Functions
  std::ostream& operator<<(std::ostream& os, const Euler& angle);

  Matrix33 rotationX(double phi);

  Matrix33 rotationY(double theta);
  
  Matrix33 rotationZ(double psi);

  Matrix33 rotationXYZ(double phi, double theta, double psi);

  const Euler eulerFromRxyz(const Matrix33& mat);

  Vector3 eulerAngleRatesXYZ(const Euler& attitude, const Vector3& omega_body);
  Vector3 eulerIntegration(const Vector3& x, const Vector3& x_dot, const double& delta_t);
  

} // namespace aml