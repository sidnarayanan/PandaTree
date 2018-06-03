#ifndef PandaTree_Objects_Photon_h
#define PandaTree_Objects_Photon_h
#include "Constants.h"
#include "ParticleP.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "SuperCluster.h"
#include "PFCand.h"
#include "GenParticle.h"

namespace panda {

  class Photon : public ParticleP {
  public:
    struct datastore : public ParticleP::datastore {
      datastore() : ParticleP::datastore() {}
      ~datastore() { deallocate(); }

      /* ParticleP
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      */
      Float_t* pfPt{0};
      Float_t* chIso{0};
      Float_t* chIsoMax{0};
      Float_t* nhIso{0};
      Float_t* phIso{0};
      Float_t* sieie{0};
      Float_t* sipip{0};
      Float_t* hOverE{0};
      Float_t* mipEnergy{0};
      Float_t* emax{0};
      Float_t* e2nd{0};
      Float_t* eleft{0};
      Float_t* eright{0};
      Float_t* etop{0};
      Float_t* ebottom{0};
      Float_t* r9{0};
      Float_t* etaWidth{0};
      Float_t* phiWidth{0};
      Float_t* time{0};
      Float_t* timeSpan{0};
      Float_t* regPt{0};
      Float_t* smearedPt{0};
      UShort_t* ix{0};
      UShort_t* iy{0};
      Bool_t* loose{0};
      Bool_t* medium{0};
      Bool_t* tight{0};
      Bool_t* highpt{0};
      Bool_t* pixelVeto{0};
      Bool_t* csafeVeto{0};
      Bool_t* pfchVeto{0};
      ContainerBase const* superClusterContainer_{0};
      Short_t* superCluster_{0};
      ContainerBase const* matchedPFContainer_{0};
      Short_t* matchedPF_{0};
      ContainerBase const* matchedGenContainer_{0};
      Short_t* matchedGen_{0};

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

    typedef Array<Photon> array_type;
    typedef Collection<Photon> collection_type;

    typedef ParticleP base_type;

    Photon(char const* name = "");
    Photon(Photon const&);
    Photon(datastore&, UInt_t idx);
    ~Photon();
    Photon& operator=(Photon const&);

    static char const* typeName() { return "Photon"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    Float_t& pfPt; ///< Pt of the dR-closest PF candidate
    Float_t& chIso;
    Float_t& chIsoMax;
    Float_t& nhIso;
    Float_t& phIso;
    Float_t& sieie;
    Float_t& sipip;
    Float_t& hOverE;
    Float_t& mipEnergy;
    Float_t& emax;
    Float_t& e2nd;
    Float_t& eleft;
    Float_t& eright;
    Float_t& etop;
    Float_t& ebottom;
    Float_t& r9;
    Float_t& etaWidth;
    Float_t& phiWidth;
    Float_t& time;
    Float_t& timeSpan;
    Float_t& regPt;
    Float_t& smearedPt;
    UShort_t& ix;
    UShort_t& iy;
    Bool_t& loose;
    Bool_t& medium;
    Bool_t& tight;
    Bool_t& highpt;
    Bool_t& pixelVeto;
    Bool_t& csafeVeto;
    Bool_t& pfchVeto;
    Ref<SuperCluster> superCluster;
    Ref<PFCand> matchedPF;
    Ref<GenParticle> matchedGen;

  protected:
    /* ParticleP
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    */

  public:
    /* BEGIN CUSTOM Photon.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    Photon(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<Photon> PhotonArray;
  typedef Collection<Photon> PhotonCollection;
  typedef Ref<Photon> PhotonRef;
  typedef RefVector<Photon> PhotonRefVector;

  /* BEGIN CUSTOM Photon.h.global */
  /* END CUSTOM */

}

#endif
