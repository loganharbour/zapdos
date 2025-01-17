//* This file is part of Zapdos, an open-source
//* application for the simulation of plasmas
//* https://github.com/shannon-lab/zapdos
//*
//* Zapdos is powered by the MOOSE Framework
//* https://www.mooseframework.org
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef ELECTRONSFROMIONIZATION_H
#define ELECTRONSFROMIONIZATION_H

#include "Kernel.h"

class ElectronsFromIonization;

template <>
InputParameters validParams<ElectronsFromIonization>();

class ElectronsFromIonization : public Kernel
{
public:
  ElectronsFromIonization(const InputParameters & parameters);
  virtual ~ElectronsFromIonization();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  Real _r_units;

  const MaterialProperty<Real> & _diffem;
  const MaterialProperty<Real> & _d_diffem_d_actual_mean_en;
  const MaterialProperty<Real> & _muem;
  const MaterialProperty<Real> & _d_muem_d_actual_mean_en;
  const MaterialProperty<Real> & _alpha_iz;
  const MaterialProperty<Real> & _d_iz_d_actual_mean_en;
  MaterialProperty<Real> _user_diffem;
  MaterialProperty<Real> _user_d_diffem_d_actual_mean_en;
  MaterialProperty<Real> _user_muem;
  MaterialProperty<Real> _user_d_muem_d_actual_mean_en;
  MaterialProperty<Real> _user_alpha_iz;
  MaterialProperty<Real> _user_d_iz_d_actual_mean_en;

  const VariableValue & _mean_en;
  const VariableGradient & _grad_potential;
  VariableGradient _minus_e_field;
  unsigned int _mean_en_id;
  unsigned int _potential_id;
  const VariableValue & _em;
  const VariableGradient & _grad_em;
  unsigned int _em_id;
};

#endif /* ELECTRONSFROMIONIZATION_H */
