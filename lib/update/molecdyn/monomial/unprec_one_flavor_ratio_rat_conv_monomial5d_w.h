// -*- C++ -*-
/*! @file
 * @brief One-flavor collection of unpreconditioned 5D ferm monomials
 */

#ifndef __unprec_one_flavor_ratio_rat_conv_monomial5d_w_h__
#define __unprec_one_flavor_ratio_rat_conv_monomial5d_w_h__

#include "update/molecdyn/field_state.h"
#include "update/molecdyn/monomial/one_flavor_ratio_rat_conv_monomial5d_w.h"
#include "update/molecdyn/monomial/one_flavor_ratio_rat_conv_monomial_params_w.h"

namespace Chroma 
{

  /*! @ingroup monomial */
  namespace UnprecOneFlavorWilsonTypeFermRatioRatConvMonomial5DEnv 
  {
    bool registerAll();
  }


  //! Wrapper class for 5D 2-flavor unprec ferm monomials
  /*! @ingroup monomial
   *
   * Monomial is expected to be the same for these fermacts
   */
  class UnprecOneFlavorWilsonTypeFermRatioRatConvMonomial5D :
    public  OneFlavorRatioRatConvExactUnprecWilsonTypeFermMonomial5D< 
    multi1d<LatticeColorMatrix>,
    multi1d<LatticeColorMatrix>,
    LatticeFermion>
  {
  public: 
    // Typedefs to save typing
    typedef LatticeFermion               T;
    typedef multi1d<LatticeColorMatrix>  P;
    typedef multi1d<LatticeColorMatrix>  Q;

    // Construct out of a parameter struct. Check against the desired FermAct name
    UnprecOneFlavorWilsonTypeFermRatioRatConvMonomial5D(const OneFlavorWilsonTypeFermRatioRatConvMonomialParams& param_);

  protected:

    const UnprecWilsonTypeFermAct5D<T,P,Q>& getNumerFermAct(void) const { 
      return *fermact_num;
    }

    const UnprecWilsonTypeFermAct5D<T,P,Q>& getDenomFermAct(void) const { 
      return *fermact_den;
    }

    //! Get parameters for the inverter
    const GroupXML_t& getNumerActionInvParams(void) const { 
      return actionInvParam_num;
    }

    //! Get parameters for the inverter
    const GroupXML_t& getNumerForceInvParams(void) const { 
      return forceInvParam_num;
    }

    //! Return number of roots in used
    int getNPF() const {return num_pf;}

    //! Accessor for pseudofermion (read only)
    const multi1d< multi1d<T> >& getPhi(void) const {return phi;}

    //! mutator for pseudofermion
    multi1d< multi1d<T> >& getPhi(void) {return phi;}

    //! Return the partial fraction expansion for the force calc
    const RemezCoeff_t& getNumerFPFE() const {return fpfe_num;}

    //! Return the partial fraction expansion for the action calc
    const RemezCoeff_t& getNumerSPFE() const {return spfe_num;}

    //! Return the partial fraction expansion for the heat-bath
    const RemezCoeff_t& getNumerSIPFE() const {return sipfe_num;}

  private:
    // Hide empty constructor and =
    UnprecOneFlavorWilsonTypeFermRatioRatConvMonomial5D();
    void operator=(const UnprecOneFlavorWilsonTypeFermRatioRatConvMonomial5D&);

    // Pseudofermion field phi
    multi1d< multi1d<T> > phi;

    // A handle for the UnprecWilsonFermAct
    Handle<const UnprecWilsonTypeFermAct5D<T,P,Q> > fermact_num;
    Handle<const UnprecWilsonTypeFermAct5D<T,P,Q> > fermact_den;

    // The parameters for the inversion
    GroupXML_t actionInvParam_num;
    GroupXML_t forceInvParam_num;

    // Number of nth-roots
    int num_pf;

    // Coefficients and roots of partial fractions
    RemezCoeff_t  fpfe_num;
    RemezCoeff_t  spfe_num;
    RemezCoeff_t  sipfe_num;
  };


} //end namespace chroma



#endif
