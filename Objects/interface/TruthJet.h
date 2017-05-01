#ifndef PandaTree_Objects_TruthJet_h
#define PandaTree_Objects_TruthJet_h
#include "Constants.h"
#include "GenJet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "GenParticle.h"

namespace panda {

  class TruthJet : public GenJet {
  public:
    struct datastore : public GenJet::datastore {
      datastore() : GenJet::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      /* ParticleM
      Float_t* mass_{0};
      */
      /* GenJet
      Short_t* pdgid{0};
      */
      ContainerBase const* constituentsContainer_{0};
      std::vector<std::vector<Short_t>>* constituents_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const& = "") const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<TruthJet> array_type;
    typedef Collection<TruthJet> collection_type;

    typedef GenJet base_type;

    TruthJet(char const* name = "");
    TruthJet(TruthJet const&);
    TruthJet(datastore&, UInt_t idx);
    ~TruthJet();
    TruthJet& operator=(TruthJet const&);

    static char const* typeName() { return "TruthJet"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    /* GenJet
    Short_t& pdgid;
    */
    RefVector<GenParticle> constituents;

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */
    /* ParticleM
    Float_t& mass_;
    */

  public:
    /* BEGIN CUSTOM TruthJet.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor() override;

  protected:
    TruthJet(ArrayBase*);

    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<TruthJet> TruthJetArray;
  typedef Collection<TruthJet> TruthJetCollection;
  typedef Ref<TruthJet> TruthJetRef;
  typedef RefVector<TruthJet> TruthJetRefVector;

  /* BEGIN CUSTOM TruthJet.h.global */
  /* END CUSTOM */

}

#endif
