// -*- C++ -*-
// $Id: staggered_operators_s.h,v 1.2 2006-11-18 07:39:44 kostas Exp $
/*! \file
 *  \brief Staggered  operators
 *
 */

#ifndef __staggered_operators_h__
#define __staggered_operators_h__


namespace Chroma 
{
  //void StaggeredZEta(LatticeStaggeredPropagator& dest,int mu);
  //void StaggeredEta(LatticeStaggeredPropagator& dest,int mu);

  //void SymShift(LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u,const int mu) ;

  //void EtaShift(LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u,const multi1d<int>& mu) ;
  //void ZetaShift(LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u,const multi1d<int>& mu) ;

  void SpinScalar(LatticeStaggeredPropagator& dest, const LatticeStaggeredPropagator& src, const  multi1d<LatticeColorMatrix>& u ) ;
  void SpinVector(LatticeStaggeredPropagator& dest, const LatticeStaggeredPropagator& src, const  multi1d<LatticeColorMatrix>& u,const int mu) ;
  void SpinTensor(LatticeStaggeredPropagator& dest, const LatticeStaggeredPropagator& src, const  multi1d<LatticeColorMatrix>& u,const int mu,const int nu) ;
  void SpinAxialVector (LatticeStaggeredPropagator& dest, const LatticeStaggeredPropagator& src, const  multi1d<LatticeColorMatrix>& u,const int mu) ;
  void SpinPseudoScalar(LatticeStaggeredPropagator& dest, const LatticeStaggeredPropagator& src, const  multi1d<LatticeColorMatrix>& u) ;

  void FlavorScalar(LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u ) ;
  void FlavorVector(LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u,const int mu) ;
  void FlavorTensor(LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u,const int mu,const int nu) ;
  void FlavorAxialVector (LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u,const int mu) ;
  void FlavorPseudoScalar(LatticeStaggeredPropagator& dest,const LatticeStaggeredPropagator& src,const  multi1d<LatticeColorMatrix>& u) ;

}  // end namespace Chroma

#endif