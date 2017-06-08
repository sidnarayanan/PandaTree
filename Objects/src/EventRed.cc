#include "../interface/EventRed.h"

panda::EventRed::EventRed() :
  EventBase()
{
  std::vector<Object*> myObjects{{&pfCandidates, &genParticles, &recoJets, &recoSubjets, &truthJets, &genJets}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&pfCandidates, &genParticles, &recoJets, &recoSubjets, &truthJets, &genJets}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  recoJets.data.constituentsContainer_ = &pfCandidates;
  recoJets.data.subjetsContainer_ = &recoSubjets;
  recoJets.data.matchedGenJetContainer_ = &genJets;
  truthJets.data.constituentsContainer_ = &genParticles;
}

panda::EventRed::EventRed(EventRed const& _src) :
  EventBase(_src),
  pfCandidates(_src.pfCandidates),
  genParticles(_src.genParticles),
  recoJets(_src.recoJets),
  recoSubjets(_src.recoSubjets),
  truthJets(_src.truthJets),
  genJets(_src.genJets),
  npv(_src.npv),
  rho(_src.rho)
{
  std::vector<Object*> myObjects{{&pfCandidates, &genParticles, &recoJets, &recoSubjets, &truthJets, &genJets}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&pfCandidates, &genParticles, &recoJets, &recoSubjets, &truthJets, &genJets}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());


  recoJets.data.constituentsContainer_ = &pfCandidates;
  recoJets.data.subjetsContainer_ = &recoSubjets;
  recoJets.data.matchedGenJetContainer_ = &genJets;
  truthJets.data.constituentsContainer_ = &genParticles;
  /* BEGIN CUSTOM EventRed.cc.copy_ctor */
  /* END CUSTOM */
}

panda::EventRed&
panda::EventRed::operator=(EventRed const& _src)
{
  EventBase::operator=(_src);

  /* BEGIN CUSTOM EventRed.cc.operator= */
  /* END CUSTOM */

  npv = _src.npv;
  rho = _src.rho;

  pfCandidates = _src.pfCandidates;
  genParticles = _src.genParticles;
  recoJets = _src.recoJets;
  recoSubjets = _src.recoSubjets;
  truthJets = _src.truthJets;
  genJets = _src.genJets;

  recoJets.data.constituentsContainer_ = &pfCandidates;
  recoJets.data.subjetsContainer_ = &recoSubjets;
  recoJets.data.matchedGenJetContainer_ = &genJets;
  truthJets.data.constituentsContainer_ = &genParticles;

  return *this;
}

void
panda::EventRed::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventRed.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::EventRed::dump(std::ostream& _out/* = std::cout*/) const
{
  EventBase::dump(_out);

  _out << "npv = " << npv << std::endl;
  _out << "rho = " << rho << std::endl;

  pfCandidates.dump(_out);
  genParticles.dump(_out);
  recoJets.dump(_out);
  recoSubjets.dump(_out);
  truthJets.dump(_out);
  genJets.dump(_out);

}
/*static*/
panda::utils::BranchList
panda::EventRed::getListOfBranches()
{
  utils::BranchList blist;
  blist += EventBase::getListOfBranches();

  blist += {"npv", "rho"};
  blist += PFCand::getListOfBranches().fullNames("pfCandidates");
  blist += GenParticle::getListOfBranches().fullNames("genParticles");
  blist += FatJet::getListOfBranches().fullNames("recoJets");
  blist += MicroJet::getListOfBranches().fullNames("recoSubjets");
  blist += TruthJet::getListOfBranches().fullNames("truthJets");
  blist += GenJet::getListOfBranches().fullNames("genJets");
  return blist;
}

/*protected*/
void
panda::EventRed::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doSetStatus_(_tree, _branches);
  utils::setStatus(_tree, "", "npv", _branches);
  utils::setStatus(_tree, "", "rho", _branches);
}

/*protected*/
panda::utils::BranchList
panda::EventRed::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventBase::doGetStatus_(_tree);

  blist.push_back(utils::getStatus(_tree, "", "npv"));
  blist.push_back(utils::getStatus(_tree, "", "rho"));
  return blist;
}

/*protected*/
panda::utils::BranchList
panda::EventRed::doGetBranchNames_() const
{
  return getListOfBranches();
}

/*protected*/
void
panda::EventRed::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventBase::doSetAddress_(_tree, _branches, _setStatus);

  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "rho", &rho, _branches, _setStatus);
}

/*protected*/
void
panda::EventRed::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doBook_(_tree, _branches);

  utils::book(_tree, "", "npv", "", 's', &npv, _branches);
  utils::book(_tree, "", "rho", "", 'F', &rho, _branches);
}

/*protected*/
void
panda::EventRed::doGetEntry_(TTree& _tree, Long64_t _entry)
{
  EventBase::doGetEntry_(_tree, _entry);

  /* BEGIN CUSTOM EventRed.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
panda::EventRed::doInit_()
{
  EventBase::doInit_();

  npv = 0;
  rho = 0.;
  /* BEGIN CUSTOM EventRed.cc.doInit_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventRed.cc.global */
/* END CUSTOM */
