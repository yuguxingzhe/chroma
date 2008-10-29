// $Id: quark_smearing_aggregate.cc,v 3.6 2008-10-29 19:42:37 jbulava Exp $
/*! \file
 *  \brief All quark smearing
 */

#include "meas/smear/quark_smearing_aggregate.h"

#include "meas/smear/no_quark_smearing.h"
#include "meas/smear/gaus_quark_smearing.h"
#include "meas/smear/vector_quark_smearing.h" 

namespace Chroma
{

  // Registration aggregator
  namespace QuarkSmearingEnv
  {
    //! Local registration flag
    static bool registered = false;

    //! Register all the factories
    bool registerAll() 
    {
      bool success = true; 
      if (! registered)
      {
	success &= NoQuarkSmearingEnv::registerAll();
	success &= GausQuarkSmearingEnv::registerAll();
	success &= VectorQuarkSmearingEnv::registerAll();
	registered = true;
      }
      return success;
    }


    // Returns a no-smearing group
    GroupXML_t   nullXMLGroup()
    {
      GroupXML_t nope;

      XMLBufferWriter xml_tmp;
      NoQuarkSmearingEnv::Params  non;
      write(xml_tmp, "SmearingParam", non);
      nope.xml = xml_tmp.str();
      nope.id = NoQuarkSmearingEnv::name;
      nope.path = "/SmearingParam";

      return nope;
    }

  }

}
