//
// $Id: qprop.h,v 1.4 2004-01-12 18:09:29 bjoo Exp $

/*! \file
 * \brief Quark propagator solution routines
 *
 * Routines for computing a quark propagator with various fermion actions
 */

/*! \defgroup qprop Quark propagator solution routines
 * \ingroup actions
 *
 * Routines for computing a quark propagator with various fermion actions
 */

#ifndef __qprop_h__
#define __qprop_h__

#ifdef CHROMA_BUILD_WILSON
#include "qprop_w.h"
#elif CHROMA_BUILD_STAGGERED
#endif

#endif
