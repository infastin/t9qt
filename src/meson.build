header_files = [
  't9qt.hpp',
  'drawingarea.hpp'
]

source_files = [
  't9qt.cpp',
  'drawingarea.cpp'
]

source_files += qt.preprocess(moc_headers: header_files)

executable('t9qt', source_files,
  dependencies: [qt_dep, fmt_dep]
)
