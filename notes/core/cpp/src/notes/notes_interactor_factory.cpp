#include "notes_interactor_factory.hpp"
#include "notes_interactor_impl.hpp"

std::shared_ptr<NotesInteractor> NotesInteractorFactory::create() {
  return std::make_shared<NotesInteractorImpl>();
}
