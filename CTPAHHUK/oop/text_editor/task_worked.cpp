// #include "task.h"
// #include "logged_command_wrapper.h"
// #include <iostream>

// // cursorPosition отображает сколько символов слева от него

// /* Курсор влево */
// class MoveCursorLeftCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }
//         if (cursorPosition != 0) {
//             cursorPosition--;
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitMoveCursorLeftCommand(*this);
//     }
// };

// /* Курсор вправо */
// class MoveCursorRightCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }
//         if (cursorPosition != (editor.GetText().length())) {
//             cursorPosition++;
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitMoveCursorRightCommand(*this);
//     }
// };

// /* Курсор вверх */
// class MoveCursorUpCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }
//         std::cout << "in move\n";
//         if (cursorPosition == 0) {
//             return;
//         }
//         // l_slahs_n &&&&& r_slash_n &&cursor&&
//         size_t r_slash_n = buffer.substr(0, cursorPosition).rfind('\n');
//         if (r_slash_n == std::string::npos) {
//             // cursorPosition = 0;
//             std::cout << "r_slash_n == 0\n";
//             return;
//         }

//         size_t l_slahs_n = buffer.substr(0, r_slash_n).rfind('\n');
//         size_t diff = cursorPosition - r_slash_n;
//         std::cout << "cursor Position = " << cursorPosition << "\tl_slash_n = " << l_slahs_n << "\trslahsl = " << r_slash_n << "\n";
//         if (l_slahs_n == std::string::npos) {
//             cursorPosition = diff - 1;
//             std::cout << "cursor in MoveCursorUpCommand = " << cursorPosition << "\n";
//             return;
//         }
//         std::cout << "Normal\n";
//         cursorPosition = l_slahs_n + diff;
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitMoveCursorUpCommand(*this);
//     }
// };

// class MoveCursorDownCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }
//         // Находим позицию следующего символа новой строки
//         size_t slash_n_right = buffer.find('\n', cursorPosition);
        
//         // Находим позицию предыдущего символа новой строки
//         size_t slash_n_left = buffer.rfind('\n', cursorPosition);
        
//         if (slash_n_right == std::string::npos) {
//             // строка и та последняя
//             cursorPosition = buffer.size();
//             return;
//         }
        
//         // Определяем начало следующей строки
//         size_t nextLineStart = slash_n_right + 1;

//         // Определяем длину текущей строки
//         size_t currentLineStart = (slash_n_left == std::string::npos) ? 0 : slash_n_left + 1;
//         // size_t currentLineLength = slash_n_right - currentLineStart;

//         // Определяем смещение курсора относительно начала текущей строки
//         size_t offset = cursorPosition - currentLineStart;

//         // Перемещаем курсор в новую строку с сохранением позиции относительно начала строки
//         cursorPosition = nextLineStart + offset;

//         // Убедимся, что курсор не выходит за пределы новой строки
//         size_t nextLineEnd = buffer.find('\n', nextLineStart);
//         if (nextLineEnd != std::string::npos) {
//             size_t newLineLength = nextLineEnd - nextLineStart;
//             if (cursorPosition > nextLineStart + newLineLength) {
//                 cursorPosition = nextLineStart + newLineLength; // Устанавливаем курсор в конец строки
//             }
//         } else {
//             cursorPosition = buffer.size();
//         }
//     }
    
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitMoveCursorDownCommand(*this);
//     }
// };

// /* Выделить текст */
// class SelectTextCommand : public ICommand {
// public:
//     SelectTextCommand(size_t sz) : selectionSize_(sz) {}
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }
//         editor.SelectText(cursorPosition, cursorPosition + selectionSize_);
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitSelectCommand(*this);
//     }
// private:
//     size_t selectionSize_;
// };

// /* Ввести текст */
// class InsertTextCommand : public ICommand {
// public:
//     InsertTextCommand(std::string text) : text_(text) {}
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             // удаляем выделенный текст
//             buffer.erase(editor.GetSelection().first, editor.GetSelection().second - editor.GetSelection().second + 1);
//             cursorPosition = editor.GetSelection().first;
//             editor.UnselectText();
//         }
//         buffer.insert(cursorPosition, text_);
//         cursorPosition += text_.length();
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitInsertTextCommand(*this);
//     }
// private:
//     std::string text_;
// };

// /* Удалить текст */
// class DeleteTextCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             // удаление выделенного текста
//             buffer.erase(editor.GetSelection().first, editor.GetSelection().second - editor.GetSelection().first);
//             cursorPosition = editor.GetSelection().first;
//             editor.UnselectText();
//             return;
//         }
//         if (cursorPosition != 0) {
//             // удаление одного символа
//             buffer.erase(cursorPosition, 1);
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitDeleteTextCommand(*this);
//     }
// };

// /* Скопировать текст */
// class CopyTextCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             clipboard = buffer.substr(editor.GetSelection().first, editor.GetSelection().second - editor.GetSelection().first + 1);
//             editor.UnselectText();
//         }
//         if (cursorPosition != 0) {
//             clipboard = buffer[cursorPosition - 1];
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitCopyTextCommand(*this);
//     }
// };

// /* Вставить скопированный текст */
// class PasteTextCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             // удаляем выделенный текст
//             // std::cout << "get_sel = " << editor.GetSelection().first << " " << editor.GetSelection().second << "\n";
//             // std::cout << "substr wich erase = {" << buffer.substr(editor.GetSelection().first, editor.GetSelection().second - editor.GetSelection().second - 1) << "}" << std::endl;
//             buffer.erase(editor.GetSelection().first, editor.GetSelection().second - editor.GetSelection().second - 1);
//             cursorPosition = editor.GetSelection().first;
//             editor.UnselectText();
//         }
//         // std::cout << "new buffer = {" << buffer << "}\n";
//         buffer.insert(cursorPosition, clipboard);
//         cursorPosition += clipboard.length();
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitPasteTextCommand(*this);
//     }
// };

// /* Привести выделенный текст в ВЕРХНИЙ регистр */
// class UppercaseTextCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             for (size_t ind = editor.GetSelection().first; ind <= editor.GetSelection().second; ++ind) {
//                 buffer[ind] = toupper(buffer[ind]);
//             }
//             editor.UnselectText();
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitUppercaseTextCommand(*this);
//     }
// };

// /* Привести выделенный текст в нижний регистр */
// class LowercaseTextCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             for (size_t ind = editor.GetSelection().first; ind <= editor.GetSelection().second; ++ind) {
//                 buffer[ind] = tolower(buffer[ind]);
//             }
//             editor.UnselectText();
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitLowercaseTextCommand(*this);
//     }
// };

// /* Перенести курсор в конец строки */
// class MoveToEndCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }

//         while (cursorPosition != editor.GetText().length() && editor.GetText()[cursorPosition] != '\n') {
//             cursorPosition++;
//         }
        
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitMoveToEndCommand(*this);
//     }
// };

// /* Перенести курсор в начало строки */
// class MoveToStartCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }
//         while (cursorPosition != 0 && editor.GetText()[cursorPosition - 1] != '\n') {
//             // std::cout << editor.GetText()[cursorPosition - 1];
//             cursorPosition--;
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitMoveToStartCommand(*this);
//     }
// };

// /* Удалить часть строки, начиная от позиции курсора до первого пробела или конца строки */
// class DeleteWordCommand : public ICommand {
// public:
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         // будем удалять текст до начала строки, т.е. направо
//         if (editor.HasSelection()) {
//             editor.UnselectText();
//         }
//         // ближайший пробел или '\n' справа
//         size_t l = cursorPosition;
//         while (l != buffer.length() && buffer[l] != ' ' && buffer[l] != '\n') {
//             l++;
//         }
//         if (l != buffer.length()) {
//             l--;
//         }
//         buffer.erase(cursorPosition, l - cursorPosition + 1);
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         visitor.VisitDeleteWordCommand(*this);
//     }
// };

// /* Макрос */
// class MacroCommand : public ICommand {
// public:
//     MacroCommand(std::list<CommandPtr> subcommands) : subcommands_(subcommands) {}
//     void Apply(std::string& buffer, size_t& cursorPosition, std::string& clipboard, TextEditor& editor) override {
//         // int cnt = 0;
//         // std::cout << "before changes = ";
//         // std::cout << "№ " << cnt << "\tbuffer = " << buffer << "\tcurs = " << cursorPosition << "\tcb = " << clipboard << "\n";
//         for (auto cur_command : subcommands_) {
//             cur_command->Apply(buffer, cursorPosition, clipboard, editor);
//             // std::cout << "№ " << ++cnt << "\tbuffer = " << buffer << "\tcurs = " << cursorPosition << "\tcb = " << clipboard << "\n";
//             // std::cout << "№ " << cnt <<   "\ttexttt = " << editor.GetText() << "\tcurs = " << cursorPosition << "\tcb = " << clipboard << "\n";
//         }
//     }
//     void AcceptVisitor(CommandVisitor& visitor) override {
//         for (auto cur_command : subcommands_) {
//             cur_command->AcceptVisitor(visitor);
//         }
//     }
// private:
//     std::list<CommandPtr> subcommands_;
// };

// CommandBuilder::CommandBuilder() {}

// CommandPtr CommandBuilder::build() {
//     if (type_ == Type::MoveCursorLeft) {
//         return std::make_shared<MoveCursorLeftCommand>();
//     } else if (type_ == Type::MoveCursorRight) {
//         return std::make_shared<MoveCursorRightCommand>();
//     } else if (type_ == Type::MoveCursorUp) {
//         return std::make_shared<MoveCursorUpCommand>();
//     } else if (type_ == Type::MoveCursorDown) {
//         return std::make_shared<MoveCursorDownCommand>();
//     } else if (type_ == Type::SelectText) {
//         return std::make_shared<SelectTextCommand>(selectionSize_);
//     } else if (type_ == Type::InsertText) {
//         return std::make_shared<InsertTextCommand>(text_);
//     } else if (type_ == Type::DeleteText) {
//         return std::make_shared<DeleteTextCommand>();
//     } else if (type_ == Type::CopyText) {
//         return std::make_shared<CopyTextCommand>();
//     } else if (type_ == Type::PasteText) {
//         return std::make_shared<PasteTextCommand>();
//     } else if (type_ == Type::UppercaseText) {
//         return std::make_shared<UppercaseTextCommand>();
//     } else if (type_ == Type::LowercaseText) {
//         return std::make_shared<LowercaseTextCommand>();
//     } else if (type_ == Type::MoveToEnd) {
//         return std::make_shared<MoveToEndCommand>();
//     } else if (type_ == Type::MoveToStart) {
//         return std::make_shared<MoveToStartCommand>();
//     } else if (type_ == Type::DeleteWord) {
//         return std::make_shared<DeleteWordCommand>();
//     } else {
//         return std::make_shared<MacroCommand>(subcommands_);
//     }
// }
// CommandBuilder& CommandBuilder::WithType(Type type) {
//     type_ = type;
//     return *this;
// }
// CommandBuilder& CommandBuilder::SelectionSize(size_t selectionSize) {
//     selectionSize_ = selectionSize;
//     return *this;
// }
// CommandBuilder& CommandBuilder::Text(std::string text) {
//     text_ = text;
//     return *this;
// }
// CommandBuilder& CommandBuilder::LogTo(std::ostream& logStream) {
//     logStreamPtr_ = &logStream;
//     return *this;
// }
// CommandBuilder& CommandBuilder::AddSubcommand(CommandPtr subcommand) {
//     subcommands_.push_back(subcommand);
//     return *this;
// }


// CommandLoggerVisitor::CommandLoggerVisitor(std::ostream& logStream) : logStream_(logStream) {}

// void CommandLoggerVisitor::VisitMoveCursorLeftCommand(MoveCursorLeftCommand& command) {
//     logStream_ << 'h';
// }
// void CommandLoggerVisitor::VisitMoveCursorRightCommand(MoveCursorRightCommand& command) {
//     logStream_ << 'l';
// }
// void CommandLoggerVisitor::VisitMoveCursorUpCommand(MoveCursorUpCommand& command) {
//     logStream_ << 'k';
// }
// void CommandLoggerVisitor::VisitMoveCursorDownCommand(MoveCursorDownCommand& command) {
//     logStream_ << 'j';
// }
// void CommandLoggerVisitor::VisitSelectCommand(SelectTextCommand& command) {
//     logStream_ << 'v';
// }
// void CommandLoggerVisitor::VisitInsertTextCommand(InsertTextCommand& command) {
//     logStream_ << 'i';
// }
// void CommandLoggerVisitor::VisitDeleteTextCommand(DeleteTextCommand& command) {
//     logStream_ << 'd';
// }
// void CommandLoggerVisitor::VisitCopyTextCommand(CopyTextCommand& command) {
//     logStream_ << 'y';
// }
// void CommandLoggerVisitor::VisitPasteTextCommand(PasteTextCommand& command) {
//     logStream_ << 'p';
// }
// void CommandLoggerVisitor::VisitUppercaseTextCommand(UppercaseTextCommand& command) {
//     logStream_ << 'U';
// }
// void CommandLoggerVisitor::VisitLowercaseTextCommand(LowercaseTextCommand& command) {
//     logStream_ << 'u';
// }
// void CommandLoggerVisitor::VisitMoveToEndCommand(MoveToEndCommand& command) {
//     logStream_ << '$';
// }
// void CommandLoggerVisitor::VisitMoveToStartCommand(MoveToStartCommand& command) {
//     logStream_ << '0';
// }
// void CommandLoggerVisitor::VisitDeleteWordCommand(DeleteWordCommand& command) {
//     logStream_ << "dE";
// }
