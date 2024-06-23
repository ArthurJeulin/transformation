// **********************************************************
//      2024 : Arthur JEULIN
//      Copyright (c) Arthur JEULIN 
//      Created by Arthur JEULIN on 18/04/2024.
// **********************************************************
//
// Module : Attitude Euler
//

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#ifndef AML_EULER_H
#define AML_EULER_H

#include "aml_matrix_33.h"

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
   * - ajouter Commentaire Doxygen
   *  * @brief Set the Phi angle and ensure it is within the range of -360 to 360 degrees.
   *  * @param phi The phi angle in degrees.
   * - Changer la classe en tempalate pour changer les données (float, doubles,etc)
   * ajouter vérification lorsque l'on convertie de radToDeg et inversement
   */
class Euler : public Vector3
{
  public:
    // Constructors
    Euler();
    // Copy constructor from Vector3
    Euler(const Vector3& vector);
    Euler(double phi, double theta, double psi);


    // Static conversion method from Vector3 to Euler
    static Euler fromVector3(const Vector3& v);

    // Accessors and Modifiers for Euler angles
    const double& phi() const;
    const double& theta() const;
    const double& psi() const;

    void phi(double phi);
    void theta(double theta);
    void psi(double psi);

    void toDeg();
    void toRad();
    
    // Display function for Euler angles
    void display() const;

  };

  // Stream Functions
  std::ostream& operator<<(std::ostream& os, const Euler& angle);

} // namespace aml

#endif /* AML_EULER_H */