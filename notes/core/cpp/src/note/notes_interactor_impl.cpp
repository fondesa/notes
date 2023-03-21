#include "notes_interactor_impl.hpp"

std::optional<Draft> NotesInteractorImpl::getDraft() {
  return std::optional<Draft>(Draft("dummy_title", "dummy_description"));
}
