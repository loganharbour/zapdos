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

#include "ADKernel.h"

class ADCoeffDiffusionLin : public ADKernel
{
public:
  static InputParameters validParams();

  ADCoeffDiffusionLin(const InputParameters & parameters);

protected:
  // virtual ADRealVectorValue precomputeQpResidual() override;
  virtual ADReal computeQpResidual();

  //  // using ADKernelGrad::getPostprocessorValue;

private:
  /// Position units
  const Real _r_units;

  /// The diffusion coefficient (either constant or mixture-averaged)
  const ADMaterialProperty<Real> & _diffusivity;
};
