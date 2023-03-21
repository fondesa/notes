#pragma once

#include "notes_interactor.hpp"

class NotesInteractorImpl : public NotesInteractor {
 public:
  std::optional<Draft> getDraft() override;
};