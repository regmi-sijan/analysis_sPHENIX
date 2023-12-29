// ----------------------------------------------------------------------------
// 'SCorrelatorQAMaker.cc'
// Derek Anderson
// 10.04.2023
//
// A module to produce TNtuples and histograms for QA
// plots relevant to the sPHENIX Cold QCD Energy-Energy
// Correlator analysis.
// ----------------------------------------------------------------------------

#define SCORRELATORQAMAKER_CC

// c++ utilities
#include <cassert>
// user includes
#include "SCorrelatorQAMaker.h"

using namespace std;



namespace SColdQcdCorrelatorAnalysis {

  // ctor/dtor ----------------------------------------------------------------

  SCorrelatorQAMaker::~SCorrelatorQAMaker() {

    delete m_checkTrackPairs;

  }  // end dtor



  // global setters -----------------------------------------------------------

  void SCorrelatorQAMaker::SetGlobalDebug(const bool debug) {

    m_checkTrackPairs -> SetDebug(debug);
    return;

  }  // end 'SetGlobalDebug(bool)'


  void SCorrelatorQAMaker::SetGlobalOutFile(const string sOutFile) {

    m_checkTrackPairs -> SetOutFile(sOutFile);
    return;

  }  // end 'SetGlobalOutFile(string)'


  void SCorrelatorQAMaker::SetGlobalVerbosity(const int verbosity) {

    m_checkTrackPairs -> SetVerbosity(verbosity);
    return;

  }  // end 'SetGlobalVerbosity(int)'



  // plugin initializers ------------------------------------------------------

  // specialization for SCheckTrackPairs
  template <> void SCorrelatorQAMaker::InitPlugin(const SCheckTrackPairsConfig& config, optional<string> name) {

    // throw error if no name provided
    if (!name.has_value()) {
      assert(name.has_value());
    }

    m_checkTrackPairs = new SCheckTrackPairs(name.value());
    m_checkTrackPairs -> SetConfig(config);
    return;

  }  // end 'InitPlugin(SCheckTrackPairs, optional<string>)'

}  // end SColdQcdCorrelatorAnalysis namespace

// end ------------------------------------------------------------------------
