// $Id: unprec_dwf_fermact_base_array_w.cc,v 1.6 2003-12-02 15:45:04 edwards Exp $
/*! \file
 *  \brief Base class for unpreconditioned domain-wall-like fermion actions
 */

#include "chromabase.h"
#include "actions/ferm/fermacts/unprec_dwf_fermact_base_array_w.h"
#include "actions/ferm/invert/invcg2_array.h"
#include "actions/ferm/linop/dwffld_w.h"

using namespace QDP;


//! Propagator of an un-preconditioned DWF linear operator
/*!
 * \param psi      quark propagator ( Modify )
 * \param state    gauge field ( Read )
 * \param chi      source ( Read )
 * \param invType  inverter type ( Read (
 * \param RsdCG    CG (or MR) residual used here ( Read )
 * \param MaxCG    maximum number of CG iterations ( Read )
 * \param ncg_had  number of CG iterations ( Write )
 */

void 
UnprecDWFermActBaseArray::qprop(LatticeFermion& psi, 
				const ConnectState& state, 
				const LatticeFermion& chi, 
				enum InvType invType,
				const Real& RsdCG, 
				int MaxCG, int& ncg_had) const
{
  START_CODE("UnprecDWTypeFermActBaseArray::qprop");

  const int  N5 = size();   // array size better match
  const Real m_q = quark_mass();
  int n_count;
  
  // Initialize the 5D fields
  //  tmp5 = (chi,0,0,0,..,0)^T
  multi1d<LatticeFermion> chi5(N5);
  multi1d<LatticeFermion> tmp5(N5);
  tmp5 = zero;
  tmp5[0] = chi;

  // chi5 = P . tmp5
  DwfFld(chi5, tmp5, PLUS);

  // tmp5 = D5(1) . chi5 =  D5(1) . P . (chi,0,0,..,0)^T 
  {
    // Create a Pauli-Villars linop and use it for just this part
    const LinearOperatorProxy< multi1d<LatticeFermion> > B(linOpPV(state));

    B(tmp5, chi5, PLUS);
  }

  //  psi5 = (psi,0,0,0,...,0)^T
  multi1d<LatticeFermion> psi5(N5);
  psi5 = zero;
  psi5[0] = psi;

  // Construct the linear operator
  const LinearOperatorProxy< multi1d<LatticeFermion> > A(linOp(state));

  switch(invType)
  {
  case CG_INVERTER: 
    // chi5 = D5^\dagger(m) . tmp5 =  D5^dagger(m) . D5(1) . P . (chi,0,0,..,0)^T
    A(chi5, tmp5, MINUS);
    
    // psi5 = (D^dag * D)^(-1) chi5
    InvCG2 (A, chi5, psi5, RsdCG, MaxCG, n_count);
    break;
  
#if 0
  case MR_INVERTER:
    // psi5 = D^(-1) * tmp5
    InvMR (A, tmp5, psi5, MRover, RsdCG, MaxCG, n_count);
    break;

  case BICG_INVERTER:
    // psi5 = D^(-1) tmp5
    InvBiCG (A, tmp5, psi5, RsdCG, MaxCG, n_count);
    break;
#endif
  
  default:
    QDP_error_exit("Unknown inverter type", invType);
  }
  
  if ( n_count == MaxCG )
    QDP_error_exit("no convergence in the inverter", n_count);
  
  ncg_had = n_count;
  
  // Overall normalization
  Real ftmp1 = Real(1) / Real(1 - m_q);

  // Project out first slice after  tmp5 <- P^(-1) . psi5
  DwfFld(tmp5, psi5, MINUS);

  // Normalize and remove contact term
  psi = ftmp1*(tmp5[0] - chi);

  END_CODE("UnprecDWTypeFermActBaseArray::qprop");
}

