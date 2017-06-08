#include "../interface/TruthJet.h"

/*static*/
panda::utils::BranchList
panda::TruthJet::getListOfBranches()
{
  utils::BranchList blist;
  blist += GenJet::getListOfBranches();
  blist += {"constituents_"};
  return blist;
}

void
panda::TruthJet::datastore::allocate(UInt_t _nmax)
{
  GenJet::datastore::allocate(_nmax);

  constituents_ = new std::vector<std::vector<Short_t>>(nmax_);
}

void
panda::TruthJet::datastore::deallocate()
{
  GenJet::datastore::deallocate();

  delete constituents_;
  constituents_ = 0;
}

void
panda::TruthJet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  GenJet::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "constituents_", _branches);
}

panda::utils::BranchList
panda::TruthJet::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(GenJet::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "constituents_"));

  return blist;
}

void
panda::TruthJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  GenJet::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "constituents_", &constituents_, _branches, _setStatus);
}

void
panda::TruthJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  GenJet::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "constituents_", "std::vector<std::vector<Short_t>>", &constituents_, _branches);
}

void
panda::TruthJet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  GenJet::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "constituents_");
}

void
panda::TruthJet::datastore::resizeVectors_(UInt_t _size)
{
  GenJet::datastore::resizeVectors_(_size);

  constituents_->resize(_size);
}


panda::utils::BranchList
panda::TruthJet::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return TruthJet::getListOfBranches().fullNames(_name);
}

panda::TruthJet::TruthJet(char const* _name/* = ""*/) :
  GenJet(new TruthJetArray(1, _name)),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::TruthJet::TruthJet(TruthJet const& _src) :
  GenJet(new TruthJetArray(1, gStore.getName(&_src))),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
  GenJet::operator=(_src);

  constituents = _src.constituents;
}

panda::TruthJet::TruthJet(datastore& _data, UInt_t _idx) :
  GenJet(_data, _idx),
  constituents(_data.constituentsContainer_, (*_data.constituents_)[_idx])
{
}

panda::TruthJet::TruthJet(ArrayBase* _array) :
  GenJet(_array),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0])
{
}

panda::TruthJet::~TruthJet()
{
  destructor();
  gStore.free(this);
}

void
panda::TruthJet::destructor()
{
  /* BEGIN CUSTOM TruthJet.cc.destructor */
  /* END CUSTOM */

  GenJet::destructor();
}

panda::TruthJet&
panda::TruthJet::operator=(TruthJet const& _src)
{
  GenJet::operator=(_src);

  constituents = _src.constituents;

  return *this;
}

void
panda::TruthJet::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  GenJet::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "constituents_", &constituents.indices(), _branches, true);
}

void
panda::TruthJet::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  GenJet::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "constituents_", "std::vector<Short_t>", &constituents.indices(), _branches);
}

void
panda::TruthJet::doInit_()
{
  GenJet::doInit_();

  constituents.init();

  /* BEGIN CUSTOM TruthJet.cc.doInit_ */
  /* END CUSTOM */
}

void
panda::TruthJet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM TruthJet.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
panda::TruthJet::dump(std::ostream& _out/* = std::cout*/) const
{
  GenJet::dump(_out);

  _out << "constituents = " << constituents << std::endl;
}

/* BEGIN CUSTOM TruthJet.cc.global */
/* END CUSTOM */
