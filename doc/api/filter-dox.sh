#!/bin/sh

# Used per doc/api/doxygen.config[.in]'s INPUT_FILTER.
# Prune some identifiers so that the generated documentation
# looks nicer and avoids internal stuff like __ATTR_PURE__.

sed -e 's:__ATTR_ALWAYS_INLINE__::g' \
    -e 's:__ATTR_CONST__::g' \
    -e 's:__ATTR_PURE__::g' \
    -e 's:__extension__::g' \
    -e 's:__inline__:inline:g' \
    -e 's:__attribute__:attribute:g' \
    -e 's:__progmem__:progmem:g' \
    -e 's:__section__:section:g' \
    $1
