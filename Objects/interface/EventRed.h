#ifndef PandaTree_Objects_EventRed_h
#define PandaTree_Objects_EventRed_h
#include "EventBase.h"
#include "Constants.h"
#include "PFCand.h"
#include "GenParticle.h"
#include "FatJet.h"
#include "MicroJet.h"
#include "TruthJet.h"
#include "GenJet.h"
#include "Event.h"
#include "TruthJet.h"

namespace panda {

  class EventRed : public EventBase {
  public:
    EventRed();
    EventRed(EventRed const&);
    ~EventRed() {}
    EventRed& operator=(EventRed const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    PFCandCollection pfCandidates = PFCandCollection("pfCandidates", 2048);
    GenParticleCollection genParticles = GenParticleCollection("genParticles", 256);
    FatJetCollection recoJets = FatJetCollection("recoJets", 8);
    MicroJetCollection recoSubjets = MicroJetCollection("recoSubjets", 16);
    TruthJetCollection truthJets = TruthJetCollection("truthJets", 8);
    GenJetCollection genJets = GenJetCollection("genJets", 32);

    UShort_t npv{};
    Float_t rho{};

    static utils::BranchList getListOfBranches();

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doGetEntry_(TTree&, Long64_t) override;
    void doInit_() override;

  public:
    /* BEGIN CUSTOM EventRed.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventRed.h.global */
  /* END CUSTOM */

}

#endif
