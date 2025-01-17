//* This file is part of Zapdos, an open-source
//* application for the simulation of plasmas
//* https://github.com/shannon-lab/zapdos
//*
//* Zapdos is powered by the MOOSE Framework
//* https://www.mooseframework.org
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef TM0CYLINDRICALEZ_H
#define TM0CYLINDRICALEZ_H

#include "Kernel.h"

class TM0CylindricalEz;

template <>
InputParameters validParams<TM0CylindricalEz>();

class TM0CylindricalEz : public Kernel
{
public:
  TM0CylindricalEz(const InputParameters & parameters);
  virtual ~TM0CylindricalEz();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  /* Real _r_units; */
  Real _omega;
  const MaterialProperty<Real> & _eps_r;
  Real _mu0;
  Real _eps0;
  const VariableValue & _Hphi;
  const VariableGradient & _grad_Hphi;
  unsigned int _Hphi_id;
};

#endif /* TM0CYLINDRICALEZ_H */
