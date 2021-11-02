project('t9qt', 'cpp',
  default_options: [
	'buildtype=debugoptimized',
	'warning_level=1',
	'cpp_std=c++20'
	],
  license: 'MIT'
  )

cxx = meson.get_compiler('cpp')

cppflags = [
  '-pipe',
  '-funsigned-char'
  ]

add_project_arguments(cxx.get_supported_arguments(cppflags), language: 'cpp')

qt = import('qt5')
qt_dep = dependency('qt5', modules: ['Core', 'Widgets', 'Gui'])
fmt_dep = dependency('fmt')

subdir('src')
