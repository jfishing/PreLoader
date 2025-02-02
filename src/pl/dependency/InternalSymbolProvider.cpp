#include "pl/SymbolProvider.h"
#include "pl/dependency/IProvider.h"
#include "pl/dependency/LibrarySearcher.h"
#include <fstream>
namespace pl::dependency_walker {

InternalSymbolProvider::InternalSymbolProvider() = default;

bool InternalSymbolProvider::queryExport(const std::string& symbol) {
    if (symbol_provider::pl_resolve_symbol_silent(symbol.c_str()) == nullptr) return false;
    else return true;
}

const IProvider::ImportContainer& InternalSymbolProvider::getImports() {
    static IProvider::ImportContainer empty;
    return empty;
}

} // namespace pl::dependency_walker
