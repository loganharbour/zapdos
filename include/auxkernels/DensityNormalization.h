//* This file is part of Zapdos, an open-source
//* application for the simulation of plasmas
//* https://github.com/shannon-lab/zapdos
//*
//* Zapdos is powered by the MOOSE Framework
//* https://www.mooseframework.org
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "AuxKernel.h"

// Forward Declarations
class DensityNormalization;

template <>
InputParameters validParams<DensityNormalization>();

class DensityNormalization : public AuxKernel
{
public:
  static InputParameters validParams();

  DensityNormalization(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;

  const VariableValue & _density;
  const Real * _pp_on_source;
  const Real * _shift;
  Real _normal_factor;
};
